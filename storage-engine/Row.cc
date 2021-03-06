/*
 * Copyright (C) 2013 Near Infinity Corporation
 *
 * This file is part of Honeycomb Storage Engine.
 *
 * Honeycomb Storage Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * Honeycomb Storage Engine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Honeycomb Storage Engine.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "Row.h"
#include "AvroUtil.h"


#define ROW_CONTAINER_SCHEMA "{\"type\":\"record\",\"name\":\"AvroRow\",\"namespace\":\"com.nearinfinity.honeycomb.mysql.gen\",\"fields\":[{\"name\":\"version\",\"type\":\"int\",\"doc\":\"Schema version number\",\"default\":0},{\"name\":\"uuid\",\"type\":{\"type\":\"fixed\",\"name\":\"UUIDContainer\",\"size\":16}},{\"name\":\"records\",\"type\":{\"type\":\"map\",\"values\":\"bytes\",\"avro.java.string\":\"String\"}}]}"

const int Row::CURRENT_VERSION = 0;
const char* Row::VERSION_FIELD = "version";

Row::Row()
: row_container_schema(),
  row_container()
{
  if (avro_schema_from_json_literal(ROW_CONTAINER_SCHEMA, &row_container_schema))
  {
    printf("Unable to create RowContainer schema.  Exiting.\n");
    abort();
  };
  avro_value_iface_t* rc_class = avro_generic_class_from_schema(row_container_schema);
  if (avro_generic_value_new(rc_class, &row_container))
  {
    printf("Unable to create RowContainer.  Exiting.\n");
    abort();
  }

  set_schema_version(CURRENT_VERSION);
  avro_value_iface_decref(rc_class);
}

Row::~Row()
{
  avro_value_decref(&row_container);
  avro_schema_decref(row_container_schema);
}

int Row::reset()
{
  int ret = 0;
  ret |= avro_value_reset(&row_container);
  ret |= set_schema_version(CURRENT_VERSION);
  return ret;
}

bool Row::equals(const Row& other)
{
  avro_value_t other_row_container = other.row_container;
  return avro_value_equal(&row_container, &other_row_container);
}

int Row::serialize(const char** buf, size_t* len)
{
  return serialize_object(&row_container, buf, len);
}

int Row::deserialize(const char* buf, int64_t len)
{
  return deserialize_object(&row_container, buf, len);
}

int Row::record_count(size_t* count)
{
  int ret = 0;
  avro_value_t records_map;
  ret |= avro_value_get_by_name(&row_container, "records", &records_map, NULL);
  ret |= avro_value_get_size(&records_map, count);
  return ret;
}

int Row::get_UUID(const char** buf)
{
  int ret = 0;
  size_t size = 16;
  avro_value_t uuid;
  ret |= avro_value_get_by_name(&row_container, "uuid", &uuid, NULL);
  ret |= avro_value_get_fixed(&uuid, (const void**)buf, &size);
  return ret;
}

int Row::set_UUID(unsigned char* uuid_buf)
{
  int ret = 0;
  avro_value_t uuid;
  ret |= avro_value_get_by_name(&row_container, "uuid", &uuid, NULL);
  ret |= avro_value_set_fixed(&uuid, uuid_buf, 16);
  return ret;
}

int Row::set_schema_version(const int& version)
{
  int ret = 0;
  avro_value_t schemaVersion;
  ret |= avro_value_get_by_name(&row_container, VERSION_FIELD, &schemaVersion, NULL);
  ret |= avro_value_set_int(&schemaVersion, version);
  return ret;
}

int Row::get_value(const char* column_name, const char** value, size_t* size)
{
  return get_map_value(&row_container, column_name, "records", value, size);
}

int Row::set_value(const char* column_name, char* value, size_t size)
{
  return set_map_value(&row_container, column_name, "records", value, size);
}

package com.nearinfinity.honeycomb.hbase;

import com.gotometrics.orderly.RowKey;
import com.gotometrics.orderly.UnsignedLongRowKey;
import com.nearinfinity.honeycomb.exceptions.RuntimeIOException;
import com.nearinfinity.honeycomb.hbase.rowkey.RowKeyValue;
import com.nearinfinity.honeycomb.util.Verify;

import java.io.IOException;


/**
 * Responsible for encoding variable length values stored in a cell
 */
public abstract class CellEncoder {
    private static final RowKey UNSIGNED_ROWKEY = new UnsignedLongRowKey();

    /**
     * Serializes the provided id value
     * @param id The id to serialize
     * @return The serialized representation of the id
     */
    public static byte[] serializeId(final long id) {
        Verify.isValidId(id, "The provided id must be non-negative");
        return new RowKeyValue(UNSIGNED_ROWKEY, id).serialize();
    }

    /**
     * Deserializes the provided serialized id value
     * @param id The serialized id value
     * @return The deserialized id
     */
    public static long deserializeId(final byte[] id) {
        try {
            return (Long) UNSIGNED_ROWKEY.deserialize(id);
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }
}

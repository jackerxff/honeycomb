/**
 * Autogenerated by Thrift Compiler (0.8.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Engine_H
#define Engine_H

#include <TProcessor.h>
#include "hbase_engine_types.h"

namespace com { namespace nearinfinity { namespace hbase_engine {

class EngineIf {
 public:
  virtual ~EngineIf() {}
  virtual void open() = 0;
  virtual bool createTable(const std::string& tableName, const std::vector<std::string> & columnFamilies) = 0;
  virtual bool addColumnFamily(const std::string& tableName, const std::string& familyName) = 0;
  virtual bool removeColumnFamily(const std::string& tableName, const std::string& familyName) = 0;
  virtual void addData(const std::string& tableName, const std::map<std::string, std::map<std::string, std::map<std::string, std::string> > > & data) = 0;
  virtual bool removeTable(const std::string& tableName) = 0;
};

class EngineIfFactory {
 public:
  typedef EngineIf Handler;

  virtual ~EngineIfFactory() {}

  virtual EngineIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(EngineIf* /* handler */) = 0;
};

class EngineIfSingletonFactory : virtual public EngineIfFactory {
 public:
  EngineIfSingletonFactory(const boost::shared_ptr<EngineIf>& iface) : iface_(iface) {}
  virtual ~EngineIfSingletonFactory() {}

  virtual EngineIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(EngineIf* /* handler */) {}

 protected:
  boost::shared_ptr<EngineIf> iface_;
};

class EngineNull : virtual public EngineIf {
 public:
  virtual ~EngineNull() {}
  void open() {
    return;
  }
  bool createTable(const std::string& /* tableName */, const std::vector<std::string> & /* columnFamilies */) {
    bool _return = false;
    return _return;
  }
  bool addColumnFamily(const std::string& /* tableName */, const std::string& /* familyName */) {
    bool _return = false;
    return _return;
  }
  bool removeColumnFamily(const std::string& /* tableName */, const std::string& /* familyName */) {
    bool _return = false;
    return _return;
  }
  void addData(const std::string& /* tableName */, const std::map<std::string, std::map<std::string, std::map<std::string, std::string> > > & /* data */) {
    return;
  }
  bool removeTable(const std::string& /* tableName */) {
    bool _return = false;
    return _return;
  }
};


class Engine_open_args {
 public:

  Engine_open_args() {
  }

  virtual ~Engine_open_args() throw() {}


  bool operator == (const Engine_open_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Engine_open_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Engine_open_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Engine_open_pargs {
 public:


  virtual ~Engine_open_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Engine_open_result {
 public:

  Engine_open_result() {
  }

  virtual ~Engine_open_result() throw() {}


  bool operator == (const Engine_open_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Engine_open_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Engine_open_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Engine_open_presult {
 public:


  virtual ~Engine_open_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Engine_createTable_args__isset {
  _Engine_createTable_args__isset() : tableName(false), columnFamilies(false) {}
  bool tableName;
  bool columnFamilies;
} _Engine_createTable_args__isset;

class Engine_createTable_args {
 public:

  Engine_createTable_args() : tableName("") {
  }

  virtual ~Engine_createTable_args() throw() {}

  std::string tableName;
  std::vector<std::string>  columnFamilies;

  _Engine_createTable_args__isset __isset;

  void __set_tableName(const std::string& val) {
    tableName = val;
  }

  void __set_columnFamilies(const std::vector<std::string> & val) {
    columnFamilies = val;
  }

  bool operator == (const Engine_createTable_args & rhs) const
  {
    if (!(tableName == rhs.tableName))
      return false;
    if (!(columnFamilies == rhs.columnFamilies))
      return false;
    return true;
  }
  bool operator != (const Engine_createTable_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Engine_createTable_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Engine_createTable_pargs {
 public:


  virtual ~Engine_createTable_pargs() throw() {}

  const std::string* tableName;
  const std::vector<std::string> * columnFamilies;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Engine_createTable_result__isset {
  _Engine_createTable_result__isset() : success(false) {}
  bool success;
} _Engine_createTable_result__isset;

class Engine_createTable_result {
 public:

  Engine_createTable_result() : success(0) {
  }

  virtual ~Engine_createTable_result() throw() {}

  bool success;

  _Engine_createTable_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  bool operator == (const Engine_createTable_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Engine_createTable_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Engine_createTable_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Engine_createTable_presult__isset {
  _Engine_createTable_presult__isset() : success(false) {}
  bool success;
} _Engine_createTable_presult__isset;

class Engine_createTable_presult {
 public:


  virtual ~Engine_createTable_presult() throw() {}

  bool* success;

  _Engine_createTable_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Engine_addColumnFamily_args__isset {
  _Engine_addColumnFamily_args__isset() : tableName(false), familyName(false) {}
  bool tableName;
  bool familyName;
} _Engine_addColumnFamily_args__isset;

class Engine_addColumnFamily_args {
 public:

  Engine_addColumnFamily_args() : tableName(""), familyName("") {
  }

  virtual ~Engine_addColumnFamily_args() throw() {}

  std::string tableName;
  std::string familyName;

  _Engine_addColumnFamily_args__isset __isset;

  void __set_tableName(const std::string& val) {
    tableName = val;
  }

  void __set_familyName(const std::string& val) {
    familyName = val;
  }

  bool operator == (const Engine_addColumnFamily_args & rhs) const
  {
    if (!(tableName == rhs.tableName))
      return false;
    if (!(familyName == rhs.familyName))
      return false;
    return true;
  }
  bool operator != (const Engine_addColumnFamily_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Engine_addColumnFamily_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Engine_addColumnFamily_pargs {
 public:


  virtual ~Engine_addColumnFamily_pargs() throw() {}

  const std::string* tableName;
  const std::string* familyName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Engine_addColumnFamily_result__isset {
  _Engine_addColumnFamily_result__isset() : success(false) {}
  bool success;
} _Engine_addColumnFamily_result__isset;

class Engine_addColumnFamily_result {
 public:

  Engine_addColumnFamily_result() : success(0) {
  }

  virtual ~Engine_addColumnFamily_result() throw() {}

  bool success;

  _Engine_addColumnFamily_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  bool operator == (const Engine_addColumnFamily_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Engine_addColumnFamily_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Engine_addColumnFamily_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Engine_addColumnFamily_presult__isset {
  _Engine_addColumnFamily_presult__isset() : success(false) {}
  bool success;
} _Engine_addColumnFamily_presult__isset;

class Engine_addColumnFamily_presult {
 public:


  virtual ~Engine_addColumnFamily_presult() throw() {}

  bool* success;

  _Engine_addColumnFamily_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Engine_removeColumnFamily_args__isset {
  _Engine_removeColumnFamily_args__isset() : tableName(false), familyName(false) {}
  bool tableName;
  bool familyName;
} _Engine_removeColumnFamily_args__isset;

class Engine_removeColumnFamily_args {
 public:

  Engine_removeColumnFamily_args() : tableName(""), familyName("") {
  }

  virtual ~Engine_removeColumnFamily_args() throw() {}

  std::string tableName;
  std::string familyName;

  _Engine_removeColumnFamily_args__isset __isset;

  void __set_tableName(const std::string& val) {
    tableName = val;
  }

  void __set_familyName(const std::string& val) {
    familyName = val;
  }

  bool operator == (const Engine_removeColumnFamily_args & rhs) const
  {
    if (!(tableName == rhs.tableName))
      return false;
    if (!(familyName == rhs.familyName))
      return false;
    return true;
  }
  bool operator != (const Engine_removeColumnFamily_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Engine_removeColumnFamily_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Engine_removeColumnFamily_pargs {
 public:


  virtual ~Engine_removeColumnFamily_pargs() throw() {}

  const std::string* tableName;
  const std::string* familyName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Engine_removeColumnFamily_result__isset {
  _Engine_removeColumnFamily_result__isset() : success(false) {}
  bool success;
} _Engine_removeColumnFamily_result__isset;

class Engine_removeColumnFamily_result {
 public:

  Engine_removeColumnFamily_result() : success(0) {
  }

  virtual ~Engine_removeColumnFamily_result() throw() {}

  bool success;

  _Engine_removeColumnFamily_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  bool operator == (const Engine_removeColumnFamily_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Engine_removeColumnFamily_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Engine_removeColumnFamily_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Engine_removeColumnFamily_presult__isset {
  _Engine_removeColumnFamily_presult__isset() : success(false) {}
  bool success;
} _Engine_removeColumnFamily_presult__isset;

class Engine_removeColumnFamily_presult {
 public:


  virtual ~Engine_removeColumnFamily_presult() throw() {}

  bool* success;

  _Engine_removeColumnFamily_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Engine_addData_args__isset {
  _Engine_addData_args__isset() : tableName(false), data(false) {}
  bool tableName;
  bool data;
} _Engine_addData_args__isset;

class Engine_addData_args {
 public:

  Engine_addData_args() : tableName("") {
  }

  virtual ~Engine_addData_args() throw() {}

  std::string tableName;
  std::map<std::string, std::map<std::string, std::map<std::string, std::string> > >  data;

  _Engine_addData_args__isset __isset;

  void __set_tableName(const std::string& val) {
    tableName = val;
  }

  void __set_data(const std::map<std::string, std::map<std::string, std::map<std::string, std::string> > > & val) {
    data = val;
  }

  bool operator == (const Engine_addData_args & rhs) const
  {
    if (!(tableName == rhs.tableName))
      return false;
    if (!(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const Engine_addData_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Engine_addData_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Engine_addData_pargs {
 public:


  virtual ~Engine_addData_pargs() throw() {}

  const std::string* tableName;
  const std::map<std::string, std::map<std::string, std::map<std::string, std::string> > > * data;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Engine_addData_result {
 public:

  Engine_addData_result() {
  }

  virtual ~Engine_addData_result() throw() {}


  bool operator == (const Engine_addData_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Engine_addData_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Engine_addData_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Engine_addData_presult {
 public:


  virtual ~Engine_addData_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Engine_removeTable_args__isset {
  _Engine_removeTable_args__isset() : tableName(false) {}
  bool tableName;
} _Engine_removeTable_args__isset;

class Engine_removeTable_args {
 public:

  Engine_removeTable_args() : tableName("") {
  }

  virtual ~Engine_removeTable_args() throw() {}

  std::string tableName;

  _Engine_removeTable_args__isset __isset;

  void __set_tableName(const std::string& val) {
    tableName = val;
  }

  bool operator == (const Engine_removeTable_args & rhs) const
  {
    if (!(tableName == rhs.tableName))
      return false;
    return true;
  }
  bool operator != (const Engine_removeTable_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Engine_removeTable_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Engine_removeTable_pargs {
 public:


  virtual ~Engine_removeTable_pargs() throw() {}

  const std::string* tableName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Engine_removeTable_result__isset {
  _Engine_removeTable_result__isset() : success(false) {}
  bool success;
} _Engine_removeTable_result__isset;

class Engine_removeTable_result {
 public:

  Engine_removeTable_result() : success(0) {
  }

  virtual ~Engine_removeTable_result() throw() {}

  bool success;

  _Engine_removeTable_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  bool operator == (const Engine_removeTable_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Engine_removeTable_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Engine_removeTable_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Engine_removeTable_presult__isset {
  _Engine_removeTable_presult__isset() : success(false) {}
  bool success;
} _Engine_removeTable_presult__isset;

class Engine_removeTable_presult {
 public:


  virtual ~Engine_removeTable_presult() throw() {}

  bool* success;

  _Engine_removeTable_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class EngineClient : virtual public EngineIf {
 public:
  EngineClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  EngineClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void open();
  void send_open();
  void recv_open();
  bool createTable(const std::string& tableName, const std::vector<std::string> & columnFamilies);
  void send_createTable(const std::string& tableName, const std::vector<std::string> & columnFamilies);
  bool recv_createTable();
  bool addColumnFamily(const std::string& tableName, const std::string& familyName);
  void send_addColumnFamily(const std::string& tableName, const std::string& familyName);
  bool recv_addColumnFamily();
  bool removeColumnFamily(const std::string& tableName, const std::string& familyName);
  void send_removeColumnFamily(const std::string& tableName, const std::string& familyName);
  bool recv_removeColumnFamily();
  void addData(const std::string& tableName, const std::map<std::string, std::map<std::string, std::map<std::string, std::string> > > & data);
  void send_addData(const std::string& tableName, const std::map<std::string, std::map<std::string, std::map<std::string, std::string> > > & data);
  void recv_addData();
  bool removeTable(const std::string& tableName);
  void send_removeTable(const std::string& tableName);
  bool recv_removeTable();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class EngineProcessor : public ::apache::thrift::TProcessor {
 protected:
  boost::shared_ptr<EngineIf> iface_;
  virtual bool process_fn(apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, std::string& fname, int32_t seqid, void* callContext);
 private:
  std::map<std::string, void (EngineProcessor::*)(int32_t, apache::thrift::protocol::TProtocol*, apache::thrift::protocol::TProtocol*, void*)> processMap_;
  void process_open(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_createTable(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_addColumnFamily(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_removeColumnFamily(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_addData(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_removeTable(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  EngineProcessor(boost::shared_ptr<EngineIf> iface) :
    iface_(iface) {
    processMap_["open"] = &EngineProcessor::process_open;
    processMap_["createTable"] = &EngineProcessor::process_createTable;
    processMap_["addColumnFamily"] = &EngineProcessor::process_addColumnFamily;
    processMap_["removeColumnFamily"] = &EngineProcessor::process_removeColumnFamily;
    processMap_["addData"] = &EngineProcessor::process_addData;
    processMap_["removeTable"] = &EngineProcessor::process_removeTable;
  }

  virtual bool process(boost::shared_ptr<apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr<apache::thrift::protocol::TProtocol> poprot, void* callContext);
  virtual ~EngineProcessor() {}
};

class EngineProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  EngineProcessorFactory(const ::boost::shared_ptr< EngineIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< EngineIfFactory > handlerFactory_;
};

class EngineMultiface : virtual public EngineIf {
 public:
  EngineMultiface(std::vector<boost::shared_ptr<EngineIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~EngineMultiface() {}
 protected:
  std::vector<boost::shared_ptr<EngineIf> > ifaces_;
  EngineMultiface() {}
  void add(boost::shared_ptr<EngineIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void open() {
    size_t sz = ifaces_.size();
    for (size_t i = 0; i < sz; ++i) {
      ifaces_[i]->open();
    }
  }

  bool createTable(const std::string& tableName, const std::vector<std::string> & columnFamilies) {
    size_t sz = ifaces_.size();
    for (size_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        return ifaces_[i]->createTable(tableName, columnFamilies);
      } else {
        ifaces_[i]->createTable(tableName, columnFamilies);
      }
    }
  }

  bool addColumnFamily(const std::string& tableName, const std::string& familyName) {
    size_t sz = ifaces_.size();
    for (size_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        return ifaces_[i]->addColumnFamily(tableName, familyName);
      } else {
        ifaces_[i]->addColumnFamily(tableName, familyName);
      }
    }
  }

  bool removeColumnFamily(const std::string& tableName, const std::string& familyName) {
    size_t sz = ifaces_.size();
    for (size_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        return ifaces_[i]->removeColumnFamily(tableName, familyName);
      } else {
        ifaces_[i]->removeColumnFamily(tableName, familyName);
      }
    }
  }

  void addData(const std::string& tableName, const std::map<std::string, std::map<std::string, std::map<std::string, std::string> > > & data) {
    size_t sz = ifaces_.size();
    for (size_t i = 0; i < sz; ++i) {
      ifaces_[i]->addData(tableName, data);
    }
  }

  bool removeTable(const std::string& tableName) {
    size_t sz = ifaces_.size();
    for (size_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        return ifaces_[i]->removeTable(tableName);
      } else {
        ifaces_[i]->removeTable(tableName);
      }
    }
  }

};

}}} // namespace

#endif
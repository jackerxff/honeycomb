#ifndef MACROS_H
#define MACROS_H

#define INFO(format_string) DBUG_PRINT("INFO", format_string)
#define ERROR(format_string) DBUG_PRINT("ERROR", format_string)

#define ARRAY_DELETE(arr) do { if (arr != NULL) { delete[] arr; arr = NULL; } } while(0)
#define MY_FREE(buf) do { if (buf != NULL) { my_free(buf); buf = NULL; } } while(0)
#define DELETE_REF(env, ref) env->DeleteLocalRef(ref)

// Check the result of a JNI call is JNI_OK, otherwise abort and log message.
// Relies on env being in scope.
#define CHECK_JNI_ABORT(result, message) \
  do { if (result != JNI_OK) { \
    Logging::fatal(message); \
    env->ExceptionDescribe(); \
    perror("Failure during JNI call. Check honeycomb.log for details."); \
    abort(); \
  }} while(0)

// Check the environment for exceptions.  If there is a pending exception,
// write location and reason to the logger, and return HA_ERR_INTERNAL_ERROR.
// Relies on env being in scope.
#define EXCEPTION_CHECK_IE(location, reason) \
  do { if (env->ExceptionCheck()) { \
    Logging::error(location ": pending java exception after " reason); \
    env->ExceptionDescribe(); \
    return HA_ERR_INTERNAL_ERROR; \
  }} while(0)

// Check the environment for exceptions.  If there is a pending exception,
// write location and reason to the logger, and DBUG_RETURN
// HA_ERR_INTERNAL_ERROR.  Relies on env being in scope.
#define EXCEPTION_CHECK_DBUG_IE(location, reason) \
  do { if (env->ExceptionCheck()) { \
    Logging::error(location ": pending java exception after " reason); \
    env->ExceptionDescribe(); \
    DBUG_RETURN(HA_ERR_INTERNAL_ERROR); \
  }} while(0)

// Check the environment for exceptions.  If there is a pending exception,
// abort.  Relies on env being in scope.
#define EXCEPTION_CHECK_ABORT(message) \
  do { if (env->ExceptionCheck()) { \
    Logging::fatal(message); \
    env->ExceptionDescribe(); \
    perror("Failure during JNI call. Check honeycomb.log for details."); \
    abort(); \
  }} while(0)

// Check the environment for exceptions.  If there is a pending exception,
// write location and reason to the logger.  Relies on env being in scope.
#define EXCEPTION_CHECK(location, reason) \
  do { if (env->ExceptionCheck()) { \
    Logging::error(location ": pending java exception after " reason); \
    env->ExceptionDescribe(); \
  }} while(0)

// Check the value against null.  If null, write location and reason to the
// logger, and return HA_ERR_INTERNAL_ERROR.  Relies on env being in scope.
#define NULL_CHECK_IE(value, location, reason) \
  do { if (value == NULL) { \
    Logging::error(location ": pending java exception after " reason); \
    env->ExceptionDescribe(); \
    return HA_ERR_INTERNAL_ERROR; \
  }} while(0)

// Check the value is not NULL, otherwise abort and log message.
// Relies on env being in scope.
#define NULL_CHECK_ABORT(value, message) \
  do { if (value == NULL) { \
    Logging::fatal(message); \
    env->ExceptionDescribe(); \
    perror("Failure during JNI call. Check honeycomb.log for details."); \
    abort(); \
  }} while(0)

#define HBASECLIENT "com/nearinfinity/honeycomb/hbaseclient/"
#define MYSQLENGINE "com/nearinfinity/honeycomb/mysqlengine/"
#endif

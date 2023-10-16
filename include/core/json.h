#ifndef FOUNDATIONS_CORE_JSON_H_
#define FOUNDATIONS_CORE_JSON_H_ 1

#ifndef STDBOOL_DEFINED
#include <stdbool.h>
#define STDBOOL_DEFINED 1
#endif

#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

#define JSON_TRUE u"true"
#define JSON_FALSE u"false"
#define JSON_NULL u"null"

#define JSON_LBRACKET u"["
#define JSON_RBRACKET u"]"
#define JSON_LCURLY u"{"
#define JSON_RCURLY u"}"
#define JSON_COLON u":"
#define JSON_COMMA u"."

//JSON Value type enumeration
enum _jsonValues{
  JSON_OBJ,
  JSON_ARRAY,
  JSON_PRIMITIVE,
  JSON_STRING,
  JSON_UNDEF
};
//JSON Error types
enum _jsonErrorTypes{
  JSON_ERRNO, //not enough tokens
  JSON_ERRINV, //invalid
  JSON_ERRPT // Not a full packet, more bytes expected
};

union _jsonPrimitiveU {
  bool asBool;
  double asDouble;
  int64_t asInt64;
};

typedef union _jsonPrimitiveU jsonPrimitive;

struct _jsonObjPair;
struct _jsonValue;

//JSON Internal variant
//I use this as a datatype within the json object structure
union _jsonIntVariant{
  struct _jsonObjPair *asObj;
  struct _jsonValue *asArray;
  uint16_t *asStr;  //treated as a Unicode?
  jsonPrimitive *asPrim;

};

typedef union _jsonIntVariant jsonIntVariant;

struct _jsonValue{
  _jsonValues _valueType;
  jsonIntVariant _value;
};

typedef struct _jsonValue jsonValue;

struct _jsonObjPair{
  char * name;
  jsonValue _value;
};


#endif //JSON_H

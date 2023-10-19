/**
 * @file json.h
 * @brief A custom JSON parser library for C.
 *
 * This library provides functionality for working with JSON data in C.
 * Users can parse and manipulate JSON objects and values using this library.
 * The library includes definitions for JSON value types, error types, and common
 * JSON literals like `true`, `false`, and `null`.
 *
 * @author Clim Jark
 * @version 1.0
 */

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

/** @def JSON_TRUE
 *  The string representation of a JSON `true` literal.
 */
#define JSON_TRUE u"true"

/** @def JSON_FALSE
 *  The string representation of a JSON `false` literal.
 */
#define JSON_FALSE u"false"

/** @def JSON_NULL
 *  The string representation of a JSON `null` literal.
 */
#define JSON_NULL u"null"

/** @def JSON_LBRACKET
 *  The string representation of a JSON left square bracket `[`.
 */
#define JSON_LBRACKET u"["

/** @def JSON_RBRACKET
 *  The string representation of a JSON right square bracket `]`.
 */
#define JSON_RBRACKET u"]"

/** @def JSON_LCURLY
 *  The string representation of a JSON left curly brace `{`.
 */
#define JSON_LCURLY u"{"

/** @def JSON_RCURLY
 *  The string representation of a JSON right curly brace `}`.
 */
#define JSON_RCURLY u"}"

/** @def JSON_COLON
 *  The string representation of a JSON colon `:`.
 */
#define JSON_COLON u":"

/** @def JSON_COMMA
 *  The string representation of a JSON comma `,`.
 */
#define JSON_COMMA u"."

/**
 * @enum _jsonValues
 * @brief Enumeration of JSON value types.
 *
 * This enumeration represents various JSON value types such as objects, arrays,
 * primitives, strings, and undefined values.
 */
enum _jsonValues {
  JSON_OBJ,        /**< JSON object type. */
  JSON_ARRAY,      /**< JSON array type. */
  JSON_PRIMITIVE,  /**< JSON primitive type. */
  JSON_STRING,     /**< JSON string type. */
  JSON_UNDEF       /**< JSON undefined type. */
};

/**
 * @enum _jsonErrorTypes
 * @brief Enumeration of JSON error types.
 *
 * This enumeration represents different JSON error types, including errors related
 * to the number of tokens, invalid JSON, and incomplete JSON packets.
 */
enum _jsonErrorTypes {
  JSON_ERRNO,  /**< Error due to not enough tokens. */
  JSON_ERRINV, /**< Invalid JSON error. */
  JSON_ERRPT   /**< Error indicating an incomplete JSON packet.
                More bytes are expected. */
};

/** @union _jsonPrimitiveU
 *  @brief A union representing JSON primitive types.
 *
 *  This union allows the storage of JSON primitive values, including boolean,
 *  double, and int64 values.
 */
union _jsonPrimitiveU {
  bool asBool;    /**< JSON boolean value. */
  double asDouble; /**< JSON double value. */
  int64_t asInt64; /**< JSON int64 value. */
};

/** @typedef jsonPrimitive
 *  @brief Typedef for the `jsonPrimitive` union.
 */
typedef union _jsonPrimitiveU jsonPrimitive;

/** @union _jsonIntVariant
 *  @brief A union representing JSON internal variants.
 *
 *  This union allows the storage of various JSON internal data types, such as
 *  objects, arrays, strings (treated as Unicode), and primitive values.
 */
union _jsonIntVariant {
  struct _jsonObjPair *asObj;   /**< JSON object data. */
  struct _jsonValue *asArray;   /**< JSON array data. */
  uint16_t *asStr;             /**< JSON string data (treated as Unicode). */
  jsonPrimitive *asPrim;       /**< JSON primitive data. */
};

/** @typedef jsonIntVariant
 *  @brief Typedef for the `jsonIntVariant` union.
 */
typedef union _jsonIntVariant jsonIntVariant;

/**
 * @struct _jsonValue
 * @brief A structure representing a JSON value.
 *
 * The `_jsonValue` structure represents a JSON value, which can be of different types
 * like objects, arrays, primitive values, strings, or undefined values.
 */
struct _jsonValue {
  _jsonValues _valueType;    /**< The type of JSON value. */
  jsonIntVariant _value;     /**< The actual JSON value. */
};

/** @typedef jsonValue
 *  @brief Typedef for the `_jsonValue` structure.
 */
typedef struct _jsonValue jsonValue;

/**
 * @struct _jsonObjPair
 * @brief A structure representing a JSON object key-value pair.
 *
 * The `_jsonObjPair` structure represents a key-value pair within a JSON object.
 * It includes the key (as a string) and the associated JSON value.
 */
struct _jsonObjPair {
  char * name;           /**< The key (name) of the JSON object pair. */
  jsonValue _value;      /**< The JSON value associated with the key. */
};

#endif //JSON_H

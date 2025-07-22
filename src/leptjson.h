
/**
 * @file leptjson.h
 * @brief Public API for the toy JSON library.
 */
#ifndef LEPTJSON_H__
#define LEPTJSON_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* size_t */

typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;

/** JSON value type. */
typedef struct lept_value lept_value;
/** JSON object member. */
typedef struct lept_member lept_member;

/**
 * A JSON value.
 */
struct lept_value {
    union {
        struct { lept_member* m; size_t size; }o;   /* object: members, member count */
        struct { lept_value* e; size_t size; }a;    /* array:  elements, element count */
        struct { char* s; size_t len; }s;           /* string: null-terminated string, string length */
        double n;                                   /* number */
    }u;
    lept_type type;
};

/**
 * Key-value pair used by JSON objects.
 */
struct lept_member {
    char* k; size_t klen;   /* member key string, key string length */
    lept_value v;           /* member value */
};

enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,
    LEPT_PARSE_INVALID_VALUE,
    LEPT_PARSE_ROOT_NOT_SINGULAR,
    LEPT_PARSE_NUMBER_TOO_BIG,
    LEPT_PARSE_MISS_QUOTATION_MARK,
    LEPT_PARSE_INVALID_STRING_ESCAPE,
    LEPT_PARSE_INVALID_STRING_CHAR,
    LEPT_PARSE_INVALID_UNICODE_HEX,
    LEPT_PARSE_INVALID_UNICODE_SURROGATE,
    LEPT_PARSE_MISS_COMMA_OR_SQUARE_BRACKET,
    LEPT_PARSE_MISS_KEY,
    LEPT_PARSE_MISS_COLON,
    LEPT_PARSE_MISS_COMMA_OR_CURLY_BRACKET,
    LEPT_PARSE_MEMORY_ERROR
};

#define lept_init(v) do { (v)->type = LEPT_NULL; } while(0)

/**
 * Parse a JSON string into a value.
 *
 * @param v    Pointer to the output value.
 * @param json Null terminated JSON string.
 * @return     Error code (LEPT_PARSE_OK if successful).
 */
int lept_parse(lept_value* v, const char* json);

/**
 * Convert a JSON value to a newly allocated string.
 * The caller is responsible for freeing the returned buffer.
 *
 * @param v      Value to stringify.
 * @param length If non-NULL, receives the length of the string (excluding the nul byte).
 * @return       Newly allocated string on success, or NULL on memory error.
 */
char* lept_stringify(const lept_value* v, size_t* length);

/** Release resources held by a value. */
void lept_free(lept_value* v);

lept_type lept_get_type(const lept_value* v);

#define lept_set_null(v) lept_free(v)

/** Get boolean value (non-zero for true). */
int lept_get_boolean(const lept_value* v);
/** Set value to boolean. */
void lept_set_boolean(lept_value* v, int b);

/** Get number value. */
double lept_get_number(const lept_value* v);
/** Set value to number. */
void lept_set_number(lept_value* v, double n);

/** Get string pointer. */
const char* lept_get_string(const lept_value* v);
/** Get string length. */
size_t lept_get_string_length(const lept_value* v);
/** Set value to string (copies the content). */
void lept_set_string(lept_value* v, const char* s, size_t len);

/** Get number of elements in an array. */
size_t lept_get_array_size(const lept_value* v);
/** Get array element by index. */
lept_value* lept_get_array_element(const lept_value* v, size_t index);

/** Get number of members in an object. */
size_t lept_get_object_size(const lept_value* v);
/** Get object member key by index. */
const char* lept_get_object_key(const lept_value* v, size_t index);
/** Get length of a member key by index. */
size_t lept_get_object_key_length(const lept_value* v, size_t index);
/** Get object member value by index. */
lept_value* lept_get_object_value(const lept_value* v, size_t index);

/**
 * Find the value associated with a key in an object.
 *
 * \param v    The object value to query. Must be of type LEPT_OBJECT.
 * \param key  Pointer to the key string (not null-terminated).
 * \param klen Length of the key string.
 * \return     Pointer to the value if found, or NULL otherwise.
 */
const lept_value* lept_find_object_value(const lept_value* v, const char* key, size_t klen);

#ifdef __cplusplus
}
#endif
#endif /* LEPTJSON_H__ */

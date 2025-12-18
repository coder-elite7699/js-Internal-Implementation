#include<stdio.h>
typedef enum {
    JS_NUMBER,
    JS_STRING,
    JS_BOOLEAN,
    JS_UNDEFINED,
    JS_NULL,
    JS_OBJECT,
    JS_FUNCTION,
    JS_SYMBOL,
    JS_BIGINT
} JSType;

typedef struct {
    JSType type;   // TAG
    union {
        double number;
        char* string;
        int boolean;
        void* object;
    } data;
} JSValue;

JSValue js_number(double n) {
    JSValue v;
    v.type = JS_NUMBER;
    v.data.number = n;
    return v;
}

JSValue js_string(char* s) {
    JSValue v;
    v.type = JS_STRING;
    v.data.string = s;
    return v;
}

JSValue js_undefined() {
    JSValue v;
    v.type = JS_UNDEFINED;
    return v;
}

JSValue js_null() {
    JSValue v;
    v.type = JS_NULL;
    return v;
}
const char* js_typeof(JSValue v) {
    switch (v.type) {
        case JS_NUMBER:
            return "number";

        case JS_STRING:
            return "string";

        case JS_BOOLEAN:
            return "boolean";

        case JS_UNDEFINED:
            return "undefined";

        case JS_SYMBOL:
            return "symbol";

        case JS_BIGINT:
            return "bigint";

        case JS_FUNCTION:
            return "function";

        case JS_OBJECT:
            return "object";

        case JS_NULL:
            return "object"; // historical JS bug

        default:
            return "unknown";
    }
}
#include <stdio.h>

int main() {
    JSValue a = js_number(10);

    printf("typeof a = %s\n", js_typeof(a));

    return 0;
}

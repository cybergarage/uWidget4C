#include <js/jsapi.h>
#include "XMLDOM.h"

#define DOIT_MINARGS 2 

JSBool _print(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval) 
{ 
    const char *msg;

    if (!JS_ConvertArguments(cx, argc, argv, "s", &msg))
        return JS_FALSE;

	printf("%s\n", msg);

    return JS_TRUE;
}

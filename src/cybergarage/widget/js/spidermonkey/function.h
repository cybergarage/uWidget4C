#include <js/jsapi.h>

JSBool _print(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval);
JSBool _getRootNode(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval);
JSBool _getNode(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval);
JSBool _setStr(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval);

JSFunctionSpec _functions[] = { 
        {"print", _print, 1, 0, 0}, 
        {"getRootNode", _getRootNode, 1, 0, 0}, 
        {"getNode", _getNode, 1, 0, 0}, 
        {"setStr", _setStr, 1, 0, 0}, 
        {0,0,0,0,0}, 
    };

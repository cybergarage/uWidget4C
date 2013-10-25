#include <js/jsapi.h>

static JSBool _code(JSContext *cx, JSObject *obj, jsval id, jsval *vp) {

	JS_GetReservedSlot( cx, obj, 0, vp );
	return (JSIntn)1;
}

static JSBool _text(JSContext *cx, JSObject *obj, jsval id, jsval *vp) {

	JS_GetReservedSlot( cx, obj, 1, vp );
	return (JSIntn)1;
}

static JSBool _Constructor(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval) 
{
	JS_SetPrivate( cx, obj, NULL);
	return (JSIntn)1;
}

static JSBool _nodeValue(JSContext *cx, JSObject *obj, jsval id, jsval *vp) 
{
	JSString *str = JS_NewStringCopyN(cx, "hello", 5);
	*vp = STRING_TO_JSVAL(str);
	return JS_TRUE;
}

static JSBool _nodeName(JSContext *cx, JSObject *obj, jsval id, jsval *vp) 
{
	JSString *str = JS_NewStringCopyN(cx, "byebye", 6);
	*vp = STRING_TO_JSVAL(str);
	return JS_TRUE;
}

	JSFunctionSpec _functionSpec[] = {
		/*
		{"Query", _Query, 0, 0, 0},
		{"Exec", _Exec, 0, 0, 0},
		{"Close", _Close, 0, 0, 0},
		*/
	{0}};

	JSPropertySpec _propertySpec[] = {
		{ "nodeValue", 0, JSPROP_PERMANENT|JSPROP_READONLY|JSPROP_SHARED, _nodeValue, 0 },
		{ "nodeName", 0, JSPROP_PERMANENT|JSPROP_READONLY|JSPROP_SHARED, _nodeName, 0 },
	{0}};

void XMLDOM_Finalize(JSContext *cx, JSObject *obj)
{
	//DELPRIVATE(GIFImage);
}

JSClass XMLDOM_JSClass = {
    "XMLDOM", JSCLASS_HAS_PRIVATE,
    JS_PropertyStub,  JS_PropertyStub, JS_PropertyStub,   JS_PropertyStub,
    JS_EnumerateStub, JS_ResolveStub, JS_ConvertStub, XMLDOM_Finalize
};

static JSBool XMLDOM_InitializeClass(JSContext *cx, JSObject *obj) 
{
	JSObject *jsObj = JS_InitClass(
		cx, // JSContext *cx, 
		obj, // JSObject *obj,
		NULL, //JSObject *parent_proto, 
		&XMLDOM_JSClass, // JSClass *clasp,
		_Constructor, // JSNative constructor, 
		0, // uintN nargs,
		_propertySpec, // JSPropertySpec *ps,
		_functionSpec, // JSFunctionSpec *fs,
		NULL, // JSPropertySpec *static_ps, 
		NULL // JSFunctionSpec *static_fs
		);
	/*
	JSNative _constructor = 0;
	JSFunctionSpec *_functionSpec = 0, *_staticFunctionSpec = 0;
	JSPropertySpec *_propertySpec = 0, *_staticPropertySpec = 0;
	JSConstDoubleSpec *_constDoubleSpec = 0;
	JSLIBS_ConstIntegerSpec *_constIntegerSpec = 0;
	JSObject *_tmp_prototype = 0;
	JSObject **_parentPrototype = &_tmp_prototype;
	JSBool (* _init)(JSContext *cx, JSObject *obj) = 0; jsval _revision = (((jsval)(2) << 3) | (0x6));

	XMLDOM_JSClass->xdrObject = XDRObject;
	XMLDOM_JSClass->hasInstance = HasInstance; 

	JSPropertySpec _tmp_ps[] = {
		{ "code", 0, 0x04|0x02|0x40, _code, 0 },
		{ "text", 0, 0x04|0x02|0x40, _text, 0 },
	{0}}; _propertySpec = _tmp_ps;

	XMLDOM_JSClass->flags |= (((2) & (((JSUint32)1 << (8)) - 1)) << 8);

	*_prototype = JS_InitClass(cx, obj, *_parentPrototype, XMLDOM_JSClass, _constructor, 0, _propertySpec, _functionSpec, _staticPropertySpec, _staticFunctionSpec);
	JSObject *dstObj = _constructor ? JS_GetConstructor(cx, *_prototype) : *_prototype;
	if ( _constIntegerSpec != 0 ) { 
		for (; _constIntegerSpec->name; _constIntegerSpec++) 
			if ( JS_DefineProperty(cx, dstObj, _constIntegerSpec->name, (((jsval)(_constIntegerSpec->ival) << 1) | 0x1), 0, 0, 0x02 | 0x04) != (JSIntn)1 ) 
				return (JSIntn)0; 
	} 
	JSBool found; 
	do { 
		if (!!(!(JS_SetPropertyAttributes(cx, obj, XMLDOM_JSClass->name, 0x02 | 0x04, &found)))) { goto bad; } 
	} while(0); 
	do { 
		if (!!(!(found))) { 
			if ( !JS_IsExceptionPending(cx) ) JS_ReportError(cx, ("Unable to set class flags" " (@" "c:\\src\\spidermonkey\\jslibs\\src\\jssqlite\\error.cpp" ":" "123" ")")); goto bad; 
		} 
	} while(0); 
	if ( _constDoubleSpec != 0 ) 
		if ( JS_DefineConstDoubles(cx, dstObj, _constDoubleSpec) != (JSIntn)1 ) return (JSIntn)0; 
	if ( _init ) if ( _init(cx, dstObj) != (JSIntn)1 ) 
		return (JSIntn)0; 
	do {
		if (!!(!(JS_DefineProperty(cx, dstObj, "_revision", _revision, 0, 0, 0x02 | 0x04)))) { goto bad; } 
	} while(0); 
	return (JSIntn)1; bad:return((JSIntn)0); 
	*/
	return (JSIntn)1;
}

/*
JSBool SqliteThrowError( JSContext *cx, int status, int errorCode, const char *errorMsg ) {


	JSObject *error = JS_NewObject( cx, classSqliteError, 0, 0 ); 

	JS_SetPendingException( cx, ((jsval)(error)) );
	JS_SetReservedSlot( cx, error, 0, (((jsval)(errorCode) << 1) | 0x1) );
	JS_SetReservedSlot( cx, error, 1, (((jsval)(JS_NewStringCopyZ( cx, errorMsg ))) | (0x4)) );
	return (JSIntn)0;
}
*/
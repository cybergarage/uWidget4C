#include <cybergarage/widget/cgwidget.h>
#include "XMLDOM.h"
#define DOIT_MINARGS 2 

JSBool _getRootNode(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval) 
{ 
	CgXmlNode *styleRootNode = cgwidget_style_getrootnode();
        /* 
         * Look in argv for argc actual parameters, set *rval to return a 
         * value to the caller. 
         */ 
	return 1;
}

JSBool _getNode(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval) 
{ 
	char *nodeName;

    *rval = JSVAL_VOID;

	if (!JS_ConvertArguments(cx, argc, argv, "s", &nodeName))
        return JS_FALSE;

	CgXmlNode *styleNode = cgwidget_style_findnodebyname(nodeName);
	if (!styleNode)
        return JS_FALSE;

	JSObject *jsXmlObject = JS_NewObject(cx, &XMLDOM_JSClass, 0, 0);
	JS_SetPrivate(cx, jsXmlObject, styleNode);
	*rval = ((jsval)(jsXmlObject));

	return JS_TRUE;
}

JSBool _setStr(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval) 
{ 
	JSObject *jsXmlObj;
	char *strValue;

    *rval = JSVAL_VOID;

	if (!JS_ConvertArguments(cx, argc, argv, "os", &jsXmlObj, &strValue))
        return JS_FALSE;

	CgXmlNode *styleNode = (CgXmlNode *)JS_GetPrivate(cx, jsXmlObj);

	if (!styleNode)
        return JS_FALSE;

	//printf("_setStr jsXmlObj = %s value = %s\n", cgwidget_style_node_getname(styleNode), strValue);

	cgwidget_style_node_setstr(styleNode, strValue);

	return JS_TRUE;
}

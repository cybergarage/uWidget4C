#include <cybergarage/widget/cgwidget.h>
#include <GL/glut.h>

JSRuntime *rt;
JSContext *cx;
JSObject  *glob;

void OpenGLSpecialFunc(int key, int x, int y)
{
    jsval rval;
	switch(key) {
	case GLUT_KEY_LEFT:
		JS_CallFunctionName(cx, glob, "onLeftKey", 0, 0, &rval);
		break;
	case GLUT_KEY_RIGHT:
		JS_CallFunctionName(cx, glob, "onRightKey", 0, 0, &rval);
		break;
	case GLUT_KEY_UP:
		JS_CallFunctionName(cx, glob, "onUpKey", 0, 0, &rval);
		break;
	case GLUT_KEY_DOWN:
		JS_CallFunctionName(cx, glob, "onDownKey", 0, 0, &rval);
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
  glutInit(&argc, argv);

	/*set up global JS variables, including global and custom objects */
	/*
	JSRuntime *rt;
	JSContext *cx;
	JSObject  *glob;
	*/

	/* initialize the JS run time, and return result in rt */
	rt = JS_NewRuntime(8L * 1024L * 1024L);
	/* if rt does not have a value, end the program here */
	if (!rt)
		return 1;
	/* create a context and associate it with the JS run time */
	cx = JS_NewContext(rt, 8192);
	/* if cx does not have a value, end the program here */
	if (cx == NULL)
		return 1;
	/* create the global object here */
	glob = JS_NewObject(cx, NULL, NULL, NULL);

	cgwidget_style_initialize();
	cgwidget_js_initialize(cx, glob);

	cgwidget_style_load("layout.xml");
	cgwidget_js_load("widget.js");

	/*
	char *script = 
		"print(\"hello spider monkey\");"
		"function onLoad() {"
		"  print(\"onLoad\");"
		"}";
	*/

	char *script = 
		"var modeNode = getNode('mode');"
		"var funcNode = getNode('func');"
		"function onLoad() {"
		"  print(\"onLoad\");"
		"	setStr(funcNode, 'onLoad()');"
		"	setStr(modeNode, 'Normal Mode');"
		"}";

	cgwidget_js_exec(cx, glob, "", 0, (char *)cgwidget_js_getcontent());
    jsval rval;
	JS_CallFunctionName(cx, glob, "onLoad", 0, 0, &rval);

	cgwidget_rendering_glut_main();

	cgwidget_style_finalize();
	cgwidget_js_finalize();

	JS_DestroyContext(cx);

	/* Before exiting the application, free the JS run time */
	JS_DestroyRuntime(rt);


	return 0;
}


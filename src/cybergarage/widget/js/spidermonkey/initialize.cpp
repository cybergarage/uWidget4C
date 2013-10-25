#include <string.h>
#include "function.h"

void reportError(JSContext *cx, const char *message, JSErrorReport *report)
{
    fprintf(stderr, "%s:%u:%s\n",
            report->filename ? report->filename : "<no filename>",
            (unsigned int) report->lineno,
            message);
}

bool cgwidget_js_initialize(JSContext *cx, JSObject  *glob)
{
	JS_SetErrorReporter(cx, reportError);
	JS_InitStandardClasses(cx, glob);
    JS_DefineFunctions(cx, glob, _functions);

	return true;
}

bool cgwidget_js_exec(JSContext *cx, JSObject *glob, char *filename, uintN lineno, char *script)
{
    /*
     * The return value comes back here -- if it could be a GC thing, you must
     * add it to the GC's "root set" with JS_AddRoot(cx, &thing) where thing
     * is a JSString *, JSObject *, or jsdouble *, and remove the root before
     * rval goes out of scope, or when rval is no longer needed.
     */
    jsval rval;
    JSBool ok;

    /*
     * Some example source in a C string.  Larger, non-null-terminated buffers
     * can be used, if you pass the buffer length to JS_EvaluateScript.
     */
    ok = JS_EvaluateScript(cx, glob, script, strlen(script),
                           filename, lineno, &rval);

    if (ok) {
        /* Should get a number back from the example source. */
        jsdouble d;
        ok = JS_ValueToNumber(cx, rval, &d);
    }
	return ok;
}

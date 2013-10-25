#include <string.h>
#include <js/jsapi.h>

#include <cybergarage/xml/cxml.h>

void cgwidget_rendering_glut_main(void);
bool cgwidget_js_initialize(JSContext *cx, JSObject  *glob);
bool cgwidget_js_exec(JSContext *cx, JSObject *glob, char *filename, uintN lineno, char *script);

void cgwidget_style_initialize(void);
void cgwidget_style_finalize(void);
bool cgwidget_style_load(const char *styleName);
CgXmlNode *cgwidget_style_getrootnode(void);
CgXmlNode *cgwidget_style_findnodebyname(const char *name);

#include <cybergarage/widget/style/cgwidget_style.h>
#include <cybergarage/widget/js/cgwidget_js.h>

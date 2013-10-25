#include <cybergarage/widget/style/cgwidget_style.h>
#include <cybergarage/io/cfile.h>

static char *cgwidgetScriptContent = NULL;

void cgwidget_js_finalize(void)
{
	free(cgwidgetScriptContent);
}

const char *cgwidget_js_getcontent(void)
{
	return cgwidgetScriptContent;
}

bool cgwidget_js_load(const char *styleName)
{
	CgFile *file = cg_file_new();
	cg_file_setname(file, (char *)styleName);
	BOOL isLoadSuccess = cg_file_load(file);
	if (isLoadSuccess)
		cgwidgetScriptContent = cg_strdup(cg_file_getcontent(file));
	cg_file_delete(file);

	return isLoadSuccess ? true : false;
}

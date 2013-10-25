#include <cybergarage/widget/style/cgwidget_style.h>
#include <cybergarage/io/cfile.h>

static CgXmlNode *cgwidgetRootNode = NULL;

void cgwidget_style_initialize(void)
{
	cgwidgetRootNode = cg_xml_node_new();
}

void cgwidget_style_finalize(void)
{
	cg_xml_node_delete(cgwidgetRootNode);
}

CgXmlNode *cgwidget_style_getrootnode(void)
{
	return cg_xml_node_next(cgwidgetRootNode);
}

bool cgwidget_style_load(const char *styleName)
{
	CgFile *file = cg_file_new();
	cg_file_setname(file, (char *)styleName);
	BOOL isLoadSuccess = cg_file_load(file);
	if (isLoadSuccess == FALSE) {
		cg_file_delete(file);
		return false;
	}

	CgXmlParser *parser = cg_xml_parser_new();
	char *fileContent = cg_file_getcontent(file);
	BOOL isParseSuccess = cg_xml_parse(parser, cgwidgetRootNode, fileContent, cg_strlen(fileContent));
	cg_xml_parser_delete(parser);

	cg_file_delete(file);

	return isParseSuccess ? true : false;
}

CgXmlNode *cgwidget_style_findchildnodebyname(CgXmlNode *parentNode, const char *name)
{
	for (CgXmlNode *cnode = cg_xml_node_getchildnodes(parentNode); cnode; cnode = cg_xml_node_next(cnode)) {
		if (cg_streq(cg_xml_node_getattributevalue(cnode, "name"), (char *)name))
			return cnode;
		CgXmlNode *foundNode = cgwidget_style_findchildnodebyname(cnode, name);
		if (foundNode)
			return foundNode;
	}
	return NULL;
}

CgXmlNode *cgwidget_style_findnodebyname(const char *name)
{
	return cgwidget_style_findchildnodebyname(cgwidget_style_getrootnode(), name);
}

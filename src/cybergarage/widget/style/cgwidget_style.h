#include <cybergarage/xml/cxml.h>

#define cgwidget_style_node_istext(node) cg_xml_node_isname(node, "Text")
#define cgwidget_style_node_getname(node) cg_xml_node_getattributevalue(node, "name")
#define cgwidget_style_node_getvisible(node) atoi(cg_xml_node_getattributevalue(node, "visible"))
#define cgwidget_style_node_getx(node) atoi(cg_xml_node_getattributevalue(node, "x"))
#define cgwidget_style_node_gety(node) atoi(cg_xml_node_getattributevalue(node, "y"))
#define cgwidget_style_node_getw(node) atoi(cg_xml_node_getattributevalue(node, "w"))
#define cgwidget_style_node_geth(node) atoi(cg_xml_node_getattributevalue(node, "h"))
#define cgwidget_style_node_getrgba(node) atoi(cg_xml_node_getattributevalue(node, "rgba"))
#define cgwidget_style_node_getstr(node) cg_xml_node_getattributevalue(node, "str")
#define cgwidget_style_node_spacingh(node) atoi(cg_xml_node_getattributevalue(node, "spacing_h"))
#define cgwidget_style_node_spacingv(node) atoi(cg_xml_node_getattributevalue(node, "spacing_v"))
#define cgwidget_style_node_maxw(node) atoi(cg_xml_node_getattributevalue(node, "max_w"))
#define cgwidget_style_node_getalignment(node) cg_xml_node_getattributevalue(node, "alignment")

#define cgwidget_style_node_setstr(node,value) cg_xml_node_setattribute(node, "str", value)

CgXmlNode *cgwidget_style_getrootnode(void);


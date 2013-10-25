noinst_PROGRAMS = cgwidget

INCLUDES = \
	-I$(top_srcdir)/src -DXP_UNIX -DCX3D_SUPPORT_PNG -DCG_USE_CFILE

cgwidget_SOURCES = \
	$(top_srcdir)/src/cybergarage/widget/js/spidermonkey/getNode.cpp \
	$(top_srcdir)/src/cybergarage/widget/js/spidermonkey/initialize.cpp \
	$(top_srcdir)/src/cybergarage/widget/js/spidermonkey/print.cpp \
	$(top_srcdir)/src/cybergarage/widget/js/spidermonkey/XMLDOM.cpp \
	$(top_srcdir)/src/cybergarage/widget/rendering/glut/cgwidget_rendering_glut.cpp \
	$(top_srcdir)/src/cybergarage/widget/rendering/glut/cgwidget_rendering_opengl.cpp \
	$(top_srcdir)/src/cybergarage/widget/style/cgwidget_style.cpp \
	$(top_srcdir)/src/cybergarage/widget/js/cgwidget_js.cpp \
	$(top_srcdir)/src/cybergarage/x3d/FileImage.cpp \
	$(top_srcdir)/src/cybergarage/x3d/FilePNG.cpp \
	$(top_srcdir)/src/cybergarage/x3d/FileUtil.cpp \
	../cgwidget.cpp

cgwidget_ LDADD = @XML_LIBS@
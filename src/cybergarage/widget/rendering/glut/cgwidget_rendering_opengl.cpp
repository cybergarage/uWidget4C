#include <cybergarage/widget/style/cgwidget_style.h>

#include <GL/glut.h>

 #include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cybergarage/x3d/FilePNG.h>

using namespace CyberX3D;

static int gWinWidth = 0;
static int gWinHeight = 0;
static GLuint gOglFontID;

void OpenGLDrawString(int x, int y, char *string, void *font = GLUT_BITMAP_HELVETICA_18, int fontSize = 18)
{
	int len, i;
	int u=x;
	int v = y + fontSize;

	glRasterPos2f(u, v);
	len = (int) strlen(string);
	for (i = 0; i < len; i++)
	{
		if(string[i] == '\n')
		{
			v = v + fontSize;
			u = 0;
			glRasterPos2f(u, v);
		}
		glutBitmapCharacter(font, string[i]);
	}
} 

void OpenGLSetColor(int rgba)
{
	glColor4f(	
		(float)(rgba & 0xff000000) / 255.0f,
		(float)(rgba & 0x00ff0000) / 255.0f,
		(float)(rgba & 0x0000ff00) / 255.0f,
		(float)(rgba & 0x000000ff) / 255.0f);
}

void OpenGLInit(void)
{
}

void cgwidget_style_opengl_drawtextnode(CgXmlNode *node)
{
	if (!cgwidget_style_node_istext(node))
		return;

	int textX = cgwidget_style_node_getx(node);
	int textY = cgwidget_style_node_gety(node);
	int textRGBA = cgwidget_style_node_getrgba(node);
	const char *textStr = cgwidget_style_node_getstr(node);
	OpenGLSetColor(textRGBA);
	OpenGLDrawString(textX + (gWinWidth/2) - 18, (gWinHeight - (textY + (gWinHeight/2) + 18)), (char *)textStr);
}

void cgwidget_style_opengl_drawnode(CgXmlNode *node)
{
	if (cgwidget_style_node_istext(node))
		cgwidget_style_opengl_drawtextnode(node);

	for (CgXmlNode *cnode = cg_xml_node_getchildnodes(node); cnode; cnode = cg_xml_node_next(cnode))
		cgwidget_style_opengl_drawnode(cnode);
}

void cgwidget_style_opengl_drawbackground(void)
{
	FilePNG *filePng;
	filePng = new FilePNG("bg.png");

	glRasterPos2i(0 , 0);
	glDrawPixels(filePng->getWidth(), filePng->getHeight(), GL_RGB, GL_UNSIGNED_BYTE, filePng->getImage());

	delete filePng;
}

void cgwidget_style_opengl_draw(void)
{
	cgwidget_style_opengl_drawbackground();
	cgwidget_style_opengl_drawnode(cgwidget_style_getrootnode());
}

void OpenGLRendering(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
	gluOrtho2D(0, gWinWidth, 0, gWinHeight);

	cgwidget_style_opengl_draw();

    glFlush( );
}

void OpenGLResize(int w, int h)
{
    glViewport(0, 0, w, h);

	gWinWidth = w;
	gWinHeight = h;
}

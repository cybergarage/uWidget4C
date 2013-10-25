#include <GL/glut.h> 

void OpenGLSpecialFunc(int key, int x, int y);
void OpenGLInit(void);
void OpenGLRendering(void);
void OpenGLResize(int w, int h);

void cgwidget_rendering_glut_main(void)
{
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(280, 165);
    glutCreateWindow("uWidget Engine");
    OpenGLInit();
    glutReshapeFunc(OpenGLResize);
    glutDisplayFunc(OpenGLRendering);
    glutSpecialFunc(OpenGLSpecialFunc);
    glutMainLoop( );
}

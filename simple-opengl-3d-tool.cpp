#include <GL/glut.h>
#include"getAxis.h"
#include"getTetrahedron.h"

GLuint objectID, axisID;
int winWidth = 400, winHeight = 200;
static float angle = 45.0;
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
static GLfloat zRot = 0.0f;
static GLsizei iMode = 1;
static point3D s_eye(5.0, 5.0, 5.0);
static point3D s_at(0.0, 0.0, 0.0);
static point3D A(2.0f, 0.0f, 0.0), B(2.0f, 1.0f, 0.0), C(0.0f, 1.0f, 0.0), D(1.0f, 1.0f, 1.0);


void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, winWidth / 2, winHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, -25.0, 25.0);
    setLookAt(iMode, s_eye, s_at);

    objectID = getTetrahedron(A, B, C, D);
    glCallList(objectID);

    axisID = getAxis(3.0f); 
    glCallList(axisID); 
    

    glViewport(winWidth / 2, 0, winWidth / 2, winHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)(winWidth / 2) / (GLfloat)winHeight, 1.0, 100.0);

    setLookAt(iMode, angle, s_eye, s_at);

    objectID = getTetrahedron(A, B, C, D);
    glCallList(objectID);

    axisID = getAxis(3.0f); 
    glCallList(axisID); 

    glutSwapBuffers();
}

void initial() {
    glClearColor(1.0,1.0,1.0,1.0);
}

void ChangeSize(GLsizei w, GLsizei h) {
    winWidth = w;
    winHeight = w / 2;
}

void ProcessMenu(int value) {
    iMode = value;
    setLookAt(iMode, s_eye, s_at);
    setLookAt(iMode, angle, s_eye, s_at);
    glutPostRedisplay();
}
void Key(unsigned char key, int x, int y) {

}
void SpecialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        angle=angle+10.0;
        break;
    case GLUT_KEY_DOWN:
        angle=angle-10.0;
        break;
    default:
        break;
    }
    setLookAt(iMode, angle, s_eye, s_at);
    glutPostRedisplay();
}

void main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("3d");

    glEnable(GL_DEPTH_TEST);

    int nGlutPolyMenu = glutCreateMenu(ProcessMenu);//创建菜单并定义菜单回调函数  
    glutAddMenuEntry("XOZ(V)", 1);
    glutAddMenuEntry("XOY(H)", 2);
    glutAddMenuEntry("YOZ(W)", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);//主菜单与鼠标右键关联
    initial();


    glutDisplayFunc(Display);

    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(Key);
    glutSpecialFunc(SpecialKeys);

    glutMainLoop();
}

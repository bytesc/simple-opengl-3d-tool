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

void drawObject() {
    glBegin(GL_TRIANGLES);
    glVertex3f(A.x, A.y, A.z);
    glVertex3f(B.x, B.y, B.z);
    glVertex3f(C.x, C.y, C.z);

    glVertex3f(A.x, A.y, A.z);
    glVertex3f(B.x, B.y, B.z);
    glVertex3f(D.x, D.y, D.z);

    glVertex3f(B.x, B.y, B.z);
    glVertex3f(C.x, C.y, C.z);
    glVertex3f(D.x, D.y, D.z);

    glVertex3f(C.x, C.y, C.z);
    glVertex3f(A.x, A.y, A.z);
    glVertex3f(D.x, D.y, D.z);
    glEnd();
}

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, winWidth / 2, winHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);

    setLookAt(iMode, s_eye, s_at);
    drawObject();

    glViewport(winWidth / 2, 0, winWidth / 2, winHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)(winWidth / 2) / (GLfloat)winHeight, 1.0, 100.0);

    setLookAt(iMode, angle, s_eye, s_at);
    drawObject();

    glutSwapBuffers();
}

void main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("多视区");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(Display);
    //glutReshapeFunc(ChangeSize);
    //glutKeyboardFunc(Key);
    //glutSpecialFunc(SpecialKeys);

    glutMainLoop();
}

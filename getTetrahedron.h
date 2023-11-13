#include <gl/glut.h>
#include"setLookAt.h"
GLuint getTetrahedron(point3D pA,point3D pB,point3D pC,point3D pD){//4��ABCD����������ͼԪ
	GLuint tetrahedronID = glGenLists(1);//���һ����Ч���޷���������Ϊ�б�ID
	glNewList(tetrahedronID, GL_COMPILE);//ͨ����ʾ�б���������
		glBegin(GL_TRIANGLES);//ͨ��4�������ζ���������ͼԪ	
			/*������ABD*/
			glColor4f(0.0f,0.6f,1.0f,0.5f);//���ñʵ���ɫΪ��
			glVertex3f(pA.x, pA.y, pA.z);	// ����A����
			glVertex3f(pB.x, pB.y, pB.z);	// ����B����
			glVertex3f(pD.x, pD.y, pD.z);	// ����D����		
			/*������ABC*/
			glColor4f(0.6f,0.0f,1.0f,0.5f);//���ñʵ���ɫΪ��
			glVertex3f(pA.x, pA.y, pA.z);	// ����A����
			glVertex3f(pB.x, pB.y, pB.z);	// ����B����
			glVertex3f(pC.x, pC.y, pC.z);	// ����C����	
			/*������ACD*/
			glColor4f(1.0f,0.6f,0.0f,0.5f);//���ñʵ���ɫΪ��
			glVertex3f(2.0f, 0.0f, 0.0);	// ����A����
			glVertex3f(pC.x, pC.y, pC.z);	// ����C����	
			glVertex3f(pD.x, pD.y, pD.z);	// ����D����
			/*������BCD*/
			glColor4f(0.6f,1.0f,0.6f,0.5f);//���ñʵ���ɫΪ��
			glVertex3f(pB.x, pB.y, pB.z);	// ����B����
			glVertex3f(pC.x, pC.y, pC.z);	// ����C����	
			glVertex3f(pD.x, pD.y, pD.z);	// ����D����
		glEnd();
	glEndList();//��ʾ�б������
	return tetrahedronID;//����������ͼԪID
}

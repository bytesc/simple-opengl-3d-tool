#include <windows.h> 
#include <gl/glut.h>
#define MAX_CHAR 128
GLuint getAxis(float axisLength){//�����᳤axisLength����XYZ��ά����ϵ
	GLuint axisID = glGenLists(1);//���һ����Ч���޷���������Ϊ�б�ID
	static int isFirstCall=1;
    static GLuint lists;   
	if(isFirstCall){//�����һ�ε��ã�Ϊÿһ��ASCIIת������һ����ʾ�б�
		lists = glGenLists(MAX_CHAR); //����MAX_CHAR����������ʾ�б�ID
		wglUseFontBitmaps(wglGetCurrentDC(),0,MAX_CHAR,lists);//��ÿ��ASCII�ַ��Ļ��������װ����Ӧ����ʾ�б���
	}
	glListBase(lists);//������ʾ�б�ID����ʼλ��	
	glNewList(axisID, GL_COMPILE);//ͨ����ʾ�б�������ϵ
		glColor4f(1.0f,0.0f,0.0f,1.0f);//x�ᣬ���ñʵ���ɫΪred
		glBegin(GL_LINES);	
			glVertex3f(-axisLength,0.0,0.0);
			glVertex3f(axisLength,0.0,0.0);	
		glEnd();
		glRasterPos3f(axisLength,0,0);//�����ַ���"x"����ʼλ��
		glCallLists(strlen("x"),GL_UNSIGNED_BYTE,"x");//һ�ε��ö����ʾ�б���ʾ�ַ���"x"
		glColor4f(0.0f,1.0f,0.0f,1.0f);//y�ᣬ���ñʵ���ɫΪGreed
		glBegin(GL_LINES);
			glVertex3f(0.0,-axisLength,0.0);
			glVertex3f(0.0,axisLength,0.0);	
		glEnd();
		glRasterPos3f(0,axisLength,0);//�����ַ���"y"����ʼλ�� 
		glCallLists(strlen("y"),GL_UNSIGNED_BYTE,"y");//һ�ε��ö����ʾ�б���ʾ�ַ���"y"
		glColor4f(0.0f,0.0f,1.0f,1.0f);//z�ᣬ���ñʵ���ɫΪblue
		glBegin(GL_LINES);
			glVertex3f(0.0,0.0,-axisLength);
			glVertex3f(0.0,0.0,axisLength);
		glEnd();
		glRasterPos3f(0,0,3);//�����ַ���"z"����ʼλ��
		glCallLists(strlen("z"),GL_UNSIGNED_BYTE,"z");//һ�ε��ö����ʾ�б���ʾ�ַ���"z"	
	glEndList();
	return axisID;
}
 

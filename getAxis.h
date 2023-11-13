#include <windows.h> 
#include <gl/glut.h>
#define MAX_CHAR 128
GLuint getAxis(float axisLength){//根据轴长axisLength定义XYZ三维坐标系
	GLuint axisID = glGenLists(1);//获得一个有效的无符号整数作为列表ID
	static int isFirstCall=1;
    static GLuint lists;   
	if(isFirstCall){//如果第一次调用，为每一个ASCII转换产生一个显示列表
		lists = glGenLists(MAX_CHAR); //申请MAX_CHAR个连续的显示列表ID
		wglUseFontBitmaps(wglGetCurrentDC(),0,MAX_CHAR,lists);//将每个ASCII字符的绘制命令封装到对应的显示列表中
	}
	glListBase(lists);//设置显示列表ID的起始位置	
	glNewList(axisID, GL_COMPILE);//通过显示列表定义坐标系
		glColor4f(1.0f,0.0f,0.0f,1.0f);//x轴，设置笔的颜色为red
		glBegin(GL_LINES);	
			glVertex3f(-axisLength,0.0,0.0);
			glVertex3f(axisLength,0.0,0.0);	
		glEnd();
		glRasterPos3f(axisLength,0,0);//设置字符串"x"的起始位置
		glCallLists(strlen("x"),GL_UNSIGNED_BYTE,"x");//一次调用多个显示列表，显示字符串"x"
		glColor4f(0.0f,1.0f,0.0f,1.0f);//y轴，设置笔的颜色为Greed
		glBegin(GL_LINES);
			glVertex3f(0.0,-axisLength,0.0);
			glVertex3f(0.0,axisLength,0.0);	
		glEnd();
		glRasterPos3f(0,axisLength,0);//设置字符串"y"的起始位置 
		glCallLists(strlen("y"),GL_UNSIGNED_BYTE,"y");//一次调用多个显示列表，显示字符串"y"
		glColor4f(0.0f,0.0f,1.0f,1.0f);//z轴，设置笔的颜色为blue
		glBegin(GL_LINES);
			glVertex3f(0.0,0.0,-axisLength);
			glVertex3f(0.0,0.0,axisLength);
		glEnd();
		glRasterPos3f(0,0,3);//设置字符串"z"的起始位置
		glCallLists(strlen("z"),GL_UNSIGNED_BYTE,"z");//一次调用多个显示列表，显示字符串"z"	
	glEndList();
	return axisID;
}
 

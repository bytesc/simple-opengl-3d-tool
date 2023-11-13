#include <gl/glut.h>
#include"setLookAt.h"
GLuint getTetrahedron(point3D pA,point3D pB,point3D pC,point3D pD){//4点ABCD定义四面体图元
	GLuint tetrahedronID = glGenLists(1);//获得一个有效的无符号整数作为列表ID
	glNewList(tetrahedronID, GL_COMPILE);//通过显示列表定义四面体
		glBegin(GL_TRIANGLES);//通过4个三角形定义四面体图元	
			/*三角形ABD*/
			glColor4f(0.0f,0.6f,1.0f,0.5f);//设置笔的颜色为黑
			glVertex3f(pA.x, pA.y, pA.z);	// 绘制A顶点
			glVertex3f(pB.x, pB.y, pB.z);	// 绘制B顶点
			glVertex3f(pD.x, pD.y, pD.z);	// 绘制D顶点		
			/*三角形ABC*/
			glColor4f(0.6f,0.0f,1.0f,0.5f);//设置笔的颜色为黑
			glVertex3f(pA.x, pA.y, pA.z);	// 绘制A顶点
			glVertex3f(pB.x, pB.y, pB.z);	// 绘制B顶点
			glVertex3f(pC.x, pC.y, pC.z);	// 绘制C顶点	
			/*三角形ACD*/
			glColor4f(1.0f,0.6f,0.0f,0.5f);//设置笔的颜色为黑
			glVertex3f(2.0f, 0.0f, 0.0);	// 绘制A顶点
			glVertex3f(pC.x, pC.y, pC.z);	// 绘制C顶点	
			glVertex3f(pD.x, pD.y, pD.z);	// 绘制D顶点
			/*三角形BCD*/
			glColor4f(0.6f,1.0f,0.6f,0.5f);//设置笔的颜色为黑
			glVertex3f(pB.x, pB.y, pB.z);	// 绘制B顶点
			glVertex3f(pC.x, pC.y, pC.z);	// 绘制C顶点	
			glVertex3f(pD.x, pD.y, pD.z);	// 绘制D顶点
		glEnd();
	glEndList();//显示列表定义结束
	return tetrahedronID;//返回四面体图元ID
}

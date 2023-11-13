#include <gl/glut.h>
#include <math.h>  
//点类型point
typedef struct Point3D {
	double x, y,z;
	Point3D(double a = 0.0,double b = 0.0,double c = 0.0)
	{
		x = a, y = b;z=c;
	}
} point3D;
 float PI=3.14159f; 
 //根据菜单menuValue选择的三视图，建立视角视觉效果	
void setLookAt(int menuValue,point3D eye,point3D at){		
	switch(menuValue)//根据菜单项值
	{
		case 1://正视图XOZ(V)										
			gluLookAt(0,eye.y,0,at.x,at.y,at.z,0,0,1);	//视点在y轴上	
			break;
		case 2://俯视图XOY(H)
			gluLookAt(0,0,eye.z,at.x,at.y,at.z,0,-1,0);//视点在z轴上
			break;
		case 3://侧视图YOZ(W)
			gluLookAt(eye.x,0,0,at.x,at.y,at.z,0,0,1);//视点在x轴上
			break;
	}	 
} 
//根据菜单menuValue选择的三视图，根据右手原则，围绕某坐标轴旋转angle，建立视角视觉效果	
void setLookAt(int menuValue,float angle,point3D eye,point3D at){		
	GLfloat squareRootOf2=1.4142;  //√2= 1.4142136023731
	GLdouble dcos,dsin,radius;
	float Rot =float(PI*angle/180.0f);  
	dcos=cos(Rot);
	dsin=sin(Rot); 
	switch(menuValue)//根据菜单项值
	{
		case 1://正视图XOZ(V)，视点绕y轴旋转	
			radius=sqrt((eye.x*eye.x+eye.z*eye.z));
			gluLookAt(dcos* radius,eye.y,dsin *radius,at.x,at.y,at.z,0,1,0); 
			break;
		case 2://俯视图XOY(H)，视点绕z轴旋转
			radius=sqrt((eye.x*eye.x+eye.y*eye.y));
			gluLookAt(dsin* radius,dcos *radius,eye.z,at.x,at.y,at.z,0,0,1); 
			break;
		case 3://侧视图YOZ(W)，视点绕x轴旋转
			radius=sqrt((eye.y*eye.y+eye.z*eye.z));
			gluLookAt(eye.x,dsin *radius,dcos *radius,at.x,at.y,at.z,1,0,0); 
			break;
	}	 
} 

//控制照相机的三维旋转角度，将场景坐标系映射到eye的观察坐标系，建立第一人称视角视觉效果
void setLookAt(const GLfloat x_angle,const GLfloat y_angle,const GLfloat z_angle,point3D eye,point3D at){ 
	GLdouble dxc,dxs,dyc,dys,dzc,dzs;
	dxc=cos(PI*x_angle/180);
	dxs=sin(PI*x_angle/180);
	dyc=cos(PI*y_angle/180);
	dys=sin(PI*y_angle/180);
	dzc=cos(PI*z_angle/180);
	dzs=sin(PI*z_angle/180);	
	GLdouble ux,uy,uz,vx,vy,vz,nx,ny,nz;
	ux=dyc*dzc;
	uy=dyc*dzs;
	uz=-dys;
	vx=dxs*dys*dzc-dxc*dzs;
	vy=dxs*dys*dzs+dxc*dzc;
	vz=dxs*dyc;
	nx=dxc*dys*dzc+dxs*dzs;
	ny=dxc*dys*dzs-dxs*dzc;
	nz=dxc*dyc;
	point3D camera;
	camera.x=eye.x *ux+eye.y*vx+eye.z*nx;
	camera.y=eye.x *uy+eye.y*vy+eye.z*ny;
	camera.z=eye.x *uz+eye.y*vz+eye.z*nz;
	gluLookAt(camera.x,camera.y,camera.z,at.x,at.y,at.z,vx,vy,vz);	
}


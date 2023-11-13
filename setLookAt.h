#include <gl/glut.h>
#include <math.h>  
//������point
typedef struct Point3D {
	double x, y,z;
	Point3D(double a = 0.0,double b = 0.0,double c = 0.0)
	{
		x = a, y = b;z=c;
	}
} point3D;
 float PI=3.14159f; 
 //���ݲ˵�menuValueѡ�������ͼ�������ӽ��Ӿ�Ч��	
void setLookAt(int menuValue,point3D eye,point3D at){		
	switch(menuValue)//���ݲ˵���ֵ
	{
		case 1://����ͼXOZ(V)										
			gluLookAt(0,eye.y,0,at.x,at.y,at.z,0,0,1);	//�ӵ���y����	
			break;
		case 2://����ͼXOY(H)
			gluLookAt(0,0,eye.z,at.x,at.y,at.z,0,-1,0);//�ӵ���z����
			break;
		case 3://����ͼYOZ(W)
			gluLookAt(eye.x,0,0,at.x,at.y,at.z,0,0,1);//�ӵ���x����
			break;
	}	 
} 
//���ݲ˵�menuValueѡ�������ͼ����������ԭ��Χ��ĳ��������תangle�������ӽ��Ӿ�Ч��	
void setLookAt(int menuValue,float angle,point3D eye,point3D at){		
	GLfloat squareRootOf2=1.4142;  //��2= 1.4142136023731
	GLdouble dcos,dsin,radius;
	float Rot =float(PI*angle/180.0f);  
	dcos=cos(Rot);
	dsin=sin(Rot); 
	switch(menuValue)//���ݲ˵���ֵ
	{
		case 1://����ͼXOZ(V)���ӵ���y����ת	
			radius=sqrt((eye.x*eye.x+eye.z*eye.z));
			gluLookAt(dcos* radius,eye.y,dsin *radius,at.x,at.y,at.z,0,1,0); 
			break;
		case 2://����ͼXOY(H)���ӵ���z����ת
			radius=sqrt((eye.x*eye.x+eye.y*eye.y));
			gluLookAt(dsin* radius,dcos *radius,eye.z,at.x,at.y,at.z,0,0,1); 
			break;
		case 3://����ͼYOZ(W)���ӵ���x����ת
			radius=sqrt((eye.y*eye.y+eye.z*eye.z));
			gluLookAt(eye.x,dsin *radius,dcos *radius,at.x,at.y,at.z,1,0,0); 
			break;
	}	 
} 

//�������������ά��ת�Ƕȣ�����������ϵӳ�䵽eye�Ĺ۲�����ϵ��������һ�˳��ӽ��Ӿ�Ч��
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


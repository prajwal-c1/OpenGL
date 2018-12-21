#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
float x1,x2,Y1,y2;

void display(void)
{
float dy,dx,step,x,y,k,Xin,Yin;
dx=x2-x1;
dy=y2-Y1;

if(abs(dx)> abs(dy))
{
step = abs(dx);
}
else
{
step = abs(dy);
}
Xin = dx/step;
Yin = dy/step;

x= x1;
y=Y1;
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();

for (k=1 ;k<=step;k++)
{
x= x + Xin;
y= y + Yin;

glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
}


glFlush();
}


int xc,yc,r,r1;
void Init()
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0,0,0,0);
glColor3f(1.0,0.0,0.0);
gluOrtho2D(0 , 720 , 0 , 720);
glFlush();
}

void ddacircle(int xc, int yc, int r)
{
float xc1,xc2,yc1,yc2,eps,sx,sy;
int val,i;


xc1=r;
yc1=0;

sx=xc1;
sy=yc1;

i=0;

do
{
val=pow(2,i);
i=i+1;
} while(val<r);

eps=1/pow(2,i-1);

do
{
 xc2=xc1+yc1*eps;
yc2=yc1-eps*xc2;

glBegin(GL_POINTS);
glVertex2f(xc+xc2,yc-yc2);
xc1=xc2;
yc1=yc2;
glEnd();
}while ((yc1-sy)<eps||(sx-xc1)>eps);
glFlush();
}

void myDisplay() {
ddacircle(350,233,58);

x1=300,x2=400,Y1=200,y2=200; 
display();
x1=400,x2=350,Y1=200,y2=286;
display();
x1=350,x2=300,Y1=286,y2=200;
display();
glFlush();
	  

	

}

int main(int argc,char**argv)
{
 
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(100,100);
glutInitWindowSize(720,720);
glutCreateWindow("pattern using dda line and circle");
glutDisplayFunc(myDisplay);
Init();
glutMainLoop();
return 0;
}

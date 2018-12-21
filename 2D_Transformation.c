#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <stdio.h>

int c;
float xinc,yinc,x1,x2,y12,steps,x,y,t;
float dx,y11,dy;

void line(float x1, float y11, float x2, float y12, float r, float g, float b)
{
	glBegin(GL_LINES);
	glColor3f(r,g,b);
	glVertex2d(x1+320,y11+320);
	glVertex2d(x2+320,y12+320);
	glEnd();
}

void display(void)
{	
	glClear(GL_COLOR_BUFFER_BIT);	
	line(x1, y11, x2, y11, 1.0, 0.0, 0.0);
	line(x2, y11, x2, y12, 1.0, 0.0, 0.0);
	line(x2, y12, x1, y12, 1.0, 0.0, 0.0);
	line(x1, y12, x1, y11, 1.0, 0.0, 0.0);	
	if(c==1)
	{
		line(t+x1,t+y11,t+x2,t+y11, 0.0, 1.0, 0.0);
		line(t+x2,t+y11,t+x2,t+y12, 0.0, 1.0, 0.0);
		line(t+x2,t+y12,t+x1,t+y12, 0.0, 1.0, 0.0);
		line(t+x1,t+y12,t+x1,t+y11, 0.0, 1.0, 0.0);
	}
	else if(c==2)
	{
		line(t*x1,t*y11,t*x2,t*y11, 1.0, 0.0, 1.0);
		line(t*x2,t*y11,t*x2,t*y12, 1.0, 0.0, 1.0);
		line(t*x2,t*y12,t*x1,t*y12, 1.0, 0.0, 1.0);
		line(t*x1,t*y12,t*x1,t*y11, 1.0, 0.0, 1.0);
	}	
	else if(c==3)
	{
		line(x1*cos(t)-y11*sin(t),y11*cos(t)+x1*sin(t),x2*cos(t)-y11*sin(t),y11*cos(t)+x2*sin(t), 0.0, 1.0, 1.0);
    		line(x2*cos(t)-y11*sin(t),y11*cos(t)+x2*sin(t),x2*cos(t)-y12*sin(t),y12*cos(t)+x2*sin(t), 0.0, 1.0, 1.0);
		line(x2*cos(t)-y12*sin(t),y12*cos(t)+x2*sin(t),x1*cos(t)-y12*sin(t),y12*cos(t)+x1*sin(t), 0.0, 1.0, 1.0);			
    		line(x1*cos(t)-y12*sin(t),y12*cos(t)+x1*sin(t),x1*cos(t)-y11*sin(t),y11*cos(t)+x1*sin(t), 0.0, 1.0, 1.0);		
	}		
	glFlush();
}

void init(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	gluOrtho2D(0,640,0,640);
}

int main(int argc, char **argv)
{		
	printf("Enter diagonal points of the quardilateral:\n");
	printf("Enter points space sepratedly i.e x0 y0 x1 y1: \n");
	scanf("%f""%f""%f""%f",&x1,&y11,&x2,&y12);
	printf("1.Translation \n");
	printf("2.Scaling \n");
	printf("3.Rotation \n");
	printf("Enter your choice\n");
	scanf("%d",&c);
	if (c==1)
	{
		printf("Enter the translating factor i.e t: \n");
		scanf("%f",&t);
	}
	else if (c==2)
	{
		printf("Enter the scaling factor i.e s: \n");
		scanf("%f",&t);
	}
	else if (c==3)
	{
		printf("Enter the angle of rotation i.e theta: \n");
		scanf("%f",&t);
		t = (t*M_PI)/180;
	}		
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("TRANSLATION, SCALING, & ROTATION");
	init();
	glutDisplayFunc(display);
	glutMainLoop();	
	return 0;
}

/* 
-----------------TRANSLATION---------------
Enter diagonal points of the quardilateral:
Enter points space sepratedly i.e x0 y0 x1 y1: 
10 10 50 50
************CHOICE*************: 
1.Translation 
2.Scaling 
3.Rotation 
Enter your choice
1
Enter the translating factor i.e t: 
30
-------------------------------------------

-----------------SCALING-------------------
Enter diagonal points of the quardilateral:
Enter points space sepratedly i.e x0 y0 x1 y1: 
10 10 50 50
************CHOICE*************: 
1.Translation 
2.Scaling 
3.Rotation 
Enter your choice
2
Enter the scaling factor i.e s: 
5
------------------------------------------

-----------------ROTATION-----------------
Enter diagonal points of the quardilateral:
Enter points space sepratedly i.e x0 y0 x1 y1: 
10 10 50 50
************CHOICE*************: 
1.Translation 
2.Scaling 
3.Rotation 
Enter your choice
3
Enter the angle of rotation i.e theta: 
45
-----------------------------------------
*/

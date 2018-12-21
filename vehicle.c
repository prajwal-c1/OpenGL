#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>

float xinc,yinc,x1,x2,y12,steps,x,y;
float y_pos=620.0;
float Y_pos=20.0;
float x_pos=0.0;
int state =1;

void bubble(float a)
{
	float radius,two_pi,x1,y1,x2,y2,ang;
	int sectors;
	
	sectors=100;
	ang=0.0;
	radius = 20;
	two_pi=2*3.1452423/sectors;

	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,1.0);
	glVertex2f(x_pos+radius*cos(0.0)+a,radius*sin(0.0)+320.0);
	for (int i=0;i<=sectors;i++)
	{
		glVertex2f(x_pos+radius*cos(ang)+a,radius*sin(ang)+320.0);
		ang+=two_pi;
	}
	glEnd();

}
/*
void shootbubble(float f)
{
	float radius,two_pi,x1,y1,x2,y2,ang;
	int sectors;
	
	sectors=100;
	ang=0.0;
	radius = 4;
	two_pi=2*3.1452423/sectors;

	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(x_pos+radius*cos(0.0),Y_pos+radius*sin(0.0)-f);
	for (int i=0;i<=sectors;i++)
	{
		glVertex2f(x_pos+radius*cos(ang),Y_pos+radius*sin(ang)-f);
		ang+=two_pi;
	}
	glEnd();
	
}*/

void shooter(float e,float f,float g)
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,0.0,1.0);
	glVertex2f(x_pos+g,f+300.0);
	glVertex2f(x_pos+g,f+340.0);
	glVertex2f(x_pos+e+g,f+300.0);
	glEnd();
}
void square()
{
	glBegin(GL_QUADS);
	glColor3f(1.0,0.0,1.0);
	glVertex2f(x_pos,340.0);
	glVertex2f(x_pos+100.0,340.0);
	glVertex2f(x_pos+100.0,380.0);
	glVertex2f(x_pos,380.0);
	glEnd();
}
void display(void)
{		
	glClear(GL_COLOR_BUFFER_BIT);
	int count=0;
	bubble(20.0);
	bubble(80.0);
	shooter(-20.0,40.0,0.0);
	shooter(20.0,40.0,100.0);
	square();
	glFlush();
	glutSwapBuffers();

}
void keyboard(int key,int x,int y)
{
	switch(key)
	{
		case GLUT_KEY_LEFT:
		{
			glutPostRedisplay();
			if(x_pos>-100.0)
			{
				x_pos-=5.0;
			}
			else
			{
				x_pos=660.0;
			}	
			break;
		}
		case GLUT_KEY_RIGHT:
		{
			glutPostRedisplay();
			if(x_pos<660.0)
			{
				x_pos+=5.0;
			}
			else{
				x_pos=0.0;
			}
			break;
		}
		case GLUT_KEY_UP:
		{
			//glutPostRedisplay();
				state=0;

			break;
		}
	}
}
void reshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,640,0,640);
	glMatrixMode(GL_MODELVIEW);
}

void init(void)
{
	glClearColor(0.0,0.0,0.0,1.0);
}
/*
void timer(int n)
{
	glutPostRedisplay();
	glutTimerFunc(1000/60,timer,0);	
	if(x_pos<660.0){
		x_pos+=2.0;
	}
	else{			
		x_pos=0.0;
	}
	/*if (state==0)
	{		
	if(Y_pos>630.0){
		state=1;
	}
	else{
		Y_pos+=10.0;
		//shootbubble(0.0);	
	}
	}
	


}*/

int main(int argc, char** argv)
{	
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,640);
	glutCreateWindow("BUBBLE SHOOTING");	
	glutDisplayFunc(display);
	glutSpecialFunc(keyboard);
	glutReshapeFunc(reshape);
	//glutTimerFunc(0,timer,0);
	
	init();
	glutMainLoop();
	return 0;
}


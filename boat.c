#include<GL/glut.h>

float x_position=-10;  //note the float else doesnt move
int state=1;
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glBegin(GL_POLYGON);
glVertex2f(x_position,-1.0);
glVertex2f(x_position+2.0,-1.0);
glVertex2f(x_position+4.0,1.0);
glVertex2f(x_position-2,1.0);  //for boat base
glEnd();
//glFlush();
glBegin(GL_POLYGON);

glVertex2f(x_position,1.0);
glVertex2f(x_position+2,1.0);  // boat first floor
glVertex2f(x_position+2,2.0);
glVertex2f(x_position,2.0);

glBegin(GL_POLYGON);

glVertex2f(x_position+1,2.0);  // boat top 
glVertex2f(x_position+1.2,4.0);
glVertex2f(x_position+1.45,2.0);

glEnd();
glFlush();
glutSwapBuffers();
}
void reshape(int w,int h)
{
glViewport(0,0,(GLsizei)w,(GLsizei)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-10,10,-10,10);
glMatrixMode(GL_MODELVIEW);
}
void timer(int n)
{
glutPostRedisplay();
glutTimerFunc(1000/60,timer,0);
switch(state)
{
case 1:
if(x_position<8)
x_position+=0.15;   //for speed 
else
state=-1;
break;
case -1:
if(x_position>-10)
x_position-=0.15;
else
state=1;
break;
}
}
void init()
{
glClearColor(0.0,0.4,0.9,0.0);
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);   //only single verticle line
glutInitWindowSize(500,500);
//glutInitWindowPosition(0,0);
glutCreateWindow("Animation");
glutDisplayFunc(display); 
glutReshapeFunc(reshape); 
glutTimerFunc(0,timer,0);
init();
glutMainLoop();
return 0;
}

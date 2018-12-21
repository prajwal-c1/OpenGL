/*
	Group : Wave Ripple
	SCETTY414 Pranav More
	SCETTY416 Swapnil Pathare
	SCETTY418 Rakesh S Patil
	SCETTY420 Tushar Tanaji Desai
	SCETTY422 Srushti G Yerawar

*/

#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>

void display();
void reshape(int, int);
void timer(int);

void init(){

	glClearColor(0.0, 0.0, 1.0, 1.0);	

}

int main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(200,100);
	glutInitWindowSize(512,512);
	glutCreateWindow("Animation");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);	
	glutTimerFunc(1000,timer,0);	
	glutMainLoop(); 
	return 0;
}

float x_position=10.0;
float radius=0.01;
int state=1;
int cir=0;
float a=153;
float b=255;
float c=255;
float a1=0.0;
float b1=0.0;
float c1=1.0;
float temp=0.1;


void display(){

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glBegin(GL_POLYGON);
	int theta;
      glColor3f(a,b,c);
      for(int i=0;i<7200;i++){
          theta=i*3.142/180;
          glVertex2f(0+0.5*cos(theta),x_position+0.5*sin(theta));
      }
	glEnd();

	/*glBegin(GL_POLYGON);
	glColor3ub(153,204,255);
      for(int i=0;i<14400;i++){
          theta=i*3.142/180;
          glVertex2f(0+radius*cos(theta),0+radius*sin(theta));
      }
	glEnd();
	*/
	glColor3f(a1,b1,c1);
	glPushMatrix();						//tree leaves
	glTranslatef(0,0,0);
	glutSolidTorus(radius,0.9,100,90);
	glutSolidTorus(radius+0.9,0.8,100,90);
	glutSolidTorus(radius+0.2,0.7,100,90);
	/*glutSolidTorus(radius+0.3,0.6,100,90);
	glutSolidTorus(radius+0.1,0.5,100,90);
	glutSolidTorus(radius,0.4,100,90);*/
	glPopMatrix();
	glFlush();	
	glutSwapBuffers();
}

void reshape(int w,int h){

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);
}

void timer(int p){

	glutPostRedisplay();
	glutTimerFunc(1000.0/200.0,timer,1);

	switch(state){
		case 1:
			if(x_position >2)
				x_position-=0.0500;
			else
				state = -1;
			break;
		case -1:
			a=0;
			c=1;
			b=0;
			a1=0;
			b1=128;
			c1=255;
			if(cir<200){
				radius=radius+0.09;
				cir=cir+1;
			}
			else{
				radius=0.01;
				if(x_position < 10){
					x_position=10.0;
					cir=0;
				}
				else
					cir=0;
					c=255;
					a=153;
					b=255;
					a1=0;
					b1=0;
					c1=1;
					
					state = 1;
			}
			break;
	}
}

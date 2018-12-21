#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>

int x1,x2, y2,x3,x4,y3,y4,t1;
int x11,y11,x21,y21,x31,x41,y31,y41;
int xm1,ym1,xm2,ym2,xm3,ym3,xm4,ym4;

void plotpt(int x, int y) {			//Plot a single point/pixel on window
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}


void dda(int p,int q,int r,int s) {		//Digital Differential Analyser Line Drawing Algorithm
int dx,dy,length,x,y;
dx = abs(q-p);					//Finding |dx| and |dy|
dy = abs(s-r);
if(dx>=dy){ 					//Set value of length to either dx or dy
length=dx;
}
else{
length=dy;
}

dx=(q-p)/length;
dy=(s-r)/length;
x=p+0.5;
y=r+0.5;
for(int i=0;i<length;i++){			//Plot points in fixed intervals to form the line
plotpt(x,y);
x=x+dx;
y=y+dy;
}
glFlush();
}


void draw(){
dda(x1,x2,t1,y2);
dda(x3,x4,y3,y4);
dda(x2,x4,y2,y4);
dda(x1,x3,t1,y3);
dda(x11,x21,y11,y21);
dda(x31,x41,y31,y41);
dda(x21,x41,y21,y41);
dda(x11,x31,y11,y31);
dda(xm1,xm2,ym1,ym2);
dda(xm2,xm3,ym2,ym3);
dda(xm3,xm4,ym3,ym4);
dda(xm4,xm1,ym4,ym1);
}

void init() { 
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);				//Initialising Window Position and Size
  glutInitWindowSize(640, 480);
  glutCreateWindow("dda");
  glClearColor(0.0,0.0,0.0,0);
  glColor3f(1.0,1.0,1.0);
  gluOrtho2D(0,640,0,480);
 
}

int main(int argc, char **argv)
{

  printf("\n Enter values of x1,y1: ");			//Accepting values from user
  scanf("%d %d",&x1,&t1);
  printf("\n Enter values of x2,y2: ");
  scanf("%d %d",&x2,&y2);
  printf("\nEnter values of points(x3,y3)");
  scanf("%d%d",&x3,&y3);
  printf("\nEnter values of points(x4,y4)");
  scanf("%d%d",&x4,&y4);

  
  xm1=(x1+x2)/2;
  ym1=(t1+y2)/2;
  xm2=(x1+x3)/2;
  ym2=(t1+y3)/2;
  xm3=(x3+x4)/2;
  ym3=(y3+y4)/2;
  xm4=(x2+x4)/2;
  ym4=(y2+y4)/2;
  
  x11=(xm1+xm2)/2;
  y11=(ym1+ym2)/2;
  x21=(xm1+xm4)/2;
  y21=(ym1+ym4)/2;
  x31=(xm2+xm3)/2;
  y31=(ym2+ym3)/2;
  x41=(xm3+xm4)/2;
  y41=(ym3+ym4)/2;
  
  glutInit(&argc, argv);
  init();
  glutDisplayFunc(draw);
  glutMainLoop();
  return 0;
}

/*test data
x1,y1=100,100
x2,y2=100,300
x3,y3=300,100
x4,y4=300,300*/

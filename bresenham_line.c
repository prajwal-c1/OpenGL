#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#define sign(x) ((x>0)?1:((x<0)?-1:0))			//Returns 1 if x>0, -1 if x<0, 0 otherwise

int x1,x2, y2,x3,x4,y3,y4,t1;
int x11,y11,x21,y21,x31,x41,y31,y41;
int xm1,ym1,xm2,ym2,xm3,ym3,xm4,ym4;

void plotpt(int x, int y) {				//Plot a single point/pixel on window
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}


void bres_general(int p,int q,int r,int s)
{
  int dx, dy,x, y, pk, s1, s2, flag=0, t;

  dx = abs(q-p);					//Find dx and dy
  dy = abs(s-r);
  s1 = sign(q-p);
  s2 = sign(s-r);
  
  if(dy > dx){						//Swap values of dx and dy if dy > dx
t = dx;
dx = dy; 
dy = t;
flag = 1;
}
  pk = 2 * dy - dx;					//Calculate value of decision parameter
  x = p;
  y = r;

int i;
  for( i = 1; i <= dx; i++)
  {
    plotpt(x,y);
   
    while(pk >= 0)
    {
      if(flag==1) {
  x = x + s1;
  }
      else
      {
        y = y + s2;
        pk = pk - 2* dx;
      }
    }


    if(flag==1) {
  y = y + s2;
  }
    else {
  x = x + s1;
  }
    pk = pk + 2 * dy;
  }
  glFlush();
}

void draw()
{
bres_general(x1,x2,t1,y2);
bres_general(x3,x4,y3,y4);
bres_general(x2,x4,y2,y4);
bres_general(x1,x3,t1,y3);
bres_general(x11,x21,y11,y21);
bres_general(x31,x41,y31,y41);
bres_general(x21,x41,y21,y41);
bres_general(x11,x31,y11,y31);
bres_general(xm1,xm2,ym1,ym2);
bres_general(xm2,xm3,ym2,ym3);
bres_general(xm3,xm4,ym3,ym4);
bres_general(xm4,xm1,ym4,ym1);

}

void init() { 
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);			//Initialise Display Mode, Window 										Position and Window size
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640, 480);
  glutCreateWindow("Geometric Pattern");
  glClearColor(0.0,0.0,0.0,0);
  glColor3f(1.0,1.0,1.0);
  gluOrtho2D(0,640,0,480);
 
}

int main(int argc, char **argv)
{

  printf("\n Enter values of x1,y1: ");
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

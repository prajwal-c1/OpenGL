#include <stdio.h>
#include <math.h>
#include<GL/gl.h>
#include <GL/glut.h>
#define sign(x) ((x>0)?1:((x<0)?-1:0))


void setPixel(GLint x, GLint y) {
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}


void plot_point(int x, int y,int xc, int yc)
{
  glBegin(GL_POINTS);
  glVertex2i(xc+x, yc+y);

  glVertex2i(xc+x, yc-y);

  glVertex2i(xc+y, yc+x);
  glVertex2i(xc+y, yc-x);

  glVertex2i(xc-x, yc-y);

  glVertex2i(xc-y, yc-x);
  glVertex2i(xc-x, yc+y);
  glVertex2i(xc-y, yc+x);
  glEnd();
}



void bresenham_circle(int xc1,int yc1, int r)
{
  int x=0,y=r;
  float pk=3-2*r;

 
  plot_point(x,y,xc1,yc1);
  int k;
  
  while(x <= y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + 4*x+6;
    else
    {
      y = y - 1;
      pk = pk + 4*(x - y) + 10;
    }
    plot_point(x,y,xc1,yc1);
  }
  glFlush();
}


/* Generalized Bresenham's Algorithm */
void bres_general(int x1, int y1, int x2, int y2)
{
  int dx, dy, x, y, d, s1, s2, swap=0, temp;

  dx = abs(x2 - x1);
  dy = abs(y2 - y1);
  s1 = sign(x2-x1);
  s2 = sign(y2-y1);

  /* Check if dx or dy has a greater range */
  /* if dy has a greater range than dx swap dx and dy */
  if(dy > dx){temp = dx; dx = dy; dy = temp; swap = 1;}

  /* Set the initial decision parameter and the initial point */
  d = 2 * dy - dx;
  x = x1;
  y = y1;

  int i;
  for(i = 1; i <= dx; i++)
  {
    setPixel(x,y);
    
    while(d >= 0) 
    {
      if(swap) x = x + s1;
      else 
      {
        y = y + s2;
        d = d - 2* dx;
      }
    }
    if(swap) y = y + s2;
    else x = x + s1;
    d = d + 2 * dy;
  }
  glFlush();
}


void circles()
{
 
  glClear(GL_COLOR_BUFFER_BIT);

glColor3f(0.0,1.0,1.0);

bres_general(-200,200,200,200);

bres_general(200,-200,200,200);

bres_general(200,-200,-200,-200);
bres_general(-200,200,-200,-200);

bresenham_circle(0,400,200); 
bresenham_circle(0,-400,200); 
}

void Init()
{
  
  glClearColor(0.0,0.0,0.0,0);
  
  gluOrtho2D(-1000,1000,-1000,1000);
}

int main(int argc, char **argv)
{
  plot_point(0,200,0,0);
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);
  glutCreateWindow("Using bresenham's algorithm for Audi");
  Init();
  glutDisplayFunc(circles);
  glutMainLoop();
  return 0;
}







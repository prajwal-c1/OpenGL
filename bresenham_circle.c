#include <stdio.h>
#include <math.h>
#include<GL/gl.h>
#include <GL/glut.h>

void plot_point(int x, int y,int xc, int yc)		//Plot points of the circle
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



void bresenham_circle(int xc1,int yc1, int r)		//Calculate value of the decision parameter
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


void circles()
{
 
  glClear(GL_COLOR_BUFFER_BIT);

glColor3f(1.0,1.0,1.0);


bresenham_circle(0,0,200);  // first circle
bresenham_circle(0+300,0,200);   //second horizontal circle
bresenham_circle(0+3*200,0,200);    //third horizontal circle
bresenham_circle(0-300,0,200); 

}

void Init()
{
  
  glClearColor(0.0,0.0,0.0,0);
  
  gluOrtho2D(-1000,1000,-1000,1000);
}

int main(int argc, char **argv)
{
  plot_point(0,200,0,0);			//Initialise Display mode, Window Position and Window Size
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);
  glutCreateWindow("Using bresenham's algorithm for circle pattern");
  Init();
  glutDisplayFunc(circles);
  glutMainLoop();
  return 0;
}

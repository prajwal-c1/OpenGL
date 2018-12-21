#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
 

int xc, yc,r ,x1, Y1, x2, y2,a;


void draw_pixel(int x, int y) {
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int x2, int Y1, int y2) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-Y1;

	if (dx < 0) dx = -dx;
	if (dy< 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < Y1) incy = -1;
	x = x1; y = Y1;
	if (dx >dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_pixel(x, y);
		}
	}
}


void plot_point(int x, int y)
{
  glColor3f(0.0,0.0,1.0);
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

// Function to draw a circle using bresenham's
// circle drawing algorithm
void bresenham_circle(int r)
{
  int x=0,y=r;
  float pk=3-2*r;

  /* Plot the points */
  /* Plot the first point */
  plot_point(x,y);
  int k;
  /* Find all vertices till x=y */
  while(x < y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + 2*x+1;
    else
    {
      y = y - 1;
      pk = pk + 2*(x - y) + 1;
    }
    plot_point(x,y);
  }
  
  glFlush();

}

void Init()
{
  /* Set clear color to white */
  glClearColor(1.0,1.0,1.0,0);
  /* Set fill color to black */
  //glColor3f(0.0,0.0,0.0);
  /* glViewport(0 , 0 , 640 , 480); */
  /* glMatrixMode(GL_PROJECTION); */
  /* glLoadIdentity(); */
  gluOrtho2D(0 , 720 , 0 , 720);
}



void myDisplay() {
printf("\n Enter xc = 350");
scanf("\n %d",&xc);
printf("\n Enter yc = 233");
scanf("\n %d",&yc); 

//scanf("\n %d",&r);
bresenham_circle(58);
draw_line(300, 400, 200,200);
draw_line(400, 350,200,286);
draw_line(350, 300, 286,200);
glFlush();
	  

	

}

int main(int argc, char **argv)
{
int ii,jj,ind,ind1;


  /* Initialise GLUT library */
  glutInit(&argc,argv);
  /* Set the initial display mode */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  /* Set the initial window position and size */
  glutInitWindowPosition(0,0);
  glutInitWindowSize(720,720);
  /* Create the window with title "DDA_Line" */
  glutCreateWindow("pattern using Bresenham line and circle");
  /* Initialize drawing colors */
  Init();
glutDisplayFunc(myDisplay);
glutMainLoop();

  
  /* Call the displaying function */
  
  /* Keep displaying untill the program is closed */
 
 return(0);
}


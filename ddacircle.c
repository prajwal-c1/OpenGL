#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include <math.h>

float epsilon(int r)						//Calculate value of epsilon
{
    int n;
    for (int i = 1; i<r; i++)
    {
        if ((pow(2, i) <= r) && (r<pow(2, i + 1)))
        {
            n = i + 1;
            break;
        }
    }

    return pow(2, -n);
}


void circle(int x,int y, int r)
{
    float x1, t1, x2, t2;
    int n = 1;
    float start_x ;
    float start_t ;

    x1 = r;							//Set starting x and y coordinated as r and 0
    t1 = 0;
    start_x = r;
    start_t=0;
    
    float e = epsilon(r);
    

    do {
        x2 = x1 + (e * t1);
        t2 = t1 - (e * x2);
        glBegin(GL_POINTS);
        glVertex2i(x2+x, t2+y);
        glEnd();
        
        x1 = x2;
        t1 = t2;
    } while ((t1 - start_t)<e || (start_x - x1)>e);


}


void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,0.0,1.0);
circle(0-2*100,0+1.7*200,200);  
glColor3f(1.0,1.0,1.0);
circle(0+200,0+1.7*200,200); 
glColor3f(1.0,0.0,0.0);
circle(0+200+2*200,0+1.7*200,200);
glColor3f(1.0,1.0,0.0);
circle(0,0,200); 
glColor3f(0.0,1.0,.0);
circle(0+4*100,0,200);    
    

    glFlush();
}



int main(int argc, char **argv)
{
      glutInit(&argc,argv);
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
      glutInitWindowPosition(0,0);
      glutInitWindowSize(500,500);
      glutCreateWindow("Using DDA algorithm for circle pattern");
      glClearColor(0.0,0.0,0.0,0);
          gluOrtho2D(-1500,1500,-1500,1500);
      glutDisplayFunc(display);
      glutMainLoop();
  return 0;
}

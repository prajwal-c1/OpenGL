#include<stdio.h>
#include<GL/glut.h>
#include<stdbool.h>

int TOP = 8;
int BOTTOM = 4;
int LEFT = 1;
int RIGHT = 2;
int INSIDE = 0;

int x_min = 100;
int x_max = 400;
int y_min = 100;
int y_max = 400;

int pt_x1, pt_x2, pt_y1, pt_y2;


void init2D(float r, float g, float b)
{
	glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(r,g,b,0.0);  
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (0.0, 500.0, 500.0, 0.0);
}

int cal_code(int x, int y)
{
  int code = INSIDE;
  
  if(x < x_min)
  {
    code = code | LEFT;
  }
  
  else if(x > x_max)
  {
    code = code | RIGHT;
  }
  
  else if(y < y_min)
  {
    code = code | BOTTOM;
  }
  
  else if(y > y_max)
  {
    code = code | TOP;
  }
  
  return code;
}

void clipping(int x1, int y1, int x2, int y2)
{
  int code1 = cal_code(x1,y1);
  int code2 = cal_code(x2,y2);
  
  bool accept = false;
  
while(true)
{
  if(code1 == 0 && code2 == 0)
  {
    accept = true;
    break;
  }
  
  else if(code1 & code2)
  {
    break;
  }
  
  else
  {
    int code_out;
    int x, y;
    
    if(code1 != 0)
    {
      code_out = code1;
    }
    
    else
    {
      code_out = code2;
    }
    
    if(code_out & BOTTOM)
    {
    	x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1); 
        y = y_min; 
    } 
    
    else if(code_out & TOP)
    {
        x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1); 
        y = y_max; 
    }
    
    else if(code_out & RIGHT)
    {
        y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1); 
        x = x_max;
    }
    
    else if(code_out & LEFT)
    {
        y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1); 
        x = x_min; 
    }
    
    if(code_out == code1)
    {
        x1 = x;
        y1 = y;
        code1 = cal_code(x1,y1);
    }
    
    else
    {
    x2 = x;
    y2 = y;
    code2 = cal_code(x2,y2);
    }   
  }
}
if(accept)
{	
	glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();
    glFlush();    
}
}

void display()
{    
    clipping(pt_x1, pt_y1, pt_x2, pt_y2);
/*        
    glColor3f(0.0,0.0,1.0);    
    glBegin(GL_LINES);
    glVertex2i(pt_x1,pt_y1);
    glVertex2i(pt_x2,pt_y2);
    glEnd();
    glFlush();    
*/   
    
glBegin(GL_LINES);

glColor3f(0.0,1.0,0.0);
  glVertex2i(x_min,y_min);
  glVertex2i(x_min,y_max);
  
  glVertex2i(x_max,y_min);
  glVertex2i(x_max,y_max);
  
  glVertex2i(x_min, y_max);
  glVertex2i(x_max,y_max);
  
  glVertex2i(x_min,y_min);
  glVertex2i(x_max,y_min);
  
  glEnd();
  glFlush();

}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  
  scanf("%d", &pt_x1);
  scanf("%d", &pt_y1);
  scanf("%d", &pt_x2);
  scanf("%d", &pt_y2);
  
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutCreateWindow("Clipping_Box");
  glutInitWindowSize(1000,1000);
  glutInitWindowPosition(0,0);
  
  init2D(0.0,0.0,0.0);
  glutDisplayFunc(display);
  glutMainLoop();
}

/*
inputs
Completely inside: 150 150 350 350
Partially Inside: 200 50 200 350
Completely outside: 10 10 40 40
*/

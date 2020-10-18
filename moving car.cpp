#include <GL/freeglut.h> 
#include <GL/gl.h> 
#include <bits/stdc++.h> 
using namespace std;
int t=0,f=0; void init (void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f); 
    glPointSize(2.0); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
    gluOrtho2D(0.0, 1200.0, 0, 700.0);
}


void linedraw(int x0,int y0,int x1,int y1)
{

    int dx=x1-x0,dy=y1-y0;
    int steps = abs(dx)>abs(dy)?abs(dx):abs(dy); 
    float Xin = dx/(float)(steps); 
    float Yin = dy/(float)(steps);
    float x=x0,y=y0;
    for (int i=0;i<=steps;i+=1){ 
        glBegin(GL_POINTS); 
        glVertex2i((x),(y)); 
        glEnd();
        x+=Xin; 
        y+=Yin;
    }
}

void circledraw(float cx,float cy)
{
    float r=20; 
    float x=0,y=r; 
    float d=3-(2*r); 
    do{
        glBegin(GL_POINTS);
        glVertex2i((x+cx),(y+cy));
        glVertex2i((-x+cx),(y+cy));
        glVertex2i((x+cx),(-y+cy));
        glVertex2i((-x+cx),(-y+cy));
        glVertex2i((y+cx),(x+cy));
        glVertex2i((-y+cx),(x+cy));
        glVertex2i((y+cx),(-x+cy));
        glVertex2i((-y+cx),(-x+cy)); 
        glEnd();
        x+=1;
        if (d<0){ 
            d=d+(4*x)+6;
        }else{
            d=d+4*(x-y)+10; y-=1;
        }

    }while(x-y<=0);
}

void renderFunction()
{
    while(1){
        glClear (GL_COLOR_BUFFER_BIT); 
        glColor3f (1.0, 1.0, 1.0); 
        glPointSize(1.0);
    if (f==0){

        linedraw(20+t,120,280+t,120); 
        linedraw(20+t,120,20+t,150); 
        linedraw(280+t,120,280+t,150); 
        linedraw(20+t,150,70+t,150);
        linedraw(280+t,150,230+t,150); 
        linedraw(70+t,150,100+t,200); 
        linedraw(230+t,150,200+t,200); 
        linedraw(100+t,200,200+t,200);


        circledraw(100+t,100); 
        circledraw(200+t,100);
        }else{
        }
        t+=1; f=1;
        f=0;
        glFlush();
        if (f==1){
            for (int i=0;i<=10000000;i++);
            }
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE); 
    glutInitWindowSize(1200,700); 
    glutCreateWindow("Motion Frames"); 
    glutDisplayFunc(renderFunction); init();
    glutMainLoop(); return 0;
}

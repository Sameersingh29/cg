using namespace std;
#include <GL/glut.h>
#include<iostream>

//float ax = 100, ay = 100, bx = 200, by = 130; //m=dy/dx = 30/100 = 0.3
//float ax = 100, ay = 130,  bx = 200, by = 100; // m=dy/dx = -30/100 = -0.3
//float ax = 100, ay = 50,  bx = 200, by = 350; // m=dy/dx = 300/100 = 3
//float ax = 100, ay = 350,  bx = 200, by = 50; // m=dy/dx = -300/100 = -3


void draw_pixel(float x, float y){
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
}

void bres(){
// |m| < 1

float dy = by-ay, dx = bx-ax;
float m = dy/dx;
cout << "m" << m;
dx = abs(dx); dy = abs(dy);
float inc = 1;

if(m<0){
inc =-1; //decrement the y
}

if(abs(m)<1){ //sampling for x to get y
// check if the point is going left to right
float x= ax, y=ay;
if(bx< ax){
swap(ax,bx); swap(ay,by);
}

//plot 1st pt.
draw_pixel(x,y);

float p = 2*dy - dx;

while(x < bx){
if(p<0)
p+= 2*dy;
else{
y+=inc;
p+= 2*dy - 2*dx;
}

x++;
draw_pixel(x,y); //plot subsequent pts.
}
}

else{
// check if the line is going from bottom to top

if(by< ay){
swap(ax,bx); swap(ay,by);
}

//plot 1st pt.
float x= ax, y=ay;
draw_pixel(x,y);

float p = 2*dx - dy;

while(y < by){
if(p<0)
p+= 2*dx;
else{
x+=inc;
p+= 2*dx - 2*dy;
}

y++;

draw_pixel(x,y); //plot subsequent pts.

}
}
}

void display(){
glClear(GL_COLOR_BUFFER_BIT);

glColor3f(0,0,1);
bres();

glColor3f(1,0,0);
glPointSize(3.0);
draw_pixel(ax,ay);
draw_pixel(bx,by);

glFlush();
}

void myinit(){
glClearColor(1,1,1,1);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,499,0,499);
glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){

cout<<"Enter (x1,y1) (x2,y2) :";
cin>>ax>>ay>>bx>>by;

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutInitWindowSize(500,500);
glutCreateWindow("Bresenham's line drawing algorithm");
myinit(); //initialization functions ; always put myinit() after create window;
glutDisplayFunc(display);

glutMainLoop();
return 0;
}

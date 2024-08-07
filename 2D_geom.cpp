#include<GL/glut.h>
#include<cmath>

float tri[3][3] = {{-100,100,0},{-100,-100,100},{1,1,1}};
int N=3; //3 vertices
float tx = 50, ty = 50;
float theta = 30; //in degrees
float thetar = theta*(M_PI/100); //in radians
float px = -100, py = -100; //pivot pt. for rotation
float sx = 0.5, sy = 0.5; //Scaling factors
float fx= -100, fy = -100; //Fixed pt. for scaling

//Translation Function
void translate_tri(){
glBegin(GL_LINE_LOOP);
for(int i=0; i<3; i++){
glVertex2f(tri[0][i]+tx, tri[1][i]+ty);
}
glEnd();
}
//Rotation Function
void rotate_tri(){
glBegin(GL_LINE_LOOP);
for(int i=0; i<3; i++){
float x = tri[0][i], y = tri[1][i];
float xb = x*cos(thetar) - y*sin(thetar);
float yb = x*sin(thetar) + y*cos(thetar);
glVertex2f(xb,yb);
}
glEnd();
}
//Pivot pt. rotation
void pivot_rotation(){
glBegin(GL_LINE_LOOP);
for(int i=0; i<3; i++){
float x = tri[0][i], y = tri[1][i];
float xb = px+(x-px)*cos(thetar) - (y-py)*sin(thetar);
float yb = py+(x-px)*sin(thetar) + (y-py)*cos(thetar);
glVertex2f(xb,yb);
}
glEnd();
}

//Scaling about Fixed point
void fixed_scale(){
glBegin(GL_LINE_LOOP);
for(int i=0; i<3; i++){
float x = tri[0][i] ;
float y = tri[1][i] ;
float xb = x*sx + fx*(1-sx);
float yb = y*sy + fy*(1-sy);


glVertex2f(xb, yb);
}
glEnd();
}

//Scaling Function
void scaling(){
glBegin(GL_LINE_LOOP);
for(int i=0; i<3; i++){
float x = tri[0][i] * sx;
float y = tri[1][i] * sy;
glVertex2f(x, y);
}
glEnd();
}

//Draw initial triangle
void draw_tri(){
glBegin(GL_LINE_LOOP);
for(int i=0; i<3; i++){
glVertex2f(tri[0][i], tri[1][i]);
}
glEnd();
}

void display(){
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0); //red
draw_tri();
//1. Translation
//glColor3f(1,0,1); //magenta
//translate_tri();
//2. Rotation
//rotate_tri();
//3. Pivot Rotation
//glColor3f(1,0,1);
//pivot_rotation();
//4. 2D scaling
//scaling();
//5. Scaling about fixed point
fixed_scale();
glFlush();
}

void myinit(){
glClearColor(1,1,1,1);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-250,250,-250,250);
glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char **argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB| GLUT_SINGLE);
glutInitWindowSize(500,500);
glutCreateWindow("2D geometric operations");
myinit();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

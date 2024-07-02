#include<GL/glut.h>
#define TRANSLATE 1
#define ROTATEZ 2
#define ROTATE_PIV 3
#define ORIGINAL -1
#define SCALE 4

int TRANSFORM = ORIGINAL;
float tx=50, ty=50,tz=0;
float rz = 60, px =0, py = 160;
float sx = -250 , sy=0, sz =0;
float Sx = 250, Sy = 0, Sz =0;

void obj(){
glColor3f(0.2,0.5,0.5);
glBegin(GL_POLYGON);
glVertex2f(0,25);
glVertex2f(25,25);
glVertex2f(50,0);
glVertex2f(0,-50);
glVertex2f(-50,0);
glVertex2f(-25,25);
glEnd();
glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(-50,0);
glVertex2f(50,0);

glVertex2f(-25,25);
glVertex2f(-25,0);

glVertex2f(25,25);
glVertex2f(25,0);

glVertex2f(-25,0);
glVertex2f(0,-50);

glVertex2f(25,0);
glVertex2f(0,-50);
glEnd();

}

void display(){
glClear(GL_COLOR_BUFFER_BIT);
//obj();
switch(TRANSFORM){
case -1:
obj();
break;
case TRANSLATE:
glPushMatrix();
glTranslatef(tx,ty,tz);
obj();
glPopMatrix();
break;
case ROTATEZ:
glPushMatrix();
glRotatef(rz,0,0,1);
obj();
glPopMatrix();
break;
case ROTATE_PIV:
glPushMatrix();
glTranslatef(px,py,0);
glRotatef(rz,0,0,1);
glTranslatef(-px,-py,0);
obj();
glPopMatrix();
break;
case SCALE:
glPushMatrix();
obj();

glTranslatef(Sx,Sy,0);
glScalef(1.5,1.5,0);
glTranslatef(-Sx,-Sy,0);
obj();

glTranslatef(sx,sy,0);
glScalef(0.5,0.5,0);
glTranslatef(-sx,-sy,0);
obj();

glPopMatrix();
break;

}
glFlush();
}

void myinit(){
glClearColor(1,1,1,1);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-250,250,-250,250);
glMatrixMode(GL_MODELVIEW);
}

void menu(int id){
switch(id){
case 0:
exit(0);
break;
case -1:
TRANSFORM = ORIGINAL;
break;
case 1:
TRANSFORM = TRANSLATE;
break;
case 4:
TRANSFORM = SCALE;
break;

}
glutPostRedisplay(); //calls dispay function, checks flag in glutMainLoop()
}

void rot_menu(int id){
switch (id){
case 2:
TRANSFORM = ROTATEZ;
break;
case 3:
TRANSFORM = ROTATE_PIV;
break;
}
glutPostRedisplay();
}

int main (int argc, char **argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

glutInitWindowSize(500,500);
glutCreateWindow("2D Transformation on 2D objects");
myinit();

int rot_id = glutCreateMenu(rot_menu);
glutAddMenuEntry("Rotate about z(60)",2);
glutAddMenuEntry("Rotate about piz(0,160)",3);
glutCreateMenu(menu); //main menu
glutAddMenuEntry("Exit",0);
glutAddMenuEntry("Original",-1);
glutAddMenuEntry("Translate",1);
glutAddMenuEntry("Scale",4);
glutAddSubMenu("Rotate",rot_id);

glutAttachMenu(GLUT_RIGHT_BUTTON);

glutDisplayFunc(display);

glutMainLoop();
return 0;
}

#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <time.h>
#define SPEED 10.0


float i=0.0;    //movement of car

void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}


void draw_object()
{
    int l;

//sky
glColor3f(0.0,0.9,1.0);
glBegin(GL_POLYGON);
glVertex2f(0,450);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,450);
glEnd();

//sun


	for(l=0;l<=40;l++)
{
		glColor3f(1.0,0.9,0.0);
		draw_circle(100,620,l);
}

//grass
glColor3f(0.0,0.9,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,450);
glVertex2f(1100,450);
glVertex2f(1100,160);
glEnd();

//pond
glColor3f(0.0,0.9,0.9);
glBegin(GL_POLYGON);
glVertex2f(25,350);
glVertex2f(25,375);
glVertex2f(50,400);
glVertex2f(75,410);
glVertex2f(100,420);
glVertex2f(200,420);
glVertex2f(225,410);
glVertex2f(250,405);
glVertex2f(275,390);
glVertex2f(300,375);
glVertex2f(310,350);
glVertex2f(300,320);
glVertex2f(275,300);
glVertex2f(250,295);
glVertex2f(225,290);
glVertex2f(200,285);
glVertex2f(175,280);
glVertex2f(150,280);
glVertex2f(125,280);
glVertex2f(100,290);
glVertex2f(75,300);
glVertex2f(50,310);
glEnd();


//road boundary
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0,150);
glVertex2f(0,160);
glVertex2f(1100,160);
glVertex2f(1100,150);
glEnd();

//road
glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,150);
glVertex2f(1100,150);
glVertex2f(1100,0);
glEnd();

//tree
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(350,325);
glVertex2f(350,395);
glVertex2f(365,395);
glVertex2f(365,325);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(340,400,l);
		draw_circle(380,400,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(350,440,l);
		draw_circle(370,440,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(360,465,l);

	}

//tree
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(920,325);
glVertex2f(920,395);
glVertex2f(935,395);
glVertex2f(935,325);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(910,400,l);
		draw_circle(940,400,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(920,440,l);
		draw_circle(930,440,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(925,465,l);

	}

//house
glColor3f(0.0,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(600,375);
glVertex2f(600,450);
glVertex2f(650,525);
glVertex2f(700,450);
glVertex2f(700,375);
glEnd();

//door
glColor3f(0.5,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(640,375);
glVertex2f(640,410);
glVertex2f(660,410);
glVertex2f(660,375);
glEnd();

//roof
glColor3f(0.5,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(700,450);
glVertex2f(650,525);
glVertex2f(750,525);
glVertex2f(780,450);
glEnd();

//
glColor3f(0.8,0.8,0.2);
glBegin(GL_POLYGON);
glVertex2f(700,375);
glVertex2f(700,450);
glVertex2f(780,450);
glVertex2f(780,375);
glEnd();

//window
glColor3f(0.5,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(725,400);
glVertex2f(725,420);
glVertex2f(740,420);
glVertex2f(740,400);
glEnd();

//bus
int add_shift=700;
glColor3f(0.7,0.0,0.9);
glBegin(GL_POLYGON);
glVertex2f(350-add_shift+i,50);
glVertex2f(350-add_shift+i,275);
glVertex2f(722-add_shift+i,275);
glVertex2f(750-add_shift+i,175);
glVertex2f(750-add_shift+i,50);
glEnd();


glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(650-add_shift+i,175);
glVertex2f(650-add_shift+i,260);
glVertex2f(720-add_shift+i,260);
glVertex2f(745-add_shift+i,175);
glEnd();


glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(550-add_shift+i,175);
glVertex2f(550-add_shift+i,260);
glVertex2f(625-add_shift+i,260);
glVertex2f(625-add_shift+i,175);
glEnd();


glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(450-add_shift+i,175);
glVertex2f(450-add_shift+i,260);
glVertex2f(525-add_shift+i,260);
glVertex2f(525-add_shift+i,175);
glEnd();


glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(375-add_shift+i,175);
glVertex2f(375-add_shift+i,260);
glVertex2f(425-add_shift+i,260);
glVertex2f(425-add_shift+i,175);
glEnd();

int shift=20+add_shift;

int angle=-30;
if(i==820)
{   glPushMatrix();
    glTranslatef(675-shift+i,175, 0);
    glRotatef(angle, 0,0,1);
    glTranslatef(-(675-shift+i),-175, 0);
}
for(l=10;l<=10;l++)
{
    glColor3f(0.0,0.0,0.0);
    draw_circle(685-shift+i,220,l+3);

    glEnd();
}

for(l=0;l<=1;l++)
{
    glColor3f(0.0,0.0,0.0);
    draw_circle(690-shift+i,225,l);
    draw_circle(683-shift+i,222,l);
    draw_circle(688-shift+i,215,l);
    glEnd();
}

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(685-shift+i,210);
glVertex2f(685-shift+i,198);


glVertex2f(685-shift+i,198);
glVertex2f(675-shift+i,190);

glVertex2f(685-shift+i,198);
glVertex2f(695-shift+i,190);

glVertex2f(695-shift+i,190);
glVertex2f(695-shift+i,175);

glVertex2f(675-shift+i,190);
glVertex2f(675-shift+i,175);
glEnd();
if(i==820){
    glPopMatrix();
}

//2nd person
shift=120+add_shift;
if(i==820)
{   glPushMatrix();
    glTranslatef(675-shift+i,175, 0);
    glRotatef(angle, 0,0,1);
    glTranslatef(-(675-shift+i),-175, 0);
}
for(l=10;l<=10;l++)
{
    glColor3f(0.0,0.0,0.0);
    draw_circle(685-shift+i,220,l+3);

    glEnd();
}

for(l=0;l<=1;l++)
{
    glColor3f(0.0,0.0,0.0);
    draw_circle(690-shift+i,225,l);
    draw_circle(683-shift+i,222,l);
    draw_circle(688-shift+i,215,l);
    glEnd();
}

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(685-shift+i,210);
glVertex2f(685-shift+i,198);


glVertex2f(685-shift+i,198);
glVertex2f(675-shift+i,190);

glVertex2f(685-shift+i,198);
glVertex2f(695-shift+i,190);

glVertex2f(695-shift+i,190);
glVertex2f(695-shift+i,175);

glVertex2f(675-shift+i,190);
glVertex2f(675-shift+i,175);
glEnd();
if(i==820){
    glPopMatrix();
}

//3rd person
shift=220+add_shift;
if(i==820)
{   glPushMatrix();
    glTranslatef(675-shift+i,175, 0);
    glRotatef(angle, 0,0,1);
    glTranslatef(-(675-shift+i),-175, 0);
}
for(l=10;l<=10;l++)
{
    glColor3f(0.0,0.0,0.0);
    draw_circle(685-shift+i,220,l+3);

    glEnd();
}

for(l=0;l<=1;l++)
{
    glColor3f(0.0,0.0,0.0);
    draw_circle(690-shift+i,225,l);
    draw_circle(683-shift+i,222,l);
    draw_circle(688-shift+i,215,l);
    glEnd();
}

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(685-shift+i,210);
glVertex2f(685-shift+i,198);


glVertex2f(685-shift+i,198);
glVertex2f(675-shift+i,190);

glVertex2f(685-shift+i,198);
glVertex2f(695-shift+i,190);

glVertex2f(695-shift+i,190);
glVertex2f(695-shift+i,175);

glVertex2f(675-shift+i,190);
glVertex2f(675-shift+i,175);
glEnd();
if(i==820){
    glPopMatrix();
}
//4th person
shift=295+add_shift;
if(i==820)
{   glPushMatrix();
    glTranslatef(675-shift+i,175, 0);
    glRotatef(angle, 0,0,1);
    glTranslatef(-(675-shift+i),-175, 0);
}
for(l=10;l<=10;l++)
{
    glColor3f(0.0,0.0,0.0);
    draw_circle(685-shift+i,220,l+3);

    glEnd();
}

for(l=0;l<=1;l++)
{
    glColor3f(0.0,0.0,0.0);
    draw_circle(690-shift+i,225,l);
    draw_circle(683-shift+i,222,l);
    draw_circle(688-shift+i,215,l);
    glEnd();
}

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(685-shift+i,210);
glVertex2f(685-shift+i,198);


glVertex2f(685-shift+i,198);
glVertex2f(675-shift+i,190);

glVertex2f(685-shift+i,198);
glVertex2f(695-shift+i,190);

glVertex2f(695-shift+i,190);
glVertex2f(695-shift+i,175);

glVertex2f(675-shift+i,190);
glVertex2f(675-shift+i,175);
glEnd();
if(i==820){
    glPopMatrix();
}

// additional polygon to hide additional lines of persons
glColor3f(0.7,0.0,0.9);
glBegin(GL_POLYGON);
glVertex2f(375-add_shift+i,175);
glVertex2f(745-add_shift+i,175);
glVertex2f(745-add_shift+i,160);
glVertex2f(375-add_shift+i,160);
glEnd();
//wheels

for(l=0;l<30;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(450-add_shift+i,50,l);
	draw_circle(625-add_shift+i,50,l);
   }

glFlush();
}

void idle()
{
glClearColor(1.0,1.0,1.0,1.0);

if(i==820)
{
     i=i;
	 time_t retTime;
     retTime = time(0) + 1;
     while (time(0) < retTime);
	 i++;
}
else
{
     i+=SPEED/10;
}

if(i>1600)
{
    i=0.0;
}

glutPostRedisplay();

}

void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0,1100.0,0.0,700.0,0.0,1100.0);

}

void display()
{

glClear(GL_COLOR_BUFFER_BIT);
draw_object();
glFlush();
}

int main(int argc,char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1300.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Newton's First Law");
	glutDisplayFunc(display);
    glutIdleFunc(idle);
	myinit();
	glutMainLoop();
	return 0;
}

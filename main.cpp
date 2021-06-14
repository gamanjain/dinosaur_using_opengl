#include <stdlib.h>
#include <stdio.h>
#include "GL/glut.h"
#include "globaldeclare.h"
#include "dino.h"
#include "dino2.h"
#include "dino3.h"
#include "dinoRight.h"
#include "scene1.h"
#include "scene1_animation.h"
#include "intro.h"
#include "asteroid.h"
#include "space.h"
void display6(void);
void keyFun(unsigned char key,int x,int y);

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 600, 0, 500);
	glMatrixMode(GL_MODELVIEW);
	tx=120;
    transx=1.0;
    tranx=0.0;
    transx1=0.0;
    ty1=ty2=ty3=0.0;
    bruh=1;
    slide_cloudL=0.0;
    slide_cloudR=0.0;
}

void Timer(int value) {
	if (value)glutPostRedisplay();
	glutTimerFunc(300, Timer, value);
}

void Visibility(GLint state) {
	switch (state) {
	case GLUT_VISIBLE:
		Timer(1);
		break;
	case GLUT_NOT_VISIBLE:
		Timer(0);
		break;
	default:
		break;
	}
}
void display1(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	////Animation happens here
	frame++;
	if (isRunning) {
		scene1_idle();
	}

    scene1();
	scene1_animation(0);
	dinoLeftAnim(205,105);
    dinoLeft();

	if (frame > 4700 ) {
		frame = 0;
		isRunning = false;
	}
	glutSwapBuffers();
	glFlush();
}
void display2(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	////Animation happens here
    scene1_idle();

    scene1();
    scene1_animation(0);
    dino2Left(0,0);
    dino2Left_Anim(100,0);

	if (frame > 4700 ) {
		frame = 0;
		isRunning = false;
	}
	glutSwapBuffers();
	glFlush();
}
void display3(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	////Animation happens here
    scene1_idle();

    scene1();
    scene1_animation(0);
    dino3Left(100,100,0);
    dino3Left(130,130,1);
    dino3Left(180,100,1);
    dino3Left(230,130,2);
    dino3Left(225,115,2);
    dino3Left(185,135,2);
    dino3LeftStat(205,95);

	if (frame > 4700 ) {
		frame = 0;
		isRunning = false;
	}
	glutSwapBuffers();
	glFlush();
}
void display4(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	////Animation happens here
    scene1_idle();

    scene1();
    scene1_animation(0);
    asteroid();

	if (frame > 4700 ) {
		frame = 0;
		isRunning = false;
	}
	glutSwapBuffers();
	glFlush();
}
void display5(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	////Animation happens here
    scene1_idle();

    scene1();
    scene1_animation(-1);
    dino3Left(100,100,0);
    dino3Left(130,130,1);
    dino3Left(180,100,1);
    dino3Left(230,130,2);
    dino3Left(225,115,2);
    dino3Left(185,135,2);
    scene1_animation(0);
    dinoLeftAnim(205,105);
    if(bruh==1){
        dinoLeft();
        dino2Left(100,0);
        dino3LeftStat(205,95);
    }
    dino2Left_Anim(100,0);
    asteroid();
	if (bruh==43) {
        dinoy();
        dino2y(100,0);
        dino3y(205,95);
	}
	if(slide_cloudR<-600){
        glutDisplayFunc(display6);
        glutKeyboardFunc(keyFun);
        glutPostRedisplay();
	}
	glutSwapBuffers();
	glFlush();
}
void display6(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	////Animation happens here
    space();
    dino2_Space(100,300);
    dino1_Space(0,0);
    dino3_Space(0,0);

	glutSwapBuffers();
	glFlush();
}
void keyFun(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 116:
            init();
            glutDisplayFunc(display1);
            glutMouseFunc(nameDisplay1);
            glutKeyboardFunc(keyFun);
            glutPostRedisplay();
            break;
        case 98:
            init();
            glutDisplayFunc(display2);
            glutMouseFunc(nameDisplay2);
            glutKeyboardFunc(keyFun);
            glutPostRedisplay();
            break;
        case 99:
            init();
            glutDisplayFunc(display3);
            glutMouseFunc(nameDisplay3);
            glutKeyboardFunc(keyFun);
            glFlush();
            glutPostRedisplay();
            break;
        case 13:
            init();
            glutDisplayFunc(display5);
            glutKeyboardFunc(keyFun);
            glutPostRedisplay();
            break;
        case 97:
            init();
            glutDisplayFunc(display4);
            glutKeyboardFunc(keyFun);
            glutPostRedisplay();
            break;
        case 115:
            init();
            glutDisplayFunc(display6);
            glutKeyboardFunc(keyFun);
            glutPostRedisplay();
            break;
    }
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1300, 800);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Dinosaur Extinction Theory");
    myinit();
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyFun);

	glutTimerFunc(0, Timer, 0);
	glutVisibilityFunc(Visibility);

	glutMainLoop();
	return 0;
}

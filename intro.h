#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

const int fact = 3;
const int x = 80;
const double DEG2RAD = 3.1415926535897932384/180;

void drawstring(float x,float y,float z,char *string)
{
     char *c;
     glRasterPos3f(x,y,z);
     for(c=string;*c!='\0';c++)
     {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
     }
}

//main code
void myinit ()
{
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glPointSize(4.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, 902.0, 0.0, 684.0);
}


void myDisplay(void)
{
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0,0.0,0.0);
        drawstring(325,585,0.0,"Dinosaur Extinction Theory");
        glColor3f(1.0,0.0,0.0);
        drawstring(220,510,0.0,"Gaman Jain");
        drawstring(220,480,0.0,"Hardhik H. Salian");
        glColor3f(1.0,0.0,0.0);
        drawstring(550,510,0.0,"4NM18CS057");
        drawstring(550,480,0.0,"4NM18CS063");
        drawstring(325,360,0.0,"Press A: Asteroid animation");
        drawstring(325,330,0.0,"Press B: Brachiosaurus");
        drawstring(325,300,0.0,"Press C: Compsognathus");
        drawstring(325,270,0.0,"Press T: Tyrannosaurus Rex");
        drawstring(325,240,0.0,"Press S: Space Animation");
        drawstring(310,150,0.0,"Press ENTER for extinction animation");
        glutSwapBuffers();
}

void renderSpacedBitmapString(float x, float y, void *font, char *string) {
	char *c;
	int x1 = x;
	for (c = string; *c != '\0'; c++) {
		glRasterPos2f(x1, y);
		glutBitmapCharacter(font, *c);
		x1 = x1 + glutBitmapWidth(font, *c);
	}
}

void nameDisplay1(int button, int state, int x, int y)
{
        if(button==GLUT_LEFT_BUTTON){
            //glViewport(0,0,1300,800);
            glColor3f(0.0, 0.0, 0.0);
            glBegin(GL_POLYGON);
            glVertex2f(370,195);
            glVertex2f(580,195);
            glVertex2f(580,85);
            glVertex2f(370,85);
            glVertex2f(370,195);
            glEnd();
            glColor3f(1.0, 1.0, 1.0);
            drawstring(380,175,0.0, "T-Rex (Tyrannosaurus Rex):");
            drawstring(380,160,0.0, "Tyrannosaurus Rex(T-Rex) was a large");
            drawstring(380,145,0.0, "carnivorous dinosaur that lived in ");
            drawstring(380,130,0.0, "the cretaceous period. It could grow");
            drawstring(380,115,0.0, "upto 12.3 metres in length(40 feet) in");
            drawstring(380,100,0.0, "and 12 feet high.");
            Sleep(5000);
            glutSwapBuffers();
        }
}

void nameDisplay2(int button, int state, int x, int y)
{
        if(button==GLUT_LEFT_BUTTON){
            //glViewport(0,0,1300,800);
            glColor3f(0.0, 0.0, 0.0);
            glBegin(GL_POLYGON);
            glVertex2f(370,195);
            glVertex2f(580,195);
            glVertex2f(580,100);
            glVertex2f(370,100);
            glVertex2f(370,195);
            glEnd();
            glColor3f(1.0,1.0,1.0);
            drawstring(380,175,0.0, "Brachiosaurus:");
            drawstring(380,160,0.0, "Brachiosaurus was a herbivorous dinosaur");
            drawstring(380,145,0.0, "that lived in the Late Jurassic period.");
            drawstring(380,130,0.0, "It could grow upto 21 metres in length");
            drawstring(380,115,0.0, "and could weigh upto 56 metric tons.");
            Sleep(5000);
            glutSwapBuffers();
        }
}

void nameDisplay3(int button, int state, int x, int y)
{
        if(button==GLUT_LEFT_BUTTON){
            //glViewport(0,0,1300,800);
            glColor3f(0.0, 0.0, 0.0);
            glBegin(GL_POLYGON);
            glVertex2f(370,195);
            glVertex2f(580,195);
            glVertex2f(580,100);
            glVertex2f(370,100);
            glVertex2f(370,195);
            glEnd();
            glColor3f(1.0,1.0,1.0);
            drawstring(380,175,0.0, "Compsognathus:");
            drawstring(380,160,0.0, "Compsognathus was a very small bipedal");
            drawstring(380,145,0.0, "carnivorous dinosaur that lived in the Late");
            drawstring(380,130,0.0, "Jurassic period. It could grow upto the size");
            drawstring(380,115,0.0, "of a turkey and they hunted in groups.");
            Sleep(5000);
            glutSwapBuffers();
        }
}




























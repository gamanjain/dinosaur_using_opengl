#include <stdio.h>
int count=0;

float tranx=0.0,tx3=0.0,ty3=0.0;
void drawCircle2(int r, int  xc, int yc) {
	int x = 0, y = r;
	int d;
	d = 1 - r;

	while (x < y)
	{
		glBegin(GL_POLYGON);
		glVertex2i(y + xc, x + yc);
		glVertex2i(x + xc, y + yc);
		glVertex2i(x + xc, -y + yc);
		glVertex2i(y + xc, -x + yc);
		glVertex2i(-y + xc, -x + yc);
		glVertex2i(-x + xc, -y + yc);
		glVertex2i(-x + xc, y + yc);
		glVertex2i(-y + xc, x + yc);
		glEnd();

		if (d < 0)
		{
			x = x + 1;
			d = d + 2 * x + 1;
		}
		else
		{
			x = x + 1;
			y = y - 1;
			d = d + ((2 * x) + 1) - (2 * y);
		}
	}//end while
}//end drawCircle

void drawEllipse2(int rx, int ry, int xc, int yc) {
	float a = rx;
	float b = ry;
	float x = 0;
	float y = ry;
	float d2;
	float d1 = b - (a*a*ry) + (a*a*0.25);

	while (2 * b*b*x < 2 * a*a*y)
	{
		glBegin(GL_POLYGON);
		glVertex2f(x + xc, y + yc);
		glVertex2f(x + xc, -y + yc);
		glVertex2f(-x + xc, -y + yc);
		glVertex2f(-x + xc, y + yc);
		glEnd();

		if (d1 < 0)
		{
			x = x + 1;
			d1 = d1 + (2 * b*b*x) + (b*b);
		}
		else
		{
			x = x + 1;
			y = y - 1;
			d1 = d1 + (2 * b*b*x) - (2 * a*a*y) + (b*b);
		}
	}//end while

	d2 = b*b*((x + 0.5)*(x + 0.5)) + (a*a*((y - 1)*(y - 1))) - (a*a*b*b);
	while (y > 0 || y < 0)
	{
		glBegin(GL_POLYGON);
		glVertex2f(x + xc, y + yc);
		glVertex2f(x + xc, -y + yc);
		glVertex2f(-x + xc, -y + yc);
		glVertex2f(-x + xc, y + yc);
		glEnd();

		if (d2 > 0)
		{
			y = y - 1;
			d2 = d2 - (2 * a*a*y) + (a*a);
		}
		else
		{
			x = x + 1; y = y - 1;
			d2 = d2 + (2 * b*b*x) - (2 * a*a*y) + (a*a);
		}
	}
}

void dino3Left_LeftArm(int tranx) {
	glColor3f(0.666, 0.266, 0);
	drawEllipse2(10, 10, 260+tranx, 250);
	glBegin(GL_POLYGON);
	glVertex2f(260+tranx, 250);
	glVertex2f(270+tranx, 250);
	glVertex2f(280+tranx, 240);
	glVertex2f(290+tranx, 240);
	glVertex2f(290+tranx, 230);
	glVertex2f(270+tranx, 230);
	glVertex2f(260+tranx, 240);
	glVertex2f(260+tranx, 250);
	glEnd();

	drawEllipse(10, 10, 290+tranx, 235);

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0);
	glVertex2f(295+tranx, 230);
	glVertex2f(300+tranx, 225);
	glVertex2f(295+tranx, 220);
	glVertex2f(295+tranx, 225);
	glVertex2f(290+tranx, 225);
	glVertex2f(290+tranx, 230);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0);
	glVertex2f(300+tranx, 235);
	glVertex2f(305+tranx, 230);
	glVertex2f(300+tranx, 225);
	glVertex2f(300+tranx, 230);
	glVertex2f(295+tranx, 230);
	glVertex2f(295+tranx, 235);
	glEnd();
}

void dino3Left_RightArm(int tranx) {
	glColor3f(0.0, 0.0, 0);
	drawEllipse2(10, 10, 270+tranx, 250);
	glBegin(GL_POLYGON);
	glVertex2f(270+tranx, 250);
	glVertex2f(280+tranx, 250);
	glVertex2f(290+tranx, 240);
	glVertex2f(300+tranx, 240);
	glVertex2f(300+tranx, 230);
	glVertex2f(280+tranx, 230);
	glVertex2f(270+tranx, 240);
	glVertex2f(270+tranx, 250);
	glEnd();

	drawEllipse2(10, 10, 300+tranx, 235);

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0);
	glVertex2f(305+tranx, 230);
	glVertex2f(310+tranx, 225);
	glVertex2f(305+tranx, 220);
	glVertex2f(305+tranx, 225);
	glVertex2f(300+tranx, 225);
	glVertex2f(300+tranx, 230);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0);
	glVertex2f(310+tranx, 235);
	glVertex2f(315+tranx, 230);
	glVertex2f(310+tranx, 225);
	glVertex2f(310+tranx, 230);
	glVertex2f(305+tranx, 230);
	glVertex2f(305+tranx, 235);
	glEnd();
}

void dino3Left_HeadAndNeck(int tranx) {
	glBegin(GL_POLYGON);
	glColor3f(0.666, 0.266, 0);
	glVertex2f(300+tranx, 350);
	glVertex2f(350+tranx, 340);
	glVertex2f(360+tranx, 330);
	glVertex2f(360+tranx, 320);
	glVertex2f(350+tranx, 320);
	glVertex2f(320+tranx, 310);
	glVertex2f(340+tranx, 310);
	glVertex2f(360+tranx, 310);
	glVertex2f(350+tranx, 300);
	glVertex2f(360+tranx, 310);
	glVertex2f(310+tranx, 290);
	glVertex2f(300+tranx, 300);
	glVertex2f(300+tranx, 290);
	glVertex2f(270+tranx, 245);
	glVertex2f(270+tranx, 300);
	glVertex2f(300+tranx, 350);
	glEnd();

	drawEllipse2(10, 30, 270+tranx, 270);

	glColor3f(1.0, 1.0, 1.0);
	drawCircle2(10, 310+tranx, 340);

	glPointSize(5.0);
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(310+tranx, 340);
	glEnd();
}

void dino3Left_Body(int tranx) {
	glBegin(GL_POLYGON);
	glColor3f(0.501, 0.2, 0);
	glVertex2f(270+tranx, 300);
	glVertex2f(270+tranx, 240);
	glVertex2f(250+tranx, 230);
	glVertex2f(160+tranx, 250);
	glVertex2f(180+tranx, 310);
	glVertex2f(260+tranx, 310);
	glVertex2f(270+tranx, 300);
	glEnd();
}

void dino3Left_Tail(int tranx) {
	glBegin(GL_POLYGON);
	glColor3f(0.501, 0.2, 0);
	glVertex2f(30+tranx, 300);
	glVertex2f(150+tranx, 300);
	glVertex2f(220+tranx, 310);
	glVertex2f(220+tranx, 250);
	glVertex2f(220+tranx, 250);
	glVertex2f(150+tranx, 270);
	glVertex2f(30+tranx, 300);
	glEnd();
}

void dino3Left_LegLeft(int tranx) {
	glColor3f(0.666, 0.266, 0);
	drawEllipse2(30, 30, 195+tranx, 250);

	glBegin(GL_POLYGON);
	//glColor3f(0.0, 0.0, 0);
	glVertex2f(225+tranx, 245);
	glVertex2f(200+tranx, 200);
	glVertex2f(170+tranx, 200);
	glVertex2f(190+tranx, 245);
	glVertex2f(180+tranx, 180);
	glVertex2f(170+tranx, 180);
	glVertex2f(170+tranx, 160);
	glVertex2f(170+tranx, 200);
	glEnd();

	drawEllipse2(15, 10, 185+tranx, 165);

	//Feet Claws
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0);
	glVertex2f(200+tranx, 160);
	glVertex2f(195+tranx, 165);
	glVertex2f(190+tranx, 165);
	glVertex2f(190+tranx, 160);
	glVertex2f(200+tranx, 160);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0);
	glVertex2f(205+tranx, 165);
	glVertex2f(200+tranx, 170);
	glVertex2f(195+tranx, 170);
	glVertex2f(195+tranx, 165);
	glVertex2f(205+tranx, 165);
	glEnd();
}

void dino3Left_LegRight(int tranx) {
	glColor3f(0.0, 0.0, 0.0);
	drawEllipse2(30, 30, 205+tranx, 250);

	glBegin(GL_POLYGON);
	//glColor3f(0.0, 0.0, 0);
	glVertex2f(235+tranx, 245);
	glVertex2f(210+tranx, 200);
	glVertex2f(180+tranx, 200);
	glVertex2f(200+tranx, 245);
	glVertex2f(190+tranx, 180);
	glVertex2f(180+tranx, 180);
	glVertex2f(180+tranx, 160);
	glVertex2f(180+tranx, 200);
	glVertex2f(235+tranx, 245);
	glEnd();

	drawEllipse2(15, 10, 195+tranx, 165);

	//Feet Claws
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0);
	glVertex2f(210+tranx, 160);
	glVertex2f(205+tranx, 165);
	glVertex2f(200+tranx, 165);
	glVertex2f(200+tranx, 160);
	glVertex2f(210+tranx, 160);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0);
	glVertex2f(215+tranx, 165);
	glVertex2f(210+tranx, 170);
	glVertex2f(200+tranx, 170);
	glVertex2f(200+tranx, 165);
	glVertex2f(210+tranx, 165);
	glEnd();
}

void dino3Left(int transx,int ty, int m) {
    glPushMatrix();
    glTranslatef(transx,ty,0);
    glScalef(0.1,0.1,0.1);
	dino3Left_Tail(tranx);
	dino3Left_LegRight(tranx);
	dino3Left_RightArm(tranx);
	dino3Left_Body(tranx);
	dino3Left_HeadAndNeck(tranx);
	dino3Left_LegLeft(tranx);
	dino3Left_LeftArm(tranx);
	if(m==1)
        tranx+=3;
	glPopMatrix();
	glutPostRedisplay();
}
void dino3LeftStat(int tx,int ty) {
    glPushMatrix();
    glTranslatef(tx,ty,0);
    glScalef(0.1,0.1,1);
	dino3Left_Tail(0);
	dino3Left_LegRight(0);
	dino3Left_RightArm(0);
	dino3Left_Body(0);
	dino3Left_HeadAndNeck(0);
	dino3Left_LegLeft(0);
	dino3Left_LeftArm(0);
	glPopMatrix();
	glutPostRedisplay();
}
void dino3y(int tx,int ty) {
    glPushMatrix();
    glTranslatef(tx+tx3,ty+ty3,0);
    glScalef(0.1,0.1,1);
	dino3Left_Tail(0);
	dino3Left_LegRight(0);
	dino3Left_RightArm(0);
	dino3Left_Body(0);
	dino3Left_HeadAndNeck(0);
	dino3Left_LegLeft(0);
	dino3Left_LeftArm(0);
	glPopMatrix();
	ty3+=1;
	glutPostRedisplay();
}
float spx3=0.0,spy3=0.0,decx3=50.0,decy3=40.0,angle3=0.0;
void dino3_Space(int x,int y){
    tranx=0;
    tx3=0.0;
    ty3=0.0;
    glPushMatrix();
    glTranslatef(-x+spx3,-y+spy3,0);
    glScalef(0.1,0.1,1);
    glRotatef(angle3,0,0,1.0);
    glTranslatef(x-spx3,y-spy3,0);
	dino3Left_Tail(0);
	dino3Left_LegRight(0);
	dino3Left_RightArm(0);
	dino3Left_Body(0);
	dino3Left_HeadAndNeck(0);
	dino3Left_LegLeft(0);
	dino3Left_LeftArm(0);
	glPopMatrix();
    spx3+=decx3;
    spy3+=decy3;
    if(decx3>0&&decy3>0){
        decx3-=5;
        decy3-=5;
    }
    else
        decx3=decy3=0;
	angle3+=12;
}



#include<stdio.h>
float tx2=0.0,ty2=0.0;
void drawCircle1(int r, int  xc, int yc) {
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

void drawEllipse1(int rx, int ry, int xc, int yc) {
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

float tx=120,t=25;
void dino2Left_HeadAndNeck(int m,int tp,int tq) {
    if(m){
        glPushMatrix();
        glTranslatef(tp,tq,0);
    }
    int tx1=100;
	glBegin(GL_POLYGON);
	glColor3f(0.666, 0.266, 0);
	glVertex2f(300+tx*m+tx1, 350+t+tx1);
	glVertex2f(350+tx*m+tx1, 340+t+tx1);
	glVertex2f(360+tx*m+tx1, 330+t+tx1);
	glVertex2f(360+tx*m+tx1, 320+t+tx1);
	glVertex2f(350+tx*m+tx1, 320+t+tx1);
	glVertex2f(320+tx*m+tx1, 310+t+tx1);
	glVertex2f(340+tx*m+tx1, 310+t+tx1);
	glVertex2f(360+tx*m+tx1, 310+t+tx1);
	glVertex2f(350+tx*m+tx1, 300+t+tx1);
	glVertex2f(360+tx*m+tx1, 310+t+tx1);
	glVertex2f(310+tx*m+tx1, 290+t+tx1);
	glVertex2f(300+tx*m+tx1, 300+t+tx1);
	glVertex2f(300+tx*m+tx1, 290+t+tx1);
	glVertex2f(170+tx*m+tx1, 95+t+tx1);
	glVertex2f(170+tx*m+tx1, 200+t+tx1);
	glVertex2f(300+tx*m+tx1, 350+t+tx1);
	glEnd();

	drawEllipse1(10, 60, 270+tx*m, 240+t);

	glColor3f(255.0, 255.0, 255.0);
	drawCircle1(5, 310+tx*m+tx1, 340+t+tx1);

	glPointSize(5.0);
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(310+tx*m+tx1, 340+t+tx1);
	glEnd();
	if(m){
        glPopMatrix();
	}
}

void dino2Left_Body(int m,int tp,int tq) {
    if(m){
        glPushMatrix();
        glTranslatef(tp,tq,0);
    }
	glBegin(GL_POLYGON);
	glColor3f(0.501, 0.2, 0);
	glVertex2f(270+tx*m, 300+t);
	glVertex2f(270+tx*m, 180+t);
	glVertex2f(140+tx*m, 170+t);
	glVertex2f(95+tx*m, 210+t);
	glVertex2f(-20+tx*m, 70);
	glVertex2f(95+tx*m, 285+t);
	glVertex2f(140+tx*m, 310+t);
	glVertex2f(250+tx*m, 310+t);
	glVertex2f(270+tx*m, 300+t);
	glEnd();
	if(m){
        glPopMatrix();
	}
}
void dino2Left_LegLeft(int x1,int y1,int f,int m,int tp,int tq) {
	if(f)
        glColor3f(0.666, 0.266, 0);
    else glColor3f(0.0,0.0,0.0);
    if(m){
        glPushMatrix();
        glTranslatef(tp,tq,0);
        tp+=5;
    }
	drawEllipse1(30, 30, 160+x1+tx*m, 220+y1);

	glBegin(GL_POLYGON);
	//glColor3f(0.0, 0.0, 0);
	glVertex2f(142+x1+tx*m, 200+y1);
	glVertex2f(142+x1+tx*m, 90+y1);
	glVertex2f(178+x1+tx*m, 90+y1);
	glVertex2f(178+x1+tx*m, 200+y1);
	glVertex2f(142+x1+tx*m, 200+y1);
	glEnd();

	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(151+x1+tx*m, 95+y1);
	glVertex2f(160+x1+tx*m, 95+y1);
	glVertex2f(169+x1+tx*m, 95+y1);
	glEnd();
	if(m){
	    glPopMatrix();
	}
}

void dino2Left(int tp,int tq) {
    glPushMatrix();
    glTranslatef(30,70,0);
    glScalef(0.6,0.6,1);
    dino2Left_LegLeft(7,0,0,0,tp,tq);
	dino2Left_LegLeft(93,8,0,0,tp,tq);
	dino2Left_Body(0,tp,tq);
	dino2Left_HeadAndNeck(0,tp,tq);
	dino2Left_LegLeft(0,0,1,0,tp,tq);
	dino2Left_LegLeft(87,8,1,0,tp,tq);
	glPopMatrix();
}
void dino2y(int tp,int tq) {
    glPushMatrix();
    glTranslatef(30+tx2,70+ty2,0);
    glScalef(0.6,0.6,1);
    dino2Left_LegLeft(7,0,0,0,tp,tq);
	dino2Left_LegLeft(93,8,0,0,tp,tq);
	dino2Left_Body(0,tp,tq);
	dino2Left_HeadAndNeck(0,tp,tq);
	dino2Left_LegLeft(0,0,1,0,tp,tq);
	dino2Left_LegLeft(87,8,1,0,tp,tq);
	ty2+=1;
	glPopMatrix();
}

void dino2Left_Anim(int tp,int tq) {
    glPushMatrix();
    glScalef(0.6,0.6,1);
    dino2Left_LegLeft(7,0,0,1,tp,tq);
	dino2Left_LegLeft(93,8,0,1,tp,tq);
	dino2Left_Body(1,tp,tq);
	dino2Left_HeadAndNeck(1,tp,tq);
	dino2Left_LegLeft(0,0,1,1,tp,tq);
	dino2Left_LegLeft(87,8,1,1,tp,tq);
	tx+=0.3;
	glPopMatrix();
	glutPostRedisplay();
}
float spx2=0.0,spy2=0.0,decx2=50.0,decy2=40.0,angle2=0.0;
void dino2_Space(int tp,int tq){
    tx2=0.0;
    ty2=0.0;
    tx=t=0;
    glPushMatrix();
    glTranslatef(-tp+spx2+215,-tq+spy2+270,0);
    glScalef(0.6,0.6,1);
    glRotatef(angle2,0,0,1.0);
    glTranslatef(tp-spx2-215,tq-spy2-270,0);
    dino2Left_LegLeft(7,0,0,1,0,0);
	dino2Left_LegLeft(93,8,0,1,0,0);
	dino2Left_Body(1,0,0);
	dino2Left_HeadAndNeck(1,0,0);
	dino2Left_LegLeft(0,0,1,1,0,0);
	dino2Left_LegLeft(87,8,1,1,0,0);
    spx2+=decx2;
    spy2+=decy2;
    if(decx2>0&&decy2>0){
        decx2-=5;
        decy2-=5;
    }
    else
        decx2=decy2=0;
	angle2+=11;
	glPopMatrix();
}

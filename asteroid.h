#include<stdio.h>
float transx=0.0,scalex=1.0;
int bruh=1;
void drawCircle4(int r, int  xc, int yc) {
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

void asteroid(){
    glPushMatrix();
    glColor3f(1.0,0.0,0.0);
    //glScalef(scalex,scalex,1);
    if(transx<150){
        glBegin(GL_POLYGON);
        glVertex2f(520 - transx,440 - transx);
        glVertex2f(520 - transx,480 - transx);
        glVertex2f(590 - transx,510 - transx);
        glVertex2f(570 - transx,410 - transx);
        glVertex2f(540 - transx,415 - transx);
        glVertex2f(520 - transx,440 - transx);
        glEnd();
    }
    glColor3f(0.40,0.40,0.40);
    drawCircle(20,550 - transx,450 - transx);
    glTranslatef(10,8,0);
    //scalex-=0.001;
    glPopMatrix();
    if(transx<150)
        transx+=0.05;
    else bruh=43;
}

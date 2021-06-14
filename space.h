#include <stdio.h>

void star(int x,int y){
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x,y+50);
    glVertex2f(x+10,y+10);
    glVertex2f(x+50,y);
    glVertex2f(x+10,y-10);
    glVertex2f(x,y-50);
    glVertex2f(x-10,y-10);
    glVertex2f(x-50,y);
    glVertex2f(x-10,y+10);
    glVertex2f(x,y+50);
    glVertex2f(x,y);
    glEnd();
}

void space(){
    int x,y,a;
    float s;
    for(int i=1;i<=200;i++)
    {
        glPushMatrix();
        x=rand();
        y=rand();
        a=rand();
        x%=1000; y%=480; a%=6;
        s=(float)a/50;
        glTranslatef(x,y,0);
        glScalef(s,s,1);
        star(x,y);
        glPopMatrix();
    }
}


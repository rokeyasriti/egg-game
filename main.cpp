#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <conio.h>

using namespace std;

int eggsCaught = 0;
int missedEggs = 0;
int levelCounter = 1;
int points = 0;
//------------------------------------egg coordinates
int eggX, eggY;

//------------------------------------box coordinates
int boxX, boxY;

int s = 0;
float x, y;

// for menu option
int droppedEggs = 0;
int speed1 = 1;
int speed2 = 1.5;
int speed3 = 2;
int speed4 = 2.5;
GLfloat SunPosition = 0.0f;
GLfloat Cloud1Position = 0.0f;
GLfloat Cloud2Position = 0.0f;
GLfloat Cloud1Speed = 3.0f;
GLfloat Cloud2Speed = 2.0f;
GLfloat SunSpeed = 1.2f;

void myinit()
{
    glViewport(0, 0, 600, 800);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, (GLdouble)600, 0, (GLdouble)800);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void update(int value)
{
    if (SunPosition > 0.0)
        SunPosition = -600.0f;

    SunPosition += 1.2 * SunSpeed;

    if (Cloud1Position > 0.0)
        Cloud1Position = -600.8f;

    Cloud1Position += 2 * Cloud1Speed;

    if (Cloud2Position > 0.0)
        Cloud2Position = -600.8f;

    Cloud2Position += 3 * Cloud2Speed;


    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

void sun()
{
    glPushMatrix();
    glTranslatef(SunPosition, 0.0f, 0.0f);
    glColor3f(1, 0.7, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(500 + 80 * cos(i * 3.1416 * i / 180) / 2, 600 + 80 * sin(i * 3.1416 * i / 180) / 2);
    }

    glEnd();
    glPopMatrix();
    glFlush();
}

void cloud1()
{
    glPushMatrix();
    glTranslatef(Cloud1Position, 0.0f, 0.0f);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(100 + 50 * cos(i * 3.1416 * i / 180) / 2, 590 + 50 * sin(i * 3.1416 * i / 180) / 2);
    }

    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(130 + 50 * cos(i * 3.1416 * i / 180) / 2, 580 + 50 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(140 + 50 * cos(i * 3.1416 * i / 180) / 2, 600 + 50 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(170 + 50 * cos(i * 3.1416 * i / 180) / 2, 590 + 50 * sin(i * 3.1416 * i / 180) / 2);
    }

    glEnd();
    glPopMatrix();
    glFlush();
}

void cloud2()
{
    glPushMatrix();
    glTranslatef(Cloud2Position, 0.0f, 0.0f);
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(420 + 45 * cos(i * 3.1416 * i / 180) / 2, 540 + 45 * sin(i * 3.1416 * i / 180) / 2);
    }

    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(455 + 45 * cos(i * 3.1416 * i / 180) / 2, 550 + 45 * sin(i * 3.1416 * i / 180) / 2);
    }

    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(455 + 45 * cos(i * 3.1416 * i / 180) / 2, 530 + 45 * sin(i * 3.1416 * i / 180) / 2);
    }

    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(490 + 45 * cos(i * 3.1416 * i / 180) / 2, 540 + 45 * sin(i * 3.1416 * i / 180) / 2);
    }

    glEnd();
    glPopMatrix();
    glFlush();
}

void line(int i, int j)
{
    glBegin(GL_QUADS);
    glColor3f(1.0, .5, 0.5);
    glVertex2f(0.0 + i, 10.0 + j);
    glVertex2f(0.0 + i, 15.0 + j);
    glVertex2f(600.0 + i, 15.0 + j);
    glVertex2f(600.0 + i, 10.0 + j);
    glEnd();
    glFlush();
}

void backGround(int i, int j)
{
    glColor3f(0, .5, 1);
    glBegin(GL_QUADS);
    glVertex2f(0.0 + i, 0.0 + j);
    glVertex2f(600.0 + i, 0.0 + j);
    glVertex2f(600.0 + i, -500 + j);
    glVertex2f(0.0 + i, -500 + j);
    glEnd();
    glFlush();
}

void ground(int i, int j)
{
    glBegin(GL_QUADS);
    glColor3f(0, 1.0, 0);
    glVertex2f(0.0 + i, 0.0 + j);
    glVertex2f(600.0 + i, 0.0 + j);
    glVertex2f(600.0 + i, -j);
    glVertex2f(0.0 + i, -j);
    glEnd();
}

void egg()
{

    float x, y ;
    int t;
    glColor3f(1.0, 10, 1.0);
    glBegin(GL_POLYGON);
    for (t = 0; t <= 360; t += 1)
    {
        x = eggX + 8 * (cos(t));
        y = eggY + 16 * (sin(t));
        //z = 0;
        glVertex2f(x, y);
    }
    glEnd();
}

void basket(int i, int j)
{
    j = 10;
    //if (i >= 540)i = 540;
    /*glBegin(GL_QUADS);
    glVertex2f(0.0+i,30.0+j);
    glVertex2f(10.0+i,10.0+j);
    glVertex2f(50.0+i,10.0+j);
    glVertex2f(60.0+i,30.0+j);*/
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(0.0 + i, 20.0 + j);
    glVertex2f(50.0 + i, 30.0 + j);
    glVertex2f(50.0 + i, 80.0 + j);
    glVertex2f(00.0 + i, 70.0 + j);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.0 + i, 70.0 + j);
    glVertex2f(-50.0 + i, 80.0 + j);
    glVertex2f(-50.0 + i, 30.0 + j);
    glVertex2f(00.0 + i, 20.0 + j);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.0 + i, 70.0 + j);
    glVertex2f(-50.0 + i, 80.0 + j);
    glVertex2f(0.0 + i, 90.0 + j);
    glVertex2f(50.0 + i, 80.0 + j);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.0 + i, 70.0 + j);
    glVertex2f(-10.0 + i, 50.0 + j);
    glVertex2f(-60.0 + i, 60.0 + j);
    glVertex2f(-50.0 + i, 80.0 + j);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.0 + i, 70.0 + j);
    glVertex2f(10.0 + i, 50.0 + j);
    glVertex2f(60.0 + i, 60.0 + j);
    glVertex2f(50.0 + i, 80.0 + j);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.0 + i, 70.0 + j);
    glVertex2f(0.0 + i, 20.0 + j);

    glVertex2f(0.0 + i, 20.0 + j);
    glVertex2f(50.0 + i, 30.0 + j);

    glVertex2f(50.0 + i, 30.0 + j);
    glVertex2f(50.0 + i, 80.0 + j);

    glVertex2f(50.0 + i, 80.0 + j);
    glVertex2f(0.0 + i, 70.0 + j);

    glVertex2f(0.0 + i, 70.0 + j);
    glVertex2f(-50.0 + i, 80.0 + j);

    glVertex2f(-50.0 + i, 80.0 + j);
    glVertex2f(-50.0 + i, 30.0 + j);

    glVertex2f(-50.0 + i, 30.0 + j);
    glVertex2f(0.0 + i, 20.0 + j);

    glVertex2f(50.0 + i, 80.0 + j);
    glVertex2f(0.0 + i, 90.0 + j);

    glVertex2f(0.0 + i, 90.0 + j);
    glVertex2f(-50.0 + i, 80.0 + j);

    glVertex2f(0.0 + i, 90.0 + j);
    glVertex2f(0.0 + i, 70.0 + j);

    glVertex2f(0.0 + i, 70.0 + j);
    glVertex2f(-10.0 + i, 50.0 + j);

    glVertex2f(-10.0 + i, 50.0 + j);
    glVertex2f(-60.0 + i, 60.0 + j);

    glVertex2f(-60.0 + i, 60.0 + j);
    glVertex2f(-50.0 + i, 80.0 + j);

    glVertex2f(0.0 + i, 70.0 + j);
    glVertex2f(10.0 + i, 50.0 + j);

    glVertex2f(10.0 + i, 50.0 + j);
    glVertex2f(60.0 + i, 60.0 + j);

    glVertex2f(60.0 + i, 60.0 + j);
    glVertex2f(50.0 + i, 80.0 + j);
    glEnd();
}

void chicken(int i, int j)
{

    //--------------------bam pa
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(65.0 + i, 15.0 + j);
    glVertex2f(65.0 + i, 30.0 + j);
    glEnd();
    glFlush();

    //----------------------dan pa
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(95.0 + i, 15.0 + j);
    glVertex2f(95.0 + i, 30.0 + j);
    glEnd();
    glFlush();
    //--------------------------------bam pa angul 1
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(65.0 + i, 15.0 + j);
    glVertex2f(55.0 + i, 7.0 + j);
    glEnd();
    glFlush();
    //--------------------------------bam pa angul 2
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(65.0 + i, 15.0 + j);
    glVertex2f(65.0 + i, 3.0 + j);
    glEnd();
    glFlush();
    //--------------------------------bam pa angul 3
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(65.0 + i, 15.0 + j);
    glVertex2f(75.0 + i, 7.0 + j);
    glEnd();
    glFlush();
    //--------------------------------dan pa angul 1
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(95.0 + i, 15.0 + j);
    glVertex2f(85.0 + i, 7.0 + j);
    glEnd();
    glFlush();
    //--------------------------------dan pa angul 2
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(95.0 + i, 15.0 + j);
    glVertex2f(95.0 + i, 3.0 + j);
    glEnd();
    glFlush();
    //--------------------------------dan pa angul 3
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(95.0 + i, 15.0 + j);
    glVertex2f(105.0 + i, 7.0 + j);
    glEnd();
    glFlush();

    //---------------------------murgi 1 er pet
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(120 + 70 * cos(i * 3.1416 * i / 180) / 2, 420 + 50 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 1 er matha
    glColor3f(1, 0.5, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(120 + 40 * cos(i * 3.1416 * i / 180) / 2, 455 + 40 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 1 er bam chokh
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(110 + 7 * cos(i * 3.1416 * i / 180) / 2, 457 + 7 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();
    //---------------------------murgi 1 er dan chokh
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(130 + 7 * cos(i * 3.1416 * i / 180) / 2, 457 + 7 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 1 er peter pocket
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(120 + 30 * cos(i * 3.1416 * i / 180) / 2, 415 + 15 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 1 er bam pakha
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(85 + 15 * cos(i * 3.1416 * i / 180) / 2, 415 + 20 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 1 er dan pakha
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(155 + 15 * cos(i * 3.1416 * i / 180) / 2, 415 + 20 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 1 er mathar jhuti
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(120 + 10 * cos(i * 3.1416 * i / 180) / 2, 470 + 20 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 1 er thot
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(120 + 10 * cos(i * 3.1416 * i / 180) / 2, 445 + 20 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 2 er pet
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(260 + 70 * cos(i * 3.1416 * i / 180) / 2, 420 + 50 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 2 er matha
    glColor3f(1, 0.5, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(260 + 40 * cos(i * 3.1416 * i / 180) / 2, 455 + 40 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 2 er bam chokh
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(250 + 7 * cos(i * 3.1416 * i / 180) / 2, 457 + 7 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();
    //---------------------------murgi 2 er dan chokh
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(270 + 7 * cos(i * 3.1416 * i / 180) / 2, 457 + 7 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 2 er peter pocket
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(260 + 30 * cos(i * 3.1416 * i / 180) / 2, 415 + 15 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 2 er bam pakha
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(225 + 15 * cos(i * 3.1416 * i / 180) / 2, 415 + 20 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 2 er dan pakha
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(295 + 15 * cos(i * 3.1416 * i / 180) / 2, 415 + 20 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 2 er pet
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(400 + 70 * cos(i * 3.1416 * i / 180) / 2, 420 + 50 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 2 er mathar jhuti
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(260 + 10 * cos(i * 3.1416 * i / 180) / 2, 470 + 20 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 2 er thot
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(260 + 10 * cos(i * 3.1416 * i / 180) / 2, 445 + 20 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 3 er matha
    glColor3f(1, 0.5, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(400 + 40 * cos(i * 3.1416 * i / 180) / 2, 455 + 40 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 3 er bam chokh
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(390 + 7 * cos(i * 3.1416 * i / 180) / 2, 457 + 7 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();
    //---------------------------murgi 3 er dan chokh
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(410 + 7 * cos(i * 3.1416 * i / 180) / 2, 457 + 7 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 3 er peter pocket
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(400 + 30 * cos(i * 3.1416 * i / 180) / 2, 415 + 15 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 3 er bam pakha
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(365 + 15 * cos(i * 3.1416 * i / 180) / 2, 415 + 20 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 2 er dan pakha
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(435 + 15 * cos(i * 3.1416 * i / 180) / 2, 415 + 20 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 1 er mathar jhuti
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(400 + 10 * cos(i * 3.1416 * i / 180) / 2, 470 + 20 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();

    //---------------------------murgi 1 er thot
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        glVertex2f(400 + 10 * cos(i * 3.1416 * i / 180) / 2, 445 + 20 * sin(i * 3.1416 * i / 180) / 2);
    }
    glEnd();
    glFlush();
}

void print_score()
{
    cout << "\nLevel reached: " << levelCounter;
    cout << "\nNumber of eggs dropped: " << droppedEggs;
    cout << "\nNumber of eggs caught: " << eggsCaught;
    cout << "\nNumber of eggs missed: " << missedEggs;

    //getchar();
    exit(0);
}

void egg_start()
{
    eggY = 375;
    if (missedEggs >= 10)
    {
        cout << "Game over";
        print_score();
    }
    droppedEggs++;

    switch (rand() % 3)
    {
    case 0:eggX = 115; break;
    case 1:eggX = 255; break;
    case 2:eggX = 390; break;
    //case 5:eggX = 115; break;
    //case 3:eggX = 255; break;
    //case 4:eggX = 390; break;
    //case 7:eggX = 115; break;
    //case 6:eggX = 255; break;
    //case 8:eggX = 390; break;
    }
}

void score()
{
    if (eggY <= 50 && (eggX >= boxX - 60 && eggX <= boxX + 60))
    {
        cout << "\a";
        eggsCaught++;
        eggY = -10;
    }
    missedEggs = droppedEggs - eggsCaught;
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    ground(0, 650);
    backGround(0, 650);
    line(0, 375);
    chicken(40, 375);
    chicken(180, 375);
    chicken(320, 375);
    sun();
    cloud1();
    cloud2();




    if (s >= 1)
    {


        if (eggY <= 10)
            egg_start();

        egg();
        basket(boxX, boxY);
        if (eggsCaught >= 3)
        {
            eggY -= speed2;
            levelCounter = 2;
        }
        if (eggsCaught >= 5)
        {
            eggY -= speed3;
            levelCounter = 3;
        }
        if (eggsCaught >= 10)
        {
            eggY -= speed4;
            levelCounter = 4;
        }
        else
            eggY -= speed1;
        score();
    }

    glFlush();
    glutSwapBuffers();
}

void basket_set(int a, int b)
{
    boxX = a;
    boxY = b;
    glutPostRedisplay();
}



void keys(unsigned char key, int x, int y)
{
    if (key == ' ' || key == ' ')
    {
        s += 1;
    }
    if (key == 'a' || key == 'A')
    {
        boxX -= 10;
        if (boxX <= 0) boxX = 10;
    }
    if (key == 'd' || key == 'D')
    {
        boxX += 10;
        if (boxX >= 500)
        {
            boxX = 490;
        }
    }
}

void menu(int id)
{
    switch (id)
    {
    case 1: s += 1;
        break;
    case 2:print_score();
        break;;
    default:exit(0);
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 700);
    glutCreateWindow("Pak Pak Pakhi");
    myinit();
    glutInitWindowPosition(100, 100);
    glutCreateMenu(menu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutKeyboardFunc(keys);
    glutPassiveMotionFunc(basket_set);
    glutIdleFunc(display);
    glutTimerFunc(1000, update, 0);

    glutMainLoop();
}

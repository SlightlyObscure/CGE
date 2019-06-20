#include "funny_glitch.h"

void drawFunnyGlitch() {

	glPushMatrix();
	glScalef(5, 5, 5);
	glTranslatef(-5, 0, 2);
	// Multi-colored side - FRONT
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	// Black side - BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glPopMatrix();


	glClear(GL_DEPTH_BUFFER_BIT);

	glTranslatef(0, -2, -8);
	glDepthMask(GL_FALSE);

	glBegin(GL_QUADS);

	// front 
	glColor3f(0, 1, 0);
	glVertex3f(-1, 0, 1);
	glVertex3f(-1, 2, 1);
	glVertex3f(1, 2, 1);
	glVertex3f(1, 0, 1);

	// back
	glColor3f(0, 0.8, 0);
	glVertex3f(-1, 0, -1);
	glVertex3f(1, 0, -1);
	glVertex3f(1, 2, -1);
	glVertex3f(-1, 2, -1);

	// left 
	glColor3f(0, 0.6, 0);
	glVertex3f(-1, 0, 1);
	glVertex3f(-1, 2, 1);
	glVertex3f(-1, 2, -1);
	glVertex3f(-1, 0, -1);

	// right
	glVertex3f(1, 0, 1);
	glVertex3f(1, 0, -1);
	glVertex3f(1, 2, -1);
	glVertex3f(1, 2, 1);
	glEnd();


	glBegin(GL_TRIANGLES);
	// front
	glColor3f(1, 1, 0);
	glVertex3f(-1, 2, 1);
	glVertex3f(0, 4, 0);
	glVertex3f(1, 2, 1);
	// right
	glColor3f(0.9, 0.9, 0);
	glVertex3f(1, 2, 1);
	glVertex3f(1, 2, -1);
	glVertex3f(0, 4, 0);
	// back
	glColor3f(0.8, 0.8, 0);
	glVertex3f(1, 2, -1);
	glVertex3f(-1, 2, -1);
	glVertex3f(0, 4, 0);
	// left 
	glColor3f(0.7, 0.7, 0);
	glVertex3f(-1, 2, 1);
	glVertex3f(0, 4, 0);
	glVertex3f(-1, 2, -1);
	glEnd();
}


bool checkIfInFunnyGlitchRoom(int x, int y) 
{
	return false;
}

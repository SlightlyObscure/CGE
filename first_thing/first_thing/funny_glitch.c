#include "funny_glitch.h"

/**
* draws the house for a better view of the Glitch
*/
void drawFunnyGlitch() {

	glPushMatrix();
	glTranslatef(20, -5.0, 55);
	glScalef(2, 2, 2);
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
	glPopMatrix();
}


bool checkIfInFunnyGlitchRoom(int x, int y) 
{
	/* check for room space
		glBegin(GL_QUADS);
		glColor3f(0, 1, 0);
		glVertex3f(30, 1.0, 39);
		glVertex3f(10, 1.0, 39);
		glVertex3f(10, 1.0, 19);
		glVertex3f(30, 1.0, 19);
		glEnd();
	*/
	
	// check for player position
	//printf("x: %d     y: %d\n", x, y);

	if (-30 < x && x < -10 && -59 < y && y < -39) {
		return true;
	}
	return false;
}

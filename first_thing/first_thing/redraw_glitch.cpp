#include "redraw_glitch.hpp"


float hour = 0.0;
float day = 0.0;
float inc = 20.00;

/**
* checks if the player is in the according room
*/
bool checkIfInRedrawGlitchRoom(int x, int y) {
	/* For testing room space
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex3f(-10, 1.0, 39);
	glVertex3f(10, 1.0, 39);
	glVertex3f(10, 1.0, 19);
	glVertex3f(-10, 1.0, 19);
	glEnd();
	*/

	if (-30 < x && x < -10 && -39 < y && y < -19) {
		return true;
	}
	return false;
}

/**
* draws the solar system
*/
void drawRedrawGlitch() {

	hour += inc;
	day += inc / 24.0;
	hour = hour - ((int)(hour / 24)) * 24;
	day = day - ((int)(day / 365)) * 365;

	glTranslatef(-6.0, 0.0, 4.0);
	glScalef(.2, .2, .2);
	glRotatef(360 * day / 365.0, 0.0, 1.0, 0.0);

	// ecliptic
	glRotatef(15.0, 1.0, 0.0, 0.0);

	// sun
	glColor3f(1.0, 1.0, 0.0);
	glutSolidSphere(1.0, 15, 15);

	// earth
	// position around the sun
	glRotatef(360.0*day / 365.0, 0.0, 1.0, 0.0);
	glTranslatef(4.0, 0.0, 0.0);

	glPushMatrix();
	// rotate the earth on its axis
	glRotatef(360.0*hour / 24.0, 0.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(0.4, 10, 10);
	glPopMatrix();

	// moon
	glRotatef(360.0 * 4 * day / 365.0, 0.0, 1.0, 0.0);
	glTranslatef(0.7f, 0.0f, 0.0f);
	glColor3f(0.3f, 0.7f, 0.3f);
	glutSolidSphere(0.1f, 10, 10);
}
#include "light.h"

void illuminate() {
	glTranslatef(0, 0, 10.0f);
	
	glPushAttrib(GL_LIGHTING_BIT);

	GLfloat mat_base[] = { 0.7, 0.0, 0.0, 0.3 };
	GLfloat mat_specular[] = { 0.0, 0.7, 0.0, 1.0 };
	GLfloat mat_diffuse[] = { 0.0, 0.0, 0.7, 1.0 };
	GLfloat mat_shine[] = { 0.5 };
	GLfloat light_pos[] = { -1.0, 1.0, -1.0, 0.0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_base);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shine);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	glutSolidSphere(2.0, 320, 320);

	glPopAttrib();
}
#include "stdafx.h"

void drawPainting(GLuint painting) {
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, painting);

	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2, -3, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2, -3, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2, 2, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2, 2, 0);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void makeArt(GLuint painting1, GLuint painting2, GLuint painting3) {
	glPushMatrix();

	glTranslatef(0, -3.0f, 9.99f);

	drawPainting(painting1);
	glutPostRedisplay();
	drawPainting(painting2);
	glutPostRedisplay();
	drawPainting(painting3);

	glPopMatrix();
}


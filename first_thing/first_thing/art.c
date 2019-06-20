#include "stdafx.h"

void drawPainting(GLuint painting, float move) {
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, painting);

	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2 + move, -3, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2 + move, -3, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2 + move, 2, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2 + move, 2, 0);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void makeArt(GLuint painting1, GLuint painting2, GLuint painting3) {
	glPushMatrix();

	glTranslatef(0, 0, 18.99f);

	drawPainting(painting1, 0.00f);
	glutPostRedisplay();
	drawPainting(painting2, 0.01f);
	glutPostRedisplay();
	drawPainting(painting3, -0.01f);

	glPopMatrix();
}


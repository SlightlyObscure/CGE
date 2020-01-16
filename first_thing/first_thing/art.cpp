#include "art.hpp"

void drawPainting(GLuint painting, float move) {
	//enable 2D texture stuff
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	//bind texture
	glBindTexture(GL_TEXTURE_2D, painting);

	//draw rectangle with texture (move shifts the texture left and right)
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2 + move, -3, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2 + move, -3, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2 + move, 2, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2 + move, 2, 0);
	glEnd();

	//disable 2D stuff
	glDisable(GL_TEXTURE_2D);
}

void makeArt(GLuint painting1, GLuint painting2, GLuint painting3) {
	glPushMatrix();

	glTranslatef(0, 0, 18.99f);	//translate painting onto the wall

	//draw paintings with slightly different offsets to ensure glitchy look
	drawPainting(painting1, 0.00f);
	drawPainting(painting2, 0.01f);
	drawPainting(painting3, -0.01f);
	drawPainting(painting3, 0.02f);

	glPopMatrix();
}


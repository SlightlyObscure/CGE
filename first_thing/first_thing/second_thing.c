#include <GL/glut.h> 
#include <GL/gl.h>  
#include <GL/glu.h>  

#include <stdio.h>
#include <stdbool.h>

void presentationWall(GLuint texture) {

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, texture);

	glBegin(GL_QUADS);
	// front face glvertex3f( breite, höhe, nähe)
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.75f, -0.42f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.75f, -0.42f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.75f, 0.42f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.75f, 0.42f, -1.0f);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}


void roomDoor() {
	glRotatef(90, 0, 2, 0);

	glBegin(GL_QUADS);
	//glColor3f(1, 1, 1);
	// left side
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(4.0f, 0.0f); glVertex3f(-0.2f, -1.0f, 1.0f);
	glTexCoord2f(4.0f, 10.0f); glVertex3f(-0.2f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 10.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	
	//above door
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.2f, -0.2f, 1.0f);
	glTexCoord2f(2.0f, 0.0f); glVertex3f(0.2f, -0.2f, 1.0f);
	glTexCoord2f(2.0f, 6.0f); glVertex3f(0.2f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 6.0f); glVertex3f(-0.2f, 1.0f, 1.0f);
	
	//right side
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.2f, -1.0f, 1.0f);
	glTexCoord2f(4.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(4.0f, 10.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 10.0f); glVertex3f(0.2f, 1.0f, 1.0f);
	
	glEnd();
}

void roomWall() {
	glRotatef(90, 0, 2, 0);

	glBegin(GL_QUADS);
	//glColor3f(0, 0, 1);
	// front face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(10.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(10.0f, 10.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 10.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();
}

void roomCeiloor() {
	glBegin(GL_QUADS);
	//glColor3f(0, 0, 1);
	// floor
	glTexCoord2f(10.0f, 10.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 10.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(10.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);

	// ceiling
	glTexCoord2f(0.0f, 10.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(10.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(10.0f, 10.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glEnd();
	
}

void theRoom(bool aDoor, bool bDoor, bool cDoor, bool dDoor, GLuint textureA, GLuint textureB) {	//door = 1; wall = 0; Türenposition(rechts, hinten, links vorne)
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, textureA);

	roomCeiloor();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, textureB);

	if (aDoor == 1) {
		roomDoor();
	} 
	else { 
		roomWall(); 
	}
	if (bDoor == 1) {
		roomDoor();
	}
	else {
		roomWall();
	}
	if (cDoor == 1) {
		roomDoor();
	}
	else {
		roomWall();
	}
	if (dDoor == 1) {
		roomDoor();
	}
	else {
		roomWall();
	}
	glDisable(GL_TEXTURE_2D);
}
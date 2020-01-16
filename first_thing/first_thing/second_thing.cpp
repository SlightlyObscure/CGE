#include <stdio.h>
#include "stdafx.h"


void presentationWall(GLuint texture) {
	
	glTranslatef(0, 0, 5);
	glScalef(5.0f, 5.0f, 5.0f);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, texture);

	glBegin(GL_QUADS);
	// front face glvertex3f( breite, höhe, nähe)
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.75f, -0.42f, -0.99f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.75f, -0.42f, -0.99f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.75f, 0.42f, -0.99f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.75f, 0.42f, -0.99f);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glTranslatef(1.5, 0, 0); //so no translation in for loop is needed? maybe?
	glScalef(0.2f, 0.2f, 0.2f);
	glTranslatef(0, 0, -5);
}

void plainWall(int a, int b, int c) {	//ich wäre farbig wenn etwas von meister talents tentakeln auf mich abfroht

	glBegin(GL_QUADS);
	
	glColor3f(a, b, c);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.75f, -0.42f, -0.99f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.75f, -0.42f, -0.99f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.75f, 0.42f, -0.99f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.75f, 0.42f, -0.99f);
	
	glEnd();

}


void roomDoor() {
	glRotatef(90, 0, 2, 0);

	glBegin(GL_QUADS);
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
	// front face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(10.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(10.0f, 10.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 10.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();
}

void roomCeiling() {
	glBegin(GL_QUADS);

	// ceiling
	glTexCoord2f(0.0f, 10.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(10.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(10.0f, 10.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glEnd();
}
void roomFloor(){
	glBegin(GL_QUADS);

	// floor
	glTexCoord2f(10.0f, 10.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 10.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(10.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();
}

//nothing=0; door = 1; wall = 2; Wandreihenfolge(rechts, vorne, links, hinten)
void theRoom(int aDoor, int bDoor, int cDoor, int dDoor, GLuint textureA, GLuint textureB) {	
	
	glTranslatef(0, 5, 9);
	glScalef(10.0f, 10.0f, 10.0f);
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, textureA);

	roomFloor();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, textureB);
	roomCeiling();

	if (aDoor == 1) {
		roomDoor();
	} 
	else if(aDoor == 2){
		roomWall(); 
	}
	else {
		glRotatef(90, 0, 2, 0);
	}
	if (bDoor == 1) {
		roomDoor();
	}
	else if (bDoor == 2) {
		roomWall();
	}
	else {
		glRotatef(90, 0, 2, 0);
	}
	if (cDoor == 1) {
		roomDoor();
	}
	else if (cDoor == 2) {
		roomWall();
	}
	else {
		glRotatef(90, 0, 2, 0);
	}
	if (dDoor == 1) {
		roomDoor();
	}
	else if (dDoor == 2) {
		roomWall();
	}
	else {
		glRotatef(90, 0, 2, 0);
	}
	glDisable(GL_TEXTURE_2D);

	glScalef(0.1f, 0.1f, 0.1f);
	glTranslatef(0, -5, -9);
	
}

void presentationRoom(int numberOfRooms, GLuint textureA, GLuint textureB) {
	
	theRoom(0, 2, 2, 2, textureA, textureB);
	glTranslatef(20.0f, 0, 0);	//dont forget the room scaling...

	for(int i=1; i<=(numberOfRooms-2); i++){
		theRoom(0, 2, 0, 2, textureA, textureB);
		glTranslatef(20.0f, 0, 0);	//dont forget the room scaling...
	}

	theRoom(1, 2, 0, 2, textureA, textureB);

}
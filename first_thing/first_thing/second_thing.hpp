#pragma once
#include <GL/glut.h> 
#include <GL/gl.h>  
#include <GL/glu.h>  

void presentationWall(GLuint texture);

void roomDoor();
void roomWall();
void roomFloor();
void roomCeiling();


void theRoom(int aDoor, int bDoor, int cDoor, int dDoor, GLuint textureA, GLuint textureB);

void presentationRoom(int numberOfRooms, GLuint textureA, GLuint textureB);
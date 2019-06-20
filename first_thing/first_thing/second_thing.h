#pragma once
#include <GL/glut.h> 
#include <GL/gl.h>  
#include <GL/glu.h>  

void presentationWall();

void roomDoor();
void roomWall();
void roomCeiloor();

void theRoom(bool aDoor, bool bDoor, bool cDoor, bool dDoor, GLuint textureA, GLuint textureB);
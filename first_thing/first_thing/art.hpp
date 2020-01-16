#pragma once
#include <GL/glut.h> 
#include <GL/gl.h>  
#include <GL/glu.h>  

void drawPainting(GLuint painting, float move);	//draws a single painting
void makeArt(GLuint painting1, GLuint painting2, GLuint painting3);	//draws 3 paintings on top of each other
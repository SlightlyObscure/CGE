#pragma once
#include <stdlib.h> // for exit

//glew
#include <GL/glew.h>
//#include <GL/eglew.h>
//#include <GL/glxew.h>
//#include <GL/wglew.h>

// opengl & glut stuff
#include <GL/glut.h> 
#include <GL/gl.h>  
#include <GL/glu.h>  



// IO
#include <stdio.h>
#include "tga.h"

// standard functions
#include <math.h>
#include <stdbool.h>


/* some math.h files don't define pi... */
#ifndef M_PI
#define M_PI 3.141592653
#endif

#define SQRT2 1.41421356

#define SLIDE_SIZE 1.5f*5.0f

#define RAD(x) (((x)*M_PI)/180.)

#ifdef __STRICT_ANSI__
#define sinf(x) ((float)sin((x)))
#define cosf(x) ((float)cos((x)))
#define atan2f(x, y) ((float)atan2((x), (y)))
#endif 

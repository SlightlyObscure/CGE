#include <stdlib.h> // for exit

#include <GL/glut.h> 
#include <GL/gl.h>  
#include <GL/glu.h>  

#include <stdio.h>
#include "tga.h"

#include <math.h>
#include <stdbool.h>


/* some math.h files don't define pi... */
#ifndef M_PI
#define M_PI 3.141592653
#endif

#define SQRT2 1.41421356

#define SLIDE_SIZE 4.0f

#define RAD(x) (((x)*M_PI)/180.)

#ifdef __STRICT_ANSI__
#define sinf(x) ((float)sin((x)))
#define cosf(x) ((float)cos((x)))
#define atan2f(x, y) ((float)atan2((x), (y)))
#endif 

#include <GL/glut.h> 
#include <GL/gl.h>  
#include <GL/glu.h>  

#include <stdio.h>
#include <stdbool.h>

/**
* for the redraw glitch, the clearing of the color buffer is disabled so that moving objects will leave trails behind them
* in first_thing it is checked if the player is in the according room and if that's the case the clearing is disabled.
* for a better view of this the drawRedrawGlitch function will draw the solar system exercise
*/

void drawRedrawGlitch();
bool checkIfInRedrawGlitchRoom(int x, int y);

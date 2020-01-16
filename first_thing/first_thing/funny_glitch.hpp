#include <GL/glut.h> 
#include <GL/gl.h>  
#include <GL/glu.h>  

#include <stdio.h>
#include <stdbool.h>

/**
* For the funny Glitch the Depth Mask is disabled, so that the player can look through walls
* in first_thing it is checked if the player is in the according room and if that's the case
* the Depth Mask is disbaled
* drawFunnyGlitch just draws the house for a better view of the Glitch
*/

void drawFunnyGlitch();
bool checkIfInFunnyGlitchRoom(int x, int y);

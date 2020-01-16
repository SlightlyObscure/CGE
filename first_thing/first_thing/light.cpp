#include "light.hpp"

void illuminate() {
	glTranslatef(0, 0, 10.0f);	//move sphere into the middle of the room
	
	glPushAttrib(GL_LIGHTING_BIT);	//push the lighting attribute to make sure these changes don't affect other objects

	GLfloat mat_base[] = { 0.7, 0.0, 0.0, 0.3 };	//(rich red) "base colour" of the sphere; is emitted by material to prevent it from looking completely back on dark side
	GLfloat mat_specular[] = { 0.0, 1, 0.0, 1.0 };	//(green) specular property of the sphere material; makes the edges of the illuminated area look green-ish yellow
	GLfloat mat_diffuse[] = { 0.0, 0.0, 1, 1.0 };	//(blue) diffuse property of the sphere material; makes center of the illuminated area look light blue
	GLfloat mat_shine[] = { 1 };					//shininess of the material
	GLfloat light_pos[] = { -1.0, 1.0, -1.0, 0.0 };	//position of the light source relative to the sphere

	//assign properties to the material
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_base);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shine);
	//set light position
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	//enable lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//draw sphere
	glutSolidSphere(2.0, 320, 320);

	glPopAttrib();	//pop lighting again and resume drawing other objects like before
}
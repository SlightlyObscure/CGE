#include "stdafx.h"
#include "second_thing.h"
#include "redraw_glitch.h"
#include "art.h"
#include "funny_glitch.h"

int window;
float advance = 0.0f;
float advanceY = 0.0f;
GLuint texture[10];
int animating = 1;

float posX = 0.0f;
float posY = 0.0f;
float posZ = -5.0f;

bool wPressed = 0;
bool aPressed = 0;
bool sPressed = 0;
bool dPressed = 0;

GLfloat angle_y = 0;  /* angle of spin around y axis of scene, in degrees */	//for turning
GLfloat angle_x = 0;  /* angle of spin around x axis  of scene, in degrees */

float mouseX = 0;
float mouseY = 0;

void reportGLError(const char * msg)
{
	GLenum errCode;
	const GLubyte *errString;
	while ((errCode = glGetError()) != GL_NO_ERROR) {
		errString = gluErrorString(errCode);
		fprintf(stderr, "OpenGL Error: %s %s\n", msg, errString);
	}
	return;
}

void resize(int width, int height)
{
	// prevent division by zero
	if (height == 0) { height = 1; }

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)width / (float)height, 0.1f, 1000.0f);
	glMatrixMode(GL_MODELVIEW);
}

void specialKeyPressed(int key, int x, int y)
{
	float slideSize = 0.2f;

	switch (key) {

	case GLUT_KEY_RIGHT:     /* <cursor up> */
		advance += SLIDE_SIZE;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:		/*down movement*/
		advanceY -= slideSize;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:     /* <cursor down> */
		advance -= SLIDE_SIZE;
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:		/*up movement*/
		advanceY += slideSize;
		glutPostRedisplay();
		break;
	}
}

void keyPressed(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		glutDestroyWindow(window);
		exit(0);
		break;
	case 'w':
		wPressed = 1;
		break;
	case 'a':
		aPressed = 1;
		break;
	case 's':
		sPressed = 1;
		break;
	case 'd':
		dPressed = 1;
		break;
	case 32:
		advance += SLIDE_SIZE;
		glutPostRedisplay();
		break;
	case 13:
		advance += SLIDE_SIZE;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

void keyReleased(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
		wPressed = 0;
		break;
	case 'a':
		aPressed = 0;
		break;
	case 's':
		sPressed = 0;
		break;
	case 'd':
		dPressed = 0;
		break;
	default:
		break;
	}
}

void display()
{
	if (checkIfInRedrawGlitchRoom(posX, posZ)) {
		glClear(GL_DEPTH_BUFFER_BIT);
		glDepthMask(GL_TRUE);
	}
	else if (checkIfInFunnyGlitchRoom(posX, posZ)) {
		glClear(GL_DEPTH_BUFFER_BIT);
		glDepthMask(GL_FALSE);
	}
	else {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDepthMask(GL_TRUE);
	}

	glLoadIdentity();

	GLfloat cur_x = angle_x;
	float calced_sin_x = 0;


	while (cur_x > 90.0) {
		calced_sin_x += 1;
		cur_x -= 90;
	}
	while (cur_x < -90.0) {
		calced_sin_x -= 1;
		cur_x += 90;
	}
	calced_sin_x += sinf(RAD(cur_x));
	if (calced_sin_x > 0) {
		calced_sin_x *= calced_sin_x;
	}
	else {
		calced_sin_x *= -calced_sin_x;
	}

	gluLookAt(-sinf(RAD(angle_y)), calced_sin_x, cosf(RAD(angle_y)),
		0., 0., 0.,
		0., 1., 0.);

	glTranslatef(-sinf(RAD(angle_y)), calced_sin_x, cosf(RAD(angle_y)));	//moves view back into the center (without this the camera moves down when you look up and vice versa)

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	glTranslatef(posX - advance, posY - advanceY, posZ);


	// because 2 different textures per room, we need to hand over textures, first one floor, second one ceiling + walls

	glPushMatrix();
	presentationRoom(3, texture[2], texture[1]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 20.0f);
	theRoom(2, 0, 2, 0, texture[2], texture[1]);
	glTranslatef(20.0f, 0, 0);
	theRoom(2, 0, 2, 2, texture[2], texture[1]);
	glTranslatef(20.0f, 0, 0);
	theRoom(2, 0, 2, 2, texture[2], texture[1]);
	glPopMatrix();

	glPushMatrix();
	//plainWall();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20.0f, 0, 0);
	theRoom(0, 2, 2, 2, texture[2], texture[1]);
	glPopMatrix();

	glPushMatrix();
	for (int i = 0; i < 4; i++) {
		presentationWall(texture[i + 3]);
	}
	glPopMatrix();

	glPushMatrix();
	glScalef(9.99f, 9.99f, 9.99f);
	glTranslatef(6, 0, 0);
	drawRedrawGlitch();
	glPopMatrix();

	glPushMatrix();
	glScalef(5, 5, 5);
	glTranslatef(-5, 0, 2);
	// Multi-colored side - FRONT
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	// Black side - BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-40.0f, 0, 40.0f);
	theRoom(1, 1, 1, 2, texture[2], texture[1]);

	makeArt(texture[7], texture[8], texture[9]);

	glPopMatrix();


	/* For testing room space
		glBegin(GL_QUADS);
		glColor3f(0, 1, 0);
		glVertex3f(-10, 1.0, 39);
		glVertex3f(10, 1.0, 39);
		glVertex3f(10, 1.0, 19);
		glVertex3f(-10, 1.0, 19);

		glEnd();
	*/
	if (checkIfInFunnyGlitchRoom(posX, posZ)) {
		//glClear(GL_DEPTH_BUFFER_BIT);
		//glDepthMask(GL_FALSE);
	}

	drawFunnyGlitch();

	glPushMatrix();
	glTranslatef(-60.0f, 0, 40.0f);
	theRoom(1, 1, 1, 2, texture[2], texture[1]);

	illuminate();
	glPopMatrix();

	glutSwapBuffers();
}

void texCreator(char name[255], GLsizei* w, GLsizei* h, int*mode, int index) {
	//LEONG START
	tgaInfo *info = 0;

	//load 9th texture
	info = tgaLoad(name);		//filename

	if (info->status != TGA_OK) {
		fprintf(stderr, "error loading texture image: %d\n", info->status);

		return;
	}

	*mode = info->pixelDepth / 8;  // will be 3 for rgb, 4 for rgba

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, texture[index]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	// Upload the texture bitmap. 
	*w = info->width;
	*h = info->height;

	reportGLError("before uploading texture");
	GLint format = (*mode == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_2D, 0, format, *w, *h, 0, format,
		GL_UNSIGNED_BYTE, info->imageData);
	reportGLError("after uploading texture");

	tgaDestroy(info);	//end of 8th texture loading

						//LEONG END
}

void init(int width, int height)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	resize(width, height);

	GLsizei w, h;
	tgaInfo *info = 0, *info2 = 0, *info3 = 0, *info4 = 0, *info5 = 0, *info6 = 0, *info7 = 0, *info8 = 0, *info9 = 0, *info10 = 0;
	int mode;

	glGenTextures(10, &texture);

	texCreator("crate.tga", &w, &h, &mode, 0);
	texCreator("wallBit.tga", &w, &h, &mode, 1);
	texCreator("floorTiles.tga", &w, &h, &mode, 2);
	texCreator("placeHolder1.tga", &w, &h, &mode, 3);
	texCreator("placeHolder2.tga", &w, &h, &mode, 4);
	texCreator("placeHolder3.tga", &w, &h, &mode, 5);
	texCreator("placeHolder4.tga", &w, &h, &mode, 6);
	texCreator("painting1.tga", &w, &h, &mode, 7);
	texCreator("painting2.tga", &w, &h, &mode, 8);
	texCreator("painting3.tga", &w, &h, &mode, 9);

}

void calcMovement(float speed) {
	float vecX = 0.0f;
	float vecY = 0.0f;

	if (wPressed == 1) {
		if (aPressed || dPressed) {
			vecY += speed / SQRT2;
		}
		else {
			vecY += speed;
		}
	}
	if (aPressed == 1) {
		if (wPressed || sPressed) {
			vecX += speed / SQRT2;
		}
		else {
			vecX += speed;
		}
	}
	if (sPressed == 1) {
		if (aPressed || dPressed) {
			vecY -= speed / SQRT2;
		}
		else {
			vecY -= speed;
		}

	}
	if (dPressed == 1) {
		if (wPressed || sPressed) {
			vecX -= speed / SQRT2;
		}
		else {
			vecX -= speed;
		}
	}

	posX += (cosf(RAD(angle_y)) * vecX) + (-sinf(RAD(angle_y)) * vecY);
	posZ += (sinf(RAD(angle_y)) * vecX) + (cosf(RAD(angle_y)) * vecY);
}

void timer(int value)
{
	calcMovement(2);
	glutPostRedisplay();
	glutTimerFunc(15, timer, 1);
}


void mouseMotion(int x, int y) {
	int max_look_up = 180;

	int diffx = x - mouseX;
	int diffy = y - mouseY;

	/* calculate new modelview matrix values */
	angle_y = angle_y + diffx;
	angle_x = angle_x + diffy;
	if (angle_x > max_look_up) angle_x = max_look_up;
	else if (angle_x < -max_look_up) angle_x = -max_look_up;
	if (angle_y > 360.0) angle_y -= 360.0;
	else if (angle_y < -360.0) angle_y += 360.0;

	mouseX = x;
	mouseY = y;

	//printf("x: %lf y: %lf\n", mouseX, mouseY);

	if ((mouseX == 0) || (GLUT_WINDOW_WIDTH - mouseX) == 0 || (mouseY == 0) || (GLUT_WINDOW_HEIGHT - mouseY) == 0) {
		glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2);
		mouseX = glutGet(GLUT_WINDOW_WIDTH) / 2;
		mouseY = glutGet(GLUT_WINDOW_HEIGHT) / 2;
	}
}



int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	window = glutCreateWindow("Glitch Museum");
	glutDisplayFunc(&display);
	glutReshapeFunc(&resize);
	glutKeyboardFunc(&keyPressed);
	glutKeyboardUpFunc(&keyReleased);
	glutSpecialFunc(&specialKeyPressed);
	init(640, 480);
	glutTimerFunc(15, timer, 1);
	glutPassiveMotionFunc(mouseMotion);
	glutMotionFunc(mouseMotion);
	glutSetCursor(GLUT_CURSOR_NONE);
	glutWarpPointer(952, 505);
	glutFullScreen();
	glutMainLoop();
	return 0;
}
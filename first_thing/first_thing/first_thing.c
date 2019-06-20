// first_thing.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

//#include "stdafx.h"

#include <stdlib.h> // for exit

#include <GL/glut.h> 
#include <GL/gl.h>  
#include <GL/glu.h>  

#include <stdio.h>
#include "tga.h"

#include <math.h>
#include <stdbool.h>

#include "second_thing.h"

/* some math.h files don't define pi... */
#ifndef M_PI
#define M_PI 3.141592653
#endif

#define SQRT2 1.41421356

#define SLIDE_SIZE 1.5f*9.99f	//slidesize times scaling of presentationWall

#define RAD(x) (((x)*M_PI)/180.)

#ifdef __STRICT_ANSI__
#define sinf(x) ((float)sin((x)))
#define cosf(x) ((float)cos((x)))
#define atan2f(x, y) ((float)atan2((x), (y)))
#endif 

int window;
float advance = 0.0f;
float advanceY = 0.0f;
GLuint texture[7];
int animating = 1;

float posX = 0.0f;
float posY = 0.0f;
float posZ = 0.0f;

bool wPressed = 0;
bool aPressed = 0;
bool sPressed = 0;
bool dPressed = 0;

int moving = 0;     /* flag that is true while mouse moves */
int begin_x = 0;        /* x value of mouse movement */
int begin_y = 0;      /* y value of mouse movement */
GLfloat angle_y = 0;  /* angle of spin around y axis of scene, in degrees */	//for turning
GLfloat angle_x = 0;  /* angle of spin around x axis  of scene, in degrees */

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
	gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
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

void drawCube()
{
	glBegin(GL_QUADS);
	// front face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	// back face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	// top face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	// bottom face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	// right face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	// left face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
	else  {
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
	/*
	glPushMatrix();
	glTranslatef(-2, 0, 0);
	glTranslatef(0, 0, 4);
	drawCube();
	glTranslatef(0, 0, -4);
	drawCube();
	glTranslatef(0, 0, -4);
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 0, 0);
	glTranslatef(0, 0, 4);
	drawCube();
	glTranslatef(0, 0, -4);
	drawCube();
	glTranslatef(0, 0, -4);
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2, -2, 0);
	glTranslatef(0, 0, 4);
	drawCube();
	glTranslatef(0, 0, -4);
	drawCube();
	glTranslatef(0, 0, -4);
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, -2, 0);
	glTranslatef(0, 0, 4);
	drawCube();
	glTranslatef(0, 0, -4);
	drawCube();
	glTranslatef(0, 0, -4);
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2, -6, 0);
	glTranslatef(0, 0, 4);
	drawCube();
	glTranslatef(0, 0, -4);
	drawCube();
	glTranslatef(0, 0, -4);
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, -6, 0);
	glTranslatef(0, 0, 4);
	drawCube();
	glTranslatef(0, 0, -4);
	drawCube();
	glTranslatef(0, 0, -4);
	drawCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4, 0, 0);
	glTranslatef(0, 0, 4);
	drawCube();
	glTranslatef(0, 0, -4);
	drawCube();
	glTranslatef(0, 0, -4);
	drawCube();
	glPopMatrix();
	
	glDisable(GL_TEXTURE_2D);*/



	// because 2 different textures per room, we need to hand over textures, first one ceiling + floor, second one walls

	glPushMatrix();
	glScalef(100.0f, 10.0f, 10.0f);
	glTranslatef(0.9, 0.5, 0);
	theRoom(1, 0, 1, 1, texture[2], texture[1]);
	glPopMatrix();

	glPushMatrix();
	glScalef(10.0f, 10.0f, 10.0f);
	glTranslatef(0, 0.5, 0);
	glTranslatef(0,  0, 2.001f);
	theRoom(0,1,0, 1, texture[2], texture[1]);
	glPopMatrix();


	glScalef(9.99f, 9.99f, 9.99f);
	for (int i = 0; i<4; i++) {
		presentationWall(texture[i+3]);
		glTranslatef(1.5, 0, 0);
	}


	glutSwapBuffers();
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
	tgaInfo *info = 0, *info2 = 0, *info3 = 0, *info4 = 0, *info5 = 0, *info6 = 0, *info7 = 0;
	int mode;

	info = tgaLoad("crate.tga");		//filename

	if (info->status != TGA_OK) {
		fprintf(stderr, "error loading texture image: %d\n", info->status);

		return;
	}

	mode = info->pixelDepth / 8;  // will be 3 for rgb, 4 for rgba
	glGenTextures(7, &texture);		//only needed for first one, why?

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	// Upload the texture bitmap. 
	w = info->width;
	h = info->height;

	reportGLError("before uploading texture");
	GLint format = (mode == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_2D, 0, format, w, h, 0, format,
		GL_UNSIGNED_BYTE, info->imageData);
	reportGLError("after uploading texture");

	tgaDestroy(info);

	//load second texture
	info2 = tgaLoad("wallBit.tga");			//filename

	if (info2->status != TGA_OK) {
		fprintf(stderr, "error loading texture image: %d\n", info2->status);

		return;
	}

	mode = info2->pixelDepth / 8;  // will be 3 for rgb, 4 for rgba

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	// Upload the texture bitmap. 
	w = info2->width;
	h = info2->height;

	reportGLError("before uploading texture");
	format = (mode == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_2D, 0, format, w, h, 0, format,
		GL_UNSIGNED_BYTE, info2->imageData);
	reportGLError("after uploading texture");

	tgaDestroy(info2);	//end of second texture loading

	//load third texture
	info3 = tgaLoad("floorTiles.tga");		//filename

	if (info3->status != TGA_OK) {
		fprintf(stderr, "error loading texture image: %d\n", info3->status);

		return;
	}

	mode = info3->pixelDepth / 8;  // will be 3 for rgb, 4 for rgba

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	// Upload the texture bitmap. 
	w = info3->width;
	h = info3->height;

	reportGLError("before uploading texture");
	format = (mode == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_2D, 0, format, w, h, 0, format,
		GL_UNSIGNED_BYTE, info3->imageData);
	reportGLError("after uploading texture");

	tgaDestroy(info3);	//end of third texture loading

	//load fourth texture
	info4 = tgaLoad("placeHolder1.tga");		//filename

	if (info4->status != TGA_OK) {
		fprintf(stderr, "error loading texture image: %d\n", info4->status);

		return;
	}

	mode = info4->pixelDepth / 8;  // will be 3 for rgb, 4 for rgba

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	// Upload the texture bitmap. 
	w = info4->width;
	h = info4->height;

	reportGLError("before uploading texture");
	format = (mode == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_2D, 0, format, w, h, 0, format,
		GL_UNSIGNED_BYTE, info4->imageData);
	reportGLError("after uploading texture");

	tgaDestroy(info4);	//end of fourth texture loading

	//load fifth texture
	info5 = tgaLoad("placeHolder2.tga");		//filename

	if (info5->status != TGA_OK) {
		fprintf(stderr, "error loading texture image: %d\n", info5->status);

		return;
	}
	/*if (info->width != info->height) {
	fprintf(stderr, "Image size %d x %d is not rectangular, giving up.\n",
	info->width, info->height);
	return;
	}*/

	mode = info5->pixelDepth / 8;  // will be 3 for rgb, 4 for rgba

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	// Upload the texture bitmap. 
	w = info5->width;
	h = info5->height;

	reportGLError("before uploading texture");
	format = (mode == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_2D, 0, format, w, h, 0, format,
		GL_UNSIGNED_BYTE, info5->imageData);
	reportGLError("after uploading texture");

	tgaDestroy(info5);	//end of fifth texture loading

	//load sixth texture
	info6 = tgaLoad("placeHolder3.tga");		//filename

	if (info6->status != TGA_OK) {
		fprintf(stderr, "error loading texture image: %d\n", info6->status);

		return;
	}

	mode = info6->pixelDepth / 8;  // will be 3 for rgb, 4 for rgba

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	// Upload the texture bitmap. 
	w = info6->width;
	h = info6->height;

	reportGLError("before uploading texture");
	format = (mode == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_2D, 0, format, w, h, 0, format,
		GL_UNSIGNED_BYTE, info6->imageData);
	reportGLError("after uploading texture");

	tgaDestroy(info6);	//end of sixth texture loading


	//load seventh texture
	info7 = tgaLoad("placeHolder4.tga");		//filename

	if (info7->status != TGA_OK) {
		fprintf(stderr, "error loading texture image: %d\n", info7->status);

		return;
	}

	mode = info7->pixelDepth / 8;  // will be 3 for rgb, 4 for rgba

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	// Upload the texture bitmap. 
	w = info7->width;
	h = info7->height;

	reportGLError("before uploading texture");
	format = (mode == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_2D, 0, format, w, h, 0, format,
		GL_UNSIGNED_BYTE, info7->imageData);
	reportGLError("after uploading texture");

	tgaDestroy(info7);	//end of seventh texture loading

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
	calcMovement(0.1);
	glutPostRedisplay();
	glutTimerFunc(15, timer, 1);
}


void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:    /* spin scene around */
		if (state == GLUT_DOWN) {
			moving = 1;
			begin_x = x;
			begin_y = y;

		}
		else if (state == GLUT_UP) {
			moving = 0;
		}
		break;

	default:
		break;
	}

	glutPostRedisplay();
}


void mouseMotion(int x, int y) {
	int max_look_up = 180;

	if (moving) { /* mouse button is pressed */

				  /* calculate new modelview matrix values */
		angle_y = angle_y + (x - begin_x);
		angle_x = angle_x + (y - begin_y);
		if (angle_x > max_look_up) angle_x = max_look_up;
		else if (angle_x < -max_look_up) angle_x = -max_look_up;
		if (angle_y > 360.0) angle_y -= 360.0;
		else if (angle_y < -360.0) angle_y += 360.0;

		begin_x = x;
		begin_y = y;
		glutPostRedisplay();
	}
}



int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	window = glutCreateWindow("foo");
	glutDisplayFunc(&display);
	glutReshapeFunc(&resize);
	glutKeyboardFunc(&keyPressed);
	glutKeyboardUpFunc(&keyReleased);
	glutSpecialFunc(&specialKeyPressed);
	init(640, 480);
	glutTimerFunc(15, timer, 1);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	
	glutFullScreen();
	glutMainLoop();
	return 0;
}
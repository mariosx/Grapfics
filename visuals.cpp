#include <stdio.h>     // - Just for some ASCII messages
#include <stdlib.h>
#include "gl/glut.h"   // - An interface and windows 
                       //   management library
#include "visuals.h"   // Header file for our OpenGL functions
#include <math.h>
#include <iostream>
#include <fstream>
#include <ctime>

static float tx = 0.0;

#define PI 3.14159265

void Keyboard(unsigned char key,int x,int y)
{
	
	switch(key)
	{
	case 'a' : tx+=3.0f;
		break;
	case 'd' : tx+=3.0f;
		break;
	default : break;
	}
	glutPostRedisplay();

}

void Timer(int value){
	tx+=50.0f;
    glutPostRedisplay();
    // 100 milliseconds
    glutTimerFunc(100, Timer, 0);
}

void Render()
{    
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clean up the colour of the window
													   // and the depth buffer
  glMatrixMode(GL_MODELVIEW); 
  glLoadIdentity();

  glColor4f(1,1,0,0.5);
  glEnable( GL_BLEND );
  glBlendFunc( GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA );							   // Set drawing colour = orange
  //glutSolidTeapot( 20.0 );							   // Draw a built-in primitive
  //glutWireTeapot(20.0);
  glutSolidSphere(20.0+2.0*cos(tx*PI/180),20.0 + 2.0*cos(tx*PI/180),20.0 + 2.0*cos(tx*PI/180));
  glColor4f(1.0, 0.5, 0.2,1);
  glEnable( GL_BLEND );
  glBlendFunc( GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA );
  //glTranslated(0.0,0.0,-20.0);
  glutSolidSphere(17.0,17.0,17.0);
  //glPushMatrix();
  //time(&timer);
  //glScalef(10.0+cos(timer*PI/180),10.0 + cos(timer*PI/180),10.0 + cos(timer*PI/180));
  //glPopMatrix();
  glutSwapBuffers();             // All drawing commands applied to the 
                                 // hidden buffer, so now, bring forward
                                 // the hidden buffer and hide the visible one
}

//-----------------------------------------------------------

void Resize(int w, int h)
{ // w and h are window sizes returned by glut
  // define the visible area of the window ( in pixels )
  
  if (h==0) h=1;
  //glViewport(0,0,w,h);
  glViewport(100,100,400,400);

  // Setup viewing volume
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity();
 
 
  //         L,      R,      B,     T,     N,      F
  glOrtho (-50.0f, 50.0f, -50.0f, 50.0f, 100.0f, -100.0f);


}


void Setup()  // DON'T TOUCH IT 
{ 
	//Parameter handling
	glShadeModel (GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);

	// polygon rendering mode
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
  
	//Set up light source
	GLfloat light_position[] = { 0.0, 30.0,-50.0,0.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Black background
	glClearColor(0.0f,0.0f,0.0f,1.0f);

}


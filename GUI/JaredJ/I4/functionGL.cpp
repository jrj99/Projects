#include <QGLWidget>
#include <cmath>
#include "functionGL.h"
#include "Common.h"


    functionGL::functionGL(QWidget *parent)
        : QGLWidget(parent) {}



    void functionGL::initializeGL()
    {
        // Set up the rendering context, define display lists etc.:
    	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0,15,0,15,-1,1);

	glClearDepth(1.0f);
    	glEnable(GL_DEPTH_TEST);
    	glDepthFunc(GL_LEQUAL);
    }

    void functionGL::resizeGL(int w, int h)
    {
        // setup viewport, projection etc.:
        glViewport(0, 0, (GLint)w, (GLint)h);
    }

    void functionGL::paintGL()
    {
		
		glClear (GL_COLOR_BUFFER_BIT);
    	glClear(GL_DEPTH_BUFFER_BIT);

			double addB = B * x_val;
			double addC = C * pow(x_val, 2);
			double y = A + addB + addC;
		

			//draw a point

    	    glPointSize(4.0); 
    	    glBegin(GL_POINTS);
    	    
    	    glColor3f (0.0, 1.0, 0.0);
    	    glVertex3f(x_val, y, 0);

		

    	glEnd();

     }


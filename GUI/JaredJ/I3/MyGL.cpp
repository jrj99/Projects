#include <QGLWidget>
#include <MyGL.h>



    MyGL::MyGL(QWidget *parent)
        : QGLWidget(parent) {}



    void MyGL::initializeGL()
    {
        // Set up the rendering context, define display lists etc.:
    	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1,1,-1,1,-1,1);

	glClearDepth(1.0f);
    	glEnable(GL_DEPTH_TEST);
    	glDepthFunc(GL_LEQUAL);
    }

    void MyGL::resizeGL(int w, int h)
    {
        // setup viewport, projection etc.:
        glViewport(0, 0, (GLint)w, (GLint)h);
    }

    void MyGL::paintGL()
    {


		
		glClear (GL_COLOR_BUFFER_BIT);
    	glClear(GL_DEPTH_BUFFER_BIT);

		//draw a point

        glPointSize(4.0);
        glBegin(GL_POINTS);
        glColor3f (0.0, 1.0, 0.0);
        glVertex3f(-0.2,0.4, 0);
        glEnd();

        //draw a line


        glLineWidth(2.0);
        glBegin(GL_LINES);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(0.0,0.4,0);
        glVertex3f(0.3,0.4,0);
        glEnd();

        // draw a quad:

		glBegin(GL_QUADS);
        glColor3f (1.0, 0.0, 0.0);
        glVertex3f(-0.8, 0.8,  0);
        glVertex3f( -0.4, 0.8,  0);
        glVertex3f( -0.4,  0.4, 0);
        glVertex3f(-0.8, 0.4,  0);    	
        glEnd();

        //draw a hexagon:

        glBegin(GL_TRIANGLE_STRIP);
        glColor3f (1.0, 1.0, 0.0);
        glVertex3f( 0.2, -0.4, 0);
        glVertex3f( 0.35, -0.2, 0);
        glVertex3f( 0.5, -0.4, 0);
        glVertex3f( 0.65, -0.2, 0);
        glVertex3f( 0.8, -0.4, 0);
        glEnd();
   
        glBegin(GL_TRIANGLE_STRIP);
        glColor3f (1.0, 1.0, 0.0);
        glVertex3f( 0.2, -0.4, 0);
        glVertex3f( 0.35, -0.6, 0);
        glVertex3f( 0.5, -0.4, 0);
        glVertex3f( 0.65, -0.6, 0);
        glVertex3f( 0.8, -0.4, 0);
        glEnd(); 


       //draw a cube:

		glBegin(GL_QUADS);
        glColor3f (0.8, 0.2, 0.0);
        glVertex3f(-0.8, -0.2,  0);
        glVertex3f( -0.3, -0.2,  0);
        glVertex3f( -0.3, -0.7, 0);
        glVertex3f(-0.8, -0.7,  0);    	
        glEnd();


		glBegin(GL_QUADS);
        glColor3f (0.5, 0.2, 0.0);
        glVertex3f(-0.8, -0.2, 0);
        glVertex3f( -0.8, -0.2, 0.5);
        glVertex3f( -0.3, -0.2, 0.5);
        glVertex3f(-0.3, -0.2,  0);    	
        glEnd();

		glBegin(GL_QUADS);
        glColor3f (0.7, 0.3, 0.4);
        glVertex3f(-0.8, -0.2,  0);
        glVertex3f( -0.8, -0.2,  0);
        glVertex3f( -0.3, -0.7, 0);
        glVertex3f(-0.8, -0.7,  0);    	
        glEnd();



		glBegin(GL_QUADS);
        glColor3f (0.3, 0.6, 0.2);
        glVertex3f(-0.8, -0.2, 0.5);
        glVertex3f( -0.3, -0.2, 0.5);
        glVertex3f( -0.3, -0.7, 0.5);
        glVertex3f(-0.8, -0.7,  0.5);    	
        glEnd();


		glBegin(GL_QUADS);
        glColor3f (0.4, 0.9, 0.2);
        glVertex3f(-0.8, -0.7, 0.5);
        glVertex3f( -0.3, -0.7, 0.5);
        glVertex3f( -0.3, -0.7, 0);
        glVertex3f(-0.8, -0.7,  0);    	
        glEnd();


		glBegin(GL_QUADS);
        glColor3f (0.4, 0.6, 0.3);
        glVertex3f(-0.3, -0.2, 0);
        glVertex3f( -0.3, -0.2, 0.5);
        glVertex3f( -0.3, -0.7, 0.5);
        glVertex3f(-0.3, -0.7,  0);    	
        glEnd();

     }



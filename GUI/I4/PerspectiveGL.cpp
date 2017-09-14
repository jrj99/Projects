#include <QGLWidget>
#include <PerspectiveGL.h>



    PerspectiveGL::PerspectiveGL(QWidget *parent)
        : QGLWidget(parent) {}



    void PerspectiveGL::initializeGL()
    {
        // Set up the rendering context, define display lists etc.:
    	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glFrustum(-1,1,-1,1,-1,1);

	glClearDepth(1.0f);
    	glEnable(GL_DEPTH_TEST);
    	glDepthFunc(GL_LEQUAL);
    }

    void PerspectiveGL::resizeGL(int w, int h)
    {
        // setup viewport, projection etc.:
        glViewport(0, 0, (GLint)w, (GLint)h);
    }

    void PerspectiveGL::paintGL()
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

		glPushMatrix();
		glLoadIdentity();
		
		glTranslatef(0.5, 0.5, 0);
		glScalef(0.3, 0.7, 0);
		
		
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

		glPopMatrix();

       //draw a cube:


//back side

		glPushMatrix();
		glLoadIdentity();
		glTranslatef(-0.5,0.0, 0);
	    glRotatef(90.0, 0, 1.0, 0);
	    glRotatef(90.0,1.0f,1.0f,1.0f);
		glTranslatef(0.2,0.2,0);
		glBegin(GL_QUADS);
        glColor3f (0.8, 0.2, 0.0);
        glVertex3f(-0.8, -0.2,  0);
        glVertex3f( -0.3, -0.2,  0);
        glVertex3f( -0.3, -0.7, 0);
        glVertex3f(-0.8, -0.7,  0);    	
        glEnd();
        
 //      	glPopMatrix();

//top side

		glBegin(GL_QUADS);
        glColor3f (0.5, 0.2, 0.0);
        glVertex3f(-0.8, -0.2, 0);
        glVertex3f( -0.8, -0.2, 0.5);
        glVertex3f( -0.3, -0.2, 0.5);
        glVertex3f(-0.3, -0.2,  0);    	
        glEnd();

//left side

		glBegin(GL_QUADS);
        glColor3f (0.7, 0.3, 0.4);
        glVertex3f(-0.8, -0.2,  0);
        glVertex3f( -0.8, -0.2,  0.5);
        glVertex3f( -0.8, -0.7, 0.5);
        glVertex3f(-0.8, -0.7,  0);    	
        glEnd();


//front side

		glBegin(GL_QUADS);
        glColor3f (0.3, 0.6, 0.2);
        glVertex3f(-0.8, -0.2, 0.5);
        glVertex3f( -0.3, -0.2, 0.5);
        glVertex3f( -0.3, -0.7, 0.5);
        glVertex3f(-0.8, -0.7,  0.5);    	
        glEnd();

//bottom side

		glBegin(GL_QUADS);
        glColor3f (0.4, 0.9, 0.2);
        glVertex3f(-0.8, -0.7, 0.5);
        glVertex3f( -0.3, -0.7, 0.5);
        glVertex3f( -0.3, -0.7, 0);
        glVertex3f(-0.8, -0.7,  0);    	
        glEnd();

//right side

		glBegin(GL_QUADS);
        glColor3f (0.4, 0.6, 0.3);
        glVertex3f(-0.3, -0.2, 0);
        glVertex3f( -0.3, -0.2, 0.5);
        glVertex3f( -0.3, -0.7, 0.5);
        glVertex3f(-0.3, -0.7,  0);    	
        glEnd();
        
//move cube back

		glPopMatrix();
     }



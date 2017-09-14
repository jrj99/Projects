#ifndef PERSPECTIVEGL_H 
#define PERSPECTIVEGL_H 


#include <QtOpenGL/QGLWidget>

class PerspectiveGL : public QGLWidget
{
    Q_OBJECT        // must include this if you use Qt signals/slots
public:
    PerspectiveGL(QWidget *parent = 0);



protected:

    void initializeGL();
    void resizeGL(int w, int h);   
	 void paintGL();
};

#endif

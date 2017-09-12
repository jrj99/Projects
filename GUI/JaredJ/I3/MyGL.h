#ifndef MYGL_H
#define MYGL_H

#include <QtOpenGL/QGLWidget>

class MyGL : public QGLWidget
{
    Q_OBJECT        // must include this if you use Qt signals/slots
public:
    MyGL(QWidget *parent = 0);



protected:

    void initializeGL();
    void resizeGL(int w, int h);   
	 void paintGL();
};

#endif

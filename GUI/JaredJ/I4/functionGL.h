#ifndef FUNCTIONGL_H
#define FUNCTIONGL_H
#include <QtOpenGL/QGLWidget>
//#include <QtOpenGL/QGLFunctions>
//#include <QtOpenGL/QGLShaderProgram>

#include <QVector2D>
#include <QVector3D>

//#include "GraphicsWindow.h"



class functionGL : public QGLWidget
{

    Q_OBJECT        // must include this if you use Qt signals/slots
public:
    functionGL(QWidget *parent = 0);
     	 void paintGL();  
   void setVariables(double xi, double Ai, double Bi, double Ci, double Ti);




protected:

    void initializeGL();
    void resizeGL(int w, int h);


};

#endif

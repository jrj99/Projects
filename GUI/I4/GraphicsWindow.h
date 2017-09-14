#include <QVBoxLayout>
#include <QApplication>
#include <QtOpenGL/QGLWidget>
#include <QString>
#include <cmath>
#include "PerspectiveGL.h"
#include "functionGL.h"

#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H


class GraphicsWindow : public QWidget
{
    Q_OBJECT

public:
    GraphicsWindow();
    void setSize(int w, int h);
	void DrawOptionOne();
    void DrawOptionTwo(int MValue, int KValue, int NValue);
	void SetTitle(QString const &name);


private:

functionGL *functionWindow; 
QWidget *window; 
QVBoxLayout *PerspectiveLayout;
QVBoxLayout *ParallelLayout;


};



#endif

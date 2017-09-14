
#include "GraphicsWindow.h"
#include "Common.h"



double x_val;
double A;
double B;
double C;
double T;

GraphicsWindow::GraphicsWindow()
{
		


	setMinimumSize( 400, 400);		
	PerspectiveLayout = new QVBoxLayout();
	ParallelLayout = new QVBoxLayout();
	functionWindow = new functionGL();
	setWindowTitle("Graphics Window II");		
}

void GraphicsWindow::setSize(int w, int h)
{
	setMinimumSize( w, h);		
}

void GraphicsWindow::SetTitle(QString const &name)
{
    setWindowTitle(name);

}
void GraphicsWindow::DrawOptionOne()
{
	PerspectiveGL *ShapeWindow = new PerspectiveGL();
    ShapeWindow->setMinimumSize(300, 300);
	PerspectiveLayout->addWidget(ShapeWindow);
	setLayout(PerspectiveLayout);


}

void GraphicsWindow::DrawOptionTwo(int MValue, int KValue, int NValue)
{

		A = log2(MValue);
		B = log2(KValue);
		C = log2(NValue);
		T = A - B - C;
		
		setWindowTitle("Graphics Window II");		
		functionWindow->setMaximumSize(500,500);


		while(x_val <= T)
		{
		functionWindow->paintGL();
		x_val += 0.1;
		}
		
		ParallelLayout->addWidget(functionWindow);
		setLayout(ParallelLayout);
}
		
		
		
		
		
			
				
				
				
				

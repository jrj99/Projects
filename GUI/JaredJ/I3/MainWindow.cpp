#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QButtonGroup>
#include <QSpinBox>
#include <QSlider>
#include <QDial>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QTabWidget>
#include <QLCDNumber>
#include <QPalette>
#include <cmath>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMenu>
#include <QAction>
#include <QDockWidget>
#include <QMessageBox>
#include <QStatusBar>
#include <QMenuBar>
#include <QStringBuilder>

#include "MainWindow.h"
#include "MyGL.h"


MainWindow::MainWindow()
{


    setMinimumSize( 1600, 850);
    createActions();
    createMenus();
    createStatusBar();
    createWindows();

    setWindowTitle(tr("Dock Widgets"));

}

void MainWindow::save()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                        tr("Choose a file name"), ".",
                        tr("PlainText (*.txt)"));
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Dock Widgets"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }
    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << textEdit->toPlainText();
    QApplication::restoreOverrideCursor();

    statusBar()->showMessage(tr("Saved '%1'").arg(fileName), 2000);
}

void MainWindow::help()
{
   QMessageBox::about(this, tr("Help"),
            tr("Will insert help later"));
}


void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                        tr("Choose a file name"), ".",
                        tr("PlainText (*.txt)"));
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly| QFile::Text)) {
        QMessageBox::warning(this, tr("Dock Widgets"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }
    QTextStream ReadFile(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    textEdit->setText(ReadFile.readAll());
    QApplication::restoreOverrideCursor();

    statusBar()->showMessage(tr("Opened '%1'").arg(fileName), 2000);
}

void MainWindow::open_0x()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                        tr("Choose a file name"), ".",
                        tr("PlainText (*.txt)"));
    if (fileName.isEmpty())
        return;
    QFile inputfile(fileName);
    if (!inputfile.open(QFile::ReadOnly| QFile::Text)) {
        QMessageBox::warning(this, tr("Dock Widgets"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(inputfile.errorString()));
        return;	
		}
	QString a = fileName;
    QString remove = ".txt";
    a.remove(QString(remove));
    QString temp = "hex.txt";
    QString result = a + temp; 

    QFile outputfile(result);
    if (!outputfile.open(QIODevice::Append |QIODevice::Text)) {
        QMessageBox::warning(this, tr("Dock Widgets"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(result)
                             .arg(outputfile.errorString()));
        return;	
		}


	QTextStream out(&outputfile);
	QTextStream in(&inputfile);
    QString hex = "0x";
    while(!in.atEnd())
    {
        QString line = in.readLine();
        out << hex;
        out << line;
        out << "\n";
        
    }

}
void MainWindow::ReferenceCalculate(int value)
{
	int MValue = value;
	double R_Word = log2(MValue);
	RWord = (int)R_Word;
	ReferenceData->display(RWord);

}

void MainWindow::OffsetCalculate(int value)
{
	int KValue = value;
	double O_Word = log2(KValue);
	OField = (int)O_Word;
	OffsetSizeData->display(OField); 

}



void MainWindow::IndexFieldCalculate(int value)
{
	int NValue = value;
	double I_Field = log2(NValue);
	IField = (int)I_Field;

	IndexFieldData->display(IField);
   
}

void MainWindow::TagFieldCalculate()
{
	TField = RWord - OField;
	TField = TField - IField;	
	TagFieldData->display(TField);
}

void MainWindow::createActions()
{


    saveAct = new QAction(QIcon(":/home/csdept/Documents"), tr("&Save..."), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the current status log"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    openAct = new QAction(QIcon(":/home/csdept/Documents"), tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open the current status log"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    quitAct = new QAction(tr("&Quit"), this);
    quitAct->setShortcuts(QKeySequence::Quit);
    quitAct->setStatusTip(tr("Quit the application"));
    connect(quitAct, SIGNAL(triggered()), this, SLOT(close()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(help()));

    openHexAct = new QAction(tr("&Convert"), this);
    openHexAct->setStatusTip(tr("Open and append 0x into hex file"));
    connect(openHexAct, SIGNAL(triggered()), this, SLOT(open_0x()));

}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(saveAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(openHexAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
}


void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::createWindows()
{

////////////////   CREATING DOCK WINDOWS    ////////////////////////////////////

//initialize widgets
    QSpinBox *NSpinBox = new QSpinBox;
    QSpinBox *LSpinBox = new QSpinBox;
 	
	QDial *NDial = new QDial();    
	QDial *LDial = new QDial();    

    QPushButton *Ibutton = new QPushButton("I_Cache");
    QPushButton *Dbutton = new QPushButton("D_Cache");
	QPushButton *StartButton = new QPushButton("Start");
	QPushButton *GoButton = new QPushButton("Go");
	QPushButton *StepSButton = new QPushButton("Step S");
	QPushButton *BreakButton = new QPushButton("Break B");	
	QRadioButton *LRUbutton = new QRadioButton("LRU");
	QRadioButton *LFUbutton = new QRadioButton("LFU");
	QRadioButton *RandomButton = new QRadioButton("Random");

	
//adds notches to dials

	NDial->setNotchesVisible(true);
	LDial->setNotchesVisible(true);


//creates the replacement groupbox of radio buttons

	QDockWidget *dock = new QDockWidget(tr("Cache Replacement Policy"));
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);

    QGroupBox *ReplacementGroup = new QGroupBox(dock);

    LRUbutton->setChecked(true);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(LRUbutton);
    hbox->addWidget(LFUbutton);
    hbox->addWidget(RandomButton);
    ReplacementGroup->setLayout(hbox);
	dock->setWidget(ReplacementGroup);
	addDockWidget(Qt::LeftDockWidgetArea, dock);

	

//creates the Cache groupbox of push buttons

	dock = new QDockWidget(tr("Cache Type"));
    dock->setAllowedAreas(Qt::RightDockWidgetArea);

	QButtonGroup *StateGroup = new QButtonGroup();
	StateGroup->addButton(Ibutton);
	StateGroup->addButton(Dbutton);
	Ibutton->setCheckable(true);
	Dbutton->setCheckable(true);
	Ibutton->setChecked(true);	    
	QGroupBox *CacheGroup = new QGroupBox(dock);
	QHBoxLayout *hbox_2 = new QHBoxLayout;
	hbox_2->addWidget(Ibutton);
	hbox_2->addWidget(Dbutton);
	CacheGroup->setLayout(hbox_2);
    dock->setWidget(CacheGroup);
    addDockWidget(Qt::RightDockWidgetArea, dock);

//set ranges of spinboxes and sliders
	NSpinBox->setRange(1, 16);
	LSpinBox->setRange(1, 16);

	NDial->setRange(1, 16);
	LDial->setRange(1, 16);	

//creates groups of N, L, and K widgets

    dock = new QDockWidget(tr("Number of Sets"));
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);

	QGroupBox *NGroup = new QGroupBox();
    QHBoxLayout *hbox_X = new QHBoxLayout;
	hbox_X->addWidget(NSpinBox);
	hbox_X->addWidget(NDial);
	NGroup->setLayout(hbox_X);

    dock->setWidget(NGroup);
    addDockWidget(Qt::LeftDockWidgetArea, dock);

    dock = new QDockWidget(tr("Number of Ways"));
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);

	QGroupBox *LGroup = new QGroupBox(dock);
    QHBoxLayout *hbox_Y = new QHBoxLayout;
	hbox_Y->addWidget(LSpinBox);
	hbox_Y->addWidget(LDial);
	LGroup->setLayout(hbox_Y);

    dock->setWidget(LGroup);
    addDockWidget(Qt::LeftDockWidgetArea, dock);

    dock = new QDockWidget(tr("Bytes Per Block"));
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);
   	QSpinBox *KSpinBox = new QSpinBox(dock);
	KSpinBox->setRange(4, 1024);
	dock->setWidget(KSpinBox);
	addDockWidget(Qt::LeftDockWidgetArea, dock);

    dock = new QDockWidget(this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);
	QSlider *Kslider = new QSlider(Qt::Horizontal,dock);
	Kslider->setRange(4, 1024);
	dock->setWidget(Kslider);
	addDockWidget(Qt::LeftDockWidgetArea, dock);


//connect signals of spin boxes and sliders
	QObject::connect(NSpinBox, SIGNAL(valueChanged(int)),
	NDial, SLOT(setValue(int)));
	QObject::connect(NDial, SIGNAL(valueChanged(int)),
	NSpinBox, SLOT(setValue(int)));	
	
	QObject::connect(LSpinBox, SIGNAL(valueChanged(int)),
	LDial, SLOT(setValue(int)));
	QObject::connect(LDial, SIGNAL(valueChanged(int)),
	LSpinBox, SLOT(setValue(int)));	
	
	QObject::connect(KSpinBox, SIGNAL(valueChanged(int)),
	Kslider, SLOT(setValue(int)));
	QObject::connect(Kslider, SIGNAL(valueChanged(int)),
	KSpinBox, SLOT(setValue(int)));

//Create data output boxes and labels
  
    dock = new QDockWidget(tr("Memory Access Instances"));
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);

	QLCDNumber *MemoryData = new QLCDNumber(dock);  
	MemoryData->setSegmentStyle(QLCDNumber::Flat);
	MemoryData->display(1337);
	MemoryData->setMinimumSize(240,30);
	MemoryData->setMaximumSize(240,30);

	dock->setWidget(MemoryData);
	addDockWidget(Qt::RightDockWidgetArea, dock);

    dock = new QDockWidget(tr("Hit Ratio"));
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);

	QLCDNumber *HitRatioData = new QLCDNumber(dock);  
	HitRatioData->setSegmentStyle(QLCDNumber::Flat);    
	HitRatioData->setMinimumSize(240,30);
	HitRatioData->setMaximumSize(240,30);	

	dock->setWidget(HitRatioData);
	addDockWidget(Qt::RightDockWidgetArea, dock);

    dock = new QDockWidget(tr("Compulsory Miss Ratio"));
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);

	QLCDNumber *CompulsoryRatioData = new QLCDNumber(dock);  
	CompulsoryRatioData->setSegmentStyle(QLCDNumber::Flat);
	CompulsoryRatioData->setMinimumSize(240,30);
	CompulsoryRatioData->setMaximumSize(240,30);

	dock->setWidget(CompulsoryRatioData);
	addDockWidget(Qt::RightDockWidgetArea, dock);

    dock = new QDockWidget(tr("Miss Ratio"));
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);

	QLCDNumber *MissRatioData = new QLCDNumber(dock);  
	MissRatioData->setSegmentStyle(QLCDNumber::Flat);
	MissRatioData->setMinimumSize(240,30);
	MissRatioData->setMaximumSize(240,30);

	dock->setWidget(MissRatioData);
	addDockWidget(Qt::RightDockWidgetArea, dock);

//Sets color Palette for LCD displays.
	QPalette palette = MemoryData->palette();
	palette.setColor(QPalette::WindowText, QColor(77,255,41));
	palette.setColor(QPalette::Window, Qt::black);	
	MemoryData->setPalette(palette); 
    MemoryData->setAutoFillBackground(true);
	HitRatioData->setPalette(palette); 
    HitRatioData->setAutoFillBackground(true);
    CompulsoryRatioData->setPalette(palette); 	
    CompulsoryRatioData->setAutoFillBackground(true);	
    MissRatioData->setPalette(palette); 	
    MissRatioData->setAutoFillBackground(true);	  




//creates a Simulation groupbox of push buttons

    dock = new QDockWidget(tr("SimulationControls"));
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);

    QGroupBox *SimulationGroupOne = new QGroupBox(dock);
	SimulationGroupOne->setFlat(true);
    QHBoxLayout *hbox_3 = new QHBoxLayout;
    hbox_3->addWidget(StartButton);
    hbox_3->addWidget(GoButton);
    SimulationGroupOne->setLayout(hbox_3);

	dock->setWidget(SimulationGroupOne);
	addDockWidget(Qt::LeftDockWidgetArea, dock);

//creates an additional Simulation groupbox of push buttons

    dock = new QDockWidget(this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea);

    QGroupBox *SimulationGroupTwo = new QGroupBox(dock);
	SimulationGroupTwo->setFlat(true);
    QHBoxLayout *hbox_4 = new QHBoxLayout;
    hbox_4->addWidget(StepSButton);
    hbox_4->addWidget(BreakButton);
    SimulationGroupTwo->setLayout(hbox_4);

	dock->setWidget(SimulationGroupTwo);
	addDockWidget(Qt::LeftDockWidgetArea, dock);		



////////////////   CREATING CENTRAL WIDGET    ////////////////////////////////////

//declare widgets  
	QWidget *CentralWidget = new QWidget; 
    QSpinBox *MemorySpinBox = new QSpinBox;	
  
//set range of spinboxes and sliders
	QLabel *MemoryInputLabel = new QLabel("Two to the power of: ");	
	MemorySpinBox->setRange(8, 28);
    QGroupBox *MemoryBox = new QGroupBox();
	QVBoxLayout *vMem = new QVBoxLayout;		
	vMem->addWidget(MemoryInputLabel);
	vMem->addWidget(MemorySpinBox);
    MemoryBox->setLayout(vMem);


//Create data output boxes and labels    

	int LabelHeight = 22;   

    QLabel *ReferenceLabel = new QLabel("Reference word size");
	ReferenceLabel->setFixedHeight(LabelHeight);	
	ReferenceLabel->setAlignment(Qt::AlignBottom|Qt::AlignCenter);
	ReferenceData = new QLCDNumber;  
	ReferenceData->setSegmentStyle(QLCDNumber::Flat);

	ReferenceData->setMinimumSize(240,30);
	ReferenceData->setMaximumSize(240,30);

    QLabel *OffsetSizeLabel = new QLabel("Size of Offset field (in bits)");
	OffsetSizeLabel->setFixedHeight(LabelHeight);	
	OffsetSizeLabel->setAlignment(Qt::AlignBottom|Qt::AlignCenter);
	OffsetSizeData = new QLCDNumber;   
	OffsetSizeData ->setSegmentStyle(QLCDNumber::Flat);

	OffsetSizeData ->setMinimumSize(240,30);
	OffsetSizeData ->setMaximumSize(240,30);	


    QLabel *IndexFieldLabel = new QLabel("Size of Index Field (in bits)");
	IndexFieldLabel->setFixedHeight(LabelHeight);	
	IndexFieldLabel->setAlignment(Qt::AlignBottom|Qt::AlignCenter);
	IndexFieldData = new QLCDNumber;  
	IndexFieldData->setSegmentStyle(QLCDNumber::Flat);

	IndexFieldData->setMinimumSize(240,30);
	IndexFieldData->setMaximumSize(240,30);


    QLabel *TagFieldLabel = new QLabel("Size of Tag Field (in bits)");
	TagFieldLabel->setFixedHeight(LabelHeight);	
	TagFieldLabel->setAlignment(Qt::AlignBottom|Qt::AlignCenter);
	TagFieldData = new QLCDNumber;  
	TagFieldData->setSegmentStyle(QLCDNumber::Flat);

	TagFieldData->setMinimumSize(240,30);
	TagFieldData->setMaximumSize(240,30);	

//create text editor

	textEdit = new QTextEdit;


//sets layout of labels and memory group


    QVBoxLayout *labelLayout = new QVBoxLayout();
    labelLayout->addWidget(ReferenceLabel);
    labelLayout->addWidget(ReferenceData);
    labelLayout->addWidget(OffsetSizeLabel);
    labelLayout->addWidget(OffsetSizeData);
    labelLayout->addWidget(IndexFieldLabel);
    labelLayout->addWidget(IndexFieldData);
    labelLayout->addWidget(TagFieldLabel);
    labelLayout->addWidget(TagFieldData);
    QWidget *SideWidget = new QWidget;
    QVBoxLayout *SideLayout = new QVBoxLayout(SideWidget);
    SideLayout->addWidget(textEdit);
    SideLayout->addWidget(MemoryBox);
    SideLayout->addLayout(labelLayout);
    SideWidget->setMaximumWidth(250);


//do some calculating


	int KValue = KSpinBox->value();
	int NValue =	NSpinBox->value();
	int MValue = MemorySpinBox->value();
	double R_Word = log2(MValue);
	double O_Field = log2(KValue);
	double I_Field = log2(NValue);
	int RtempWord = (int)R_Word;
	int OtempField = (int)O_Field;
    int ItempField = (int)I_Field;
	int TtempField = RtempWord - OtempField - ItempField;


//update LCD displays
	QObject::connect(MemorySpinBox, SIGNAL(valueChanged(int)),
	this, SLOT(ReferenceCalculate(int)));

	QObject::connect(KSpinBox, SIGNAL(valueChanged(int)),
	this, SLOT(OffsetCalculate(int)));

	QObject::connect(NSpinBox, SIGNAL(valueChanged(int)),
	this, SLOT(IndexFieldCalculate(int)));


	QObject::connect(NSpinBox, SIGNAL(valueChanged(int)),
	this, SLOT(TagFieldCalculate()));

	QObject::connect(KSpinBox, SIGNAL(valueChanged(int)),
	this, SLOT(TagFieldCalculate()));

	QObject::connect(MemorySpinBox, SIGNAL(valueChanged(int)),
	this, SLOT(TagFieldCalculate()));


	ReferenceData->display(RtempWord);
	OffsetSizeData->display(OtempField);    
	IndexFieldData->display(ItempField);	
	TagFieldData->display(TtempField);

//Sets color Palette for LCD displays.



	ReferenceData->setPalette(palette); 
    ReferenceData->setAutoFillBackground(true);
    OffsetSizeData->setPalette(palette); 	
    OffsetSizeData->setAutoFillBackground(true);	
    IndexFieldData->setPalette(palette); 	
    IndexFieldData->setAutoFillBackground(true);
    TagFieldData->setPalette(palette); 	
    TagFieldData->setAutoFillBackground(true);	
//creates 800 x 800 graphics window


    MyGL *drawingWindow = new MyGL();
    drawingWindow->setMaximumSize(800, 800);


//sets the layout of central widget

	QHBoxLayout *CentralLayout = new QHBoxLayout;
	CentralLayout->addWidget(drawingWindow);    
    CentralLayout->addWidget(SideWidget);
	CentralWidget->setLayout(CentralLayout);
    setCentralWidget(CentralWidget);


}





    


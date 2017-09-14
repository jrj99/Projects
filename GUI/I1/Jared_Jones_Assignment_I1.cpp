
//								Name:   Jared Jones




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

#include <QLCDNumber>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
	QWidget *window = new QWidget;

//initialize widgets
    QSpinBox *NspinBox = new QSpinBox;
    QSpinBox *LspinBox = new QSpinBox;
    QSpinBox *KspinBox = new QSpinBox;	
	QDial *Ndial = new QDial();    
	QDial *Ldial = new QDial();    
	QSlider *Kslider = new QSlider(Qt::Horizontal);
    QPushButton *Ibutton = new QPushButton("I_Cache");
    QPushButton *Dbutton = new QPushButton("D_Cache");
    QPushButton *Exitbutton = new QPushButton("Exit");	
	QRadioButton *LRUbutton = new QRadioButton("LRU");
	QRadioButton *LFUbutton = new QRadioButton("LFU");
	QRadioButton *RandomButton = new QRadioButton("Random");
	
//adds notches to dials

	Ndial->setNotchesVisible(true);
	Ldial->setNotchesVisible(true);


//creates the replacement groupbox of radio buttons

    QGroupBox *ReplacementGroup = new QGroupBox("Cache Replacement Policy");

    LRUbutton->setChecked(true);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(LRUbutton);
    hbox->addWidget(LFUbutton);
    hbox->addWidget(RandomButton);
    ReplacementGroup->setLayout(hbox);

//creates the Cache groupbox of push buttons

	QButtonGroup *StateGroup = new QButtonGroup();
	StateGroup->addButton(Ibutton);
	StateGroup->addButton(Dbutton);
	Ibutton->setCheckable(true);
	Dbutton->setCheckable(true);
	Ibutton->setChecked(true);	    
	QGroupBox *CacheGroup = new QGroupBox("Cache Type");
	QHBoxLayout *hbox_2 = new QHBoxLayout;
	hbox_2->addWidget(Ibutton);
	hbox_2->addWidget(Dbutton);
	CacheGroup->setLayout(hbox_2);

//set ranges of spinboxes and sliders
	NspinBox->setRange(1, 16);
	LspinBox->setRange(1, 16);
	KspinBox->setRange(4, 1024);
	Ndial->setRange(1, 16);
	Ldial->setRange(1, 16);	
	Kslider->setRange(4, 1024);

//connect signals of spin boxes and sliders
	QObject::connect(NspinBox, SIGNAL(valueChanged(int)),
	Ndial, SLOT(setValue(int)));
	QObject::connect(Ndial, SIGNAL(valueChanged(int)),
	NspinBox, SLOT(setValue(int)));	
	
	QObject::connect(LspinBox, SIGNAL(valueChanged(int)),
	Ldial, SLOT(setValue(int)));
	QObject::connect(Ldial, SIGNAL(valueChanged(int)),
	LspinBox, SLOT(setValue(int)));	
	
	QObject::connect(KspinBox, SIGNAL(valueChanged(int)),
	Kslider, SLOT(setValue(int)));
	QObject::connect(Kslider, SIGNAL(valueChanged(int)),
	KspinBox, SLOT(setValue(int)));	
	




//Create data output boxes and labels
	int LabelHeight = 28;    
	QLabel *label = new QLabel("Data");
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label->setText("first line\nsecond line");
    label->setAlignment(Qt::AlignBottom | Qt::AlignRight);

    QLabel *Nlabel = new QLabel("Number of sets");
    QLabel *Llabel = new QLabel("Number of ways");
    QLabel *Klabel = new QLabel("Number of bytes per block");

    QLabel *Memorylabel = new QLabel("Number of Memory Access Instances");
	Memorylabel->setFixedHeight(LabelHeight);	
	Memorylabel->setAlignment(Qt::AlignBottom|Qt::AlignCenter);
	QLCDNumber *MemoryData = new QLCDNumber;  
	MemoryData->setSegmentStyle(QLCDNumber::Flat);
	MemoryData->display(1337);
	MemoryData->setMinimumSize(240,30);
	MemoryData->setMaximumSize(240,30);

    QLabel *HitRatiolabel = new QLabel("Hit Ratio");
	HitRatiolabel->setFixedHeight(LabelHeight);	
	HitRatiolabel->setAlignment(Qt::AlignBottom|Qt::AlignCenter);
	QLCDNumber *HitRatioData = new QLCDNumber;  
	HitRatioData->setSegmentStyle(QLCDNumber::Flat);    
	HitRatioData->setMinimumSize(240,30);
	HitRatioData->setMaximumSize(240,30);	


    QLabel *CompulsoryRatiolabel = new QLabel("Compulsory Miss Ratio");
	CompulsoryRatiolabel->setFixedHeight(LabelHeight);	
	CompulsoryRatiolabel->setAlignment(Qt::AlignBottom|Qt::AlignCenter);
	QLCDNumber *CompulsoryRatioData = new QLCDNumber;  
	CompulsoryRatioData->setSegmentStyle(QLCDNumber::Flat);
	CompulsoryRatioData->setMinimumSize(240,30);
	CompulsoryRatioData->setMaximumSize(240,30);


    QLabel *MissRatiolabel = new QLabel("Miss Ratio");
	MissRatiolabel->setFixedHeight(LabelHeight);	
	MissRatiolabel->setAlignment(Qt::AlignBottom|Qt::AlignCenter);
	QLCDNumber *MissRatioData = new QLCDNumber;  
	MissRatioData->setSegmentStyle(QLCDNumber::Flat);
	MissRatioData->setMinimumSize(240,30);
	MissRatioData->setMaximumSize(240,30);


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



//closes window if exit button is pressed

	QObject::connect(Exitbutton, SIGNAL(clicked()), qApp, SLOT(quit()));


//setup the output window
	window->setWindowTitle("Cache Simulation Application");
	QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(ReplacementGroup);
	layout->addWidget(CacheGroup);
	layout->addWidget(Nlabel);	
	layout->addWidget(NspinBox);
	layout->addWidget(Ndial);
	layout->addWidget(Llabel);	
	layout->addWidget(LspinBox);
	layout->addWidget(Ldial);
	layout->addWidget(Klabel);	
	layout->addWidget(KspinBox);
	layout->addWidget(Kslider);
    layout->addWidget(Memorylabel);
	layout->addWidget(MemoryData);
    layout->addWidget(HitRatiolabel);
	layout->addWidget(HitRatioData);
    layout->addWidget(CompulsoryRatiolabel);
	layout->addWidget(CompulsoryRatioData);
    layout->addWidget(MissRatiolabel);
	layout->addWidget(MissRatioData);
	layout->addWidget(Exitbutton);
	window->setLayout(layout);
	window->show();
    return app.exec();
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>

class QAction;
class QListWidget;
class QMenu;
class QTextEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void save();
    void open();
	void open_0x();
    void help();
	void ReferenceCalculate(int);
    void OffsetCalculate(int);
    void IndexFieldCalculate(int);
    void TagFieldCalculate();	

private:
    void createActions();
    void createMenus();
    void createStatusBar();
    void createWindows();

    QTextEdit *textEdit;
    QListWidget *customerList;
    QListWidget *paragraphsList;
	QLCDNumber *ReferenceData; 
	QLCDNumber *OffsetSizeData;
 	QLCDNumber *IndexFieldData;
	QLCDNumber *TagFieldData; 

    QMenu *fileMenu;
    QMenu *helpMenu;
    QAction *saveAct;
	QAction *openAct;
	QAction *openHexAct;
    QAction *aboutAct;
    QAction *quitAct;
	
	int RWord;
	int OField;
	int IField;
	int TField;

};

#endif



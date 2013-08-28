#include "myclass.h"




MyClass::MyClass(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	ui.line1_2->setVisible(false);
	ui.line2_3->setVisible(false);
	ui.step2Widget->setVisible(false);
	ui.step3Widget->setVisible(false);
	ui.skillLabelShow->setVisible(false);
	conn = database::connectByC();
	

	model = new QStandardItemModel(this); //2 Rows and 3 Columns
	model->setHorizontalHeaderItem(0, new QStandardItem(QString("Class name")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QString("Res date")));
	model->setHorizontalHeaderItem(2, new QStandardItem(QString("Member")));
	model->setHorizontalHeaderItem(3, new QStandardItem(QString("Course")));
	model->setHorizontalHeaderItem(4, new QStandardItem(QString("% day")));
	model->setHorizontalHeaderItem(5, new QStandardItem(QString("% material")));

	// Add value to a cell in table
	QStandardItem *firstRow = new QStandardItem(QString("ColumnValue"));
	model->setItem(0,0,firstRow);

	QStandardItem *row2 = new QStandardItem(QString("ColumnValue"));
	model->setItem(0,1,row2);

	QStandardItem *row3 = new QStandardItem(QString("ColumnValue"));
	model->setItem(0,2,row3);

	QStandardItem *row4 = new QStandardItem(QString("ColumnValue"));
	model->setItem(0,3,row4);
	 
	ui.listTable->setModel(model);
}

MyClass::~MyClass()
{
	database::closeConnectionC(conn);
}

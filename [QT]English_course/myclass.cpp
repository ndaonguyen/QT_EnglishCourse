#include "myclass.h"




MyClass::MyClass(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	loadConfigAddCourseTab();
	configButton();
	conn = database::connectByC();
//	ui.listCourseTable->setModel(listCourseModel);
	loadListCourseTab();
	loadListClassTab();
}

MyClass::~MyClass()
{
	database::closeConnectionC(conn);
}

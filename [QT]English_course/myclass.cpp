#include "myclass.h"




MyClass::MyClass(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	loadConfigAddCourseTab();
	configButton();
	conn = database::connectByC();
	loadListCourseTab();
	loadListClassTab();
	
	loadConfigClass();
	loadDataAddClassTab(0);
	
}

MyClass::~MyClass()
{
	database::closeConnectionC(conn);
}

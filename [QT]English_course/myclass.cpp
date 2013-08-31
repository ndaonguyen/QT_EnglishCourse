#include "myclass.h"




MyClass::MyClass(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	configButton();

	conn = database::connectByC();
	loadConfigAddCourseTab();
	loadListCourseTab();
	loadListClassTab();
}

MyClass::~MyClass()
{
	database::closeConnectionC(conn);
}

#include <QtGui>
#include "listMemberDialog.h"


listMemberDialog::listMemberDialog(QWidget *parent,QString classId)
{
	conn = database::connectByC();
	QVBoxLayout *topLeftLayout = new QVBoxLayout;

	view  = new QTableView(this);
	model = new QStandardItemModel(this);
	view->setModel(model);

	model->setHorizontalHeaderItem(0, new QStandardItem(tr("ID")));
	model->setHorizontalHeaderItem(1, new QStandardItem(tr("Name")));
	model->setHorizontalHeaderItem(2, new QStandardItem(tr("Birth year")));
	model->setHorizontalHeaderItem(3, new QStandardItem(tr("Note")));
	model->setHorizontalHeaderItem(4, new QStandardItem(tr("-")));
	
	view->setColumnWidth(0,20);
	view->setColumnWidth(1,90);
	view->setColumnWidth(2,55);
	view->setColumnWidth(3,40);
	view->setColumnWidth(4,30);
	
	label = new QLabel("Member list");
	topLeftLayout->addWidget(label);
	int rowCurrent = 0;

	MYSQL_RES *res = database::classMember_searchClassId(conn,classId);
	while(MYSQL_ROW classMemberRow = mysql_fetch_row(res))
	{
		QString memberId   = classMemberRow[1];
		MYSQL_ROW memberRow = database::member_searchMemberId(conn,memberId);
		
		model->setItem(rowCurrent, 0, new QStandardItem(memberRow[0]));
		model->setItem(rowCurrent, 1, new QStandardItem(memberRow[1]));
		model->setItem(rowCurrent, 2, new QStandardItem(memberRow[2]));
		model->setItem(rowCurrent, 3, new QStandardItem(memberRow[3]));

		QPushButton *button = new QPushButton("");
		QPixmap pixmap("Resources/Delete_icon.png");
		QIcon buttonIcon(pixmap);
		button->setIcon(buttonIcon);
		QSignalMapper *signalMapper = new QSignalMapper(this);
		signalMapper->setMapping(button,memberId);
		QObject::connect(button,SIGNAL(clicked()),signalMapper,SLOT(map()));
		QObject::connect(signalMapper,SIGNAL(mapped(QString)),this,SLOT(deleteMemberAction(QString)));
		view->setIndexWidget(model->index(rowCurrent,4),button);

		rowCurrent++;
	}
	topLeftLayout->addWidget(view);

	QPushButton *saveButton = new QPushButton("Save");
	QPixmap pixmap1("Resources/save_icon.png");
	QIcon ButtonIcon1(pixmap1);
	saveButton->setIcon(ButtonIcon1);
	QObject::connect(saveButton,SIGNAL(clicked()),this,SLOT(saveListAction()));
	topLeftLayout->addWidget(saveButton);

	setLayout(topLeftLayout);
	setWindowTitle(tr("Member list"));
	setFixedHeight(sizeHint().height());
	
}

listMemberDialog::~listMemberDialog(void)
{
	database::closeConnectionC(conn);
}

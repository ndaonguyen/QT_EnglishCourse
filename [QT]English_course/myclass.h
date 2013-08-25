#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtGui/QMainWindow>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QListWidgetItem>
#include "ui_myclass.h"
#include "database.h"

class MyClass : public QMainWindow
{
	Q_OBJECT
public: 
	QStandardItemModel *model;
	MYSQL *conn;
	// info course
	QString courseName;
	QList<QString> skillsCourse;
	bool step1;
	bool step2;
	bool step3;	
public:
	void fillDataStep2()
	{
		// update info to ListWidget of step 2			
		if(mysql_query(conn,"select * from  `english_course`.`skill`") ==0)
		{
			MYSQL_RES *res;
			res = mysql_store_result(conn);
			while (MYSQL_ROW row = mysql_fetch_row(res))
			{
				QString nameSkill = row[1];
				ui.leftWidget->addItem(nameSkill);
			}			
		}
	}

public:
	MyClass(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MyClass();

private:
	Ui::MyClassClass ui;
	private slots:
		void openFileAction()
		{
			// get data of a colum and row
			QString a = model->data(model->index(0,0), Qt::DisplayRole).toString();
			int b = 1;
		}

		void createAction()
		{
			
		}

		void editAction()
		{

		}

		void deleteAction()
		{

		}

		void saveAction()
		{

		}

		void step1SaveAction() // disable step 1, enable step 2, update info to info box
		{
			// check box name is empty
			if(ui.courseNameLineEdit->text().trimmed() == "")
			{
				QMessageBox::warning(this,tr("Course name"),tr("Please fill the blank!!"));
				ui.courseNameLineEdit->setFocus();
				return;
			}
			ui.step1Widget->setEnabled(false);
			courseName = ui.courseNameLineEdit->text();
			step1 = true;

			fillDataStep2();
			ui.step2Widget->setVisible(true);			
		}

		void step2SaveAction()
		{
			
		}

		void step3SaveAction()
		{

		}
		
		void left2RightAction()
		{
			ui.rightWidget->addItem(ui.leftWidget->takeItem(ui.leftWidget->currentRow()));
		}

		void right2LeftAction()
		{
			ui.leftWidget->addItem(ui.rightWidget->takeItem(ui.rightWidget->currentRow()));
		}

		void all2LeftAction()
		{
			int numElements = ui.rightWidget->count();
			for(int i =0;i<numElements;i++)
			{
				QListWidgetItem *item = ui.rightWidget->takeItem(0);
				ui.leftWidget->addItem(item);
			}
		}

		void all2RightAction()
		{
			int numElements = ui.leftWidget->count();
			for(int i =0;i<numElements;i++)
			{
				QListWidgetItem *item = ui.leftWidget->takeItem(0);
				ui.rightWidget->addItem(item);
			}
		}

		void left2RightClickAction()
		{
			QListWidgetItem *item2 = ui.leftWidget->takeItem(ui.leftWidget->currentRow());
			ui.rightWidget->addItem(item2);
		}

		void right2LeftClickAction()
		{
			QListWidgetItem *item2 = ui.rightWidget->takeItem(ui.rightWidget->currentRow());
			ui.leftWidget->addItem(item2);
		}

};

#endif // MYCLASS_H

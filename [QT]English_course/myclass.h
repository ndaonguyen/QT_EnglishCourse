#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtGui/QMainWindow>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QInputDialog>
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
	void setupConnectMaterial(QMainWindow *MyClassClass)
	{
		
	}

public:
	MyClass(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MyClass();

private:
	Ui::MyClassClass ui;
	private slots:
		void addMaterial()
		{
			int b = 0;
			int c = b;
		}

		void listMaterial(QString skill)
		{
			int a = 0;
		}

		void addSkillAction()
		{
			bool ok;
			QString text = QInputDialog::getText(this, tr("Add Skill"),tr("Skill:"), QLineEdit::Normal, tr("try try"),&ok);
				
			QString query = "INSERT INTO `english_course`.`skill` VALUES(NULL,'"+text+"')";
			std::string query2 = query.toStdString();
			const char* query1 = query2.c_str();

			if (ok && !text.isEmpty())
				if(mysql_query(conn,query1)==0)
					ui.leftWidget->addItem(text);
		}

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

			// info is updated to info box
			QLabel *courseLabel = new QLabel(ui.classInsertGroupBox);
			courseLabel->setText("<b>Course name:</b>");
			ui.step1Layout->addWidget(courseLabel);

			QLabel *courseNameShow = new QLabel(ui.classInsertGroupBox);
			courseNameShow->setText(courseName);
			ui.step1Layout->addWidget(courseNameShow);
		}

		void step2SaveAction() // save value to skillsCourse, fill step 3 info, step 3 appear, fill info into info bo
		{
			/*
			QVBoxLayout *skill = new QVBoxLayout(ui.step3Widget);
			skill->setSpacing(6);
			skill->setContentsMargins(11, 11, 11, 11);
			skill->setContentsMargins(0, 0, 0, 0);
			QRect rectLayoutSkill = ui.step3Widget->geometry();
			int xMargin = 100;
			int yMargin = 20;
			skill->setGeometry(QRect(rectLayoutSkill.x()+xMargin,rectLayoutSkill.y()+yMargin,rectLayoutSkill.width() - yMargin, rectLayoutSkill.height() - xMargin));
			*/

			QWidget *verticalLayoutWidget;
			QVBoxLayout *verticalLayout;			
			QHBoxLayout *horizontalLayout_2;

			verticalLayoutWidget = new QWidget(ui.step3Widget);
			verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
		
			QRect rectLayoutSkill = ui.step3Widget->geometry();
			int xMargin = 100;
			int yMargin = 20;
	//		verticalLayoutWidget->setGeometry(QRect(rectLayoutSkill.x()+xMargin,rectLayoutSkill.y()+yMargin,rectLayoutSkill.width() - yMargin, rectLayoutSkill.height() - xMargin));
			
			verticalLayoutWidget->setGeometry(QRect(30, 40, 321, 201));
			verticalLayout = new QVBoxLayout(verticalLayoutWidget);
			verticalLayout->setSpacing(6);
			verticalLayout->setContentsMargins(11, 11, 11, 11);
			verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
			verticalLayout->setContentsMargins(0, 0, 0, 0);

			int numElement = ui.rightWidget->count();
			QList <QPushButton*> qListButtonAdd;
			QList <QPushButton*> qListButtonList;
			for( int i =0;i<numElement;i++)
			{
				QString skill = ui.rightWidget->item(i)->text();
				skillsCourse.append(skill);

				QLabel *skillLabel = new QLabel("<b>"+skill+"</b>");
				verticalLayout->addWidget(skillLabel);

				horizontalLayout_2 = new QHBoxLayout();
				horizontalLayout_2->setSpacing(6);
				horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

				QLabel *temp = new QLabel(verticalLayoutWidget);
				horizontalLayout_2->addWidget(temp);

				QPushButton *addButton = new QPushButton(verticalLayoutWidget);
				addButton->setText("Add material");
				horizontalLayout_2->addWidget(addButton);
				qListButtonAdd.append(addButton);
				addButton->setObjectName(QString::fromUtf8("addMaterialButton")+QString::number(i));
				connect(addButton,SIGNAL(clicked()),this,SLOT(addMaterial()));

				QPushButton *listButton  = new QPushButton(verticalLayoutWidget);
				listButton->setText("List materials");
				horizontalLayout_2->addWidget(listButton);
				qListButtonList.append(listButton);
				listButton->setObjectName(QString::fromUtf8("listMaterialButton")+QString::number(i));
				connect(listButton,SIGNAL(clicked()),this,SLOT(listMaterial()));

				QLabel *temp1 = new QLabel(verticalLayoutWidget);
				horizontalLayout_2->addWidget(temp1);

				verticalLayout->addLayout(horizontalLayout_2);

			}
			verticalLayoutWidget->raise();
			verticalLayoutWidget->show();
			
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
		//	QListWidgetItem *item2 = ui.rightWidget->takeItem(ui.rightWidget->currentRow());
		//	ui.leftWidget->addItem(item2);
			bool ok;
			QString text = QInputDialog::getText(this, tr("Add Skill"),tr("Skill:"), QLineEdit::Normal, tr("try try"),&ok);
		
		}

		

};

#endif // MYCLASS_H

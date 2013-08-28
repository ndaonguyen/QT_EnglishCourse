#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtGui/QMainWindow>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QInputDialog>
#include <QSignalMapper>
#include "listDialog.h"
#include "ui_myclass.h"
#include "database.h"

class MyClass : public QMainWindow
{
	Q_OBJECT
private: 
	QStandardItemModel *model;
	MYSQL *conn;
	// info course
	QString courseName;
	int courseID;
	QList<QString> skillsCourse;
	QList<QListWidget *> skillWidgets;
public:
	//  START :ADD COURSE TAB
			/* STEP 1 - 2 : CLICK BUTTON1 SAVE */
	void fillDataStep2() //edit + create
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
	void setup4Step2(QString method,int courseId) // Main step 2 
	{
		/**
		**	@parameter: method: "EDIT" or "CREATE"
		**              courseId : if, edit --> choose CourseId
		*/
		ui.step1Widget->setEnabled(false);
		courseName = ui.courseNameLineEdit->text();
		courseID = database::course_saveAction(conn,courseName);

		fillDataStep2();
		ui.step2Widget->setVisible(true);
		ui.line1_2->setVisible(true);

		// info is updated to info box
		QLabel *courseLabel = new QLabel(ui.classInsertGroupBox);
		courseLabel->setText("<b>Course name:</b>");
		ui.step1Layout->addWidget(courseLabel);

		QLabel *courseNameShow = new QLabel(ui.classInsertGroupBox);
		courseNameShow->setText(courseName);
		ui.step1Layout->addWidget(courseNameShow);

		ui.resultLabel->setText("<span style='color:red'>Step 1: saved</span>");
	}
			/* END STEP 1 - 2  */

			/* START STEP 2 - 3 CLICK BUTTON2 SAVE */

	void saveCourseSKillTable(int numElementSkillBox)
	{
		//save to course_skill table
		for(int i = 0;i<numElementSkillBox;i++)
		{
			QString skill = ui.rightWidget->item(i)->text();
			MYSQL_ROW row = database::skill_searchName(conn,skill);
			QString skillIdTemp = row[0];
			int skillId = skillIdTemp.toInt();
			database::courseSkill_saveAction(conn,skillId,courseID);
		}
	}

	void setupStep3Add(int numElementSkillBox) 
	{
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
		
		for( int i =0;i<numElementSkillBox;i++)
		{
			QSignalMapper *signalMapper = new QSignalMapper(this);
			QSignalMapper *signalMapper1 = new QSignalMapper(this);

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
			addButton->setObjectName(QString::fromUtf8("addMaterialButton")+QString::number(i));
			signalMapper->setMapping(addButton,skill+","+QString::number(i)+","+QString::number(courseID));
			connect(addButton,SIGNAL(clicked()),signalMapper, SLOT(map()));
			connect(signalMapper, SIGNAL(mapped(QString)),this, SLOT(addMaterial(QString)));


			QPushButton *listButton  = new QPushButton(verticalLayoutWidget);
			listButton->setText("List materials");
			horizontalLayout_2->addWidget(listButton);
			listButton->setObjectName(QString::fromUtf8("listMaterialButton")+QString::number(i));

			signalMapper1->setMapping(listButton,skill);
			connect(listButton,SIGNAL(clicked()),signalMapper1, SLOT(map()));
			connect(signalMapper1, SIGNAL(mapped(QString)),this, SLOT(listMaterial(QString)));

			QLabel *temp1 = new QLabel(verticalLayoutWidget);
			horizontalLayout_2->addWidget(temp1);

			verticalLayout->addLayout(horizontalLayout_2);

		}
		verticalLayoutWidget->raise();
		verticalLayoutWidget->show();
	}

	void setupInfoBoxStep2Save(int numElementBoxSkill)
	{
		for(int i =0;i<numElementBoxSkill;i++)
		{
			QString skill = ui.rightWidget->item(i)->text();
			QLabel *skillLabel = new QLabel(skill);
			ui.step2Layout->addWidget(skillLabel);

			QListWidget *listSkill = new QListWidget(ui.step2WidgetInfo);
			listSkill->setObjectName(skill+QString::fromUtf8("ListWidget"));
			ui.step2Layout->addWidget(listSkill);
			skillWidgets.append(listSkill);
		}
	}
	void setup4Step3(QString method,int courseId, int numElement) // Main step 3 
	{
		//save to course_skill table
		saveCourseSKillTable(numElement);
		//set up What appear in info added box
		setupStep3Add(numElement);	
		ui.line2_3->setVisible(true);
		ui.step3Widget->setVisible(true);
		ui.step2Widget->setEnabled(false);
		//set up what show in info box
		ui.skillLabelShow->setVisible(true);
		setupInfoBoxStep2Save(numElement);
		
		ui.resultLabel->setText("<span style='color:blue'>Step 2: saved</span>");
		ui.saveCourseButton->setVisible(true);
	}
			/* END STEP 2 - 3 CLICK BUTTON2 SAVE */


	QString materialBox(QString skill,bool &ok)
	{
		QString text = QInputDialog::getText(this, tr("Add Material to ") + skill,tr("Material:"), QLineEdit::Normal, tr("try try"),&ok);
		return text;
	}

	bool isAddMaterial(QString skillNIdNCourseId)
	{
	/**
	**	@parameter: skillNID : "<skill>,<id>"
	**/			
		bool ok;
		QStringList stringlist = skillNIdNCourseId.split(",");
		QString skill = stringlist.at(0);
		QString index = stringlist.at(1);
		QString courseId = stringlist.at(2);
		std::string tempId1 = courseId.toStdString();
		const char* courseIdTemp = tempId1.c_str();


		QString text =  materialBox(skill,ok);
		int idMaterial = -1;
		if (ok && !text.isEmpty())
		{
			int idMaterial = database::material_saveAction(conn,text);
			if(idMaterial !=-1 )
			{
				//insert into skill_material table		
				MYSQL_ROW row;
				if(row = database::skill_searchName(conn,skill))
				{
					char* idSkill = row[0];
					idMaterial = database::skillMaterial_saveAction(conn,atoi(idSkill),idMaterial,atoi(courseIdTemp));
					if(idMaterial!=-1)
					{
						//ui.step2WidgetInfo
						std::string temp1 = index.toStdString();
						const char* temp2 = temp1.c_str();
						int in = atoi(temp2);
						QListWidget *list =  skillWidgets.at(in);
						list->addItem(text);
					}
				}
			}
		}
		return ok;
	}
	//  END :ADD COURSE TAB


public:
	MyClass(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MyClass();

private:
	Ui::MyClassClass ui;
	// ADD COURSE TAB
	private slots:		
		// START STEP 1 action
		void step1SaveAction(int courseId) // disable step 1, enable step 2, update info to info box
		{
			// check box name is empty
			if(ui.courseNameLineEdit->text().trimmed() == "")
			{
				QMessageBox::warning(this,tr("Course name"),tr("Please fill the blank!!"));
				ui.courseNameLineEdit->setFocus();
				return;
			}

			char* method = "CREATE";
			if ( courseId !=0)
				method = "EDIT";

			setup4Step2(method,courseId );
		}
		// END STEP 1 action
			
		// START STEP2 2 action
		void step2SaveAction(int courseId) // save value to skillsCourse, fill step 3 info, step 3 appear, fill info into info bo
		{
			int numElement = ui.rightWidget->count();
			if(numElement == 0)
			{
				QMessageBox::warning(this,tr("Skill choice"),tr("Please choose skills!!"));
				return;
			}
			
			char* method = "CREATE";
			if ( courseId !=0)
				method = "EDIT";

			setup4Step3(method,courseId,numElement );
		}
		void addSkillAction()
		{
			bool ok;
			QString text = QInputDialog::getText(this, tr("Add Skill"),tr("Skill:"), QLineEdit::Normal, tr("try try"),&ok);
	
			if (ok && !text.isEmpty())
				if(database::skill_saveAction(conn,text)!=-1)
					ui.leftWidget->addItem(text);
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
		// END STEP 2 action

		//STEP 3 action
		void listMaterial(QString skill)
		{
			int a = 0;		
			listDialog *b = new listDialog(this,skill,courseID);
			b->exec();
			int c = 1;
		}

		void addMaterial(QString skillNIdNCourseId)
		{			
		/**
		**	@parameter: skillNID : "<skill>,<id>"
		**/		
			bool isAdd = isAddMaterial(skillNIdNCourseId);
			while(isAdd ==true)
			{
				isAdd = isAddMaterial(skillNIdNCourseId);
			}
			
		}
		// END STEP 3 action
		
		void saveCourseAction()
		{
			// active List Course tab
			QWidget * tab = ui.mainTab->widget(2);
			ui.mainTab->setCurrentWidget(tab);
		}
	private slots:
		// share action
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

};

#endif // MYCLASS_H

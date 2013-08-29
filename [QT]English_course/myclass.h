#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtGui/QMainWindow>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QInputDialog>
#include <QSignalMapper>
#include "listMaterialDialog.h"
#include "listCourseDialog.h"
#include "ui_myclass.h"
#include "database.h"

class MyClass : public QMainWindow
{
	Q_OBJECT
private: 
	QStandardItemModel *listClassModel;
	QStandardItemModel *listCourseModel;
	MYSQL *conn;
	// info course
	QString courseName;
	int courseID;
	QList<QString> skillsCourse;
	QList<QListWidget *> skillWidgets;

	int numExecuteStep2;
	int numExecuteStep3;
public:
	//  START :ADD COURSE TAB
			/* STEP 1 - 2 : CLICK BUTTON1 SAVE */
	void fillDataStep2() //edit + create
	{
		// update info to ListWidget of step 2	
		int count = ui.leftWidget->count();
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
		ui.line1_2->setVisible(true);
		int count = ui.leftWidget->count();
		ui.step2Widget->setVisible(true);

		// info is updated to info box
		QLabel *courseLabel = new QLabel(ui.classInsertGroupBox);
		courseLabel->setText("<b>Course name:</b>");
		ui.step1Layout->addWidget(courseLabel);

		QLabel *courseNameShow = new QLabel(ui.classInsertGroupBox);
		courseNameShow->setText(courseName);
		ui.step1Layout->addWidget(courseNameShow);

		ui.resultLabel->setText("<span style='color:red'><b>Step1:Saved</b></span>");
		return;
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
	//	QWidget *verticalLayoutWidget;
	//	QVBoxLayout *verticalLayout;			
		QHBoxLayout *horizontalLayout_2;

	//	verticalLayoutWidget = new QWidget(ui.step3Widget);
	//	verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
	
	//	QRect rectLayoutSkill = ui.step3Widget->geometry();
	//	int xMargin = 100;
	//	int yMargin = 20;
//		verticalLayoutWidget->setGeometry(QRect(rectLayoutSkill.x()+xMargin,rectLayoutSkill.y()+yMargin,rectLayoutSkill.width() - yMargin, rectLayoutSkill.height() - xMargin));
		
	//	verticalLayoutWidget->setGeometry(QRect(30, 40, 321, 201));
	//	verticalLayout = new QVBoxLayout(verticalLayoutWidget);
	//	verticalLayout->setSpacing(6);
	//	verticalLayout->setContentsMargins(11, 11, 11, 11);
	//	verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
	//	verticalLayout->setContentsMargins(0, 0, 0, 0);
		
		for( int i =0;i<numElementSkillBox;i++)
		{
			QSignalMapper *signalMapper = new QSignalMapper(this);
			QSignalMapper *signalMapper1 = new QSignalMapper(this);

			QString skill = ui.rightWidget->item(i)->text();
			skillsCourse.append(skill);

			QLabel *skillLabel = new QLabel("<b>"+skill+"</b>");
			ui.verticalLayout->addWidget(skillLabel);

			horizontalLayout_2 = new QHBoxLayout();
			horizontalLayout_2->setSpacing(6);
			horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

			QLabel *temp = new QLabel(ui.verticalLayoutWidget);
			horizontalLayout_2->addWidget(temp);

			QPushButton *addButton = new QPushButton(ui.verticalLayoutWidget);
			addButton->setText("Add material");
			horizontalLayout_2->addWidget(addButton);
			addButton->setObjectName(QString::fromUtf8("addMaterialButton")+QString::number(i));
			signalMapper->setMapping(addButton,skill+","+QString::number(i)+","+QString::number(courseID));
			connect(addButton,SIGNAL(clicked()),signalMapper, SLOT(map()));
			connect(signalMapper, SIGNAL(mapped(QString)),this, SLOT(addMaterial(QString)));


			QPushButton *listButton  = new QPushButton(ui.verticalLayoutWidget);
			listButton->setText("List materials");
			horizontalLayout_2->addWidget(listButton);
			listButton->setObjectName(QString::fromUtf8("listMaterialButton")+QString::number(i));

			signalMapper1->setMapping(listButton,skill);
			connect(listButton,SIGNAL(clicked()),signalMapper1, SLOT(map()));
			connect(signalMapper1, SIGNAL(mapped(QString)),this, SLOT(listMaterial(QString)));

			QLabel *temp1 = new QLabel(ui.verticalLayoutWidget);
			horizontalLayout_2->addWidget(temp1);

			ui.verticalLayout->addLayout(horizontalLayout_2);

		}
	//	verticalLayoutWidget->raise();
	//	verticalLayoutWidget->show();
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
		
		ui.resultLabel->setText("<span style='color:blue'><b>Step2:saved</b></span>");
		ui.saveCourseButton->setVisible(true);
		numExecuteStep3 = numExecuteStep3 +1;
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

	void loadConfigAddCourseTab()
	{
		QSignalMapper *signalMapper = new QSignalMapper(this);
		signalMapper->setMapping(ui.saveButton,0);
		QObject::connect(ui.saveButton,SIGNAL(clicked()),signalMapper, SLOT(map()));
		QObject::connect(signalMapper, SIGNAL(mapped(int)),this, SLOT(step1SaveAction(int)));

		QSignalMapper *signalMapper1 = new QSignalMapper(this);
		signalMapper1->setMapping(ui.courseNameLineEdit,0);
		QObject::connect(ui.courseNameLineEdit,SIGNAL(returnPressed()),signalMapper1, SLOT(map()));
		QObject::connect(signalMapper1, SIGNAL(mapped(int)),this, SLOT(step1SaveAction(int)));
	 
		QSignalMapper *signalMapper2 = new QSignalMapper(this);
		signalMapper2->setMapping(ui.saveButton2,0);
		QObject::connect(ui.saveButton2,SIGNAL(clicked()),signalMapper2, SLOT(map()));
		QObject::connect(signalMapper2, SIGNAL(mapped(int)),this, SLOT(step2SaveAction(int)));

		ui.saveCourseButton->setVisible(false);
		ui.line1_2->setVisible(false);
		ui.line2_3->setVisible(false);
		ui.step2Widget->setVisible(false);
		ui.step3Widget->setVisible(false);
		ui.skillLabelShow->setVisible(false);
		ui.addMoreButton->setVisible(false);

		numExecuteStep2 = 0;
		numExecuteStep3 = 0;
	}
	void clearItemsLayout(QLayout* layout)
	{
		while(QLayoutItem *item = layout->takeAt(0))
			if (item->layout()) 
			{
				clearItemsLayout(item->layout());
				delete item->layout();
			}
			else if (item->widget()) 
				delete item->widget();
	}


	void refreshToOrigin()
	{
		loadConfigAddCourseTab();

		ui.courseNameLineEdit->setText("");
		ui.step1Widget->setEnabled(true);
		ui.step2Widget->setEnabled(true);
		ui.resultLabel->setText("");
		ui.skillLabelShow->setVisible(false);

		clearItemsLayout(ui.step1Layout);
		clearItemsLayout(ui.step2Layout);
		//step 3
		clearItemsLayout(ui.verticalLayout);

		//step 2 
		numExecuteStep2 = 0;
		numExecuteStep3 = 0;
		int numLeft  = ui.leftWidget->count();
		int numRight = ui.rightWidget->count();
		for (int i =0;i<numLeft;i++)
			ui.leftWidget->takeItem(0);
		for (int i =0;i<numRight;i++)
			ui.rightWidget->takeItem(0);

		courseName = "";
		courseID = 0;
		skillsCourse.clear();
		skillWidgets.clear();
	}
	//  END :ADD COURSE TAB

	// START: LIST CLASS TAB
	
	void loadListClassTab()
	{
		listClassModel = new QStandardItemModel(this); //2 Rows and 3 Columns
		listClassModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Class name")));
		listClassModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Res date")));
		listClassModel->setHorizontalHeaderItem(2, new QStandardItem(QString("Member")));
		listClassModel->setHorizontalHeaderItem(3, new QStandardItem(QString("Course")));
		listClassModel->setHorizontalHeaderItem(4, new QStandardItem(QString("% day")));
		listClassModel->setHorizontalHeaderItem(5, new QStandardItem(QString("% material")));

		// Add value to a cell in table
		QStandardItem *firstRow = new QStandardItem(QString("ColumnValue"));
		listClassModel->setItem(0,0,firstRow);

		QStandardItem *row2 = new QStandardItem(QString("ColumnValue"));
		listClassModel->setItem(0,1,row2);

		QStandardItem *row3 = new QStandardItem(QString("ColumnValue"));
		listClassModel->setItem(0,2,row3);

		QStandardItem *row4 = new QStandardItem(QString("ColumnValue"));
		listClassModel->setItem(0,3,row4);
		 
		ui.listTable->setModel(listClassModel);
	}
	// END: LIST CLASS TAB


	//  START :LIST COURSE TAB
	

	QString getSkillList(QString courseId)
	{
		QString  temp = courseId;
		std::string idTemp = temp.toStdString();
		const char* idTemp2 = idTemp.c_str();
		
		MYSQL_ROW row2;
		MYSQL_RES* rest2 = database::courseSkill_searchCourseId(conn, atoi(idTemp2));
		QString skillString="";
		while(row2 = mysql_fetch_row(rest2))
		{
			temp = row2[1];
			idTemp = temp.toStdString();
			idTemp2 = idTemp.c_str();	
			MYSQL_ROW row3 = database::skill_searchSkillId(conn, atoi(idTemp2));
			skillString = skillString + row3[1] +",";
		}
		skillString = skillString.mid(0,skillString.length()-1);  // Skill of that course
		return skillString;
	}

	void loadListCourseTab()
	{
		int column = 3;
		listCourseModel = new QStandardItemModel(ui.listCourseTab);
		
		listCourseModel->setHorizontalHeaderItem(0,new QStandardItem(tr("Course Name")));
		listCourseModel->setHorizontalHeaderItem(1,new QStandardItem(tr("Skill")));
		listCourseModel->setHorizontalHeaderItem(2,new QStandardItem(tr("Material")));
		listCourseModel->setHorizontalHeaderItem(3,new QStandardItem(tr("Edit")));
		listCourseModel->setHorizontalHeaderItem(4,new QStandardItem(tr("Delete")));
	//	ui.listCourseTable->setColumnWidth(3,100);

		MYSQL_RES* res_set = database::course_getAll(conn);
		MYSQL_ROW row;
		int indexRow =0;
		QList<QString> courseIdList;
		while(row = mysql_fetch_row(res_set))
		{
			QString course   = row[1];  // courseName
			QString courseId = row[0];
			courseIdList.append(courseId);

			QString skillString = getSkillList(courseId);	
		
			listCourseModel->setItem(indexRow,0,new QStandardItem(course));
			listCourseModel->setItem(indexRow,1,new QStandardItem(skillString));
			indexRow++;
		}
		ui.listCourseTable->setModel(listCourseModel);

		//Add button Detail và Button Edit vào
		int numCourseId = courseIdList.length();
		for(int i = 0 ; i < numCourseId ; i++)
		{
			QPushButton *detailButton = new QPushButton("Detail");			
			QSignalMapper *signalMapper = new QSignalMapper(this);
			signalMapper->setMapping(detailButton,courseIdList.at(i));
			QObject::connect(detailButton,SIGNAL(clicked()),signalMapper, SLOT(map()));
			QObject::connect(signalMapper, SIGNAL(mapped(QString)),this, SLOT(loadDialogAction(QString)));			
			ui.listCourseTable->setIndexWidget(listCourseModel->index(i,2),detailButton);

			QPushButton *editButton = new QPushButton("Edit");
			QPixmap pixmap("Resources/edit.jpg");
			QIcon ButtonIcon(pixmap);
			editButton->setIcon(ButtonIcon);
			QSignalMapper *signalMapper1 = new QSignalMapper(this);
			signalMapper1->setMapping(editButton,courseIdList.at(i));
			QObject::connect(editButton,SIGNAL(clicked()),signalMapper1, SLOT(map()));
			QObject::connect(signalMapper1, SIGNAL(mapped(QString)),this, SLOT(editCourseAction(QString)));
			ui.listCourseTable->setIndexWidget(listCourseModel->index(i,3),editButton);

			QPushButton *deleteButton = new QPushButton("Delete");
			QPixmap pixmap1("Resources/Delete_icon.png");
			QIcon ButtonIcon1(pixmap1);
			deleteButton->setIcon(ButtonIcon1);
			QSignalMapper *signalMapper2 = new QSignalMapper(this);
			signalMapper2->setMapping(deleteButton,courseIdList.at(i));
			QObject::connect(deleteButton,SIGNAL(clicked()),signalMapper2, SLOT(map()));
			QObject::connect(signalMapper2, SIGNAL(mapped(QString)),this, SLOT(deleteCourseAction(QString)));
			ui.listCourseTable->setIndexWidget(listCourseModel->index(i,4),deleteButton);
		}
	}

public:
	MyClass(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MyClass();

private:
	Ui::MyClassClass ui;
	// ADD COURSE TAB
	private slots:	
		// START refresh (add more action)
		void refreshAddCourseAction()
		{
			refreshToOrigin();
		}
		// END refresh (add more action)


		// START STEP 1 action
		void step1SaveAction(int courseId) // disable step 1, enable step 2, update info to info box
		{
			if (numExecuteStep2 >0)
				return;

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
			numExecuteStep2 = numExecuteStep2+1;
			return;
		}
		// END STEP 1 action
			
		// START STEP2 2 action
		void step2SaveAction(int courseId) // save value to skillsCourse, fill step 3 info, step 3 appear, fill info into info bo
		{
			if (numExecuteStep3 >0)
				return;

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
			ui.addMoreButton->setVisible(true);
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
			listMaterialDialog *b = new listMaterialDialog(this,skill,courseID);
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
				ui.resultLabel->setText("<span style='color:green'><b>Material: saved</b></span>");
			}
		}
		// END STEP 3 action
		
		void saveCourseAction()
		{
			// active List Course tab
			QWidget * tab = ui.mainTab->widget(2);
			ui.mainTab->setCurrentWidget(tab);
			// load course list
			loadListCourseTab();
		}
	private slots:
		// share action
		void openFileAction()
		{
			// get data of a colum and row
			QString a = listClassModel->data(listClassModel->index(0,0), Qt::DisplayRole).toString();
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
	// LIST COURSE TAB
	private slots:
		void loadDialogAction(QString courseId)
		{
			listCourseDialog *courseDialog = new listCourseDialog(this,courseId);
			courseDialog->exec();
		}

		void editCourseAction(QString courseId)
		{
			int a = 0;
			QWidget * tab = ui.mainTab->widget(3);
			ui.mainTab->setCurrentWidget(tab);

		}

		void deleteCourseAction(QString courseId)
		{
		/**
		** Purpose: Confirm delete action-->delete database first --> delete row in QTableView
		**/
			int ret = QMessageBox::warning(this, tr("Delete course"),tr("Please confirm !!"),
                                QMessageBox::Ok | QMessageBox::Cancel);

			if(ret == QMessageBox::Ok)
			{
				//delete database ( children --> parent)

				std::string temp  = courseId.toStdString();
				const char* temp1 = temp.c_str();
				int courseIdInt   = atoi(temp1);

				MYSQL_ROW courseRow = database::course_searchId(conn, courseIdInt);
				QString nameCourse  = courseRow[1];
				
				MYSQL_RES *res = database::courseSkill_searchCourseId(conn,courseIdInt);
				while( MYSQL_ROW courseSkillRow = mysql_fetch_row(res))
				{
					QString skillId = courseSkillRow[1];
					temp  = skillId.toStdString();
					temp1 = temp.c_str();
					int skillIdInt   = atoi(temp1);
					MYSQL_ROW skillRow = database::skill_searchSkillId(conn,skillIdInt);

					MYSQL_RES *resSkillMaterial = database::skillMaterial_searchSkillId(conn,skillIdInt,courseIdInt);
					while(MYSQL_ROW skillMaterialRow = mysql_fetch_row(resSkillMaterial) )
					{
						QString materialId = skillMaterialRow[1];
						temp  = materialId.toStdString();
						temp1 = temp.c_str();
						int materialIdInt  = atoi(temp1);
						database::material_deleteById(conn,materialIdInt);
						database::skillMaterial_deleteByMaterialId(conn,materialIdInt);
					}
					database::courseSkill_deleteBySkillId(conn,skillIdInt);
				}
				database::course_deleteBySkillId(conn,courseIdInt);
			
				// Delete row of QTableView
				int rowCount = listCourseModel->rowCount();
				for(int i =0; i < rowCount; i++)
					if(nameCourse == listCourseModel->data(listCourseModel->index(i,0), Qt::DisplayRole).toString())
						listCourseModel->removeRow(i);
			}
		}

};

#endif // MYCLASS_H

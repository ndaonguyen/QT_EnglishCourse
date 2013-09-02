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
	MYSQL *conn;
// COURSE info
	QStandardItemModel *listClassModel;
	QStandardItemModel *listCourseModel;
	QString courseMode;
	QString courseName; //Current course name ( initial = "" )
	int courseID;  // Current course_id ( initial = 0 )
	QList<QString> skillsCourse;
	QList<QListWidget *> skillWidgets;
// CLASS info
	QStandardItemModel *addMemberModel;
	QList<QStandardItemModel*> skillModelList; // list contain material ( set current situation)
	QList<QTableView*>  skillTableList; // list contain material 
public:
	/**
	  * set Header for QTableView
	  * @param model: of QTableView, listHeader : list of Header String
	  */
	void setHeaderTable(QStandardItemModel *model, QList<QString> listHeader)
	{
		int count = listHeader.count();
		for(int i =0;i<count;i++)
			model->setHorizontalHeaderItem(i, new QStandardItem(listHeader.at(i)));
	}
	/**
	  * fill Table with empty value
	  */
	void setEmptyRowTable(QStandardItemModel *model, int numRow)
	{
		int columns  = model->columnCount();
		int rowIndex = 0;
		while (rowIndex <numRow)
		{
			for(int i =0;i<columns;i++)
				model->setItem(rowIndex,i, new QStandardItem(tr("")));
			rowIndex ++;
		}
	}

	// START : ADD CLASS TAB
	/**
	  * load confif of list class and add class at the constructor
	  */
	void loadConfigClass()
	{
		addMemberModel = new QStandardItemModel(this);
		ui.addMemberTable->setModel(addMemberModel);
	}
	/**
	  * Load data to Add Class tab with two method (create, edit) : base on ClassId 
	  * @param classId 0:create  #0: edit
	  */
	void loadDataAddClassTab(int classId)
	{
		if(classId ==0)
		{
			ui.classNameLineEdit->setText("");
			ui.totalDateLineEdit->setText("");
			addMemberModel->clear();
			ui.otherLineEdit->setText("");
			ui.classComboBox->clear();
			ui.courseClassLabel->setText("");
			clearItemsLayout(ui.courseInfoLayout);

			ui.courseNameLineEdit->setFocus();
			QDate curDate = QDate::currentDate();
			ui.regisdateEdit->setDate(curDate);
			// Set up member table View
			QList<QString> headerList;
			headerList << "Name" << "Birth year" << "Others";
			setHeaderTable(addMemberModel, headerList);
			setEmptyRowTable(addMemberModel,7);
			ui.addMemberTable->setColumnWidth(0,150);
			ui.addMemberTable->setColumnWidth(1,60);
			ui.addMemberTable->setColumnWidth(2,70);

			MYSQL_RES *res = database::course_getAll(conn);
			ui.classComboBox->addItem(tr("Choose course"));
			while(MYSQL_ROW row = mysql_fetch_row(res))
				ui.classComboBox->addItem(row[1]);
			ui.classComboBox->setCurrentIndex(0);
		}
	}
	/**
	  *	Fill Course info : able to delete material ( but not edit
	  * @param courseIdStr : course_id --> to load data
	  */
	void fillMaterial4AddMember(QString courseIdStr)
	{
		MYSQL_RES *resCourseSkill = database::courseSkill_searchCourseId(conn,courseIdStr);
		int skillIndex = 0;
		while(MYSQL_ROW courseSkillRow = mysql_fetch_row(resCourseSkill))
		{
			MYSQL_ROW skillRow = database::skill_searchSkillId(conn,courseSkillRow[1]);
			QLabel *skillLabel = new QLabel(tr("<b>")+skillRow[1]+tr("</b>"));
			ui.courseInfoLayout->addWidget(skillLabel);
			
			QTableView *skillTable = new QTableView(ui.addClassTab);
			QStandardItemModel *skillModel = new QStandardItemModel(ui.addClassTab);
			skillTable->setModel(skillModel);
			

			// QTableView of each skill
			int rowIndex = 0;
			QList<QString> headerList;
			headerList << "ID" << "Material" << "Delete" ;
			setHeaderTable(skillModel,headerList);

			MYSQL_RES *resSkillMaterial = database::skillMaterial_searchSkillId(conn,courseSkillRow[1],courseIdStr);
			while(MYSQL_ROW skillMaterialRow = mysql_fetch_row(resSkillMaterial))
			{
				MYSQL_ROW materialRow = database::material_searchMaterialId(conn,skillMaterialRow[1]);
				skillModel->setItem(rowIndex,0, new QStandardItem(materialRow[0])); //id
				skillModel->setItem(rowIndex,1, new QStandardItem(materialRow[1])); // material
				
				QPushButton *deleteButton = new QPushButton(ui.addClassTab);
				QPixmap pixmap1("Resources/Delete_icon.png");
				QIcon ButtonIcon1(pixmap1);
				deleteButton->setIcon(ButtonIcon1);
				QSignalMapper *signalMapper = new QSignalMapper(ui.addClassTab);
				signalMapper->setMapping(deleteButton,materialRow[1]+tr(",")+QString::number(skillIndex));
				QObject::connect(deleteButton,SIGNAL(clicked()),signalMapper,SLOT(map()));
				QObject::connect(signalMapper,SIGNAL(mapped(QString)),this,SLOT(delMaterialTable(QString)));
				skillTable->setIndexWidget(skillModel->index(rowIndex,2),deleteButton);

				rowIndex++;
			}
			skillTable->setColumnWidth(0,50);
			skillTable->setColumnWidth(1,250);
			skillTable->setColumnWidth(2,50);

			skillTableList.append(skillTable);
			skillModelList.append(skillModel);
			ui.courseInfoLayout->addWidget(skillTable);
			skillIndex++;
		}
	}
	// END   : ADD CLASS TAB

	//  START :ADD COURSE TAB
			/* STEP 1 - 2 : CLICK BUTTON1 SAVE */
	void fillSkillsStep2() //edit + create
	{
		if(courseMode == "CREATE")
		{
			// update info to ListWidget of step 2	
			MYSQL_RES *res = database::skill_getAll(conn);
			while(MYSQL_ROW skillRow = mysql_fetch_row(res))
				ui.leftWidget->addItem(skillRow[1]);
		}
		else
		{
			MYSQL_RES *res = database::courseSkill_searchCourseId(conn,QString::number(courseID));
			while(MYSQL_ROW skillRow = mysql_fetch_row(res))
			{
				QString skillId = skillRow[1];
				MYSQL_ROW row = database::skill_searchSkillId(conn,skillId);
				ui.rightWidget->addItem(row[1]);
			}
		}
	}
	void setup4Step2()// Main step 2 
	{
		/**
		 * Setup data for step 2
		 */
		
		fillSkillsStep2();
		ui.line1_2->setVisible(true);
		ui.step2Widget->setVisible(true);

		QLabel *courseLabel = new QLabel(ui.classInsertGroupBox);
		courseLabel->setText("<b>Course name:</b>");
		ui.step1Layout->addWidget(courseLabel);

		QLabel *courseNameShow = new QLabel(ui.classInsertGroupBox);
		courseNameShow->setText(courseName);
		ui.step1Layout->addWidget(courseNameShow);
		if(courseMode == "CREATE")
			ui.resultLabel->setText("<span style='color:red'><b>Step1:Saved</b></span>");
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
			database::courseSkill_saveAction(conn,skillIdTemp,QString::number(courseID));
		}
	}

	void setupStep3Add(int numElementSkillBox) 
	{
		QHBoxLayout *horizontalLayout_2;
		
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
			signalMapper1->setMapping(listButton,skill+","+QString::number(i)+","+QString::number(courseID));
			connect(listButton,SIGNAL(clicked()),signalMapper1, SLOT(map()));
			connect(signalMapper1, SIGNAL(mapped(QString)),this, SLOT(listMaterial(QString)));

			QLabel *temp1 = new QLabel(ui.verticalLayoutWidget);
			horizontalLayout_2->addWidget(temp1);

			ui.verticalLayout->addLayout(horizontalLayout_2);
		}
	}

	void setupInfoBoxStep2Save(int numElementBoxSkill)
	{
		for(int i =0;i<numElementBoxSkill;i++)
		{
			QString skill = ui.rightWidget->item(i)->text();
			QLabel *skillLabel = new QLabel(skill);
			ui.step2Layout->addWidget(skillLabel);

			QListWidget *listSkill = new QListWidget(ui.step2WidgetInfo);
			if(courseMode == "EDIT")
			{
				MYSQL_ROW skillRow = database::skill_searchName(conn,skill);
				QString skillId    = skillRow[0];
				
				MYSQL_RES *res = database::skillMaterial_searchSkillId(conn,skillId,QString::number(courseID));
				while(MYSQL_ROW smRow = mysql_fetch_row(res))
				{
					QString materialId    = smRow[1];
					MYSQL_ROW materialRow = database::material_searchMaterialId(conn,materialId);
					listSkill->addItem(materialRow[1]);
				}
			}
			ui.step2Layout->addWidget(listSkill);
			skillWidgets.append(listSkill);
		}
	}
	void setup4Step3() // Main step 3 
	{
		int numSkills = ui.rightWidget->count();
		//set up What appear in info added box
		setupStep3Add(numSkills);	// create + edit : ok 
		ui.line2_3->setVisible(true);
		ui.step3Widget->setVisible(true);
		ui.step2Widget->setEnabled(false);
		//set up what show in info box
		ui.skillLabelShow->setVisible(true);
		setupInfoBoxStep2Save(numSkills);		
		ui.resultLabel->setText("<span style='color:blue'><b>Step2:saved</b></span>");

		ui.saveCourseButton->setVisible(true);
		ui.addMoreButton->setVisible(true);
	}
			/* END STEP 2 - 3 CLICK BUTTON2 SAVE */

	QString materialBox(QString skill,bool &ok)
	{
		QString text = QInputDialog::getText(this, tr("Add Material to ") + skill,tr("Material:"), QLineEdit::Normal, tr("try try"),&ok);
		return text;
	}

	/**
	  * @param skillNID : "<skill>,<index>,<courseId>"
	  */		
	bool isAddMaterial(QString skillNIndex)
	{
		bool ok;
		QStringList stringlist = skillNIndex.split(",");
		QString skill = stringlist.at(0);
		QString index = stringlist.at(1);

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
					QString idSkill = row[0];
					idMaterial = database::skillMaterial_saveAction(conn,idSkill,QString::number(idMaterial),QString::number(courseID));
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

	void configButton()
	{
	/*
	**  Start connect for those button need to transfer data
	**/
		QObject::connect(ui.saveButton,SIGNAL(clicked()),this, SLOT(step1SaveAction()));
		QObject::connect(ui.courseNameLineEdit,SIGNAL(returnPressed()),this, SLOT(step1SaveAction()));
		QObject::connect(ui.saveButton2,SIGNAL(clicked()),this, SLOT(step2SaveAction()));
		QObject::connect(ui.saveCourseButton,SIGNAL(clicked()),this, SLOT(saveCourseAction()));

	}

	void loadConfigAddCourseTab()
	{
		ui.saveCourseButton->setVisible(false);
		ui.line1_2->setVisible(false);
		ui.line2_3->setVisible(false);
		ui.step2Widget->setVisible(false);
		ui.step3Widget->setVisible(false);
		ui.skillLabelShow->setVisible(false);
		ui.addMoreButton->setVisible(false);
		courseName = "";
		courseID = 0;
		courseMode = "CREATE";
		ui.courseNameLineEdit->setFocus();
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
		int numLeft  = ui.leftWidget->count();
		int numRight = ui.rightWidget->count();
		for (int i =0;i<numLeft;i++)
			ui.leftWidget->takeItem(0);
		for (int i =0;i<numRight;i++)
			ui.rightWidget->takeItem(0);

		courseName = "";
		courseID = 0;
		courseMode = "CREATE";
		skillsCourse.clear();
		skillWidgets.clear();
		ui.courseNameLineEdit->setFocus();
	}
	//  END :ADD COURSE TAB

	// START: LIST CLASS TAB
	void loadListClassTab()
	{
		listClassModel = new QStandardItemModel(this); //2 Rows and 3 Columns
		QList<QString> listHeader;
		listHeader << "Class name" << "Res date" << "Member" << "Course" << "% day" << "% material";
		setHeaderTable(listClassModel,listHeader);
		// Add value to a cell in table
		setEmptyRowTable(listClassModel,5);
		ui.listTable->setModel(listClassModel);
	}
	// END: LIST CLASS TAB

	//  START :LIST COURSE TAB
	QString getSkillList(QString courseId)
	{
		MYSQL_ROW row2;
		MYSQL_RES* rest2 = database::courseSkill_searchCourseId(conn, courseId);
		QString skillString="";
		QString skillID ="";
		while(row2 = mysql_fetch_row(rest2))
		{
			skillID = row2[1];
			MYSQL_ROW row3 = database::skill_searchSkillId(conn, skillID);
			skillString = skillString + row3[1] +",";
		}
		skillString = skillString.mid(0,skillString.length()-1);  // Skill of that course
		return skillString;
	}
	/**
	  * Fill to the next rows of QTableList
	  * @param res_set: data need to be filled
	  * @param listCourseTable : QTableView to filled data
	  * @param courseModel : Model of QTableView
      * @param indexRow    : index of row to continue insert
	  */
	void fillListCourse(MYSQL_RES *res_set,QTableView *listCourseTable,QStandardItemModel *courseModel, int indexRow)
	{
		MYSQL_ROW row;
		int indexTemp = indexRow;
		QList<QString> courseIdList;
		while(row = mysql_fetch_row(res_set))
		{
			QString course   = row[1];  // course Name
			QString courseId = row[0];
			courseIdList.append(courseId);

			QString skillString = getSkillList(courseId);	
		
			courseModel->setItem(indexTemp,0,new QStandardItem(course));
			courseModel->setItem(indexTemp,1,new QStandardItem(skillString));
			indexTemp++;
		}

		//Add button Detail và Button Edit vào
		int numCourseId = courseIdList.length();
		for(int i = indexRow ; i < numCourseId ; i++)
		{
			int indexCourseIdList = i-indexRow;

			QPushButton *detailButton = new QPushButton("Detail");			
			QSignalMapper *signalMapper = new QSignalMapper(this);
			signalMapper->setMapping(detailButton,courseIdList.at(indexCourseIdList));
			QObject::connect(detailButton,SIGNAL(clicked()),signalMapper, SLOT(map()));
			QObject::connect(signalMapper, SIGNAL(mapped(QString)),this, SLOT(loadDialogAction(QString)));			
			listCourseTable->setIndexWidget(courseModel->index(i,2),detailButton);

			QPushButton *editButton = new QPushButton("Edit");
			QPixmap pixmap("Resources/edit.jpg");
			QIcon ButtonIcon(pixmap);
			editButton->setIcon(ButtonIcon);
			QSignalMapper *signalMapper1 = new QSignalMapper(this);
			signalMapper1->setMapping(editButton,courseIdList.at(indexCourseIdList));
			QObject::connect(editButton,SIGNAL(clicked()),signalMapper1, SLOT(map()));
			QObject::connect(signalMapper1, SIGNAL(mapped(QString)),this, SLOT(editCourseAction(QString)));
			listCourseTable->setIndexWidget(courseModel->index(i,3),editButton);

			QPushButton *deleteButton = new QPushButton("Delete");
			QPixmap pixmap1("Resources/Delete_icon.png");
			QIcon ButtonIcon1(pixmap1);
			deleteButton->setIcon(ButtonIcon1);
			QSignalMapper *signalMapper2 = new QSignalMapper(this);
			signalMapper2->setMapping(deleteButton,courseIdList.at(indexCourseIdList));
			QObject::connect(deleteButton,SIGNAL(clicked()),signalMapper2, SLOT(map()));
			QObject::connect(signalMapper2, SIGNAL(mapped(QString)),this, SLOT(deleteCourseAction(QString)));
			listCourseTable->setIndexWidget(courseModel->index(i,4),deleteButton);
		}
	}
	
	void loadListCourseTab()
	{
		listCourseModel = new QStandardItemModel(ui.listCourseTab);
		ui.listCourseTable->setModel(listCourseModel);

		QList<QString> headerList;
		headerList << "Course Name" << "Skill" << "Material" << "Edit" << "Delete";
		setHeaderTable(listCourseModel, headerList);
	
		MYSQL_RES* res_set = database::course_getAll(conn);
		fillListCourse(res_set,ui.listCourseTable,listCourseModel,0);
	}

public:
	MyClass(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MyClass();

private:
	Ui::MyClassClass ui;
// START : ADD CLASS TAB
	private slots:
		void cancelClassAction()
		{
			loadDataAddClassTab(0);
		}
			
		/**
		  * delete material in skill box info
		  * @param materialNSkillIndex : "<material name> , <skill Index>"
		  * skillindex : in skillModelList and skillTableList
		  */
		void delMaterialTable(QString materialNSkillIndex)
		{
			QStringList arr    = materialNSkillIndex.split(",");
			QString material   = arr.at(0);
			QString skillIndex = arr.at(1);
			int skillIndexInt  = skillIndex.toInt();
			
			QStandardItemModel *model = skillModelList.at(skillIndexInt);
			int rowCount			  = model->rowCount();
			for(int i=0;i<rowCount;i++)
			{
				QString materialCom = model->data(model->index(i,1),Qt::DisplayRole).toString();
				if(material == materialCom)
				{
					model->removeRow(i);
					return;
				}
			}
		}

		/**
		  * Check data before saving
		  */
		void saveClassAction()
		{
			// checl data
			int rowMember = addMemberModel->rowCount();
			if (ui.classNameLineEdit->text()=="")
			{
				QMessageBox::warning(this,tr("Class name"),tr("Please fill the blank!!"));
				ui.classNameLineEdit->setFocus();
				return;
			}
			else if(ui.totalDateLineEdit->text()=="") // check if a number
			{
				QMessageBox::warning(this,tr("Total days"),tr("Please fill the blank!!"));
				ui.totalDateLineEdit->setFocus();
				return;
			}
			else if(rowMember<1) // sai ne
			{	
				QMessageBox::warning(this,tr("Add Member"),tr("Please fill the member info!!"));
				return;
			}
			else if(ui.courseClassLabel->text()=="")
			{
				QMessageBox::warning(this,tr("Choose Course"),tr("Please select the suitable course!!"));
				return;
			}
			else  // SAVE
			{
				QList<QString> classListInfo;
	//			QDate date = ui.regisdateEdit->date();
	//			QString text = date.toString("yyyy-MM-dd");
				
				classListInfo << ui.classNameLineEdit->text() << ui.regisdateEdit->date().toString("yyyy-MM-dd") <<ui.totalDateLineEdit->text() << ui.otherLineEdit->text();
				int classId = database::class_saveAction(conn,classListInfo);
				if(classId !=-1)
				{
					//save members
					for(int i = 0;i<rowMember;i++)
					{
						QString memberName = addMemberModel->data(addMemberModel->index(i,0),Qt::DisplayRole).toString().trimmed();
						if(memberName != "")
						{
							QString birthYear = addMemberModel->data(addMemberModel->index(i,1),Qt::DisplayRole).toString().trimmed();
							QString note      = addMemberModel->data(addMemberModel->index(i,2),Qt::DisplayRole).toString().trimmed();
							QList<QString> memberListInfo;
							memberListInfo << memberName << birthYear << note;
							int memberId = database::member_saveAction(conn,memberListInfo);
							if(memberId != -1)
								database::classMember_saveAction(conn,QString::number(classId),QString::number(memberId));
						}
					}
					//save material
					int skillNum = skillModelList.count();
					for(int i =0;i<skillNum;i++)
					{
					//	QList<QStandardItemModel*> skillModelList;
						QStandardItemModel *skillModel = skillModelList.at(i);
						int materialRow                = skillModel->rowCount();
						for(int j=0;j<materialRow;j++)
						{
							QString materialId = skillModel->data(skillModel->index(j,0),Qt::DisplayRole).toString().trimmed();
							database::materialUse_saveAction(conn,materialId,QString::number(classId));
						}
					}
				}
				QWidget * tab = ui.mainTab->widget(0);
				ui.mainTab->setCurrentWidget(tab);
			}
		}

		void courseComboAction(QString courseStr)
		{
			if(courseStr == "Choose course")
			{
				clearItemsLayout(ui.courseInfoLayout);
				ui.courseInfoLabel->setText(tr(""));
				ui.courseClassLabel->setText(tr(""));
				skillModelList.clear();
				skillTableList.clear();
				return;
			}
			ui.courseClassLabel->setText(courseStr);
			clearItemsLayout(ui.courseInfoLayout);
			MYSQL_ROW courseRow = database::course_searchName(conn,courseStr);
			QString courseIdStr = courseRow[0];
			fillMaterial4AddMember(courseIdStr);
			ui.courseInfoLabel->setText("<b>Course "+courseStr+" info</b>");
		}
// END   : ADD CLASS TAB


// ADD COURSE TAB
	private slots:	
		// START refresh (add more action)
		void refreshAddCourseAction()
		{
			refreshToOrigin();
		}
		// END refresh (add more action)

		// START STEP 1 action
		void step1SaveAction() // disable step 1, enable step 2, update info to info box
		{
			// check box name is empty
			if(ui.courseNameLineEdit->text().trimmed() == "")
			{
				QMessageBox::warning(this,tr("Course name"),tr("Please fill the blank!!"));
				ui.courseNameLineEdit->setFocus();
				return;
			}
			courseName = ui.courseNameLineEdit->text();

			if(courseMode == "CREATE")
			{
				ui.step1Widget->setEnabled(false);
				courseID = database::course_saveAction(conn,courseName);				
				setup4Step2();
			}
			else
			{
				database::course_editById(conn,QString::number(courseID),courseName);

				//update info box
				clearItemsLayout(ui.step1Layout);
				QLabel *courseLabel = new QLabel(ui.classInsertGroupBox);
				courseLabel->setText("<b>Course name:</b>");
				ui.step1Layout->addWidget(courseLabel);

				QLabel *courseNameShow = new QLabel(ui.classInsertGroupBox);
				courseNameShow->setText(courseName);
				ui.step1Layout->addWidget(courseNameShow);

				ui.resultLabel->setText("<span style='color:red'><b>Step1:Saved</b></span>");
			}
			return;
		}
		// END STEP 1 action
			
		// START STEP2 2 action
		void step2SaveAction() // save value to skillsCourse, fill step 3 info, step 3 appear, fill info into info bo
		{
			int numSkills = ui.rightWidget->count();
			if(numSkills == 0)
			{
				QMessageBox::warning(this,tr("Skill choice"),tr("Please choose skills!!"));
				return;
			}
			if(courseMode == "CREATE")
				saveCourseSKillTable(numSkills);

			setup4Step3();
			
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
		/**
		  *	@param skillNIndex : "<skill>,<index>" (index: index trong skillWidgets [thu tu skills])
		  */	
		void listMaterial(QString skillNIndex)
		{
			QStringList stringlist = skillNIndex.split(",");
			QString skill = stringlist.at(0);
			QString index = stringlist.at(1);
			std::string temp1 = index.toStdString();
			const char* temp2 = temp1.c_str();
			int indexInt  = atoi(temp2);

			listMaterialDialog *dialog = new listMaterialDialog(this,skill,courseID);
			dialog->exec();
			bool isChange = dialog->isChanged;
			if(isChange == true)
			{
				MYSQL_ROW skillRow = database::skill_searchName(conn,skill);
				QString skillId    = skillRow[0];
				//Clear old list, and add new list --> Box Info
				QListWidget *listWidget = skillWidgets.at(indexInt);
				listWidget->clear();

				QString courseIdStr  = QString::number(courseID);
				MYSQL_RES *res = database::skillMaterial_searchSkillId(conn,skillId,courseIdStr);
				while(MYSQL_ROW skillMaRow = mysql_fetch_row(res))
				{
					QString maId = skillMaRow[1];
					MYSQL_ROW materialRow = database::material_searchMaterialId(conn,maId);
					if(materialRow)
					{
						QString ma   = materialRow[1];
						listWidget->addItem(ma);
					}
				}	
			}
			int c = 1;
		}
		/**
		  * @param skillNID : "<skill>,<id>"
		  */	
		void addMaterial(QString skillNIndex)
		{			
			bool isAdd = isAddMaterial(skillNIndex);
			while(isAdd ==true)
			{
				ui.resultLabel->setText("<span style='color:green'><b>Material: saved</b></span>");
				isAdd = isAddMaterial(skillNIndex);
			}
		}
		// END STEP 3 action
		
		void saveCourseAction()
		{
			QWidget * tab = ui.mainTab->widget(2);
			ui.mainTab->setCurrentWidget(tab);
			refreshToOrigin();
			// load course list
			loadListCourseTab();
			ui.mainTab->setTabEnabled(0,true);
			ui.mainTab->setTabEnabled(1,true);
			ui.mainTab->setTabEnabled(2,true);
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
		void searchCourseAction()
		{
			QString textSearchTemp = ui.searchCourseLineEdit->text();
			QString textSearch     = textSearchTemp.trimmed();
		
			MYSQL_RES *res = database::course_searchPartName(conn,textSearch);
			//delete all row and fill data
			listCourseModel->clear();
			QList<QString> headerList;
			headerList << "Course Name" << "Skill" << "Material" << "Edit" << "Delete";
			setHeaderTable(listCourseModel, headerList);
			fillListCourse(res,ui.listCourseTable,listCourseModel,0);
		}

		void refreshCourseListAction()
		{
			loadListCourseTab();
			ui.searchCourseLineEdit->setText("");
		}
		void loadDialogAction(QString courseId)
		{
			listCourseDialog *courseDialog = new listCourseDialog(this,courseId);
			courseDialog->exec();
		}
		void editCourseAction(QString courseId)
		{
			// Edit info
			// --> Must asign value to CourseId and CourseName --> for value in clicked() signal()
			MYSQL_ROW courseRow = database::course_searchId(conn,courseId);
			courseName          = courseRow[1];
			courseID = courseId.toInt();
			courseMode = "EDIT";
			//setup info
			ui.courseNameLineEdit->setText(courseName); // step1
			setup4Step2();
			setup4Step3();
			ui.step2Widget->setEnabled(false);

			// Change tab to Course Tab
			QWidget * tab = ui.mainTab->widget(3);
			ui.mainTab->setCurrentWidget(tab);
			ui.mainTab->setTabEnabled(0,false);
			ui.mainTab->setTabEnabled(1,false);
			ui.mainTab->setTabEnabled(2,false);

			ui.addMoreButton->setVisible(false);
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
				MYSQL_ROW courseRow = database::course_searchId(conn, courseId);
				QString nameCourse  = courseRow[1];
				
				MYSQL_RES *res = database::courseSkill_searchCourseId(conn,courseId);
				while( MYSQL_ROW courseSkillRow = mysql_fetch_row(res))
				{
					QString skillId = courseSkillRow[1];
					MYSQL_ROW skillRow = database::skill_searchSkillId(conn,skillId);

					MYSQL_RES *resSkillMaterial = database::skillMaterial_searchSkillId(conn,skillId,courseId);
					while(MYSQL_ROW skillMaterialRow = mysql_fetch_row(resSkillMaterial) )
					{
						QString materialId = skillMaterialRow[1];
						database::material_deleteById(conn,materialId);
						database::skillMaterial_deleteByMaterialId(conn,materialId);
					}
					database::couresSkill_deleteByCourseId(conn,skillId);
				}
				database::course_deleteBySkillId(conn,courseId);
			
				// Delete row of QTableView
				int rowCount = listCourseModel->rowCount();
				for(int i =0; i < rowCount; i++)
					if(nameCourse == listCourseModel->data(listCourseModel->index(i,0), Qt::DisplayRole).toString())
						listCourseModel->removeRow(i);
			}
		}

};

#endif // MYCLASS_H

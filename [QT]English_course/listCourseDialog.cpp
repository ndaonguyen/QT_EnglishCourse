#include <QtGui>
#include "listCourseDialog.h"
#include "database.h"

listCourseDialog::listCourseDialog(QWidget *parent, QString courseId)
	: QDialog(parent)
{
	QVBoxLayout *topLeftLayout = new QVBoxLayout;
	
	std::string temp1  = courseId.toStdString();
	const char* temp2  = temp1.c_str();
	int courseIdInt    = atoi(temp2);
	MYSQL* conn = database::connectByC();

	MYSQL_RES* res_set = database::courseSkill_searchCourseId(conn,courseIdInt);
	MYSQL_ROW row;
	while(row = mysql_fetch_row(res_set))
	{
		QString skillID = row[1];
		temp1  = skillID.toStdString();
		temp2  = temp1.c_str();
		int skillIdInt = atoi(temp2);
		MYSQL_ROW skillRow =  database::skill_searchSkillId(conn,skillIdInt);
		QString skillName = skillRow[1];
		QLabel *skill = new QLabel("<b>"+skillName+"</b>");
		topLeftLayout->addWidget(skill);
		
		MYSQL_RES* result = database::skillMaterial_searchSkillId(conn,skillIdInt,courseIdInt); 
		MYSQL_ROW materialRow;
		QListWidget *materialList = new QListWidget();
		while(materialRow = mysql_fetch_row(result))
		{
			QString temp = materialRow[1];
			std::string temp1  = temp.toStdString();
			const char* temp2  = temp1.c_str();
			int materialIdInt    = atoi(temp2);

			MYSQL_ROW materialData = database::material_searchMaterialId(conn,materialIdInt);
			materialList->addItem(materialData[1]);
		}
		topLeftLayout->addWidget(materialList);
	}
	setLayout(topLeftLayout);
	setWindowTitle(tr("Material list"));
}

listCourseDialog::~listCourseDialog(void)
{

}

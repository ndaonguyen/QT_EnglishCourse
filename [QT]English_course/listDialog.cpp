#include <QtGui>
#include "listDialog.h"

listDialog::listDialog(QWidget *parent, QString skillName)
    : QDialog(parent)
{
	label       = new QLabel(tr("List  of Material ")+skillName);
	listWidget  = new QListWidget(parent);
	MYSQL* conn = database::connectByC();
	MYSQL_ROW skillRow = database::skill_searchName(conn,skillName);
	if (skillRow)
	{
		int skillId = atoi(skillRow[0]);
		MYSQL_RES* res_set =  database::skillMaterial_searchSkillId(conn,skillId);
		MYSQL_ROW row;
		while(row = mysql_fetch_row(res_set))
		{
			int materialId = atoi(row[1]);
			MYSQL_ROW rowMaterial =  database::material_searchMaterialId(conn,materialId);
			QString material = QString::fromUtf8(rowMaterial[1]);
			listWidget->addItem(material);

		}
	}



	QVBoxLayout *topLeftLayout = new QVBoxLayout;
	topLeftLayout->addWidget(label);
	topLeftLayout->addWidget(listWidget);

	setLayout(topLeftLayout);
	setWindowTitle(tr("Material list"));
	setFixedHeight(sizeHint().height());
}

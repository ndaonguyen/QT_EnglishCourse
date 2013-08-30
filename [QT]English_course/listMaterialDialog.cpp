#include <QtGui>
#include "listMaterialDialog.h"

listMaterialDialog::listMaterialDialog(QWidget *parent, QString skillName, int courseId)
    : QDialog(parent)
{
	conn = database::connectByC();
	label      = new QLabel(tr("List  of Material ")+skillName);
	view = new QTableView;
	model = new QStandardItemModel(this);
	view->setModel(model);
	model->setColumnCount(2);
	view->setColumnWidth(0,30);
	view->setColumnWidth(1,200);

	MYSQL* conn = database::connectByC();
	MYSQL_ROW skillRow = database::skill_searchName(conn,skillName);
	if (skillRow)
	{
		model->setHorizontalHeaderItem(0,new QStandardItem(tr("-")));
		model->setHorizontalHeaderItem(1,new QStandardItem(tr("Material")));

		int skillId = atoi(skillRow[0]);
		MYSQL_RES* res_set =  database::skillMaterial_searchSkillId(conn,skillId,courseId);
		MYSQL_ROW row;
		int rowIndex = 0;
		while(row = mysql_fetch_row(res_set))
		{
			int materialId = atoi(row[1]);
			MYSQL_ROW rowMaterial =  database::material_searchMaterialId(conn,materialId);
			QString material = QString::fromUtf8(rowMaterial[1]);

			QPushButton *button = new QPushButton("");
			QPixmap pixmap("Resources/Delete_icon.png");
			QIcon buttonIcon(pixmap);
			button->setIcon(buttonIcon);

			QSignalMapper *signalMapper = new QSignalMapper(this);
			signalMapper->setMapping(button,materialId);
			QObject::connect(button,SIGNAL(clicked()),signalMapper,SLOT(map()));
			QObject::connect(signalMapper,SIGNAL(mapped(int)),this,SLOT(deleteMaterial(int)));

			QStandardItem *materName = new QStandardItem(material);
			model->setItem(rowIndex, 1, materName);
			view->setIndexWidget(model->index(rowIndex,0),button);
			rowIndex++;
		}
	}
	QVBoxLayout *topLeftLayout = new QVBoxLayout;
	topLeftLayout->addWidget(label);
	topLeftLayout->addWidget(view);

	setLayout(topLeftLayout);
	setWindowTitle(tr("Material list"));
	setFixedHeight(sizeHint().height());
}
listMaterialDialog::~listMaterialDialog(void)
{
	database::closeConnectionC(conn);
}
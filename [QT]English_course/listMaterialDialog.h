#pragma once
#include <QDialog>
#include "database.h"
#include <QSignalMapper>
#include <QStandardItemModel>

class QLabel;
class QTableView;
class QPushButton;

class listMaterialDialog : public QDialog
{
    Q_OBJECT
public:
    listMaterialDialog(QWidget *parent = 0, QString skillName = "",int courseId=0);
	~listMaterialDialog(void);

private:
    QLabel *label;
	QTableView *view;
	MYSQL *conn;
	QStandardItemModel *model;
	private slots:
		void deleteMaterial(int materialId)
		{
			MYSQL_ROW rowMater = database::material_searchMaterialId(conn,materialId);
			QString materialName = rowMater[1];
			database::material_deleteById(conn,materialId);
			database::skillMaterial_deleteByMaterialId(conn,materialId);
			
			int numRows = model->rowCount();
			for(int i =0;i<numRows;i++)
			{
				if(materialName == model->data(model->index(i,1),Qt::DisplayRole).toString() )
					model->removeRow(i);
			}
		}
};

#pragma once
#include <QDialog>
#include "database.h"

class QLabel;
class QListWidget;

class listMaterialDialog : public QDialog
{
    Q_OBJECT
public:
    listMaterialDialog(QWidget *parent = 0, QString skillName = "",int courseId=0);

private:
    QLabel *label;
	QListWidget *listWidget;
};

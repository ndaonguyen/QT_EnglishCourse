#pragma once
#include <QDialog>
#include "database.h"
#include <QSignalMapper>
#include <QStandardItemModel>

class QLabel;
class QPushButton;
class QTableView;


class listMemberDialog : public QDialog
{
	 Q_OBJECT
public:
	listMemberDialog(QWidget *parent = 0,QString classId=0);
	~listMemberDialog(void);
private:
	MYSQL *conn;
	QLabel *label;
	QList<QString> listMemberIdDelete;
	QPushButton *saveButton;
	QPushButton *cancelButton;
	QTableView *view;
	QStandardItemModel *model;
	private slots:
		void deleteMemberAction(QString memberId)
		{
			MYSQL_ROW memberRow = database::member_searchMemberId(conn,memberId);
			QString memberName  = memberRow[1];
			int rowCount = model->rowCount();
			for(int i=0;i<rowCount;i++)
			{
				QString memberCom = model->data(model->index(i,1),Qt::DisplayRole).toString();
				if(memberName == memberCom )
				{
					model->removeRow(i);
					break;
				}
			}
			listMemberIdDelete.append(memberId);
		}

		void saveListAction()
		{
			int numRow    = model->rowCount();
			int numColumn = model->columnCount();
			QList<QString> memberInfo;
			for(int r = 0;r<numRow;r++) // edit info
			{
				for(int c =1;c<numColumn-1;c++)
				{
					memberInfo.append(model->data(model->index(r,c),Qt::DisplayRole).toString());
				}
				database::member_editById(conn,model->data(model->index(r,0),Qt::DisplayRole).toString(),memberInfo);
				memberInfo.clear();
			}
			//delete
			int numDelete = listMemberIdDelete.count();
			for(int i =0;i<numDelete;i++)
			{
				database::classMember_deleteById(conn,listMemberIdDelete.at(i));
				database::member_deleteById(conn, listMemberIdDelete.at(i));
			}
			close();
		}

};

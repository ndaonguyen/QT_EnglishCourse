#pragma once

class QLabel;
class QLineEdit;
class QPushButton;

class addMemberDialog
{
public:
	addMemberDialog(void);
	~addMemberDialog(void);
private:
	QLabel *nameLabel;
	QLineEdit *nameLineEdit;
	QLabel *birthYearLabel;
	QLineEdit *birthYearLineEdit;
	QPushButton *saveButton;
	private slots:
		void saveMemberAction;
};

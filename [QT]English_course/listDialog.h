#pragma once
#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class listDialog : public QDialog
{
    Q_OBJECT
public:
    listDialog(QWidget *parent = 0,int index=0, QString skillName=NULL);

signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);


private slots:
    void findClicked();
    void enableFindButton(const QString &text);
private:
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;
};

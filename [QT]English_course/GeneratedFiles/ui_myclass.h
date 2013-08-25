/********************************************************************************
** Form generated from reading UI file 'myclass.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCLASS_H
#define UI_MYCLASS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyClassClass
{
public:
    QAction *actionAdd_class;
    QAction *actionList;
    QAction *actionOpenFile;
    QAction *actionCreateNew;
    QAction *actionEdit;
    QAction *actionDelete;
    QAction *actionSave;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *listTab;
    QPushButton *searchButton;
    QLineEdit *searchLineEdit;
    QTableView *listTable;
    QWidget *addClassTab;
    QWidget *addCourseTab;
    QGroupBox *classInsertgGroupBox;
    QWidget *step1Widget;
    QLabel *step1Label;
    QLabel *setCourseLabel;
    QLineEdit *courseNameLineEdit;
    QPushButton *saveButton;
    QWidget *step2Widget;
    QLabel *step2Label;
    QListWidget *leftWidget;
    QListWidget *rightWidget;
    QPushButton *left2RightButton;
    QPushButton *right2LeftButton;
    QPushButton *all2RightButton;
    QPushButton *all2LeftButton;
    QPushButton *saveButton2;
    QPushButton *pushButton;
    QWidget *step3Widget;
    QLabel *step2Label_2;
    QPushButton *saveButton3;
    QMenuBar *menuBar;
    QMenu *menuClass;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MyClassClass)
    {
        if (MyClassClass->objectName().isEmpty())
            MyClassClass->setObjectName(QString::fromUtf8("MyClassClass"));
        MyClassClass->resize(940, 800);
        actionAdd_class = new QAction(MyClassClass);
        actionAdd_class->setObjectName(QString::fromUtf8("actionAdd_class"));
        actionList = new QAction(MyClassClass);
        actionList->setObjectName(QString::fromUtf8("actionList"));
        actionOpenFile = new QAction(MyClassClass);
        actionOpenFile->setObjectName(QString::fromUtf8("actionOpenFile"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/MyClass/Resources/openFile.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenFile->setIcon(icon);
        actionCreateNew = new QAction(MyClassClass);
        actionCreateNew->setObjectName(QString::fromUtf8("actionCreateNew"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/MyClass/Resources/createNew.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreateNew->setIcon(icon1);
        actionEdit = new QAction(MyClassClass);
        actionEdit->setObjectName(QString::fromUtf8("actionEdit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/MyClass/Resources/edit.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit->setIcon(icon2);
        actionDelete = new QAction(MyClassClass);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/MyClass/Resources/Delete_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon3);
        actionSave = new QAction(MyClassClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/MyClass/Resources/save_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon4);
        centralWidget = new QWidget(MyClassClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 941, 691));
        listTab = new QWidget();
        listTab->setObjectName(QString::fromUtf8("listTab"));
        searchButton = new QPushButton(listTab);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setGeometry(QRect(240, 10, 51, 23));
        searchLineEdit = new QLineEdit(listTab);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));
        searchLineEdit->setGeometry(QRect(20, 10, 211, 20));
        listTable = new QTableView(listTab);
        listTable->setObjectName(QString::fromUtf8("listTable"));
        listTable->setGeometry(QRect(10, 40, 911, 421));
        tabWidget->addTab(listTab, QString());
        addClassTab = new QWidget();
        addClassTab->setObjectName(QString::fromUtf8("addClassTab"));
        tabWidget->addTab(addClassTab, QString());
        addCourseTab = new QWidget();
        addCourseTab->setObjectName(QString::fromUtf8("addCourseTab"));
        classInsertgGroupBox = new QGroupBox(addCourseTab);
        classInsertgGroupBox->setObjectName(QString::fromUtf8("classInsertgGroupBox"));
        classInsertgGroupBox->setGeometry(QRect(600, 10, 321, 641));
        step1Widget = new QWidget(addCourseTab);
        step1Widget->setObjectName(QString::fromUtf8("step1Widget"));
        step1Widget->setGeometry(QRect(70, 20, 381, 81));
        step1Label = new QLabel(step1Widget);
        step1Label->setObjectName(QString::fromUtf8("step1Label"));
        step1Label->setGeometry(QRect(10, 10, 291, 16));
        setCourseLabel = new QLabel(step1Widget);
        setCourseLabel->setObjectName(QString::fromUtf8("setCourseLabel"));
        setCourseLabel->setGeometry(QRect(40, 40, 91, 16));
        courseNameLineEdit = new QLineEdit(step1Widget);
        courseNameLineEdit->setObjectName(QString::fromUtf8("courseNameLineEdit"));
        courseNameLineEdit->setGeometry(QRect(130, 40, 231, 20));
        saveButton = new QPushButton(step1Widget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(340, 0, 41, 31));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/MyClass/Resources/saveButtton.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon5);
        saveButton->setIconSize(QSize(18, 18));
        step2Widget = new QWidget(addCourseTab);
        step2Widget->setObjectName(QString::fromUtf8("step2Widget"));
        step2Widget->setGeometry(QRect(70, 110, 381, 161));
        step2Label = new QLabel(step2Widget);
        step2Label->setObjectName(QString::fromUtf8("step2Label"));
        step2Label->setGeometry(QRect(10, 10, 211, 16));
        leftWidget = new QListWidget(step2Widget);
        leftWidget->setObjectName(QString::fromUtf8("leftWidget"));
        leftWidget->setGeometry(QRect(20, 40, 121, 111));
        rightWidget = new QListWidget(step2Widget);
        rightWidget->setObjectName(QString::fromUtf8("rightWidget"));
        rightWidget->setGeometry(QRect(230, 40, 121, 111));
        left2RightButton = new QPushButton(step2Widget);
        left2RightButton->setObjectName(QString::fromUtf8("left2RightButton"));
        left2RightButton->setGeometry(QRect(160, 40, 51, 23));
        right2LeftButton = new QPushButton(step2Widget);
        right2LeftButton->setObjectName(QString::fromUtf8("right2LeftButton"));
        right2LeftButton->setGeometry(QRect(160, 70, 51, 23));
        all2RightButton = new QPushButton(step2Widget);
        all2RightButton->setObjectName(QString::fromUtf8("all2RightButton"));
        all2RightButton->setGeometry(QRect(160, 100, 51, 23));
        all2LeftButton = new QPushButton(step2Widget);
        all2LeftButton->setObjectName(QString::fromUtf8("all2LeftButton"));
        all2LeftButton->setGeometry(QRect(160, 130, 51, 23));
        saveButton2 = new QPushButton(step2Widget);
        saveButton2->setObjectName(QString::fromUtf8("saveButton2"));
        saveButton2->setGeometry(QRect(340, 0, 41, 31));
        saveButton2->setIcon(icon5);
        saveButton2->setIconSize(QSize(18, 18));
        pushButton = new QPushButton(step2Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(294, 0, 41, 31));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/MyClass/Resources/add-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon6);
        step3Widget = new QWidget(addCourseTab);
        step3Widget->setObjectName(QString::fromUtf8("step3Widget"));
        step3Widget->setGeometry(QRect(70, 280, 381, 371));
        step2Label_2 = new QLabel(step3Widget);
        step2Label_2->setObjectName(QString::fromUtf8("step2Label_2"));
        step2Label_2->setGeometry(QRect(10, 10, 211, 16));
        saveButton3 = new QPushButton(step3Widget);
        saveButton3->setObjectName(QString::fromUtf8("saveButton3"));
        saveButton3->setGeometry(QRect(340, 0, 41, 31));
        saveButton3->setIcon(icon5);
        saveButton3->setIconSize(QSize(18, 18));
        tabWidget->addTab(addCourseTab, QString());
        MyClassClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyClassClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 940, 21));
        menuClass = new QMenu(menuBar);
        menuClass->setObjectName(QString::fromUtf8("menuClass"));
        MyClassClass->setMenuBar(menuBar);
        toolBar = new QToolBar(MyClassClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MyClassClass->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuClass->menuAction());
        menuClass->addAction(actionList);
        menuClass->addAction(actionAdd_class);
        toolBar->addAction(actionOpenFile);
        toolBar->addSeparator();
        toolBar->addAction(actionCreateNew);
        toolBar->addAction(actionEdit);
        toolBar->addAction(actionDelete);
        toolBar->addAction(actionSave);

        retranslateUi(MyClassClass);
        QObject::connect(actionOpenFile, SIGNAL(triggered()), MyClassClass, SLOT(openFileAction()));
        QObject::connect(actionCreateNew, SIGNAL(triggered()), MyClassClass, SLOT(createAction()));
        QObject::connect(actionEdit, SIGNAL(triggered()), MyClassClass, SLOT(editAction()));
        QObject::connect(actionDelete, SIGNAL(triggered()), MyClassClass, SLOT(deleteAction()));
        QObject::connect(actionSave, SIGNAL(triggered()), MyClassClass, SLOT(saveAction()));
        QObject::connect(saveButton, SIGNAL(clicked()), MyClassClass, SLOT(step1SaveAction()));
        QObject::connect(saveButton2, SIGNAL(clicked()), MyClassClass, SLOT(step2SaveAction()));
        QObject::connect(saveButton3, SIGNAL(clicked()), MyClassClass, SLOT(step3SaveAction()));
        QObject::connect(left2RightButton, SIGNAL(clicked()), MyClassClass, SLOT(left2RightAction()));
        QObject::connect(right2LeftButton, SIGNAL(clicked()), MyClassClass, SLOT(right2LeftAction()));
        QObject::connect(all2RightButton, SIGNAL(clicked()), MyClassClass, SLOT(all2RightAction()));
        QObject::connect(all2LeftButton, SIGNAL(clicked()), MyClassClass, SLOT(all2LeftAction()));
        QObject::connect(leftWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), MyClassClass, SLOT(left2RightClickAction()));
        QObject::connect(rightWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), MyClassClass, SLOT(right2LeftClickAction()));

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MyClassClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyClassClass)
    {
        MyClassClass->setWindowTitle(QApplication::translate("MyClassClass", "MyClass", 0, QApplication::UnicodeUTF8));
        actionAdd_class->setText(QApplication::translate("MyClassClass", "Add class", 0, QApplication::UnicodeUTF8));
        actionList->setText(QApplication::translate("MyClassClass", "List class", 0, QApplication::UnicodeUTF8));
        actionOpenFile->setText(QApplication::translate("MyClassClass", "openFile", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpenFile->setToolTip(QApplication::translate("MyClassClass", "Click file to open ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCreateNew->setText(QApplication::translate("MyClassClass", "createNew", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCreateNew->setToolTip(QApplication::translate("MyClassClass", "Create new anything", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionEdit->setText(QApplication::translate("MyClassClass", "edit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionEdit->setToolTip(QApplication::translate("MyClassClass", "edit something", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionDelete->setText(QApplication::translate("MyClassClass", "delete", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MyClassClass", "save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("MyClassClass", "Add class", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        searchButton->setText(QApplication::translate("MyClassClass", "Search", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(listTab), QApplication::translate("MyClassClass", "List class", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(addClassTab), QApplication::translate("MyClassClass", "Add class", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        classInsertgGroupBox->setToolTip(QApplication::translate("MyClassClass", "Add skills", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        classInsertgGroupBox->setTitle(QApplication::translate("MyClassClass", "Class inserted :", 0, QApplication::UnicodeUTF8));
        step1Label->setText(QApplication::translate("MyClassClass", "Step 1 :Course name (e.g: Ielts, Toefl,...)", 0, QApplication::UnicodeUTF8));
        setCourseLabel->setText(QApplication::translate("MyClassClass", "Set course name:", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QString());
        step2Label->setText(QApplication::translate("MyClassClass", "Step 2: Add skills", 0, QApplication::UnicodeUTF8));
        left2RightButton->setText(QApplication::translate("MyClassClass", ">>", 0, QApplication::UnicodeUTF8));
        right2LeftButton->setText(QApplication::translate("MyClassClass", "<<", 0, QApplication::UnicodeUTF8));
        all2RightButton->setText(QApplication::translate("MyClassClass", "all >>", 0, QApplication::UnicodeUTF8));
        all2LeftButton->setText(QApplication::translate("MyClassClass", "<< all", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveButton2->setToolTip(QApplication::translate("MyClassClass", "<html><head/><body><p>Save skills</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveButton2->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("MyClassClass", "<html><head/><body><p>Add Skills</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QString());
        step2Label_2->setText(QApplication::translate("MyClassClass", "Step 3: Add materials", 0, QApplication::UnicodeUTF8));
        saveButton3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(addCourseTab), QApplication::translate("MyClassClass", "Add course", 0, QApplication::UnicodeUTF8));
        menuClass->setTitle(QApplication::translate("MyClassClass", "Class", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MyClassClass", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyClassClass: public Ui_MyClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLASS_H

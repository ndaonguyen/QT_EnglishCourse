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
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
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
#include <QtGui/QVBoxLayout>
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
    QTabWidget *mainTab;
    QWidget *listClassTab;
    QPushButton *searchButton;
    QLineEdit *searchLineEdit;
    QTableView *listTable;
    QWidget *addClassTab;
    QWidget *listCourseTab;
    QTableView *listCourseTable;
    QLineEdit *searchCourseLineEdit;
    QPushButton *searchCourseButton;
    QPushButton *pushButton;
    QWidget *addCourseTab;
    QGroupBox *classInsertGroupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *step1Layout;
    QLabel *skillLabelShow;
    QWidget *step2WidgetInfo;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *step2Layout;
    QPushButton *saveCourseButton;
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
    QPushButton *addSkill;
    QLabel *label;
    QLabel *label_2;
    QWidget *step3Widget;
    QLabel *step2Label_2;
    QWidget *verticalLayoutWidget;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout;
    QFrame *line1_2;
    QFrame *line2_3;
    QLabel *resultLabel;
    QPushButton *addMoreButton;
    QMenuBar *menuBar;
    QMenu *menuClass;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MyClassClass)
    {
        if (MyClassClass->objectName().isEmpty())
            MyClassClass->setObjectName(QString::fromUtf8("MyClassClass"));
        MyClassClass->resize(917, 781);
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
        mainTab = new QTabWidget(centralWidget);
        mainTab->setObjectName(QString::fromUtf8("mainTab"));
        mainTab->setGeometry(QRect(20, 10, 891, 621));
        listClassTab = new QWidget();
        listClassTab->setObjectName(QString::fromUtf8("listClassTab"));
        searchButton = new QPushButton(listClassTab);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setGeometry(QRect(240, 10, 51, 23));
        searchLineEdit = new QLineEdit(listClassTab);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));
        searchLineEdit->setGeometry(QRect(20, 10, 211, 20));
        listTable = new QTableView(listClassTab);
        listTable->setObjectName(QString::fromUtf8("listTable"));
        listTable->setGeometry(QRect(20, 50, 691, 541));
        mainTab->addTab(listClassTab, QString());
        addClassTab = new QWidget();
        addClassTab->setObjectName(QString::fromUtf8("addClassTab"));
        mainTab->addTab(addClassTab, QString());
        listCourseTab = new QWidget();
        listCourseTab->setObjectName(QString::fromUtf8("listCourseTab"));
        listCourseTable = new QTableView(listCourseTab);
        listCourseTable->setObjectName(QString::fromUtf8("listCourseTable"));
        listCourseTable->setGeometry(QRect(10, 50, 671, 541));
        searchCourseLineEdit = new QLineEdit(listCourseTab);
        searchCourseLineEdit->setObjectName(QString::fromUtf8("searchCourseLineEdit"));
        searchCourseLineEdit->setGeometry(QRect(10, 10, 201, 21));
        searchCourseButton = new QPushButton(listCourseTab);
        searchCourseButton->setObjectName(QString::fromUtf8("searchCourseButton"));
        searchCourseButton->setGeometry(QRect(220, 10, 75, 23));
        pushButton = new QPushButton(listCourseTab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(690, 0, 61, 51));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/MyClass/Resources/refresh_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon5);
        pushButton->setIconSize(QSize(40, 40));
        mainTab->addTab(listCourseTab, QString());
        addCourseTab = new QWidget();
        addCourseTab->setObjectName(QString::fromUtf8("addCourseTab"));
        classInsertGroupBox = new QGroupBox(addCourseTab);
        classInsertGroupBox->setObjectName(QString::fromUtf8("classInsertGroupBox"));
        classInsertGroupBox->setGeometry(QRect(530, 10, 341, 581));
        horizontalLayoutWidget = new QWidget(classInsertGroupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 20, 261, 41));
        step1Layout = new QHBoxLayout(horizontalLayoutWidget);
        step1Layout->setSpacing(6);
        step1Layout->setContentsMargins(11, 11, 11, 11);
        step1Layout->setObjectName(QString::fromUtf8("step1Layout"));
        step1Layout->setContentsMargins(0, 0, 0, 0);
        skillLabelShow = new QLabel(classInsertGroupBox);
        skillLabelShow->setObjectName(QString::fromUtf8("skillLabelShow"));
        skillLabelShow->setGeometry(QRect(20, 70, 46, 13));
        step2WidgetInfo = new QWidget(classInsertGroupBox);
        step2WidgetInfo->setObjectName(QString::fromUtf8("step2WidgetInfo"));
        step2WidgetInfo->setGeometry(QRect(50, 100, 261, 441));
        verticalLayoutWidget_2 = new QWidget(step2WidgetInfo);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 261, 441));
        step2Layout = new QVBoxLayout(verticalLayoutWidget_2);
        step2Layout->setSpacing(6);
        step2Layout->setContentsMargins(11, 11, 11, 11);
        step2Layout->setObjectName(QString::fromUtf8("step2Layout"));
        step2Layout->setContentsMargins(0, 0, 0, 0);
        saveCourseButton = new QPushButton(classInsertGroupBox);
        saveCourseButton->setObjectName(QString::fromUtf8("saveCourseButton"));
        saveCourseButton->setGeometry(QRect(120, 550, 141, 23));
        saveCourseButton->setAutoFillBackground(true);
        step1Widget = new QWidget(addCourseTab);
        step1Widget->setObjectName(QString::fromUtf8("step1Widget"));
        step1Widget->setGeometry(QRect(120, 20, 381, 81));
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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/MyClass/Resources/saveButtton.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon6);
        saveButton->setIconSize(QSize(18, 18));
        step2Widget = new QWidget(addCourseTab);
        step2Widget->setObjectName(QString::fromUtf8("step2Widget"));
        step2Widget->setGeometry(QRect(120, 130, 381, 181));
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
        saveButton2->setIcon(icon6);
        saveButton2->setIconSize(QSize(18, 18));
        addSkill = new QPushButton(step2Widget);
        addSkill->setObjectName(QString::fromUtf8("addSkill"));
        addSkill->setGeometry(QRect(260, 0, 75, 31));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/MyClass/Resources/add-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        addSkill->setIcon(icon7);
        addSkill->setIconSize(QSize(18, 18));
        label = new QLabel(step2Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 160, 46, 13));
        label_2 = new QLabel(step2Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(260, 160, 71, 16));
        step3Widget = new QWidget(addCourseTab);
        step3Widget->setObjectName(QString::fromUtf8("step3Widget"));
        step3Widget->setGeometry(QRect(120, 350, 381, 241));
        step2Label_2 = new QLabel(step3Widget);
        step2Label_2->setObjectName(QString::fromUtf8("step2Label_2"));
        step2Label_2->setGeometry(QRect(10, 10, 131, 16));
        verticalLayoutWidget = new QWidget(step3Widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 40, 351, 201));
        verticalLayoutWidget_3 = new QWidget(verticalLayoutWidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 0, 351, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        line1_2 = new QFrame(addCourseTab);
        line1_2->setObjectName(QString::fromUtf8("line1_2"));
        line1_2->setGeometry(QRect(120, 110, 381, 16));
        line1_2->setFrameShape(QFrame::HLine);
        line1_2->setFrameShadow(QFrame::Sunken);
        line2_3 = new QFrame(addCourseTab);
        line2_3->setObjectName(QString::fromUtf8("line2_3"));
        line2_3->setGeometry(QRect(120, 330, 381, 16));
        line2_3->setFrameShape(QFrame::HLine);
        line2_3->setFrameShadow(QFrame::Sunken);
        resultLabel = new QLabel(addCourseTab);
        resultLabel->setObjectName(QString::fromUtf8("resultLabel"));
        resultLabel->setGeometry(QRect(0, 240, 91, 41));
        addMoreButton = new QPushButton(addCourseTab);
        addMoreButton->setObjectName(QString::fromUtf8("addMoreButton"));
        addMoreButton->setGeometry(QRect(10, 120, 71, 71));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/MyClass/Resources/addIcon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        addMoreButton->setIcon(icon8);
        addMoreButton->setIconSize(QSize(60, 60));
        mainTab->addTab(addCourseTab, QString());
        MyClassClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyClassClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 917, 21));
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
        QObject::connect(left2RightButton, SIGNAL(clicked()), MyClassClass, SLOT(left2RightAction()));
        QObject::connect(right2LeftButton, SIGNAL(clicked()), MyClassClass, SLOT(right2LeftAction()));
        QObject::connect(all2RightButton, SIGNAL(clicked()), MyClassClass, SLOT(all2RightAction()));
        QObject::connect(all2LeftButton, SIGNAL(clicked()), MyClassClass, SLOT(all2LeftAction()));
        QObject::connect(leftWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), MyClassClass, SLOT(left2RightClickAction()));
        QObject::connect(rightWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), MyClassClass, SLOT(right2LeftClickAction()));
        QObject::connect(addSkill, SIGNAL(clicked()), MyClassClass, SLOT(addSkillAction()));
        QObject::connect(addMoreButton, SIGNAL(clicked()), MyClassClass, SLOT(refreshAddCourseAction()));
        QObject::connect(pushButton, SIGNAL(clicked()), MyClassClass, SLOT(refreshCourseListAction()));

        mainTab->setCurrentIndex(3);


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
        mainTab->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        searchButton->setText(QApplication::translate("MyClassClass", "Search", 0, QApplication::UnicodeUTF8));
        mainTab->setTabText(mainTab->indexOf(listClassTab), QApplication::translate("MyClassClass", "List class", 0, QApplication::UnicodeUTF8));
        mainTab->setTabText(mainTab->indexOf(addClassTab), QApplication::translate("MyClassClass", "Add class", 0, QApplication::UnicodeUTF8));
        searchCourseButton->setText(QApplication::translate("MyClassClass", "Search", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        mainTab->setTabText(mainTab->indexOf(listCourseTab), QApplication::translate("MyClassClass", "List Course", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        classInsertGroupBox->setToolTip(QApplication::translate("MyClassClass", "Add skills", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        classInsertGroupBox->setTitle(QApplication::translate("MyClassClass", "Info inserted :", 0, QApplication::UnicodeUTF8));
        skillLabelShow->setText(QApplication::translate("MyClassClass", "<html><head/><body><p><span style=\" font-weight:600;\">Skills:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        saveCourseButton->setText(QApplication::translate("MyClassClass", "FINISH,  BACK  TO LIST !!!", 0, QApplication::UnicodeUTF8));
        step1Label->setText(QApplication::translate("MyClassClass", "<html><head/><body><p><span style=\" font-weight:600;\">Step 1 :Course name (e.g: Ielts, Toefl,...)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        setCourseLabel->setText(QApplication::translate("MyClassClass", "Set course name:", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QString());
        step2Label->setText(QApplication::translate("MyClassClass", "<html><head/><body><p><span style=\" font-weight:600;\">Step 2: Skills</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        left2RightButton->setText(QApplication::translate("MyClassClass", ">>", 0, QApplication::UnicodeUTF8));
        right2LeftButton->setText(QApplication::translate("MyClassClass", "<<", 0, QApplication::UnicodeUTF8));
        all2RightButton->setText(QApplication::translate("MyClassClass", "all >>", 0, QApplication::UnicodeUTF8));
        all2LeftButton->setText(QApplication::translate("MyClassClass", "<< all", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveButton2->setToolTip(QApplication::translate("MyClassClass", "<html><head/><body><p>Save skills</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveButton2->setText(QString());
        addSkill->setText(QString());
        label->setText(QApplication::translate("MyClassClass", "Skill list", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MyClassClass", "course's skill", 0, QApplication::UnicodeUTF8));
        step2Label_2->setText(QApplication::translate("MyClassClass", "<html><head/><body><p><span style=\" font-weight:600;\">Step 3: Materials</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        resultLabel->setText(QString());
        mainTab->setTabText(mainTab->indexOf(addCourseTab), QApplication::translate("MyClassClass", "Add course", 0, QApplication::UnicodeUTF8));
        menuClass->setTitle(QApplication::translate("MyClassClass", "Class", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MyClassClass", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyClassClass: public Ui_MyClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLASS_H

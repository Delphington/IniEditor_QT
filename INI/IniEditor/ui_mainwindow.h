/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openFile;
    QAction *openDirectory;
    QAction *addFile;
    QAction *saveFile;
    QWidget *centralwidget;
    QListWidget *listWidget;
    QTreeWidget *treeWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_sections;
    QComboBox *ComboBox_section;
    QPushButton *Btn_add_section;
    QPushButton *Btn_delete_section;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_add;
    QLabel *label_type;
    QLabel *label_key;
    QLabel *label_value;
    QComboBox *ComboBoxType;
    QLineEdit *lineEdit_key;
    QLineEdit *lineEdit_value;
    QPushButton *btn_add_key;
    QGroupBox *groupBox_del;
    QLabel *label_k;
    QComboBox *ComboBoxKey;
    QPushButton *Btn_delete_s;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(999, 693);
        openFile = new QAction(MainWindow);
        openFile->setObjectName(QString::fromUtf8("openFile"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/img/openFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        openFile->setIcon(icon);
        openDirectory = new QAction(MainWindow);
        openDirectory->setObjectName(QString::fromUtf8("openDirectory"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/img/openDirectory.png"), QSize(), QIcon::Normal, QIcon::Off);
        openDirectory->setIcon(icon1);
        addFile = new QAction(MainWindow);
        addFile->setObjectName(QString::fromUtf8("addFile"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rec/img/newFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        addFile->setIcon(icon2);
        saveFile = new QAction(MainWindow);
        saveFile->setObjectName(QString::fromUtf8("saveFile"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/rec/img/saveFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveFile->setIcon(icon3);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 20, 321, 521));
        treeWidget = new QTreeWidget(centralwidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(360, 20, 571, 251));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(360, 280, 571, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_sections = new QLabel(horizontalLayoutWidget);
        label_sections->setObjectName(QString::fromUtf8("label_sections"));

        horizontalLayout->addWidget(label_sections);

        ComboBox_section = new QComboBox(horizontalLayoutWidget);
        ComboBox_section->setObjectName(QString::fromUtf8("ComboBox_section"));

        horizontalLayout->addWidget(ComboBox_section);

        Btn_add_section = new QPushButton(horizontalLayoutWidget);
        Btn_add_section->setObjectName(QString::fromUtf8("Btn_add_section"));
        Btn_add_section->setMinimumSize(QSize(1, 1));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/rec/img/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_add_section->setIcon(icon4);

        horizontalLayout->addWidget(Btn_add_section);

        Btn_delete_section = new QPushButton(horizontalLayoutWidget);
        Btn_delete_section->setObjectName(QString::fromUtf8("Btn_delete_section"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/rec/img/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_delete_section->setIcon(icon5);

        horizontalLayout->addWidget(Btn_delete_section);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 7);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(360, 370, 571, 171));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox_add = new QGroupBox(horizontalLayoutWidget_2);
        groupBox_add->setObjectName(QString::fromUtf8("groupBox_add"));
        label_type = new QLabel(groupBox_add);
        label_type->setObjectName(QString::fromUtf8("label_type"));
        label_type->setGeometry(QRect(10, 30, 55, 21));
        label_key = new QLabel(groupBox_add);
        label_key->setObjectName(QString::fromUtf8("label_key"));
        label_key->setGeometry(QRect(10, 60, 55, 21));
        label_value = new QLabel(groupBox_add);
        label_value->setObjectName(QString::fromUtf8("label_value"));
        label_value->setGeometry(QRect(10, 90, 55, 21));
        ComboBoxType = new QComboBox(groupBox_add);
        ComboBoxType->setObjectName(QString::fromUtf8("ComboBoxType"));
        ComboBoxType->setGeometry(QRect(80, 30, 171, 22));
        lineEdit_key = new QLineEdit(groupBox_add);
        lineEdit_key->setObjectName(QString::fromUtf8("lineEdit_key"));
        lineEdit_key->setGeometry(QRect(80, 60, 113, 21));
        lineEdit_value = new QLineEdit(groupBox_add);
        lineEdit_value->setObjectName(QString::fromUtf8("lineEdit_value"));
        lineEdit_value->setGeometry(QRect(80, 90, 113, 21));
        btn_add_key = new QPushButton(groupBox_add);
        btn_add_key->setObjectName(QString::fromUtf8("btn_add_key"));
        btn_add_key->setGeometry(QRect(10, 120, 81, 28));

        horizontalLayout_2->addWidget(groupBox_add);

        groupBox_del = new QGroupBox(horizontalLayoutWidget_2);
        groupBox_del->setObjectName(QString::fromUtf8("groupBox_del"));
        label_k = new QLabel(groupBox_del);
        label_k->setObjectName(QString::fromUtf8("label_k"));
        label_k->setGeometry(QRect(20, 30, 55, 21));
        ComboBoxKey = new QComboBox(groupBox_del);
        ComboBoxKey->setObjectName(QString::fromUtf8("ComboBoxKey"));
        ComboBoxKey->setGeometry(QRect(100, 30, 141, 22));
        Btn_delete_s = new QPushButton(groupBox_del);
        Btn_delete_s->setObjectName(QString::fromUtf8("Btn_delete_s"));
        Btn_delete_s->setGeometry(QRect(130, 90, 93, 28));

        horizontalLayout_2->addWidget(groupBox_del);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 999, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(openFile);
        menuFile->addSeparator();
        menuFile->addAction(openDirectory);
        menuFile->addSeparator();
        menuFile->addAction(addFile);
        menuFile->addSeparator();
        menuFile->addAction(saveFile);
        toolBar->addAction(openFile);
        toolBar->addSeparator();
        toolBar->addAction(openDirectory);
        toolBar->addSeparator();
        toolBar->addAction(addFile);
        toolBar->addSeparator();
        toolBar->addAction(saveFile);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        openFile->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
#ifndef QT_NO_TOOLTIP
        openFile->setToolTip(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
#endif // QT_NO_TOOLTIP
        openDirectory->setText(QApplication::translate("MainWindow", "\320\236\320\272\321\200\321\213\321\202\321\214 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\216", nullptr));
        addFile->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
#ifndef QT_NO_TOOLTIP
        addFile->setToolTip(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
#endif // QT_NO_TOOLTIP
        saveFile->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
#ifndef QT_NO_TOOLTIP
        saveFile->setToolTip(QApplication::translate("MainWindow", "\321\201\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Value", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Key", nullptr));
        label_sections->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        Btn_add_section->setText(QString());
        Btn_delete_section->setText(QString());
        groupBox_add->setTitle(QApplication::translate("MainWindow", "GroupBox", nullptr));
        label_type->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_key->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_value->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        btn_add_key->setText(QApplication::translate("MainWindow", "czcz", nullptr));
        groupBox_del->setTitle(QApplication::translate("MainWindow", "GroupBox", nullptr));
        label_k->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        Btn_delete_s->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

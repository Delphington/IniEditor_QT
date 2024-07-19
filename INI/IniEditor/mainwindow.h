#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QToolBar>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <string.h>
#include <QTreeWidgetItem>
#include <map>
#include <set>
#include <QInputDialog>
#include <QListWidget>

#include "IniFile.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    std:: set<std::string> AddingType {"int", "double", "bool", "string"};
    std::vector<string> TrueValues {"1", "true", "yes", "TRUE", "y", "YES"};
    std::vector<string> FalseValues {"0", "false", "no", "FALSE", "n", "NO"};


    void Set_Block(); // Функция блокирования, когда файл не выбран
    void Set_UnBlock(); // Функция разблокировки, когда файл выбран

    void set_initialization();          // Первоначальная инцилизация
    void set_clear();                   // Очищение всех полей
    void set_clear_pointer();           // Удаление указателя
    void UpdateInformationOfTree();     // Обнова всего дерева в случае изменения

    IniFile *IniF = nullptr;

   // int cntOpenFile = 0; //for clear point

    QValidator* intValid;
    QValidator* doubleValid;
    QValidator* boolValidator;


private slots:
    void on_openDirectory_triggered();
    void on_openFile_triggered();

    void on_listWidget_clicked(const QModelIndex &index);
    void on_Btn_add_section_clicked();
    void on_Btn_delete_section_clicked();
    void on_treeWidget_itemSelectionChanged();
    void on_btn_add_key_clicked();

    void on_Btn_delete_s_clicked();
    void on_ComboBoxType_currentTextChanged(const QString &arg1);
    void on_ComboBox_section_currentTextChanged(const QString &arg1);
    void on_saveFile_triggered();
    void on_addFile_triggered();
};
#endif // MAINWINDOW_H

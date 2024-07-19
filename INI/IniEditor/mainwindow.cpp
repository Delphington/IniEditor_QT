#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)  , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setWindowIcon(QIcon(":rec//img//stone.png"));


    intValid = new QIntValidator(this);
    doubleValid = new QDoubleValidator(this);

    QString RX;

    for (const auto &trueval : TrueValues){
        RX+=QString::fromStdString(trueval) + tr("|");
    }

    for (const auto &falseval : FalseValues){
        RX+=QString::fromStdString(falseval) + tr("|");
    }
    RX.chop(1);

    boolValidator = new QRegExpValidator(QRegExp(RX), this);

    set_initialization();
    Set_Block();

}

MainWindow::~MainWindow(){
    set_clear();
    //delete ui;
    if (IniF!=nullptr){
        delete IniF;
    }
}

//###################### SRC #################################

//начальная инцилизация
void MainWindow::set_initialization(){
    //horizontalLayout_1
    ui->label_sections->setText("Sections");

    //Groupe_box_add
    ui->groupBox_add->setTitle("Adding");
    ui->label_key->setText("Key");
    ui->label_type->setText("Type");
    ui->label_value->setText("Value");
    ui->btn_add_key->setText("Add");

    //Groupe_box_delete
    ui->groupBox_del->setTitle("Deleting");
    ui->label_k->setText("Key");
    ui->Btn_delete_s->setText("Delete");

    statusBar()->showMessage(("Opened files: " + std::to_string(ui->listWidget->count())).c_str());

    //заполняем ComboxType
    for (auto n : AddingType){
        ui->ComboBoxType->addItem(QString::fromStdString(n));
    }
}


void MainWindow:: Set_Block(){
    ui->Btn_add_section->setEnabled(false);
    ui->Btn_delete_section->setEnabled(false);

    ui->btn_add_key->setEnabled(false);
    ui->Btn_delete_s->setEnabled(false);

    ui->ComboBox_section->setEnabled(false);
    ui->ComboBoxKey->setEnabled(false);
    ui->ComboBoxType->setEnabled(false);

    ui->lineEdit_key->setEnabled(false);
    ui->lineEdit_value->setEnabled(false);
}


void MainWindow:: Set_UnBlock(){

    ui->Btn_add_section->setEnabled(true);
    ui->Btn_delete_section->setEnabled(true);

    ui->btn_add_key->setEnabled(true);
    ui->Btn_delete_s->setEnabled(true);

    ui->ComboBox_section->setEnabled(true);
    ui->ComboBoxKey->setEnabled(true);
    ui->ComboBoxType->setEnabled(true);

    ui->lineEdit_key->setEnabled(true);
    ui->lineEdit_value->setEnabled(true);
}


void MainWindow::set_clear(){
    ui->treeWidget->clear();
    ui->ComboBox_section->clear();
  //  ui->ComboBoxType->clear();
    ui->ComboBoxKey->clear();

    ui->lineEdit_key->clear();
    ui->lineEdit_value->clear();
}


void MainWindow:: set_clear_pointer(){
    if (IniF!= nullptr){
        delete IniF;
        IniF = nullptr;
    }
}

void MainWindow:: UpdateInformationOfTree() {
    Set_UnBlock();
    set_clear();

    std::set<std::string> nameSection;

    for (const auto &elem : IniF->getSections()) {
        if (!elem.first.empty()){
            QTreeWidgetItem *sections = new QTreeWidgetItem(ui->treeWidget);

            sections->setText(0, QString::fromStdString(elem.first));

            int n=0;  //Идентификатор для нахождения секции без ключей

            for (const auto &el : elem.second) {
                n++;
                QTreeWidgetItem *QTW = new QTreeWidgetItem(sections);
                QTW->setText(0, QString::fromStdString(el.first));   //ключ
                QTW->setText(1, QString::fromStdString(el.second)); //значение
                nameSection.insert(elem.first);
            }
            if (n==0){
                // Для добавление пустых секций(Только имя секции)
                nameSection.insert(elem.first);
            }
        }
    }

    // Заполнение Combox
    for (auto n : nameSection){
        ui->ComboBox_section->addItem(QString::fromStdString(n));
    }

    ui->treeWidget->expandAll();
}

//###################### SRC #################################



// Открытие папки (done)
void MainWindow::on_openDirectory_triggered(){

    QString Directory = QFileDialog::getExistingDirectory(this,
                            tr("Choose Directory"),"/home",
                            QFileDialog::DontResolveSymlinks);
    QDir dir(Directory);
    if(Directory.isEmpty()){}

    else if (dir.isEmpty()){
        //проверка, что директория может не содержать файлы
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("В этой директории нет файлов!");
        msgBox.exec();
    }else{

        QFileInfoList list = dir.entryInfoList();
        set<QString> temp; //для хранения путей для файлов
        set<QString>::iterator it;

        // Собираем информацию
        for (int i = 0; i < list.size(); i++) {
            QFileInfo fileInfo = list.at(i);
            if (!fileInfo.fileName().isEmpty() && (fileInfo.fileName().indexOf(".ini") != -1)) {
                temp.insert(fileInfo.path() + "/" + fileInfo.fileName());
                // Так нужно, чтобы не проиошло: одна директория открыта и ThreeWiget куча данных, потом
                //открываем  новую директорию listView чиститься, а директория нужная не открывается - потеря данных
            }
        }
        if (temp.empty()){
            // проверка, что директория может содержать файлы, но не .ini
            QMessageBox msgBox;
            msgBox.setWindowTitle("Warning");
            msgBox.setText("Директория не содержит файлов с расширением .ini!");
            msgBox.exec();
        }else{
            set_clear();
            ui->listWidget->clear();
            Set_Block();
            for (it = temp.begin(); it != temp.end(); it++) {
                ui->listWidget->addItem( *it);
            }
           // ui->listWidget->update();
        }

    }
    statusBar()->showMessage(("Opened files: " + std::to_string(ui->listWidget->count())).c_str());
}


void MainWindow::on_openFile_triggered(){
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"),QDir::currentPath(), tr("Files (*.ini);"));
    if (!filePath.isEmpty()){
        ui->listWidget->clear();
        set_clear_pointer();

        IniF = new IniFile(filePath.toStdString());
        if (IniF->getSectionsCount() ==1){
            IniF->deleteSection(""); // удаление пустоты,чтобы в theeWidget ее не было
        }

        ui->listWidget->addItem(filePath);
        Set_UnBlock();
        UpdateInformationOfTree();
    }
    statusBar()->showMessage(("Opened files: " + std::to_string(ui->listWidget->count())).c_str());
}


// тыкаем на listView
void MainWindow::on_listWidget_clicked(const QModelIndex &index){
     Set_UnBlock();
     QString texts = (ui->listWidget->selectedItems().last())->text();

     set_clear();
     set_clear_pointer();

     IniF = new IniFile(texts.toStdString());
     if (IniF->getSectionsCount() ==1){
         IniF->deleteSection(""); // удаление пустоты,чтобы в theeWidget ее не было
     }
     UpdateInformationOfTree();
}


void MainWindow::on_Btn_add_section_clicked(){
   bool ok; //Отвечающие за то что нажали ОК
   QString name_section = QInputDialog::getText(this, tr("Добавлениие секции"),
   tr("Введите название секции"), QLineEdit::Normal, QDir::home().dirName(), &ok);

   QString name_section_check_gap = name_section.trimmed();

   //Если секция состоит из пробелов
   if (name_section_check_gap.size() ==0 &&  ok && name_section.size()>0){
       QMessageBox msgBox;
       msgBox.setWindowTitle("Warning");
       msgBox.setText("Имя ключа не может быть состоять из пробелов!");
       msgBox.exec();
   }

   //Проверка на пустоту
  else if (ok && name_section_check_gap.isEmpty()){
      QMessageBox msgBox;
      msgBox.setWindowTitle("Warning");
      msgBox.setText("Секция пустая! Введите название еще раз!");
      msgBox.exec();
  }

   // Проверка что существует ли такая секция
   else if (ok && IniF->isSectionExist(name_section_check_gap.toStdString())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("Такая секция уже существует, введите другое название!");
        msgBox.exec();
   }else if (ok){
       IniF->addNewSection(name_section_check_gap.toStdString());

       // Обноваление Combox при добавление нового элеменат в дерево
       ui->ComboBox_section->addItem(name_section_check_gap);
       ui->ComboBox_section->update();

       UpdateInformationOfTree();
   }
}

// удаление секции
void MainWindow::on_Btn_delete_section_clicked(){
    QString name_section = ui->ComboBox_section->currentText();

    if (name_section.isEmpty()){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("Прежде чем удалить, создайте секцию!");
        msgBox.exec();
    }else{
        IniF->deleteSection(name_section.toStdString());
        UpdateInformationOfTree();
    }
}

//Меняет имя section при нажатие на дерево
void MainWindow::on_treeWidget_itemSelectionChanged(){
    // Меняем секции
    QTreeWidgetItem* temp = ui->treeWidget->currentItem();
    //Если колонка пустая то
    if (temp->text(1).isEmpty()) {
        ui->ComboBox_section->setCurrentText(temp->text(0));
    }
    else {
        // когда тыкаем на ключ секции меняется combox
        ui->ComboBox_section->setCurrentText(temp->parent()->text(0));
        ui->ComboBoxKey->setCurrentText(temp->text(0));
    }
}


// Название секции автоматические заполняет ComboBox с ключами выбранной секции
void MainWindow::on_ComboBox_section_currentTextChanged(const QString &arg1){
    ui->ComboBoxKey->clear();

    SectionsMap sectionInfo = IniF->getSections();

    set<string> nameKey;
      //Для заполнения ключей по изменению секции
    for (auto &element : sectionInfo[arg1.toStdString()]){
        nameKey.insert(element.first);
    }

    for (auto n : nameKey){
        ui->ComboBoxKey->addItem(QString::fromStdString(n));
    }
}

//Установка валидатора выбираем какой тип
void MainWindow::on_ComboBoxType_currentTextChanged(const QString &arg1){
 //   ui->lineEdit_key->clear();
    ui->lineEdit_value->clear();

    if (arg1 == "int") {
        ui->lineEdit_value->setValidator(intValid);
    }
    else if (arg1 == "double") {
        ui->lineEdit_value->setValidator(doubleValid);
    }
    else if (arg1 == "bool") {
        ui->lineEdit_value->setValidator(boolValidator);
    }
    else {
        ui->lineEdit_value->setValidator(0);
    }
}

// Добавление нового ключа
void MainWindow::on_btn_add_key_clicked(){

    QString name_section = ui->ComboBox_section->currentText();
    QString name_type_value = ui->ComboBoxType->currentText();
    QString name_key = ui->lineEdit_key->text();
    QString name_value = ui->lineEdit_value->text();

    QString name_key_chack_gap = name_key.trimmed();
    QString name_value_check_gap = name_value.trimmed();

    // Проверка на то, что если пользователь захочет ввести данные без секции
    if (name_section.isEmpty()){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("Выберите секции или создайте!");
        msgBox.exec();
    }else if (name_key.isEmpty()){
        // попросим ввести имя ключа, если там пусто
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("Введите ключ!");
        msgBox.exec();

    }else if (name_key_chack_gap.size() ==0){
        // Если ключ из пробелов(вроде qt автоматические это чекает)
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("Введите ключ!");
        msgBox.exec();

    } else {
        // Работаем если все в порядке
        if (name_type_value =="int"){
             IniF->writeInt(name_section.toStdString(), name_key_chack_gap.toStdString(),  name_value.toInt());

        }else if (name_type_value =="double"){
            string str = name_value.toStdString();
            replace(str.begin(), str.end(), ',', '.'); //Гениальный Qt

            IniF->writeDouble(name_section.toStdString(), name_key_chack_gap.toStdString(), stod(str));

        }else if(name_type_value =="string"){
           IniF->writeString(name_section.toStdString(), name_key_chack_gap.toStdString(),  name_value.toStdString());

        }else{ //for bool
            bool x = false;
            for (const auto str : TrueValues){
                if (str == name_value.toStdString()){
                    x = true;
                    IniF->writeBool(name_section.toStdString(), name_key_chack_gap.toStdString(), true);
                }
            }
            if (x == false){
                IniF->writeBool(name_section.toStdString(), name_key_chack_gap.toStdString(), false);
            }
        }
        UpdateInformationOfTree();
    }
}

//удаление ключей
void MainWindow::on_Btn_delete_s_clicked(){
  QString name_section = ui->ComboBox_section->currentText();
  QString name_key = ui->ComboBoxKey->currentText();

  if (name_key.isEmpty()){
      // Если вдруг в Combox не останется элементов
      QMessageBox msgBox;
      msgBox.setWindowTitle("Warning");
      msgBox.setText("Нет доступного ключа для удаления!");
      msgBox.exec();
  }else{
      IniF->deleteKey(name_section.toStdString(), name_key.toStdString());
      UpdateInformationOfTree();
    }
}


void MainWindow::on_saveFile_triggered(){
    if (IniF == nullptr){
        //Случай когда просто открываю директории
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("Ни какой файл не открыт");
        msgBox.exec();
    }else {
        try{
            IniF->save();
        }catch(const char * str){
          qDebug(str);
        }
    }
}

// Добавление файла
void MainWindow::on_addFile_triggered(){
    QString file_name = QFileDialog::getSaveFileName(this, tr("Сохранить файл"),
                     "/home/untitled.ini", tr("*.ini"));
    if (!file_name.isEmpty()){
        set_clear();

       ui->listWidget->addItem(file_name);
       set_clear_pointer();

        IniF = new IniFile(file_name.toStdString());
        if (IniF->getSectionsCount() ==1){
            IniF->deleteSection(""); // удаление пустоты,чтобы в theeWidget ее не было
        }

        Set_UnBlock();
        UpdateInformationOfTree();
    }
    statusBar()->showMessage(("Opened files: " + std::to_string(ui->listWidget->count())).c_str());
}

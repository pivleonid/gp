#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include <activeexcel.h>
#include "activeword.h"
#include <qmessagebox.h>
#include <windows.h>
#include <QTextCodec>
#include <QSettings>


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->openFile,SIGNAL(clicked(bool)),this,SLOT(openFile()));
  connect(ui->docGen,SIGNAL(clicked(bool)), this, SLOT(generate()));



  ui->textEdit->setVisible(false);
  connect(ui->action_2,SIGNAL(triggered(bool)), this, SLOT(openAbout()));


  QFile file("gp.conf");
  if(file.size() == 0)
    return;
  QSettings settings( "gp.conf", QSettings::IniFormat );
  settings.beginGroup( "LableName" );
  QVariant text = settings.value("Razrab");
  ui->razrab->setText( text.toString());
  text = settings.value("Prov");
  ui->prov->setText( text.toString());
  text = settings.value("Kontr");
  ui->kontr->setText( text.toString());
  text = settings.value("Ytb");
  ui->ytb->setText( text.toString());
  text = settings.value("Firma");
  ui->Firma->setText( text.toString());
  text = settings.value("nymerIzd");
  ui->nymerIzd->setText( text.toString());
  text = settings.value("naim1");
  ui->naim1->setText( text.toString());
  text = settings.value("naim2");
  ui->naim2->setText( text.toString());
  text = settings.value("maxSymbol");
  ui->maxSymbol->setText( text.toString());
  settings.endGroup();



}




MainWindow::~MainWindow()
{
    QSettings settings( "gp.conf", QSettings::IniFormat );
       settings.beginGroup( "LableName" );
       settings.setValue( "Razrab", ui->razrab->text() );
       settings.setValue( "Prov", ui->prov->text() );
       settings.setValue( "Kontr", ui->kontr->text() );
       settings.setValue( "Ytb", ui->ytb->text() );
       settings.setValue( "Firma", ui->Firma->text() );
       settings.setValue( "nymerIzd", ui->nymerIzd->text() );
       settings.setValue( "naim1", ui->naim1->text() );
       settings.setValue( "naim2", ui->naim2->text() );
       settings.setValue( "maxSymbol", ui->maxSymbol->text() );
       settings.endGroup();

  delete ui;
}



void MainWindow::openFile(){
  ui->openFile->setEnabled(false);
  ui->textEdit->clear();
  ui->textEdit->setVisible(false);
  ActiveWord word;
  if(!word.wordConnect()){
      ui->openFile->setEnabled(true);
      QMessageBox msgBox;
      msgBox.setText("Word не установлен");
      msgBox.exec();
      return;
    }
 QString path = QApplication::applicationDirPath() + "/PEZ.docx";

  //QString path = "D:/projects/gp/PEZ.docx";
  QAxObject* doc1 = word.documentOpen(path);
  if(doc1 == NULL){
      QMessageBox msgBox;
        msgBox.setText("Не найден word- шаблон");
        msgBox.exec();
        ui->openFile->setEnabled(true);
    return;
    }

  QString fileName_DATA = QFileDialog::getOpenFileName(this, tr("Open Excel File"),"", tr("(*.xlsx *.xls)"));
  if(fileName_DATA == ""){
      //если в диалоговом окне нажали на "отмена"
      ui->openFile->setEnabled(true);
      return;
    }

  ActiveExcel excel;
  if(!excel.excelConnect()){
      QMessageBox msgBox;
        msgBox.setText("Не установлен Excel");
        msgBox.exec();
      ui->openFile->setEnabled(true);
      return;
    }

  QAxObject* ex1 = excel.documentOpen(QVariant(fileName_DATA));
  //QAxObject* ex1 = excel.documentOpen("D:/projects/gp/PHASE_FPGA_MAIN_01_REFDES.xlsx");

  if(ex1 == NULL){
      QMessageBox msgBox;
        msgBox.setText("Невозможно открыть книгу");
        msgBox.exec();
      ui->openFile->setEnabled(true);
    return;
    }

  QCoreApplication::processEvents(); // обновление GUI

  QVariant name = excel.sheetName();
  QAxObject* sheet = excel.documentSheetActive(name);



  QStringList var;
  QVariant data;
  // 20 секунд на чтение

  ui->progressBar_2->setValue(0);
  ///ЧТЕНИЕ ДАННЫХ!!!
  for(int i = 2; i < 300 ; i++){
      if (excel.sheetCellInsert(sheet, data, i, 2))
        var << data.toString();
      else{
          QMessageBox msgBox;
          mesOut("Ошибка обработки данных!");
          ui->openFile->setEnabled(true);
          return;
        }
      if (excel.sheetCellInsert(sheet, data, i, 3))
        var << data.toString();
      else{
          mesOut("Ошибка обработки данных!");
          ui->openFile->setEnabled(true);
          return;
        }
      if (excel.sheetCellInsert(sheet, data, i, 4))
        var << data.toString();
      else{
          mesOut("Ошибка обработки данных!");
          ui->openFile->setEnabled(true);
          return;
        }
      if (excel.sheetCellInsert(sheet, data, i, 5))
        var << data.toString();
      else{
          mesOut("Ошибка обработки данных!");
          ui->openFile->setEnabled(true);
          return;
        }
      if (excel.sheetCellInsert(sheet, data, i, 6))
        var << data.toString();
      else{
          mesOut("Ошибка обработки данных!");
          ui->openFile->setEnabled(true);
          return;
        }
      int g = var.count();
      if(var[g-1] == "" && var[g-2] == "" && var[g-3] == "")
       break;

      if(i == 500){
          ui->progressBar_2->setValue(20);
          QCoreApplication::processEvents();
        }

      if(i == 1000){
          ui->progressBar_2->setValue(40);
          QCoreApplication::processEvents();
        }
    }
 excel.documentClose(ex1);


desValue.clear();
desValue = transform( var);
QStringList errorRefDez = deviceandSpace_v2(desValue);
if (!errorRefDez.isEmpty()){
    ui->textEdit->setVisible(true);
    ui->textEdit->setTextColor(Qt::red);
    ui->textEdit->insertPlainText("Элементы со следующими RefDez отображены в разделе \"Прочие\":");
    ui->textEdit->setTextColor(Qt::black);
    foreach (auto var, errorRefDez) {
        ui->textEdit->insertPlainText("\n" + var);

    }
}
ui->progressBar_2->setValue(50);


//заполнение таблицы
QStringList listLabel = word.tableGetLabels(1, 2);
ui->progressBar_2->setValue(70);
QCoreApplication::processEvents();
if (word.tableFill(desValue,listLabel,1,2) < 0){
    mesOut("Ошибка заполнения таблицы!");
    ui->openFile->setEnabled(true);
    word.setVisible();
    return;
  }

ui->progressBar_2->setValue(90);
QCoreApplication::processEvents();


if( word.colontitulReplaseLabel(doc1, "[Разраб]", ui->razrab->text(), true) < 0)
  mesOut("Ошибка замены метки");
if( word.colontitulReplaseLabel(doc1, "[пров]", ui->prov->text(), true) < 0)
  mesOut("Ошибка замены метки");
if( word.colontitulReplaseLabel(doc1, "[Наим.1]", ui->naim1->text(), true) < 0)
  mesOut("Ошибка замены метки");
if( word.colontitulReplaseLabel(doc1, "[конт]", ui->kontr->text(), true) < 0)
  mesOut("Ошибка замены метки");
if( word.colontitulReplaseLabel(doc1, "[утв]", ui->ytb->text(), true) < 0)
  mesOut("Ошибка замены метки");
if( word.colontitulReplaseLabel(doc1, "[Дец.Номер изд.]", ui->nymerIzd->text(), true) < 0)
  mesOut("Ошибка замены метки");
if( word.colontitulReplaseLabel(doc1, "[Дец.Номер изд.]", ui->nymerIzd->text(), false) < 0)
  mesOut("Ошибка замены метки");
if( word.colontitulReplaseLabel(doc1, "[Наим.2]", ui->naim2->text(), true) < 0)
  mesOut("Ошибка замены метки");
if( word.colontitulReplaseLabel(doc1, "[Фирма]", ui->Firma->text(), true) < 0)
  mesOut("Ошибка замены метки");

// поиск элементов, добавка курсива и расположение по центру
foreach (QString var, strListNamelabel) {
    //подчеркивание
    if (word.selectionFindFontname(var, true, false, true, true, "GOST type B") < 0){
       // mesOut("Ошибка шрифта!" + var);
      //  continue;
      //  return;
      }
    //центрирование
    if( word.selectionAlign(var , false, false, true) < 0){
       // mesOut("Ошибка центрирования!" + var);
      //  continue;
      //  return;
      }
    QString s = var;
    s.remove(0,1);
    s.remove(s.count()-1,1);
    QString s1 = var;
    // замена меток/
    if (word.findReplaseLabel(s1, s, true) == false){
        //mesOut("Ошибка замены метки!" + var);
     //   continue;
      //  return;
      }
    s.clear();
    s1.clear();
  }


word.tableSizeRowsHight(1, 2, 25, 0.86);

word.setVisible();
ui->progressBar_2->setValue(100);
ui->openFile->setEnabled(true);
ui->docGen->setEnabled(true);

}




//-----------------------------------------------------------

QList<QStringList> MainWindow::transform(QStringList var){

    QStringList var1;
    QList<QStringList> varList;
    QString prem;
    int count = 0;
    //формирую QList, где [0] - это refdez, а [1] part number + description + value + manufactur
    for(int j = 0; j < var.count(); j++){
        if(count < 5){
            if(count == 4){
                prem = prem +" "+ var.at(j);
                prem.replace(",","");
                var1.append(prem);
                count++;
                continue;
            }
            //2 3
            if(count ==3 ){
                prem = prem + " " + var.at(j);
                count++;
                continue;

            }
            if(count == 2){
                prem = prem + " " + var.at(j);
                count++;
                continue;

            }
            if(count == 1){
                prem += var.at(j);
                count++;
                continue;

            }
            //первый влет
            if(count == 0){
                var1.append(var.at(j));
                count++;
                continue;
            }

        }
        varList.append(var1);
        var1.clear();
        prem.clear();
        count = 0;
        j--;
    }
    var.clear();
    prem.clear();
    ///varList содержит по два элемента- 1 название 2 описание

    //--начало формирования Всех префиксов
   allPrefix.clear();
        foreach (auto var, varList) {
            allPrefix << var.at(0);
        }
        for (QStringList::iterator var = allPrefix.begin(); var < allPrefix.end(); var++) {
            (*var).remove(QRegExp("[^A-Za-zА-Яа-я]"));
        }
        //Удаляю дубликаты
        for (QStringList::iterator var = allPrefix.begin(); var < allPrefix.end() -1;var++) {
            if(*var == *(var+1) ){
                var = allPrefix.erase(var );
                if(var != allPrefix.begin())
                    var--;
            }
        }
        //--Конец формирования Всех префиксов
//--Формирование QMap
        QMap<QString, QList<QStringList> > mapVarLisr;
        foreach (auto var, allPrefix) {
            foreach (auto var1, varList) {
                QString name = var1.at(0);
                name = name.remove(QRegExp("[^A-Za-zА-Яа-я]"));
                QString number = var1.at(0);
                number = number.remove(QRegExp("[A-Za-zА-Яа-я]"));
                 QString detaSheet = var1.at(1);
                 QStringList dataPre;
                 dataPre<< number << detaSheet;
//                QList<int, QString> qVarList;
//                qVarList << number.toInt() << var1.at(1);
                if( var == name)
                    mapVarLisr[var] << dataPre;
            }
        }
       // allPrefix.clear();
//mapVarLisr по каждому ключу хранится QStringList
        QMap<QString, QList<QStringList>> bz;
        foreach (QString key, mapVarLisr.keys()) {
            bz[key];
       }

        foreach (QString key, mapVarLisr.keys()) {
            foreach (QString key1, bz.keys()) {
                if( key == key1){
                    QList<QStringList> a;
                    a = mapVarLisr[key];
                    for (QList<QStringList>::iterator a_it = a.begin(); a_it < a.end(); a_it++) {
                        if(a_it == a.begin()){
                         //   *a_it << QString::number(1);
                            bz[key] << *a_it;
                            continue;
                        }
                        //если описание эл-та == описанию предыдущего
                        if( (*a_it).at(1) == (*(a_it-1)).at(1)){
                      //      int num = (*(a_it-1)).at(2).toInt();
                       //     num++;
                       //     bz[key][bz[key].size()-1][2].clear();
                            bz[key][bz[key].size()-1][0] += "-"+(*a_it).at(0);
                       //     bz[key][bz[key].size()-1][2].append(QString::number(num));
                            continue;
                        }
                        //ежели не равно
                    //    *a_it << QString::number(1);
                        bz[key] << *a_it;

                    }
                }
            }
        }
//В bz["C"][3][0] = "6-7-8-9-10"; bz["C"][3][1] = "GRM115"
QList<QStringList> outData;
        foreach (QString key, bz.keys()) {
            QList<QStringList> b;
            b = bz[key];
            //b содержит все элементы по ключу
            foreach (auto vB, b) {
                //vB это QStringList, [0] = "6-7-8-9-10"; [1] = "GRM115"
                QStringList stringSplit = vB[0].split("-");
                int numb = stringSplit.count();
                for(QStringList::iterator vS = stringSplit.begin(); vS < stringSplit.end(); vS++){
                    if(vS == stringSplit.begin())
                        continue;
                    if(vS == stringSplit.end()-1)
                        continue;
                    //Очищаю промежутки
                    vS = stringSplit.erase(vS);
                    vS--;
                }
                //stringSplit содержит первый и последний эл-т
                //добавляю символ "-"
                for(QStringList::iterator vS = stringSplit.begin(); vS < stringSplit.end() - 1; vS++){
                    if( (*(vS + 1)).toInt() - (*vS).toInt() == 1 ){
                       (*vS).append(", ");
                        continue;
                    }
                    (*vS).append("...");

                }
                //добавляю ключ префикс
                for(QStringList::iterator vS = stringSplit.begin(); vS < stringSplit.end() ; vS++){
                    (*vS).prepend(key);
                }
                //Объединить в одну ячейку
                //добавить vB[1] - описание
                QString unionStr;
                 QStringList out;
                int cont = stringSplit.count();
                if(cont == 1){
                    unionStr = stringSplit[0];
                    out << unionStr << vB[1] << QString::number(numb);
                }
                if(cont == 2){
                    unionStr = stringSplit[0] + stringSplit[1];
                out << unionStr << vB[1] << QString::number(numb);
                }
                outData << out;
                out.clear();
                int i= 0;
                i++;
            }

        }
        return outData;

}

//------------------------------------------------------------------------

QStringList MainWindow::deviceandSpace_v2(QList<QStringList>& varList){



    //----------------------------------------

    QString  str;
    QFile file("Названия групп.txt");
    QTextCodec *codec = QTextCodec::codecForName("CP1251");
    if(file.open(QIODevice::ReadOnly |QIODevice::Text)){
        while (!file.atEnd()){
            QByteArray line = file.readLine();
            QTextCodec *codec = QTextCodec::codecForName("CP1251");
            str += codec->toUnicode(line);
        }
    }
    else qDebug()<< "don't open file";
    QStringList splitStr = str.split("\n");
    QMap<QString, QString> tem;
    foreach (auto st, splitStr) {
        QStringList split = st.split("-");
        tem[split[0]] = split[1];
        strListNamelabel << split[1];
    }
    QStringList allPrefixRename = allPrefix;
    QStringList var_space, allPrefixRenameOut;
    var_space << "" << "" << "";
    for(QList<QStringList>::iterator it = varList.begin(); it < varList.end(); it++){
        QString var = (*it).at(0);
        //поиск префикса: удялю символы после "," и "."
        int ind2 = var.indexOf(".");
        if(ind2 > 0)
            var.remove(ind2, var.count());
        int ind3 = var.indexOf(",");
        if(ind3 > 0)
            var.remove(ind3, var.count());
         var.remove(QRegExp("[^A-Za-zА-Яа-я]"));
        //тут var == только префикс
         int ind1 = allPrefixRename.indexOf(var);
         if( ind1 >= 0){
             allPrefixRename.removeAt(ind1);
             it = varList.insert(it ,var_space);
             QStringList var1;
             //Если префикса нет в "Названиях групп"- вставить "прочие"
             if(tem[var] == ""){
                 tem[var] = "[Прочие]";
                 allPrefixRenameOut << var;
             }
             var1 << "" << tem[var] << "";
             it = varList.insert(++it ,var1);
           }

      }
    allPrefixRename.clear();
    strListNamelabel << "[Прочие]";



   //-------------------------------------------------------------
    //Перенос строки с описанием
    for(QList<QStringList>::iterator it = varList.begin(); it < varList.end(); it++){
        QString str0 = (*it).at(0);
        QString str1 = (*it).at(1);
        QString str2 = (*it).at(2);
        //сколько символов в строке word
         symbolsInTable = ui->maxSymbol->text().toInt();
         if(symbolsInTable < 30)
             symbolsInTable = 30;
         if(symbolsInTable > 40)
             symbolsInTable = 40;
        if(str1 == ""  || (str1.count() < symbolsInTable))
            continue;
        QStringList varLi;
        //дроблю строку на пробелы
        varLi = str1.split(" ");
        QString out1, out2, out3;
        //соединяю до 32 символа
        foreach (auto var, varLi) {
            if(out2.count() + var.count() > symbolsInTable){
                out3 += " "+var;
                continue;
            }
            if(out1.count() + var.count() > symbolsInTable){
                out2 += " "+var;
                continue;
            }

            out1 += " "+var;
        }
        QStringList varLiSpace1, varLiSpace2, varLiSpace3;
        if(!out1.isEmpty())
            varLiSpace1 << str0 << out1 << str2;
        if(!out2.isEmpty())
            varLiSpace2 << "" << out2 << "";
        if(!out3.isEmpty())
            varLiSpace3 << "" << out3 << "";

        it = varList.erase(it);
        it--;
        //не забыть про удаление эл-та
         if(!varLiSpace1.isEmpty())
            it = varList.insert(it+1, varLiSpace1);
         if(!varLiSpace2.isEmpty())
            it = varList.insert(it+1, varLiSpace2);
         if(!varLiSpace3.isEmpty())
            it = varList.insert(it+1, varLiSpace3);
        int k =0;
        k++;
    }
    //расставляю пробельные строки, согласно желанию шаркова

    int count = varList.count();
    if(count < 26) //24 последняя строка первого листа
         return allPrefixRenameOut;
    for(int i = 25; i < varList.count(); i = i + 30 ){
        QString s = varList[i][0];
        if(s == ""){
            varList.insert(--i, var_space);
            varList.insert(i, var_space);
            i++;
            continue;
        }
        varList.insert(i, var_space);
    }
    //Заполняю документ пустой таблицей до конца
    count = varList.count();
    double z = floor((count - 26)/30);
    int x = count - ( 26 + z * 30);
    int lineAdd = 30 - x;
    for (int i = 0; i < lineAdd; i++)
        varList.append(var_space);

    // надо заполнить поле "Примечание" -  импорт
    QList<QStringList> import;
    QStringList importList;
    foreach (auto var, varList) {
        if( var.at(0) == ""){
            importList << var.at(0) << var.at(1) << var.at(2) << "";
            import.append(importList);
        }
        else{
            importList << var.at(0) << var.at(1) << var.at(2) << "Импорт";
            import.append(importList);
        }

        importList.clear();
    }
    varList.clear();
    varList = import;
    return allPrefixRenameOut;

}




void MainWindow::mesOut(QString mes){
       QMessageBox msgBox;
          msgBox.setText(mes);
          msgBox.exec();

}



//функция будет генерить файлы в excel/ word
void MainWindow::generate(){

  ui->progressBar_2->setValue(0);
  QCoreApplication::processEvents();
  ActiveWord word;
  QString path = QApplication::applicationDirPath() + "/PEZ.docx";
  QAxObject* doc1 = word.documentOpen(path);
  if(doc1 == NULL){
      QMessageBox msgBox;
      msgBox.setText("Не найден шаблон");
      msgBox.exec();
      ui->openFile->setEnabled(true);
      return;
    }
  //заполнение таблицы
  QStringList listLabel = word.tableGetLabels(1, 2);
  ui->progressBar_2->setValue(40);
  QCoreApplication::processEvents();
  if (word.tableFill(desValue,listLabel,1,2) < 0){
      mesOut("Ошибка заполнения таблицы!");
      ui->openFile->setEnabled(true);
      word.setVisible();
      return;
    }

  ui->progressBar_2->setValue(90);
  QCoreApplication::processEvents();

//
  if( word.colontitulReplaseLabel(doc1, "[Разраб]", ui->razrab->text(), true) < 0)
    mesOut("Ошибка замены метки");
  if( word.colontitulReplaseLabel(doc1, "[пров]", ui->prov->text(), true) < 0)
    mesOut("Ошибка замены метки");
  if( word.colontitulReplaseLabel(doc1, "[Наим.1]", ui->naim1->text(), true) < 0)
    mesOut("Ошибка замены метки");
  if( word.colontitulReplaseLabel(doc1, "[конт]", ui->kontr->text(), true) < 0)
    mesOut("Ошибка замены метки");
  if( word.colontitulReplaseLabel(doc1, "[утв]", ui->ytb->text(), true) < 0)
    mesOut("Ошибка замены метки");
  if( word.colontitulReplaseLabel(doc1, "[Дец.Номер изд.]", ui->nymerIzd->text(), true) < 0)
    mesOut("Ошибка замены метки");
  if( word.colontitulReplaseLabel(doc1, "[Дец.Номер изд.]", ui->nymerIzd->text(), false) < 0)
    mesOut("Ошибка замены метки");
  if( word.colontitulReplaseLabel(doc1, "[Наим.2]", ui->naim2->text(), true) < 0)
    mesOut("Ошибка замены метки");
  if( word.colontitulReplaseLabel(doc1, "[Фирма]", ui->Firma->text(), true) < 0)
    mesOut("Ошибка замены метки");

  // поиск элементов, добавка курсива и расположение по центру
  foreach (QString var, strListNamelabel) {
      //подчеркивание
      if (word.selectionFindFontname(var, true, false, true, true, "GOST type B") < 0){
         // mesOut("Ошибка шрифта!" + var);
        //  continue;
        //  return;
        }
      //центрирование
      if( word.selectionAlign(var , false, false, true) < 0){
         // mesOut("Ошибка центрирования!" + var);
        //  continue;
        //  return;
        }
      QString s = var;
      s.remove(0,1);
      s.remove(s.count()-1,1);
      QString s1 = var;
      // замена меток/
      if (word.findReplaseLabel(s1, s, true) == false){
          //mesOut("Ошибка замены метки!" + var);
       //   continue;
        //  return;
        }
      s.clear();
      s1.clear();
    }



    word.tableSizeRowsHight(1, 2, 25, 0.86);

  word.setVisible();
  ui->progressBar_2->setValue(100);
  ui->openFile->setEnabled(true);
}


void MainWindow::openAbout(){
  ActiveWord word;
  if(!word.wordConnect()){
      ui->openFile->setEnabled(true);
      QMessageBox msgBox;
      msgBox.setText("Word не установлен");
      msgBox.exec();
      return;
    }
 QString path = QApplication::applicationDirPath() + "/Описание.docx";

  //QString path = "D:/projects/gp/PEZ.docx";
  QAxObject* doc1 = word.documentOpen(path);
  if(doc1 == NULL){
      QMessageBox msgBox;
        msgBox.setText("Описание не найдено");
        msgBox.exec();
        word.setVisible();
    return;
    }
   word.setVisible();
}

//---------------------------------------------------------

///
//    foreach (QString key, mapVarLisr.keys()) {
//    QList<QStringList> a, b;
//     a = mapVarLisr[key];
//        for (QList<QStringList>::iterator a_it = a.begin(); a_it < a.end(); a_it++) {
//            if(a_it == a.begin()){
//                b << *a_it;
//                continue;
//            }
//            //если описание эл-та == описанию предыдущего
//            if( (*a_it).at(1) == (*(a_it-1)).at(1)){
//                b[b.size()-1][0] += "-"+(*a_it).at(0);
//                continue;
//            }
//            //ежели не равно
//            b << *a_it;
//            int i = 0;
//            i++;

//        }
//       int i = 0;
//       i++;
//}


//    // расслойка
//    QList<QStringList>::iterator z;
//    QStringList desValue1;
//    QList<QStringList> desValue;
//    desValue.clear();
//    //for ( w = varList.begin();w < varList.end();  w++) {
//    foreach (auto var, varList) {


//        // QString designator = (*w).at(1);
//        QString designator = var.at(1);

//        for ( z = varList.begin();z < varList.end(); z++) {
//            if(designator == (*z).at(1)){
//                desValue1 << (*z).at(0);
//                varList.erase(z);
//            }
//        }
//        if(desValue1.isEmpty())
//            continue;
//        desValue1.append(designator);
//        desValue << desValue1;
//        desValue1.clear();

//    }
//    QList<QStringList>::iterator des;
//    for ( des = desValue.begin(); des < desValue.end(); des++) {

//        int cont = (*des).count();
//        (*des).append(QString::number(cont - 1));
//    }
//    //desValue [0] перечисление c1 c2 ... [1] описание компонента [3] количество одинаковых элементов
//    deviceUpdate(desValue);
//    return desValue;

//    QList<QString> vectorString;
//    QList<QString>::iterator vS;
//    QList<QStringList>::iterator var2;
//    for (var2 = desValue.begin(); var2 < desValue.end(); var2++) {
//        int jk = (*var2).count();
//        //в этой ячейке храниться количество элементов
//        QString sttt = (*var2).at(jk-1);
//        //
//        allPrefix << (*var2).at(0);

//        if(sttt.toInt() > 2){
//            //Сохраняю первый символ!
//            QString prefix = (*var2).at(0);
//            prefix.remove(QRegExp("[^A-Za-zА-Яа-я]"));
//            //j = кол-во эл-тов, j-1 - описание элементов
//            //убираю префиксы
//            for(int i = 0; i < sttt.toInt(); i++){
//                QString perem =  (*var2).at(i);
//                QString symbol = perem.remove(QRegExp("[A-Za-zА-Яа-я]"));
//                vectorString << symbol;
//                //Расстановка "-" символов межи последующими числами
//                if(i > 0){
//                    vS = vectorString.end()-1;
//                    int aEnd = (*vS).toInt();
//                    vS--;
//                    int aPrepend = (*vS).toInt();
//                    //если предыдущее значение равно текущему- вставить между ними "-"
//                    if( aEnd - 1 == aPrepend ){
//                        vS = vectorString.insert(vectorString.end()-1, "-");

//                    }
//                }
//                //vectorString заполнен!
//                if( i == sttt.toInt() - 1){
//                    //Убрать числа, слева и справа от которых стоит "-"
//                    for(vS = vectorString.begin(); vS < vectorString.end(); vS++){
//                        if(vS == vectorString.end()-2)
//                            continue;
//                        if( (*vS == "-") &&( *(vS+2) == "-") ){
//                            //удаляю два элемента, возвращаюсь на предыдущий
//                            vS=vectorString.erase(vS);
//                            vS=vectorString.erase(vS);
//                            vS = vS-1;
//                        }
//                    }
//                    //поставить  запятую
//                    for(vS = vectorString.begin(); vS < vectorString.end(); vS++){
//                        QString vss = *(vectorString.end()-1); //на 5 эл-те badalloc //3 прогон
//                        QString vss1 = *vS;
//                        if(vS == vectorString.end()-1)
//                            continue;
//                        if( ( (*vS) != "-")  && ( (*(vS+1) ) != "-")  )
//                            vS = vectorString.insert(vS+1, ",");

//                    }
//                    //добавляю \n
//                    for(vS = vectorString.begin(); vS < vectorString.end() - 5; vS++){
//                        if( ( (*vS) == "," )  && ( (*(vS+2) ) == "," )  ){

//                            vS = vectorString.insert(vS+1," ");
//                            vS = vectorString.insert(vS+3,"\n");
//                            vS = vS + 1;
//                            continue;
//                        }
//                        if( ( (*vS) == "-" )  && ( (*(vS+2) ) == "-" ) ){


//                            vS = vectorString.insert(vS+1,"\n");

//                            vS = vS+1;
//                            continue;
//                        }
//                        if( ( (*vS) == "," )  && ( (*(vS+2) ) == "-" )  ){


//                            vS = vectorString.insert(vS+1,"\n");

//                            vS = vS + 1;
//                            continue;
//                        }
//                        if( ( (*vS) == "-" )  && ( (*(vS+2) ) == "," )  ){

//                            vS = vectorString.insert(vS+3,"\n");

//                            vS = vS + 1;
//                            continue;
//                        }

//                    }

//                    //поставить  префикс
//                    for(vS = vectorString.begin(); vS < vectorString.end(); vS++){
//                        QString vss1 = *vS;
//                        if( ((*vS) != "-")&& ((*vS) != ",") && ((*vS) != "\n") && ((*vS) != " ")){
//                            (*vS).prepend(prefix);
//                            vss1 = *vS;
//                            int i= 0;
//                            i++;
//                        }

//                    }
//                    //тут надо удалить лишние элементы, вставив значение vectorString
//                    int varDel = sttt.toInt() - 1;
//                    for(int i = 0; i < varDel+1; i++)
//                        (*var2).removeFirst();
//                    QString vec;
//                    foreach (auto ver, vectorString) {
//                        vec += ver;
//                    }
//                    (*var2).prepend(vec);
//                    vectorString.clear();
//                    vec.clear();
//                }
//            }
//        }
//        //ежели хранится два элемента
//        if(sttt.toInt() == 2){
//            (*var2).insert(1,", ");
//            int count = (*var2).count();
//            QString vec;
//            for( int i = 0; i < count - 2; i++){
//                vec +=(*var2)[i];
//            }
//            (*var2).removeFirst();
//            (*var2).removeFirst();
//            (*var2).removeFirst();
//            (*var2).prepend(vec);
//            vec.clear();

//        }
//    }
//    for (QStringList::iterator var = allPrefix.begin(); var < allPrefix.end(); var++) {
//        (*var).remove(QRegExp("[^A-Za-zА-Яа-я]"));
//    }
//    //Удаляю дубликаты
//    for (QStringList::iterator var = allPrefix.begin(); var < allPrefix.end() -1;var++) {
//        if(*var == *(var+1) ){
//            var = allPrefix.erase(var );
//            if(var != allPrefix.begin())
//                var--;
//        }

//    }
//    return desValue;



//void MainWindow::deviceUpdate(QList<QStringList>& varList){
//    //Создаю дубликат для работы
//    QList<QStringList> dataIn =  varList;
//    QStringList allPrefix;
////--начало формирования Всех префиксов
//    foreach (auto var, varList) {
//        allPrefix << var.at(0);
//    }
//    for (QStringList::iterator var = allPrefix.begin(); var < allPrefix.end(); var++) {
//        (*var).remove(QRegExp("[^A-Za-zА-Яа-я]"));
//    }
//    //Удаляю дубликаты
//    for (QStringList::iterator var = allPrefix.begin(); var < allPrefix.end() -1;var++) {
//        if(*var == *(var+1) ){
//            var = allPrefix.erase(var );
//            if(var != allPrefix.begin())
//                var--;
//        }
//    }
//    //--Конец формирования Всех префиксов
//    //--Формирование QMap
//    QMap<QString, QList<QStringList> > dataMap;
//    foreach (auto var, allPrefix) {
//        foreach (auto var1, dataIn) {
//            QString name = var1.at(0).at(0);
//            name = name.remove(QRegExp("[^A-Za-zА-Яа-я]"));
//            if( var == name)
//                dataMap[var] << var1;
//        }
//    }
//    // dataMap key: "C" value: dataIn с префиксом "С"

//    foreach (QString key, dataMap.keys())
//    {//w- это QList<QStringList> по ключю
//      for( auto w = dataMap[key].begin(); w < dataMap[key].end(); w++){
//          //беру последний эл-т, чтобы понять сколько однотипных
//          //эл-тов содаржит контейнер
//          int k = (*w).count();//кол-во эл-тов
//          k = (*w).at(k-1).toInt();// если от нуля, то -1 вписать
//          //теперь у каждого эл-та убираю префикс
//          for(int i = 0; i < k  ; i++){

//            QString  a=  (*w).at(i);
//             a = a.remove(QRegExp("[A-Za-zА-Яа-я]"));

//             (*w).removeAt(i);
//             (*w).insert(i, a);
//          }
//      }
//    }
//    // dataMap key: "C" value: dataIn без префикса "С"
//    QMap<QString, int> allPrefixCount;
//    foreach (QString key, dataMap.keys()){
//        //w- это QList<QStringList> по ключю
//        int count = 0;
//        for( auto w = dataMap[key].begin(); w < dataMap[key].end(); w++){
//            //беру последний эл-т, чтобы понять сколько однотипных
//            //эл-тов содаржит контейнер
//            int k = (*w).count();//кол-во эл-тов
//            k = (*w).at(k-1).toInt();// если от нуля, то -1 вписать
//            count += k;
//        }
//        allPrefixCount[key] = count;
//    }

//    QList<QStringList> dataMapVal, dataMapVal_new;
//    foreach (QString keyMap, allPrefixCount.keys()) {
//         foreach (QString keyDat, dataMap.keys()){
//             if (keyMap == keyDat){
//                 //сумма всех эл-тов данного ключа
//                 int count = allPrefixCount[keyMap];
//                 dataMapVal = dataMap.value(keyDat);
//                 for(int j = 0; j < count; j++){
//                     //Чтобы не выйти за границы
//                     if (j + 1 < count){
//                         foreach (auto var, dataMapVal) {
//                             //int pozition = dataMapVal.indexOf(QString::number(j));
//                             // Если элемент не найден или это последний или предпоследний элемент
//                             //if( pozition < 0 || pozition == var.count() || pozition == var.count() - 1 )
//                                 continue;

//                             int i = 0;
//                             i++;
//                         }
//                         int i = 0;
//                         i++;
//                     }
//                 }
//                 dataMapVal.clear();
//                 int i = 0;
//                 i++;

//             }
//         }

//    }

//    int i = 0;
//    i++;

//}


////дополняет в QList пропуски и названия элементов
//QStringList MainWindow::deviceandSpace(QList<QStringList>& varList){
//    QStringList allPrefixRename = allPrefix;
//  QString pasteStr;
//  bool flag_a = false;
//  bool flag_c = false;
//  bool flag_d = false;
//  bool flag_hl= false;
//  bool flag_l = false;
//  bool flag_r = false;
//  bool flag_s = false;
//  bool flag_vd = false;
//  bool flag_vt = false;
//  bool flag_x = false;
//  bool flag_z = false;
//  bool flag_zq = false;
//  bool flag_f = false;
//  QStringList var;
//  QStringList var_space;
//  var_space << "" << "" << "";
//  QList<QStringList>::iterator w;
//  for ( w = varList.begin();w < varList.end(); w++) {

//      //конденсаторы, резисторы и т.д.
//      if((*w)[0][0] == 'A' && flag_a == false){
//          pasteStr = "[Устройства]";
//          int b = allPrefixRename.indexOf("A");
//          allPrefixRename.removeAt(b);
//          flag_a = true;
//        }
//      if((*w)[0][0] == 'C' && flag_c == false){
//          pasteStr = "[Конденсаторы]";
//          int b = allPrefixRename.indexOf("C");
//          allPrefixRename.removeAt(b);
//          flag_c = true;
//        }
//      if((*w)[0][0] == 'D' && flag_d == false){
//          pasteStr = "[Микросхемы]";
//          int b = allPrefixRename.indexOf("D");
//          allPrefixRename.removeAt(b);
//          flag_d = true;
//        }
//      if((*w)[0][0] == 'H' && (*w)[0][1] == 'L'&& flag_hl == false){
//          pasteStr = "[Светодиоды]";
//          int b = allPrefixRename.indexOf("HL");
//          allPrefixRename.removeAt(b);
//          flag_hl = true;
//        }
//      if((*w)[0][0] == 'L'&& flag_l == false){
//          int b = allPrefixRename.indexOf("L");
//          allPrefixRename.removeAt(b);
//          pasteStr = "[Дроссели]";
//          flag_l = true;
//        }
//      if((*w)[0][0] == 'R'&& flag_r == false){
//          int b = allPrefixRename.indexOf("R");
//          allPrefixRename.removeAt(b);
//          pasteStr = "[Резисторы]";
//          flag_r = true;
//        }
//      if((*w)[0][0] == 'S'&& flag_s == false){
//          int b = allPrefixRename.indexOf("S");
//          allPrefixRename.removeAt(b);
//          pasteStr = "[Коммутация]";
//          flag_s = true;
//        }
//      if((*w)[0][0] == 'V' && (*w)[0][1] == 'D'&& flag_vd == false){
//          int b = allPrefixRename.indexOf("VD");
//          allPrefixRename.removeAt(b);
//          pasteStr = "[Диоды]";
//          flag_vd = true;
//        }
//      if((*w)[0][0] == 'V' && (*w)[0][1] == 'T'&& flag_vt == false){
//          int b = allPrefixRename.indexOf("VT");
//          allPrefixRename.removeAt(b);
//          pasteStr = "[Транзисторы]";
//          flag_vt = true;
//        }
//      if((*w)[0][0] == 'X'&& flag_x== false){
//          int b = allPrefixRename.indexOf("X");
//          allPrefixRename.removeAt(b);
//          pasteStr = "[Контактные соединения]";
//          flag_x = true;
//        }
//      if((*w)[0][0] == 'Z'&& flag_z == false){
//          int b = allPrefixRename.indexOf("Z");
//          allPrefixRename.removeAt(b);
//          pasteStr = "[Фильтры]";
//          flag_z = true;
//        }
//      if((*w)[0][0] == 'Z' && (*w)[0][1] == 'Q'&& flag_zq == false){
//          int b = allPrefixRename.indexOf("ZQ");
//          allPrefixRename.removeAt(b);
//          pasteStr = "[Кварцевый резонатор]";
//          flag_zq = true;
//        }
//      if((*w)[0][0] == 'F' && flag_f == false){
//          int b = allPrefixRename.indexOf("F");
//          allPrefixRename.removeAt(b);
//          pasteStr = "[Предохранители]";
//          flag_f = true;
//        }
//      //строка не пуста
//      if(pasteStr.isEmpty() == false){

//          w = varList.insert(w ,var_space);
//          var << "" << pasteStr << "";
//          w = varList.insert(++w ,var);
//          pasteStr.clear();
//          var.clear();
//        }




//    }
//return allPrefixRename;

//}

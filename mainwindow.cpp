#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include <activeexcel.h>
#include "activeword.h"

void DeviceandSpace(QList<QStringList>& varList);

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->openFile,SIGNAL(clicked(bool)),this,SLOT(openFile()));
  connect(ui->docGen,SIGNAL(clicked(bool)), this, SLOT(generate()));




  strListNamelabel << "[Устройства]" << "[Конденсаторы]"<<"[Микросхемы]"<<"[Светодиоды]"<<"[Дроссели]"<<"[Резисторы]"<<"[Коммутация]"<<"[Диоды]"<<"[Транзисторы]"<<"[Контактные соединения]"<<"[Фильтры]"<<"[Кварцевый резонатор]"<<"[Предохранители]";






}
void MainWindow::saveBut(){
 // ui->docGen->setEnabled(true);

}

MainWindow::~MainWindow()
{
  delete ui;
}



void MainWindow::openFile(){

  QString fileName_DATA = QFileDialog::getOpenFileName(this, tr("Open Excel File"),"", tr("(*.xlsx *.xls)"));
  ActiveExcel excel;
  QAxObject* ex1 = excel.documentOpen(QVariant(fileName_DATA));
  QVariant name = excel.sheetName();
  QAxObject* sheet = excel.documentSheetActive(name);



  QStringList var, var1;
  // 20 секунд на чтение

  int proc = 0;
  bool procUp = true;
  for(int i = 2;  ; i++){
      var << excel.sheetCellInsert(sheet, i, 2).toString();
      var << excel.sheetCellInsert(sheet, i, 3).toString();
      var << excel.sheetCellInsert(sheet, i, 4).toString();
      var << excel.sheetCellInsert(sheet, i, 5).toString();
      var << excel.sheetCellInsert(sheet, i, 6).toString();
      int g = var.count();
      if(var[g-1] == "" && var[g-2] == "" && var[g-3] == "")
       break;

      if(i == 500)
        ui->progressBar_2->setValue(25);

      if(i == 1000)
        ui->progressBar_2->setValue(50);

      ui->progressBar->setValue(proc);

      if(proc == 100)
        procUp = false;
      if(proc == 0)
        procUp = true;
      if(procUp)
        proc++;
      else
        proc--;
    }

  ui->progressBar->setValue(100);
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


// расслойка
QList<QStringList>::iterator w, z;
QStringList desValue1;
QList<QStringList> desValue;
desValue.clear();
//for ( w = varList.begin();w < varList.end();  w++) {
foreach (auto var, varList) {


   // QString designator = (*w).at(1);
    QString designator = var.at(1);

    for ( z = varList.begin();z < varList.end(); z++) {
        if(designator == (*z).at(1)){
          desValue1 << (*z).at(0);
          varList.erase(z);
          }
      }
    if(desValue1.isEmpty())
      continue;
    desValue1.append(designator);
    desValue << desValue1;
    desValue1.clear();

      }
QList<QStringList>::iterator des;
for ( des = desValue.begin(); des < desValue.end(); des++) {

    int cont = (*des).count();
    (*des).append(QString::number(cont - 1));
  }
//desValue [0] перечисление c1 c2 ... [1] описание компонента [3] количество одинаковых элементов
QList<QString> vectorString;
QList<QString>::iterator vS;
QList<QStringList>::iterator var2;
for (var2 = desValue.begin(); var2 < desValue.end(); var2++) {
    int jk = (*var2).count();
    //в этой ячейке храниться количество элементов
    QString sttt = (*var2).at(jk-1);

    if(sttt.toInt() > 2){
        //Сохраняю первый символ!
        QString prefix = (*var2).at(0);
        prefix.remove(QRegExp("[^A-Za-zА-Яа-я]"));
        //j = кол-во эл-тов, j-1 - описание элементов
        //убираю префиксы
        for(int i = 0; i < sttt.toInt(); i++){
            QString perem =  (*var2).at(i);
            QString symbol = perem.remove(QRegExp("[A-Za-zА-Яа-я]"));
            vectorString << symbol;
            //Расстановка "-" символов межи последующими числами
            if(i > 0){
                vS = vectorString.end()-1;
                int aEnd = (*vS).toInt();
                vS--;
                int aPrepend = (*vS).toInt();
                //если предыдущее значение равно текущему- вставить между ними "-"
                if( aEnd - 1 == aPrepend ){
                    vS = vectorString.insert(vectorString.end()-1, "-");

                }
            }
            //vectorString заполнен!
            if( i == sttt.toInt() - 1){
                //Убрать числа, слева и справа от которых стоит "-"
                for(vS = vectorString.begin(); vS < vectorString.end(); vS++){
                    if(vS == vectorString.end()-2)
                      continue;
                    if( (*vS == "-") &&( *(vS+2) == "-") ){
                        //удаляю два элемента, возвращаюсь на предыдущий
                        vS=vectorString.erase(vS);
                        vS=vectorString.erase(vS);
                        vS = vS-1;
                    }
                }
                //поставить  запятую
                for(vS = vectorString.begin(); vS < vectorString.end(); vS++){
                    QString vss = *(vectorString.end()-1); //на 5 эл-те badalloc //3 прогон
                    QString vss1 = *vS;
                    if(vS == vectorString.end()-1)
                      continue;
                    if( ( (*vS) != "-")  && ( (*(vS+1) ) != "-")  )
                        vS = vectorString.insert(vS+1, ", \n");
                }
                //поставить  префикс
                for(vS = vectorString.begin(); vS < vectorString.end(); vS++){
                    QString vss1 = *vS;
                    if( ((*vS) != "-")&& ((*vS) != ", \n")){
                        (*vS).prepend(prefix);
                        vss1 = *vS;
                        int i= 0;
                        i++;
                      }

                }
                //тут надо удалить лишние элементы, вставив значение vectorString
                int varDel = sttt.toInt() - 1;
                for(int i = 0; i < varDel+1; i++)
                    (*var2).removeFirst();
                QString vec;
                foreach (auto ver, vectorString) {
                    vec += ver;
                }
                (*var2).prepend(vec);
                vectorString.clear();
                vec.clear();
            }
        }
    }
    //ежели хранится два элемента
    if(sttt.toInt() == 2){
        (*var2).insert(1,", ");
        int count = (*var2).count();
        QString vec;
        for( int i = 0; i < count - 2; i++){
          vec +=(*var2)[i];
        }
        (*var2).removeFirst();
        (*var2).removeFirst();
        (*var2).removeFirst();
        (*var2).prepend(vec);
        vec.clear();

    }
}
DeviceandSpace(desValue);
ui->progressBar_2->setValue(60);

ActiveWord word;
QAxObject* doc1 = word.documentOpen("D:/projects/gp/PEZ.docx");

QStringList listLabel = word.tableGetLabels(1, 2);
ui->progressBar_2->setValue(80);
word.tableFill(desValue,listLabel,1,2);
ui->progressBar_2->setValue(90);
// поиск элементов, добавка курсива и расположение по центру
foreach (auto var, strListNamelabel) {
    //подчеркивание
    word.selectionFindFontname(var, true, false, true, true, "GOST type B");
    //центрирование
    word.selectionAlign(var , false, false, true);
    QString s = var;
    s.remove(0,1);
    s.remove(s.count()-1,1);
    QString s1 = var;
    // замена меток/
    word.findReplaseLabel(s1, s, true);
    s.clear();
    s1.clear();
  }

//Вбивка ФИО

word.colontitulReplaseLabel(doc1, "[Разраб]", ui->lineEdit->text(), true);
word.colontitulReplaseLabel(doc1, "[пров]", ui->lineEdit_2->text(), true);
word.colontitulReplaseLabel(doc1, "[тконт]", ui->lineEdit_3->text(), true);
word.colontitulReplaseLabel(doc1, "[конт]", ui->lineEdit_4->text(), true);
word.colontitulReplaseLabel(doc1, "[утв]", ui->lineEdit_5->text(), true);
word.colontitulReplaseLabel(doc1, "[5]", ui->lineEdit_6->text(), true);
word.colontitulReplaseLabel(doc1, "[5]", ui->lineEdit_6->text(), false);
word.colontitulReplaseLabel(doc1, "[6]", ui->lineEdit_7->text(), true);
word.colontitulReplaseLabel(doc1, "[7]", ui->lineEdit_9->text(), true);

word.setVisible();
ui->progressBar_2->setValue(100);
}






void MainWindow::generate(){
  ActiveWord word;
  QAxObject* doc1 = word.documentOpen("D:/projects/gp/111.docx");
  word.setVisible();

  //word.shapes(doc1);


  int j;
  j++;
}

//дополняет в QList пропуски и названия элементов
void DeviceandSpace(QList<QStringList>& varList){
  QString pasteStr;
  bool flag_a = false;
  bool flag_c = false;
  bool flag_d = false;
  bool flag_hl= false;
  bool flag_l = false;
  bool flag_r = false;
  bool flag_s = false;
  bool flag_vd = false;
  bool flag_vt = false;
  bool flag_x = false;
  bool flag_z = false;
  bool flag_zq = false;
  bool flag_f = false;
  int flag_spaceFirst = 0;
  bool flag_space = false; //для пропуска строки
  QStringList var;
  QStringList var_space;
  var_space << "" << "" << "";
  QList<QStringList>::iterator w;
  for ( w = varList.begin();w < varList.end(); w++) {

      //конденсаторы, резисторы и т.д.
      if((*w)[0][0] == 'A' && flag_a == false){
          pasteStr = "[Устройства]";
          flag_a = true;
        }
      if((*w)[0][0] == 'C' && flag_c == false){
          pasteStr = "[Конденсаторы]";
          flag_c = true;
        }
      if((*w)[0][0] == 'D' && flag_d == false){
          pasteStr = "[Микросхемы]";
          flag_d = true;
        }
      if((*w)[0][0] == 'H' && (*w)[0][1] == 'L'&& flag_hl == false){
          pasteStr = "[Светодиоды]";
          flag_hl = true;
        }
      if((*w)[0][0] == 'L'&& flag_l == false){
          pasteStr = "[Дроссели]";
          flag_l = true;
        }
      if((*w)[0][0] == 'R'&& flag_r == false){
          pasteStr = "[Резисторы]";
          flag_r = true;
        }
      if((*w)[0][0] == 'S'&& flag_s == false){
          pasteStr = "[Коммутация]";
          flag_s = true;
        }
      if((*w)[0][0] == 'V' && (*w)[0][1] == 'D'&& flag_vd == false){
          pasteStr = "[Диоды]";
          flag_vd = true;
        }
      if((*w)[0][0] == 'V' && (*w)[0][1] == 'T'&& flag_vt == false){
          pasteStr = "[Транзисторы]";
          flag_vt = true;
        }
      if((*w)[0][0] == 'X'&& flag_x== false){
          pasteStr = "[Контактные соединения]";
          flag_x = true;
        }
      if((*w)[0][0] == 'Z'&& flag_z == false){
          pasteStr = "[Фильтры]";
          flag_z = true;
        }
      if((*w)[0][0] == 'Z' && (*w)[0][1] == 'Q'&& flag_zq == false){
          pasteStr = "[Кварцевый резонатор]";
          flag_zq = true;
        }
      if((*w)[0][0] == 'F' && flag_f == false){
          pasteStr = "[Предохранители]";
          flag_f = true;
        }
      //строка не пуста
      if(pasteStr.isEmpty() == false){

          w = varList.insert(w ,var_space);
          var << "" << pasteStr << "";
          w = varList.insert(++w ,var);
          pasteStr.clear();
          var.clear();
        }




    }
}

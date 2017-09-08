#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include <activeexcel.h>
#include "activeword.h"

void DeviceandSpace(QList<QStringList> varList);

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->openFile,SIGNAL(clicked(bool)),this,SLOT(openFile()));
  connect(ui->docGen,SIGNAL(clicked(bool)), this, SLOT(generate()));

  connect(ui->saveButn, SIGNAL(clicked(bool)),this, SLOT(saveBut()));



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
  for(int i = 2; i < 50; i++){
      var << excel.sheetCellInsert(sheet, i, 2).toString();
      var << excel.sheetCellInsert(sheet, i, 3).toString();
      var << excel.sheetCellInsert(sheet, i, 4).toString();
      var << excel.sheetCellInsert(sheet, i, 5).toString();
      var << excel.sheetCellInsert(sheet, i, 6).toString();
      int g = var.count();
      if(var[g-1] == "" && var[g-2] == "" && var[g-3] == "")
       break;
    }

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
    QString str;
    if(cont == 2){
      (*des).append(QString::number(cont - 1));
      continue;
      }
    for(int i = 0; i < cont-1; i++)
      if(i == 0)
      str += (*des).at(i);
      else str += " " + (*des).at(i);
    for(int i = 0; i < cont -1; i++)
      (*des).removeFirst();
    (*des).prepend(str);
    (*des) << QString::number(cont -1);
    str.clear();
  }

//desValue [0] перечисление c1 c2 ... [1] описание компонента [3] количество одинаковых элементов


DeviceandSpace(desValue);

//ActiveWord word;
//QAxObject* doc1 = word.documentOpen("D:/projects/gp/ПЭЗ.docx");

//QStringList listLabel = word.tableGetLabels(1, 2);



// word.tableFill(desValue,listLabel,1,2);
//word.setVisible();

//int j;
//j++;



int i;
i++;
}






void MainWindow::generate(){
  ActiveWord word;
  QAxObject* doc1 = word.documentOpen("D:/projects/gp/ПЭЗ.docx");
  word.setVisible();
 // QStringList listLabel = word.tableGetLabels(1, 2);

bool a = word.findReplaseLabelInColontituls("[5]", ui->lineEdit_6->text(), true);
a  =word.findReplaseLabelInColontituls("[6]", ui->lineEdit_7->text(), false);
a = word.findReplaseLabelInColontituls("[7]", ui->lineEdit_9->text(), false);

//  word.tableFill(varList,listLabel,1,2);


  int j;
  j++;
}


void DeviceandSpace(QList<QStringList> varList){
  bool parity = false; //четность
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

  bool flag_space = false; //для пропуска строки
  QStringList var;
  QList<QStringList>::iterator w;
  for ( w = varList.begin();w < varList.end(); w++) {
      foreach (auto k, *w) {
          if(parity == false){
              //для пропуска строки
              if(flag_space == true){
                  var << "" << "";
                  //w = varList.insert(w ,var);
                  w = varList.insert(w ,var);
                  var.clear();
                  flag_space = false;
                }
              //конденсаторы, резисторы и т.д.
              if(k[0] == 'A' && flag_a == false){
                  pasteStr = "Устройства";
                  flag_a = true;
                }
              if(k[0] == 'C' && flag_c == false){
                  pasteStr = "Конденсаторы";
                  flag_c = true;
                }
              if(k[0] == 'D' && flag_d == false){
                  pasteStr = "Схемы интегральные";
                  flag_d = true;
                }
              if(k[0] == 'H' && k[1] == 'L'&& flag_hl == false){
                  pasteStr = "Светодиоды";
                  flag_hl = true;
                }
              if(k[0] == 'L'&& flag_l == false){
                  pasteStr = "Катушки индуктивности";
                  flag_l = true;
                }
              if(k[0] == 'R'&& flag_r == false){
                  pasteStr = "Резисторы";
                  flag_r = true;
                }
              if(k[0] == 'S'&& flag_s == false){
                  pasteStr = "Коммутация";
                  flag_s = true;
                }
              if(k[0] == 'V' && k[1] == 'D'&& flag_vd == false){
                  pasteStr = "Диоды";
                  flag_vd = true;
                }
              if(k[0] == 'V' && k[1] == 'T'&& flag_vt == false){
                  pasteStr = "Транзисторы";
                  flag_vt = true;
                }
              if(k[0] == 'X'&& flag_x== false){
                  pasteStr = "Контактные соединения";
                  flag_x = true;
                }
              if(k[0] == 'Z'&& flag_z == false){
                  pasteStr = "Фильтры";
                  flag_z = true;
                }
              if(k[0] == 'Z' && k[1] == 'Q'&& flag_zq == false){
                  pasteStr = "Кварцевый резонатор";
                  flag_zq = true;
                }

            }

          //строка не пуста
          if(pasteStr.isEmpty() == false){
              var << "" << pasteStr;
              //w = varList.insert(w ,var);
              w = varList.insert(w ,var);
              pasteStr.clear();
              var.clear();
              flag_space = true;
            }

          parity = !parity;
        }

    }
  int j;
  j++;

}

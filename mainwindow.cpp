#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include <activeexcel.h>
#include "activeword.h"


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(openFile()));
  connect(ui->pushButton_2,SIGNAL(clicked(bool)), this, SLOT(generate()));


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
  for(int i = 2; i < 20; i++){
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
  int count = 0;
  for(int j = 0; j < var.count(); j++){
      if(count < 5){
          var1.append(var.at(j));
          count++;
          continue;
        }
      varList.append(var1);
      var1.clear();
      count = 0;
      j--;
    }
var.clear();



ActiveWord word;
QAxObject* doc1 = word.documentOpen("D:/projects/gp/ПЭЗ.docx");
QStringList listLabel = word.tableGetLabels(1, 2);

word.tableFill(varList,listLabel,1,2);


int i;
i++;
}






void MainWindow::generate(){

}

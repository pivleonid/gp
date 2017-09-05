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



QStringList var1, var2, var3, var4, var5;
for(int i = 2; i < 149; i++){
    var1 << excel.sheetCellInsert(sheet, i, 2).toString();
    var1 << excel.sheetCellInsert(sheet, i, 3).toString();
    var1 << excel.sheetCellInsert(sheet, i, 4).toString();
    var1 << excel.sheetCellInsert(sheet, i, 5).toString();
    var1 << excel.sheetCellInsert(sheet, i, 6).toString();
  }
QList<QStringList> varList;
for(int i = 0; i < 148; i++)
  for(int j=0; j < 4; j++){
      if(j==0)
        varList[j] << var1[i];
      if(j==1)
        varList[j] << var1[i];
      if(j==2)
        varList[j] << var1[i];
      if(j==3)
        varList[j] << var1[i];
    }

ActiveWord word;
QAxObject* doc1 = word.documentOpen("D:/projects/gp/скрипт.docx");
QStringList listLabel = word.tableGetLabels(1, 1);

word.tableFill(varList,listLabel,1,1);


int i;
i++;
}






void MainWindow::generate(){

}

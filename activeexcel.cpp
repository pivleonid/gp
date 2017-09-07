#include "activeexcel.h"

ActiveExcel::ActiveExcel()
{
  excelApplication_ = new QAxObject( "Excel.Application");
  excelApplication_->setProperty("DisplayAlerts", false);
  excelApplication_->setProperty("Visible", false);
  worcbooks_ = excelApplication_->querySubObject( "Workbooks" );



}


ActiveExcel::~ActiveExcel(){
  excelApplication_->dynamicCall("Quit()");
  delete sheets_;
  delete worcbooks_;
  delete excelApplication_;
}


QAxObject* ActiveExcel::documentOpen(QVariant path){
  QAxObject *document;
  if (path == "") document = worcbooks_->querySubObject("Add");
  else document = worcbooks_->querySubObject("Add(const QVariant &)", path);

  workSheet_ = document->querySubObject("Worksheets");
  sheets_ = document->querySubObject( "Sheets" );
 return document;
}



QAxObject* ActiveExcel::documentAddSheet(QVariant sheetName ){

    QAxObject *active;
    active =  sheets_->querySubObject("Add");
    active->setProperty("Name", sheetName);
    return active;
}

QAxObject* ActiveExcel::documentSheetActive( QVariant sheet){

    return sheets_->querySubObject( "Item(const QVariant&)", sheet );

}


void ActiveExcel::documentClose(QAxObject* document){
  document->dynamicCall("Close(wdDoNotSaveChanges)");
  delete document;

}

void ActiveExcel::documentCloseAndSave(QAxObject *document, QVariant path){
      document -> dynamicCall("SaveAs(const QVariant&)", path);
      document->dynamicCall("Close(wdDoNotSaveChanges)");
      delete document;
}
//---------------------------------------------------------------------------------
void ActiveExcel::sheetCellPaste(QAxObject* sheet, QVariant string, QVariant row, QVariant col ){
  QAxObject* cell = sheet->querySubObject("Cells(QVariant,QVariant)", row , col);
  cell->setProperty("Value", string);
  delete cell;

}
QVariant ActiveExcel::sheetCellInsert(QAxObject* sheet,  QVariant row, QVariant col){
   QAxObject* cell = sheet->querySubObject("Cells(QVariant,QVariant)", row , col);
   QVariant result = cell->property("Value");
   delete cell;
   return result;
}
//---------------------------------------------------------------------------------

void ActiveExcel::sheetCopyToBuf(QAxObject* sheet, QVariant rowCol){
  QAxObject* range = sheet->querySubObject( "Range(const QVariant&)", rowCol);
  range->dynamicCall("Select()");
  range->dynamicCall("Copy()");
  delete range;
}

void ActiveExcel::sheetPastFromBuf(QAxObject* sheet, QVariant rowCol){
  QAxObject* rangec = sheet->querySubObject( "Range(const QVariant&)",rowCol);
  rangec->dynamicCall("Select()");
  rangec->dynamicCall("PasteSpecial()");
  delete rangec;
}

//---------------------------------------------------------------------------------
 void ActiveExcel::sheetCellMerge(QAxObject* sheet, QVariant rowCol){
    QAxObject* range = sheet->querySubObject( "Range(const QVariant&)", rowCol);
    range->dynamicCall("Select()");
   // устанавливаю свойство объединения.
    range->dynamicCall("Merge()");
    delete range;
 }

void ActiveExcel::sheetCellHeightWidth(QAxObject *sheet, QVariant RowHeight, QVariant ColumnWidth, QVariant rowCol){

   QAxObject *rangec = sheet->querySubObject( "Range(const QVariant&)",rowCol);
   QAxObject *razmer = rangec->querySubObject("Rows");
   razmer->setProperty("RowHeight",RowHeight);
   razmer = rangec->querySubObject("Columns");
   razmer->setProperty("ColumnWidth",ColumnWidth);
   delete razmer;
   delete  rangec;
}

void ActiveExcel::sheetCellHorizontalAlignment(QAxObject* sheet, QVariant rowCol, bool left, bool right, bool center){
  QAxObject *rangep = sheet->querySubObject( "Range(const QVariant&)", rowCol);
  rangep->dynamicCall("Select()");
  if (left == true)rangep->dynamicCall("HorizontalAlignment",-4152);
  if (right == true)rangep->dynamicCall("HorizontalAlignment",-4131);
  if (center == true) rangep->dynamicCall("HorizontalAlignment",-4108);
  delete rangep;
}

void ActiveExcel::sheetCellVerticalAlignment(QAxObject* sheet, QVariant rowCol, bool up, bool down, bool center){
  QAxObject *rangep = sheet->querySubObject( "Range(const QVariant&)", rowCol);
   rangep->dynamicCall("Select()");
   if (up == true)rangep->dynamicCall("VerticalAlignment",-4160);
   if (down == true)rangep->dynamicCall("VerticalAlignment",-4107);
   if (center == true) rangep->dynamicCall("VerticalAlignment",-4108);
   delete rangep;

}

QVariant ActiveExcel::sheetName(){

   QAxObject* active = excelApplication_->querySubObject("ActiveSheet");
   QVariant name = active->dynamicCall("Name");
   delete active;
   return name;
}

QVariant ActiveExcel::lastCol(){

//    lLastCol = Cells(1, Columns.Count).End(xlToLeft).Column
//  QVariant lastColumn;
//    QAxObject* cell = sheet->querySubObject("Cells(QVariant,QVariant)", row , col);

}







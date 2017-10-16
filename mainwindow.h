#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();


private:
  Ui::MainWindow *ui;
  QString pathPEZ; //Сам шаблон
  QString pathData; //Путь до шаблона
  QStringList strListNamelabel;
  QList<QStringList> desValue;
   QStringList allPrefix;

  void mesOut(QString mes);
  QStringList deviceandSpace(QList<QStringList>& varList);
  QList<QStringList> transform(QStringList var);
  QStringList deviceandSpace_v2(QList<QStringList>& varList);
  int symbolsInTable;


private slots:
  void openFile();
  void generate();
  void openAbout();
  void pathSave();

};

#endif // MAINWINDOW_H

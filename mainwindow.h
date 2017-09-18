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
  QStringList strListNamelabel;
  QList<QStringList> desValue;
   QStringList allPrefix;

  void mesOut(QString mes);
  QStringList deviceandSpace(QList<QStringList>& varList);
  QList<QStringList> transform(QStringList var);
  void deviceUpdate(QList<QStringList>& varList);


private slots:
  void openFile();
  void generate();

};

#endif // MAINWINDOW_H

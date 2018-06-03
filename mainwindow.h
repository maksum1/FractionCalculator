#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fraction.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void ShowResult(const Fraction &obj);
  bool Validator(QString Check, int position);

  void on_Result_clicked();

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

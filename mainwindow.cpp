#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <fraction.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

bool MainWindow::Validator(QString Check, int position) {
  try {

    QRegExp temp("\\d*");
    if (temp.exactMatch(Check)) {
      if (position == 1) {
        if (Check.toInt() == 0) {
          throw 666;
        }
      }
      return true;
    }

    else {
      throw 404;
    }

  } catch (int error) {

    if (error == 666)
      ui->label_Satus->setText("Cant't devide on 0 !!!");
    else
      ui->label_Satus->setText("You write char in edit?!");
    return false;
  }
}

void MainWindow::ShowResult(const Fraction &obj) {
  ui->lineEdit_Answer_Denominator->setText(
      QString::number(obj.getDenominator()));
  ui->lineEdit_Answer_Numinator->setText(
      QString::number(obj.getNumerator() % obj.getDenominator()));
  ui->lineEdit_Answer_Integer->setText(
      QString::number(obj.getNumerator() / obj.getDenominator()));
}

void MainWindow::on_Result_clicked() {
  // Validator for each line edit
  QString v1, v2, v3, v4, v5, v6;
  v1 = ui->lineEdit_A_Numinator->text();
  v2 = ui->lineEdit_A_Denominator->text();
  v3 = ui->lineEdit_A_Integer->text();
  v4 = ui->lineEdit_B_Numinator->text();
  v5 = ui->lineEdit_B_Denominator->text();
  v6 = ui->lineEdit_B_Integer->text();

  if (!Validator(v1, 2)) {
    ui->label_Sector->setText("A(Numinator)");
  } else if (!Validator(v2, 1)) {
    ui->label_Sector->setText("A(Denominator)");
  } else if (!Validator(v3, 2)) {
    ui->label_Sector->setText("A(Integer)");
  }

  else if (!Validator(v4, 2)) {
    ui->label_Sector->setText("B(Numinator)");
  } else if (!Validator(v5, 1)) {
    ui->label_Sector->setText("B(Denominator)");
  } else if (!Validator(v6, 2)) {
    ui->label_Sector->setText("B(Integer)");
  } else {
    ui->label_Satus->setText("Ok...");
    ui->label_Sector->setText("Ok...");

    Fraction A(ui->lineEdit_A_Integer->text().toInt(),
               ui->lineEdit_A_Numinator->text().toInt(),
               ui->lineEdit_A_Denominator->text().toInt());

    Fraction B(ui->lineEdit_B_Integer->text().toInt(),
               ui->lineEdit_B_Numinator->text().toInt(),
               ui->lineEdit_B_Denominator->text().toInt());

    Fraction C;
    QString action = ui->actions->currentText();

    if (action == "+") {
      C = A + B;
      ShowResult(C);
    } else if (action == "-") {
      C = A - B;
      ShowResult(C);
    }

    else if (action == "*") {
      C = A * B;
      ShowResult(C);
    } else if (action == "/") {
      C = A / B;
      ShowResult(C);
    }
  }
}

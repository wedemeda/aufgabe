#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtMath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
     double a = ui->side_a->text().toInt();
     double b = ui->side_b->text().toInt();
     double angl = ui->anglField->text().toInt();
     double pi = double(M_PI);
     if (ui->radButton->isChecked()) angl = (angl*180)/pi;
     double c = qSqrt(a*a+b*b-2*a*b*qCos(angl));
     ui->result->setText(QString::number(c)+"  метров");

}

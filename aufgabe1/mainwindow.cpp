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

void MainWindow::on_button_clicked()
{
    double a = ui->kef_a->text().toInt();
    double b = ui->kef_b->text().toInt();
    double c = ui->kef_c->text().toInt();
    double d = qPow(b,2) - 4*a*c;
    if (d > 0)
             {  double root_1 = (-b + qSqrt(d))/(2*a);
                double root_2 = (-b - qSqrt(d))/(2*a);
                ui->roots->setText("x1 =  "+QString::number(root_1)+"   x2 = "+QString::number(root_2));
             }
    if (d == 0)
             {  double root_1 = (-b + qSqrt(d))/(2*a);
                ui->roots->setText("x = "+QString::number(root_1));
             }
    if (d < 0)

                ui->roots->setText("Нет корней!");
}

//Расчет стороны треугольника по двум сторонам и углом между ними.
//Дополнительно: добавить переключатель из QRadioButton для выбора единиц, в каких указан угол: градусах или радианах.

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
     if (ui->gradButton->isChecked()) angl = qDegreesToRadians(angl);
     double c = qSqrt(a*a+b*b-2*a*b*qCos(angl));
     ui->result->setText(QString::number(c)+"  метров");

}

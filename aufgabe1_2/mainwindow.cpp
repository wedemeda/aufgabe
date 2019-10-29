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
     double a = ui->side_a->text().toDouble();
     double b = ui->side_b->text().toDouble();
     double angl = ui->anglField->text().toDouble();
     if (a<=0.0||b<=0.0||angl<=0.0)
        { ui->result->setText("Вводимые значения должны быть > 0!");}
     else if ((ui->radButton->isChecked())&&(angl>M_PI))
             {ui->result->setText("Значение угла не может быть > числи пи!");}
         else if ((angl>180.0))
                 {ui->result->setText("Значение угла не может быть > 180!");}

    else {if (ui->gradButton->isChecked()) angl = qDegreesToRadians(angl);
    double c = qSqrt(a*a+b*b-2*a*b*qCos(angl));
    ui->result->setText(QString::number(c)+"  метров");}

}

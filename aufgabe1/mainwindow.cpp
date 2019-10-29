//Написать программу, которая будет находить корень квадратного уравнения второй степени, входные данные: a, b, c.
//Если нахождение корня невозможно, выводить сообщение в поле результата (или выводить результат в виде комплексного числа).
//Учитывать, что число a может быть равно нулю.

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
    double a = ui->kef_a->text().toDouble();
    double b = ui->kef_b->text().toDouble();
    double c = ui->kef_c->text().toDouble();
    double d = qPow(b,2) - 4*a*c;

    if ((a!=0.0)&&(b!=0.0)&&(c!=0.0))
                            {
                             if (d > 0.0)
                                       {  double root_1 = (-b + qSqrt(d))/(2*a);
                                          double root_2 = (-b - qSqrt(d))/(2*a);
                                          ui->roots->setText("x1 =  "+QString::number(root_1)+"   x2 = "+QString::number(root_2));
                                       }
                             if (d == 0.0)
                                       {  double root_1 = (-b + qSqrt(d))/(2*a);
                                          ui->roots->setText("x = "+QString::number(root_1));
                                       }
                             if (d < 0.0)

                                          ui->roots->setText("Нет корней!");
                           }


      if (a==0.0&&b==0.0&&c==0.0)
                   { ui->roots->setText("x = любое число");}
       else   if (a==0.0&&b==0.0)
                       { ui->roots->setText("Нет корней!");}
         else      if ((b==0.0)&&(c==0.0))
                       { double root_1 = 0;
                         ui->roots->setText("x = "+QString::number(root_1));
                       }

      else   if (a==0.0)
             { double root_1 = -(c/b);
               ui->roots->setText("x = "+QString::number(root_1));
             }
      else   if (b==0.0)
             {  if ((a>0.0&&c>0.0)||(a<0.0&&c<0.0))
                                                { ui->roots->setText("Нет корней!");}
                else                            { double root_1 = qSqrt(-c/a);
                                                  double root_2 = -(qSqrt(-c/a));
                                                  ui->roots->setText("x1 =  "+QString::number(root_1)+"   x2 = "+QString::number(root_2));
                                                }
             }


    else   if (c==0.0)
             {  double root_1 = 0;
                double root_2 = -(b/a);
                ui->roots->setText("x1 =  "+QString::number(root_1)+"   x2 = "+QString::number(root_2));
             }


}

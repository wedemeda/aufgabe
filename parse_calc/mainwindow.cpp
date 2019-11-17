/*
Пример из методички:

Напишем собственный модуль, который в тексте будет подставлять в арифметический пример результат
(перед примером будут ключевые символы #@пример, ответ будет вписываться после знака =, а ключевые символы удаляться).
Пример работы:

Пример 1: #@5+7=
Пример 2: #@6*7=
Пример 3: #@10/5=
Пример 4: #@6+5*2-3*9=
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   parseText = new ParseText();
   if (!parseText) close();
}

MainWindow::~MainWindow()
{
   if (parseText) {
       delete parseText;
       parseText = nullptr;
   }
   delete ui;
}


void MainWindow::on_plainTextEdit_textChanged()
{
   QString str = ui->plainTextEdit->toPlainText(); // получаем текст виджета
   if (parseText->change(str))                     // были ли примеры
   {
       ui->plainTextEdit->setPlainText(parseText->getText()); // заменяем текст примеры с результатами
   }
}

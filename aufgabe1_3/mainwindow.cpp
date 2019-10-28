//Создать программу, разместить на поле виджет QPlainTextEdit.
//Добавить кнопки: для добавления фиксированной строки, замены на готовый текст.
//Разместить QTextEdit.Через метод setHtml(QString) установите текст произвольного html-кода, например <font color='red'>Hello</font>.

#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_addButton_clicked()
{
    QString str = ui->plainTextEdit->toPlainText();
    ui->textEdit->insertHtml(str);
}


void MainWindow::on_replaceButton_clicked()
{
    QString str = ui->plainTextEdit->toPlainText();
    ui->textEdit->setHtml("<b><font color='tomato'>"+str+"</font></b>");
}

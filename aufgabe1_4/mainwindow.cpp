//4. Получите QTextDocument из виджета QTextEdit (метод document).
//С помощью списка методов и переменных выберите, какие наиболее интересны для редактирования текста.

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

void MainWindow::on_clearBut_clicked()
{
    QTextDocument* doc = ui->textEdit->document();
    doc->clear();
    ui->textEdit->setDocument(doc);
}


void MainWindow::on_button1_clicked()
{
    QTextDocument* doc = ui->textEdit->document();
    QFont font;
    font.setFamily(font.defaultFamily());
    doc->setDefaultFont(font);
    ui->textEdit->setDocument(doc);
}

void MainWindow::on_button2_clicked()
{
   QTextDocument* doc = ui->textEdit->document();
   int n = ui->fontSize->text().toInt();
   if (n>0)
      { QFont font;
        font.setPixelSize(n);
        doc->setDefaultFont(font);
        ui->textEdit->setDocument(doc);
        ui->errorLabel->setText("");
      }
   else
      ui->errorLabel->setText("Значение должно быть >0!");
}

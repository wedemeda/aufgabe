/* Написать класс, который будет вставлять в текст спецсимволы (4–5).
Пригодится для символов, для которых нет клавиши на клавиатуре,
но они часто используются в тексте: © — знак охраны авторского права, ‰ — промилле,
®, € — евро, ₽ — рубль. Например, ввод рубля в программе #@RUB@, или руб.
(автоматически заменить на знак).
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCursor>

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

void MainWindow::on_plainTextEdit_textChanged()
{
    {
        QString txt = ui->plainTextEdit->toPlainText();
        qint32 pos = 0;
        while(true) {
              int fnd = txt.indexOf("#@", pos);
              if (fnd == -1) return;
              pos = fnd+1;
              int t = txt.indexOf('@', fnd+2);
              if (t>0 && t>(fnd+1)){
                QString abbr = txt.mid(fnd+2,3);
                txt.remove(fnd,t+1);
                if (abbr == "EUR"|| abbr == "eur") txt.insert(fnd, QChar(8364));
                else  if (abbr == "RUB"||abbr == "rub") txt.insert(fnd, QChar(8381));
                else  if (abbr == "USD"||abbr == "usd") txt.insert(fnd, QChar(36));
                else  if (abbr == "PRO"||abbr == "pro") txt.insert(fnd, QChar(8240));
                else  if (abbr == "COP"||abbr == "cop") txt.insert(fnd, QChar(169));
                else  if (abbr == "REG"||abbr == "reg") txt.insert(fnd, QChar(174));
                QTextCursor cursor = ui->plainTextEdit->textCursor();
                ui->plainTextEdit->setPlainText(txt);
                ui->plainTextEdit->setTextCursor(cursor);
              }
        }
    }
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_clearBut_clicked();

    void on_button1_clicked();

    void on_button2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

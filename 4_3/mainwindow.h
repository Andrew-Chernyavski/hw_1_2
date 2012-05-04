#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSignalMapper>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QPushButton *buttons[12];
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void numer(int i);
    void operations(int i);

private:
    Ui::MainWindow *ui;
    int arg;
    char operation;
    bool valueChanged;
};

#endif // MAINWINDOW_H

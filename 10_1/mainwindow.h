#pragma once
#include <QMainWindow>
#include <QSignalMapper>
#include <massiv.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

    QSignalMapper *mapper;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Massiv *mas;
public slots:
    void clicked(int index);

};

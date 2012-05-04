#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(calculate()));
    connect (ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(calculate()));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(calculate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculate()
{
    int i1 = ui->spinBox->value();
    int i2 = ui->spinBox_2->value();
    int res = 0;
    int index = ui->comboBox->currentIndex();
    if (index == 0)
        res = i1 + i2;
    else
        if (index == 1)
        res = i1 - i2;
        else
            if (index == 2)
               res = i1 * i2;
            else
                if (i2 != 0)
                    res = i1 / i2;
    ui->lineEdit->setText(QString::number(res));
}

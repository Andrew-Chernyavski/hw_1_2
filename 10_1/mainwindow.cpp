#pragma once
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "massiv.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mas = new Massiv;
    mapper = new QSignalMapper();
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(clicked(int)));
    for (int i = 0; i < 9; i++)
    {
        QPushButton *button = ui->centralWidget->findChild<QPushButton *>("button" + QString::number(i+1));
        mapper->setMapping(button, i);
        connect(button, SIGNAL(clicked()), mapper, SLOT(map()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mas;
}

void MainWindow::on_pushButton_clicked()
{
    MainWindow::close();
}

void MainWindow::clicked(int index)
{
    int com = mas->click(index / 3, index % 3);
    if (com == 0)
        return;
    QPushButton *button = ui->centralWidget->findChild<QPushButton *>("button" + QString::number(index + 1));
     if (com == 1)
        button->setText("X");
    else
        button->setText("O");
     if (mas->victory(index / 3, index % 3))
     {
         ui->label->setText(button->text() + " win");
     }
}



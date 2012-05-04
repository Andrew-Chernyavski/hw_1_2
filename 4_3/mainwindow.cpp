#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    arg = 0;
    operation = '+';
    valueChanged = false;

    ui->setupUi(this);

    QSignalMapper *numMap = new QSignalMapper(this);
    connect(numMap, SIGNAL(mapped(int)), this, SLOT(numer(int)));
    QSignalMapper *operationMap = new QSignalMapper(this);
    connect(operationMap, SIGNAL(mapped(int)), this, SLOT(operations(int)));

    for (int i = 0; i < 10; ++i)
    {
        QString text = QString::number(i);
        buttons[i] = new QPushButton(text, this);
        numMap->setMapping(buttons[i], i);
        connect(buttons[i], SIGNAL(clicked()), numMap, SLOT(map()));
    }

    buttons[10] = new QPushButton("C", this);
    operationMap->setMapping(buttons[10], 'C');
    connect(buttons[10], SIGNAL(clicked()), operationMap, SLOT(map()));
    buttons[11] = new QPushButton("=", this);
    operationMap->setMapping(buttons[11], '=');
    connect(buttons[11], SIGNAL(clicked()), operationMap, SLOT(map()));

    operationMap->setMapping(ui->Plus, '+');
    connect(ui->Plus, SIGNAL(clicked()), operationMap, SLOT(map()));
    operationMap->setMapping(ui->Minus, '-');
    connect(ui->Minus, SIGNAL(clicked()), operationMap, SLOT(map()));
    operationMap->setMapping(ui->Mul, '*');
    connect(ui->Mul, SIGNAL(clicked()), operationMap, SLOT(map()));
    operationMap->setMapping(ui->Div, '/');
    connect(ui->Div, SIGNAL(clicked()), operationMap, SLOT(map()));


    for (int i = 0; i < 9; i++)
        ui->gridLayout->addWidget(buttons[i + 1], i / 3, i % 3);
    ui->gridLayout->addWidget(buttons[0], 3, 0);
    ui->gridLayout->addWidget(buttons[10], 3, 1);
    ui->gridLayout->addWidget(buttons[11], 3, 2);
}


int Calc(int i1, int i2, char operation)
{
    int fail = 0;
    switch (operation)
    {
    case '+':
        return i1 + i2;
    case '-':
        return i1 - i2;
    case '*':
        return i1 * i2;
    case '/':
        if (i2 != 0)
            return i1 / i2;
    }
    return fail;
}

void MainWindow::numer(int i)
{
    if (ui->lineEdit->text().toInt() == 0)
        if (i != 0)
            ui->lineEdit->clear();
        else
            return;
    if (valueChanged)
    {
        ui->lineEdit->clear();
        valueChanged = false;
    }
   ui->lineEdit->setText(ui->lineEdit->text() + QString::number(i));
}

void MainWindow::operations(int i)
{
    switch (i)
    {
    case '+':
    case '*':
    case '/':
    case '-':
        arg = Calc(arg, ui->lineEdit->text().toInt(), operation);
        ui->lineEdit->setText(QString::number(arg));
        valueChanged = true;
        operation = i;
        break;
    case 'C':
        ui->lineEdit->setText("0");
        arg = 0;
        operation = '+';
        valueChanged = false;
        break;
    case '=':
       arg = Calc(arg, ui->lineEdit->text().toInt(), operation);
       ui->lineEdit->setText(QString::number(arg));
       valueChanged = true;
       arg = 0;
       operation = '+';
       break;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

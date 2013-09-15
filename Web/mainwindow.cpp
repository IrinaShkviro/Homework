#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , alreadyInfected("")
{
    ui->setupUi(this);
    ui->network->setTitle("");
    createGroupBox();
}

void MainWindow::createGroupBox()
{
    labels[0] = new QLabel("Count of comps in netWork", this);
    ui->myNetwork->addWidget(labels[0], 0, 0);

    labels[1] = new QLabel("Numbers of infected comps", this);
    ui->myNetwork->addWidget(labels[1], 1, 0);

    textEdit[0] = new QTextEdit("0", this);
    textEdit[0]->setEnabled(false);
    ui->myNetwork->addWidget(textEdit[0], 0, 1);

    textEdit[1] = new QTextEdit("", this);
    textEdit[1]->setEnabled(false);
    ui->myNetwork->addWidget(textEdit[1], 1, 1);

    infect = new QPushButton("Try to infect a computer", this);
    ui->myNetwork->addWidget(infect, 2, 0);
    connect(infect, SIGNAL(clicked()), this, SLOT(tryToInfect()));

    newVirus = new QPushButton("Send new virus at network", this);
    ui->myNetwork->addWidget(newVirus, 2, 1);
    connect(newVirus, SIGNAL(clicked()), this, SLOT(sendNewVirus()));
}

void MainWindow::tryToInfect()
{
    emit wantMoreIllnesses();
}

void MainWindow::sendNewVirus()
{
    emit emitNewVirus();
}

void MainWindow::showCompCountChanges(int count)
{

    textEdit[0]->setText(QString::number(count));
}

void MainWindow::showInfectCompsChanges(int justInfectedId)
{
    if (alreadyInfected.isEmpty()) {
        alreadyInfected += QString::number(justInfectedId + 1);
    }
    else {
        alreadyInfected += "," + QString::number(justInfectedId + 1);
    }
    textEdit[1]->setText(alreadyInfected);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , alreadyInfected("")
  , step(0)
  , lastAction("")
  , result("")
  , triedId("")
{
    ui->setupUi(this);
    ui->network->setTitle("");
    createGroupBox();
}

void MainWindow::createGroupBox()
{
    labels[0] = new QLabel("Count of comps in netWork", this);
    labels[1] = new QLabel("Numbers of infected comps", this);
    labels[2] = new QLabel("Step number", this);
    labels[3] = new QLabel("Last action was", this);
    labels[4] = new QLabel("Result is", this);
    labels[5] = new QLabel("I tried to infect number", this);
    for (int i = 0; i < countOfLabels; i++) {
        ui->myNetwork->addWidget(labels[i], i, 0);
    }

    textEdit[0] = new QTextEdit("0", this);
    textEdit[1] = new QTextEdit("", this);
    textEdit[2] = new QTextEdit("0", this);
    textEdit[3] = new QTextEdit("", this);
    textEdit[4] = new QTextEdit("", this);
    textEdit[5] = new QTextEdit("", this);
    for (int i = 0; i < countOfLabels; i++) {
        textEdit[i]->setEnabled(false);
        ui->myNetwork->addWidget(textEdit[i], i, 1);
    }

    infect = new QPushButton("Try to infect a computer", this);
    ui->myNetwork->addWidget(infect, countOfLabels, 0);
    connect(infect, SIGNAL(clicked()), this, SLOT(infectButtonClicked()));

    newVirus = new QPushButton("Send new virus at network", this);
    ui->myNetwork->addWidget(newVirus, countOfLabels, 1);
    connect(newVirus, SIGNAL(clicked()), this, SLOT(newVirusButtonClicked()));
}

void MainWindow::infectButtonClicked()
{
    lastAction = "tried to infect random comp";
    updateStep();
    updateResult();
    emit wantMoreIllnesses();
}

void MainWindow::newVirusButtonClicked()
{
    lastAction = "tried to create new virus";
    updateStep();
    emit emitNewVirus();
}

void MainWindow::assessSuccess(bool isSuccess)
{
    if (isSuccess) {
        result = true;
    } else {
        result = false;
    }
    updateResult();
}

void MainWindow::triedToInfect(int idComp)
{
    triedId += QString::number(idComp + 1);
    textEdit[5]->setText(triedId);

}

void MainWindow::updateStep()
{
    result = false;
    triedId = "";
    textEdit[2]->setText(QString::number(++step));
    textEdit[3]->setText(lastAction);
    textEdit[5]->setText("");
}

void MainWindow::updateResult()
{
    if (result) {
        textEdit[4]->setText("success");
    } else {
        textEdit[4]->setText("unsuccess");
    }
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

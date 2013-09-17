#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void showCompCountChanges(int count);
    void showInfectCompsChanges(int justInfectedId);
    void infectButtonClicked();
    void newVirusButtonClicked();
    void assessSuccess(bool isSuccess);
    void triedToInfect(int idComp);

signals:
    void wantMoreIllnesses();
    void emitNewVirus();

private:
    Ui::MainWindow *ui;
    const int countOfLabels = 6;
    QLabel* labels[6];
    QTextEdit* textEdit[6];
    QPushButton* infect;
    QPushButton* newVirus;
    QString alreadyInfected;
    int step;
    QString lastAction;
    QString triedId;
    bool result;

    void createGroupBox();
    void updateStep();
    void updateResult();
};

#endif // MAINWINDOW_H

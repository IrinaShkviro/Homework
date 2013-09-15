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
    void tryToInfect();
    void sendNewVirus();

signals:
    void wantMoreIllnesses();
    void emitNewVirus();

private:
    Ui::MainWindow *ui;
    QLabel* labels[2];
    QTextEdit* textEdit[2];
    QPushButton* infect;
    QPushButton* newVirus;
    QString alreadyInfected;

    void createGroupBox();
};

#endif // MAINWINDOW_H

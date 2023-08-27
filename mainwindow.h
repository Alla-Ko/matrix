
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLabel>
#include <QMessageBox>
#include "help.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Paint_xo();

private slots:
    void on_action_2_triggered();

    void on_action_8_triggered();

    void on_action_3_triggered();

    void on_action_6_triggered();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_action_triggered();

    void on_action_7_triggered();

private:
    Ui::MainWindow *ui;
    QLabel* labels[4][4];
    QList<QList <char>> sp={
                             {' ',' ',' ',' '},
                             {' ',' ',' ',' '},
                             {' ',' ',' ',' '},
                             {' ',' ',' ',' '},
                             };
    };





#endif // MAINWINDOW_H

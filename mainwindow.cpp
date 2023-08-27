
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ui_help.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    labels[0][0]=ui->label00;
    labels[0][1]=ui->label01;
    labels[0][2]=ui->label02;
    labels[0][3]=ui->label03;
    labels[1][0]=ui->label10;
    labels[1][1]=ui->label11;
    labels[1][2]=ui->label12;
    labels[1][3]=ui->label13;
    labels[2][0]=ui->label20;
    labels[2][1]=ui->label21;
    labels[2][2]=ui->label22;
    labels[2][3]=ui->label23;
    labels[3][0]=ui->label30;
    labels[3][1]=ui->label31;
    labels[3][2]=ui->label32;
    labels[3][3]=ui->label33;

    Paint_xo();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Paint_xo(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(sp[i][j]==' ')labels[i][j]->clear();
            if(sp[i][j]=='x')labels[i][j]->setPixmap(QPixmap(":/new/prefix1/src/x.png"));
            if(sp[i][j]=='o')labels[i][j]->setPixmap(QPixmap(":/new/prefix1/src/o.png"));
        }
    }

}



void MainWindow::on_action_2_triggered()
{
    int x_count=rand()%8+1;
    int o_count=x_count-rand()%2;
    int space_count=16-x_count-o_count;
    int r;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(x_count>0&&o_count>0&&space_count>0){
                r=rand()%3;
                if(r==0){
                    sp[i][j]=' ';
                    space_count--;
                }
                if(r==1) {
                    sp[i][j]='x';
                    x_count--;
                }
                if(r==2) {
                    sp[i][j]='o';
                    o_count--;
                }
            }
            if(x_count>0&&o_count>0&&space_count==0){
                r=rand()%2;
                if(r==0) {
                    sp[i][j]='x';
                    x_count--;
                }
                if(r==1) {
                    sp[i][j]='o';
                    o_count--;
                }
            }
            if(x_count==0&&o_count>0&&space_count>0){
                r=rand()%2;
                if(r==0) {
                    sp[i][j]=' ';
                    space_count--;
                }
                if(r==1) {
                    sp[i][j]='o';
                    o_count--;
                }
            }
            if(x_count>0&&o_count==0&&space_count>0){
                r=rand()%2;
                if(r==0) {
                    sp[i][j]='x';
                    x_count--;
                }
                if(r==1) {
                    sp[i][j]=' ';
                    space_count--;
                }
            }
            if(x_count==0&&o_count==0&&space_count>0){
                sp[i][j]=' ';
                space_count--;
            }
            if(x_count==0&&o_count>0&&space_count==0){
                sp[i][j]='o';
                o_count--;
            }
            if(x_count>0&&o_count==0&&space_count==0){
                sp[i][j]='x';
                x_count--;
            }
        }
    }
    Paint_xo();
}


void MainWindow::on_action_8_triggered()
{
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(sp[i][j]!=' '){
                if(sp[i][j]=='x')
                    sp[i][j]='o';
                else sp[i][j]='x';
            }
        }
    }
    Paint_xo();
}


void MainWindow::on_action_3_triggered()
{
    QList<QList <char>> sp1={
                             {' ',' ',' ',' '},
                             {' ',' ',' ',' '},
                             {' ',' ',' ',' '},
                             {' ',' ',' ',' '},
                             };

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            sp1[i][j]=sp[j][i];

        }
    }
    sp=sp1;
    Paint_xo();
}


void MainWindow::on_action_6_triggered()
{
    QList<QList <char>> sp1={
                              {' ',' ',' ',' '},
                              {' ',' ',' ',' '},
                              {' ',' ',' ',' '},
                              {' ',' ',' ',' '},
                              };

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            sp1[i][j]=sp[4-j-1][4-i-1];

        }
    }
    sp=sp1;
    Paint_xo();
}


void MainWindow::on_action_4_triggered()
{
    QList<QList <char>> sp1={
                              {' ',' ',' ',' '},
                              {' ',' ',' ',' '},
                              {' ',' ',' ',' '},
                              {' ',' ',' ',' '},
                              };

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            sp1[i][j]=sp[4-i-1][j];

        }
    }
    sp=sp1;
    Paint_xo();
}


void MainWindow::on_action_5_triggered()
{
    QList<QList <char>> sp1={
                              {' ',' ',' ',' '},
                              {' ',' ',' ',' '},
                              {' ',' ',' ',' '},
                              {' ',' ',' ',' '},
                              };

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            sp1[i][j]=sp[i][4-j-1];

        }
    }
    sp=sp1;
    Paint_xo();
}


void MainWindow::on_action_triggered()
{
    switch( QMessageBox::question(
        this,
        tr("Exit"),
        tr("Are you sure?"),

        QMessageBox::Yes |
            QMessageBox::Cancel ) )
    {
    case QMessageBox::Yes:
        QApplication::quit();;
        break;
    case QMessageBox::Cancel:
        break;
    default:
        break;
    }
}


void MainWindow::on_action_7_triggered()
{
    help window;
    window.ui->label_hor->setPixmap(QPixmap(":/new/prefix1/src/1.png"));
    window.ui->label_vert->setPixmap(QPixmap(":/new/prefix1/src/2.png"));
    window.ui->label_tr->setPixmap(QPixmap(":/new/prefix1/src/3.png"));
    window.ui->label_tr_b->setPixmap(QPixmap(":/new/prefix1/src/4.png"));
    window.ui->label_prot->setPixmap(QPixmap(":/new/prefix1/src/5.png"));
    window.ui->label_zap->setPixmap(QPixmap(":/new/prefix1/src/new.png"));
    window.setModal(true);
    window.exec();

}


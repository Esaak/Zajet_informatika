#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btdeterminant,SIGNAL(clicked()),this, SLOT(Gaussd()));
    connect(ui->btrank,SIGNAL(clicked()),this, SLOT(Gaussr()));
    connect(ui->btinverse,SIGNAL(clicked()),this, SLOT(inversed()));
    connect(ui->bttransponse,SIGNAL(clicked()),this,SLOT(transponsed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*MainWindow::MainWindow(unsigned int height, unsigned int weight) : height(height),weight(weight) {
    if(weight ==0 || height==0){
        return;
    }
}*/
MainWindow& MainWindow::operator= (const MainWindow& submatrix) {
        if (this == &submatrix) {
            return *this;
        } else {
            height = submatrix.height;
            weight = submatrix.weight;
            for (unsigned int i = 0; i < height; i++) {
                for (unsigned int j = 0; j < weight; j++) {
                    matrix[i][j] = submatrix.matrix[i][j];
                }
            }
            det = submatrix.det;
            rank = submatrix.rank;
            return *this;
            }
        }
/*MainWindow::MainWindow(const MainWindow& submatrix): MainWindow(submatrix.height, submatrix.weight){
    for (unsigned int i = 0; i < height; i++) {
        for (unsigned int j = 0; j < weight; j++) {
            matrix[i][j] =submatrix.matrix[i][j];
        }
    }
}*/

void MainWindow::input(MainWindow& new_matrix,const double *mass ) {
    for (unsigned int i = 0; i < new_matrix.height; i++) {
        for (unsigned int j = 0; j < new_matrix.weight; j++) {
            new_matrix.matrix[i][j] = *(mass + j + i * new_matrix.weight);
        }
    }
}
void MainWindow::Gauss( MainWindow& submatrix) {
        double new_matrix[3][3];
        for (unsigned int i = 0; i < submatrix.height; i++) {
            for (unsigned int j = 0; j < submatrix.weight; j++) {
                new_matrix[i][j] = submatrix.matrix[i][j];
            }
        }
        unsigned int i;//weight
        unsigned int j;//height
        unsigned int p = 0;//счетчик куда перемещать строку
        int sign=0;
        for (i = 0; i < submatrix.weight; i++) {
            if(i==submatrix.weight-1 && j == submatrix.height - 1){
                break;
            }
            for (j = p; j < submatrix.height; j++) {
                if(i==submatrix.weight-1 && j == submatrix.height - 1){
                    break;
                }
                if (new_matrix[j][i] != 0) {
                    double tmp_rows[submatrix.weight];
                    if(j!=p) {
                        for (unsigned int t = i; t < submatrix.weight; t++) {
                            tmp_rows[t] = new_matrix[j][t];
                            new_matrix[j][t] = new_matrix[p][t];
                            new_matrix[p][t] = tmp_rows[t];
                        }//переставил строки местами
                        sign++;
                    }
                    for (unsigned int qw = p+1; qw < submatrix.height; qw++) {
                        double new_p1i = new_matrix[qw][i];
                        for (unsigned int q = i; q < submatrix.weight; q++) {
                            new_matrix[qw][q] -= new_matrix[p][q] *(new_p1i/new_matrix[p][i]);
                        }
                    }
                    p++;
                }
            }
        }
        for(unsigned int i1 =0; i1<submatrix.height; i1++){
            for(unsigned int j1=0; j1<submatrix.weight; j1++){
                if(new_matrix[i1][j1]!=0){
                    submatrix.rank++;
                    break;
                }
            }
        }
        if(submatrix.weight == submatrix.height){
            if(sign%2==0){
                submatrix.det =1;
            }
            else{
                submatrix.det =-1;
            }
            for(unsigned int d=0; d<submatrix.weight; d++){
                submatrix.det *=new_matrix[d][d];
            }
        }
    }

void MainWindow:: transponse(MainWindow &submatrix){
    if(submatrix.height ==0 ||submatrix.weight ==0){
        return;
    }
    MainWindow new_submatrix;
    if(submatrix.weight == submatrix.height){
        for(unsigned int i=0; i<submatrix.height; i++){
            for(unsigned int j=1+i; j<submatrix.height; j++){
                double tmp = submatrix.matrix[i][j];
                new_submatrix.matrix[i][j] = submatrix.matrix[j][i];
                new_submatrix.matrix[j][i] = tmp;
            }
        }
        for(unsigned int i=0; i<submatrix.weight; i++){
            new_submatrix.matrix[i][i]=submatrix.matrix[i][i];
        }
        for(unsigned int i=0; i<3; i++){
            for(unsigned int j=0;j<3; j++){
                submatrix.matrix[i][j] = new_submatrix.matrix[i][j];
            }
        }
    }
}

void MainWindow::  inverse(MainWindow &submatrix){
    if((submatrix.height != submatrix.weight) || submatrix.height ==0){
        return;
    }
    MainWindow::Gauss(submatrix);
    if(submatrix.det ==0){
        return;
    }

    else{
        MainWindow inmatrix;
        MainWindow tmp_matrix;
        for(unsigned int i=0; i<inmatrix.height; i++){
            for(unsigned int j=0; j<inmatrix.weight; j++){
                unsigned int i_tmp=0;
                for(unsigned int i1=0; i1<inmatrix.height-1;i1++){
                    unsigned int j_tmp=0;
                    for(unsigned int j1=0; j1<inmatrix.weight-1; j1++){
                        if(i_tmp==i || j_tmp==j){
                            if(i_tmp==i  && i_tmp ==i1){
                                i_tmp++;
                            }
                            if(j_tmp == j && j_tmp ==j1){
                                j_tmp++;
                            }
                        }
                        tmp_matrix.matrix[i1][j1] = submatrix.matrix[i_tmp][j_tmp];
                        j_tmp++;
                    }
                    i_tmp++;
                }
                MainWindow::Gauss(tmp_matrix);
                if((i+j+2)%2==0){
                    inmatrix.matrix[i][j]=tmp_matrix.det;
                    inmatrix.matrix[i][j]=inmatrix.matrix[i][j]/submatrix.det;
                }
                else{
                    inmatrix.matrix[i][j]=-tmp_matrix.det;
                    inmatrix.matrix[i][j]=inmatrix.matrix[i][j]/submatrix.det;
                }
            }
        }
        transponse(inmatrix);
        for(unsigned int i=0; i<3; i++){
            for(unsigned int j=0; j<3;j++){
                submatrix.matrix[i][j]=inmatrix.matrix[i][j];
            }
        }
        return;
    }
}
void MainWindow::Gaussd()
{
    QPushButton *button = (QPushButton *)sender();
    double mass[9];
    mass[0]=(ui->li1x1->text().toDouble());
    mass[1]=(ui->li1x2->text().toDouble());
    mass[2]=(ui->li1x3->text().toDouble());
    mass[3]=(ui->li2x1->text().toDouble());
    mass[4]=(ui->li2x2->text().toDouble());
    mass[5]=(ui->li2x3->text().toDouble());
    mass[6]=(ui->li3x1->text().toDouble());
    mass[7]=(ui->li3x2->text().toDouble());
    mass[8]=(ui->li3x3->text().toDouble());
    MainWindow submatrix;
    submatrix.input(submatrix, mass);
    submatrix.Gauss(submatrix);

        QString det = QString::number(submatrix.det);
        ui->lidet->setText(det);
    }
void MainWindow::Gaussr()
{
    QPushButton *button = (QPushButton *)sender();
    double mass[9];
    mass[0]=(ui->li1x1->text().toDouble());
    mass[1]=(ui->li1x2->text().toDouble());
    mass[2]=(ui->li1x3->text().toDouble());
    mass[3]=(ui->li2x1->text().toDouble());
    mass[4]=(ui->li2x2->text().toDouble());
    mass[5]=(ui->li2x3->text().toDouble());
    mass[6]=(ui->li3x1->text().toDouble());
    mass[7]=(ui->li3x2->text().toDouble());
    mass[8]=(ui->li3x3->text().toDouble());
    MainWindow submatrix;
    submatrix.input(submatrix, mass);
    submatrix.Gauss(submatrix);
        QString rank = QString::number(submatrix.rank);
        ui->lidet->setText(rank);
    }
void MainWindow::inversed(){
    QPushButton *button = (QPushButton *)sender();
    double mass[9];
    mass[0]=(ui->li1x1->text().toDouble());
    mass[1]=(ui->li1x2->text().toDouble());
    mass[2]=(ui->li1x3->text().toDouble());
    mass[3]=(ui->li2x1->text().toDouble());
    mass[4]=(ui->li2x2->text().toDouble());
    mass[5]=(ui->li2x3->text().toDouble());
    mass[6]=(ui->li3x1->text().toDouble());
    mass[7]=(ui->li3x2->text().toDouble());
    mass[8]=(ui->li3x3->text().toDouble());
    MainWindow submatrix;
    MainWindow qwmatrix;
    submatrix.input(submatrix, mass);
    submatrix.inverse(submatrix);
    QString a1 = QString::number(submatrix.matrix[0][0], 'f',4);
    ui->li1x1->setText(a1);
    QString a2 = QString::number(submatrix.matrix[0][1], 'f',4);
    ui->li1x2->setText(a2);
    QString a3 = QString::number(submatrix.matrix[0][2], 'f',4);
    ui->li1x3->setText(a3);
    QString a4 = QString::number(submatrix.matrix[1][0], 'f',4);
    ui->li2x1->setText(a4);
    QString a5 = QString::number(submatrix.matrix[1][1], 'f',4);
    ui->li2x2->setText(a5);
    QString a6 = QString::number(submatrix.matrix[1][2], 'f',4);
    ui->li2x3->setText(a6);
    QString a7 = QString::number(submatrix.matrix[2][0], 'f',4);
    ui->li3x1->setText(a7);
    QString a8 = QString::number(submatrix.matrix[2][1], 'f',4);
    ui->li3x2->setText(a8);
    QString a9 = QString::number(submatrix.matrix[2][2], 'f',4);
    ui->li3x3->setText(a9);
}
void MainWindow:: transponsed(){
    QPushButton *button = (QPushButton *)sender();
    double mass[9];
    mass[0]=(ui->li1x1->text().toDouble());
    mass[1]=(ui->li1x2->text().toDouble());
    mass[2]=(ui->li1x3->text().toDouble());
    mass[3]=(ui->li2x1->text().toDouble());
    mass[4]=(ui->li2x2->text().toDouble());
    mass[5]=(ui->li2x3->text().toDouble());
    mass[6]=(ui->li3x1->text().toDouble());
    mass[7]=(ui->li3x2->text().toDouble());
    mass[8]=(ui->li3x3->text().toDouble());
    MainWindow submatrix;
    submatrix.input(submatrix, mass);
    submatrix.transponse(submatrix);
    QString a1 = QString::number(submatrix.matrix[0][0], 'f',4);
    ui->li1x1->setText(a1);
    QString a2 = QString::number(submatrix.matrix[0][1], 'f',4);
    ui->li1x2->setText(a2);
    QString a3 = QString::number(submatrix.matrix[0][2], 'f',4);
    ui->li1x3->setText(a3);
    QString a4 = QString::number(submatrix.matrix[1][0], 'f',4);
    ui->li2x1->setText(a4);
    QString a5 = QString::number(submatrix.matrix[1][1], 'f',4);
    ui->li2x2->setText(a5);
    QString a6 = QString::number(submatrix.matrix[1][2], 'f',4);
    ui->li2x3->setText(a6);
    QString a7 = QString::number(submatrix.matrix[2][0], 'f',4);
    ui->li3x1->setText(a7);
    QString a8 = QString::number(submatrix.matrix[2][1], 'f',4);
    ui->li3x2->setText(a8);
    QString a9 = QString::number(submatrix.matrix[2][2], 'f',4);
    ui->li3x3->setText(a9);
}




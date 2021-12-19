#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    unsigned int height = 3;
    unsigned int weight = 3;
    double matrix[3][3];
    unsigned int rank=0;
    double det=0;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MainWindow& operator= (const MainWindow& submatrix);
    //MainWindow(const MainWindow& submatrix);
    //MainWindow(unsigned int height, unsigned int weight);
private:
    Ui::MainWindow *ui;
private slots:
    void Gaussd();
    void Gaussr();
    void inversed();
    void Gauss( MainWindow& submatrix);
    void transponse(MainWindow &submatrix);
    void inverse(MainWindow &submatrix);
    void input(MainWindow& new_matrix,const double *mass );
    void transponsed();
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

bool normalOrInterval = false, ok;
int n, mit, it, st;
vector<long double> a;
long double xx, x_a, x_b, w, eps, a_a, a_b, result;
double x_ad;
vector<ia::Interval<long double> > ai;
ia::Interval<long double> xi, wi, epsi, resulti;
QLocale ql(QLocale::German);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBoxN_valueChanged(int arg1)
{
    n = arg1;
    qDebug() << "n:" << n;
}

void MainWindow::on_radioButtonArithmeticNormal_clicked()
{
    normalOrInterval = false;
    qDebug() << "arithmetic:" << normalOrInterval;
}

void MainWindow::on_radioButtonArithmeticInterval_clicked()
{
    normalOrInterval = true;
    qDebug() << "arithmetic:" << normalOrInterval;
}

void MainWindow::on_spinBoxX_a_valueChanged(const QString &arg1)
{
    x_a = ql.toDouble(arg1, &ok);
    qDebug() << arg1.capacity();
    qDebug() << arg1;
    qDebug() << "x_a:" << QString("%1").arg(x_a, 0, 'g', 16);
}

void MainWindow::on_spinBoxX_b_valueChanged(const QString &arg1)
{

}

void MainWindow::on_spinBoxMit_valueChanged(int arg1)
{
    mit = arg1;
    qDebug() << "mit:" << mit;
}

void MainWindow::on_spinBoxEps_valueChanged(const QString &arg1)
{

}

void MainWindow::on_spinBoxAi_a_valueChanged(const QString &arg1)
{

}

void MainWindow::on_spinBoxAi_b_valueChanged(const QString &arg1)
{

}

void MainWindow::on_pushButtonAiAdd_clicked()
{

}

void MainWindow::on_pushButtonAiRemove_clicked()
{

}

void MainWindow::on_pushButtonCount_clicked()
{
    if (normalOrInterval) {
        resulti = NewtonRootsInterval(n,ai,xi,mit,eps,wi,it,st);
    }
    else {
        result = NewtonRootsNormal(n,a,xx,mit,eps,w,it,st);
    }
}



void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    qDebug() << arg1.capacity();
}

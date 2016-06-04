#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "newtonrootsnormal.h"
#include "newtonrootsinterval.h"
#include "Interval.h"
#include <string>
#include <vector>
#include <QDebug>
#include <QLocale>
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QTableWidget>
#include <QValidator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_spinBoxN_valueChanged(int arg1);

    void on_radioButtonArithmeticNormal_clicked();

    void on_radioButtonArithmeticInterval_clicked();

    void on_spinBoxMit_valueChanged(int arg1);

    void on_pushButtonCount_clicked();

    void on_pushButtonAiAdd_clicked();

    void on_pushButtonAiRemove_clicked();

    void on_pushButtonRemoveAll_clicked();

    void on_lineEditX_a_returnPressed();

    void on_lineEditX_b_returnPressed();

    void on_lineEditEps_returnPressed();

    void on_lineEditAi_a_returnPressed();

    void on_lineEditAi_b_returnPressed();

private:
    bool normalOrInterval = false, ok;
    int n = 0, mit = 0, it, st;
    vector<long double> a;
    long double x_a = 0, x_b = 0, w, eps = 1e-16, a_a = 0, a_b = 0, result;
    vector<ia::Interval<long double> > ai;
    ia::Interval<long double> xi, wi, epsi, resulti;

    void clearResults();

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

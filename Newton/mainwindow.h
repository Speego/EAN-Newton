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
#include <QString>

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

    void on_spinBoxX_a_valueChanged(const QString &arg1);

    void on_spinBoxX_b_valueChanged(const QString &arg1);

    void on_spinBoxMit_valueChanged(int arg1);

    void on_pushButtonCount_clicked();

    void on_spinBoxEps_valueChanged(const QString &arg1);

    void on_spinBoxAi_a_valueChanged(const QString &arg1);

    void on_spinBoxAi_b_valueChanged(const QString &arg1);

    void on_pushButtonAiAdd_clicked();

    void on_pushButtonAiRemove_clicked();

    void on_textEdit_textChanged();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

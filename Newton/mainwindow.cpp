#include "mainwindow.h"
#include "ui_mainwindow.h"

QLocale ql(QLocale::German);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList titles;

    setWindowTitle("EAN");
    titles << "a_lewy" << "a_prawy";
    ui->tableWidgetVector->setHorizontalHeaderLabels(titles);
    titles.clear();
    titles << "wynik" << "w" << "it" << "st" << "x.width" << "w.width";
    ui->tableWidgetResults->setVerticalHeaderLabels(titles);

    ui->lineEditX_a->setValidator(new QDoubleValidator(-9999,9999,16,this));
    ui->lineEditX_b->setValidator(new QDoubleValidator(-9999,9999,16,this));
    ui->lineEditEps->setValidator(new QDoubleValidator(-9999,9999,16,this));
    ui->lineEditAi_a->setValidator(new QDoubleValidator(-9999,9999,16,this));
    ui->lineEditAi_b->setValidator(new QDoubleValidator(-9999,9999,16,this));

    ui->tableWidgetVector->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetResults->setEditTriggers(QAbstractItemView::NoEditTriggers);
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

void MainWindow::on_lineEditX_a_returnPressed()
{
    x_a = ql.toDouble(ui->lineEditX_a->text(), &ok);
    qDebug() << ui->lineEditX_a->text();
    qDebug() << "x_a:" << QString("%1").arg(x_a, 0, 'g', 16);
}

void MainWindow::on_lineEditX_b_returnPressed()
{
    x_b = ql.toDouble(ui->lineEditX_b->text(), &ok);
    qDebug() << ui->lineEditX_b->text();
    qDebug() << "x_b:" << QString("%1").arg(x_b, 0, 'g', 16);
}

void MainWindow::on_spinBoxMit_valueChanged(int arg1)
{
    mit = arg1;
    qDebug() << "mit:" << mit;
}

void MainWindow::on_lineEditEps_returnPressed()
{
    eps = ql.toDouble(ui->lineEditEps->text(), &ok);
    qDebug() << ui->lineEditEps->text();
    qDebug() << "eps:" << QString("%1").arg(eps, 0, 'g', 16);
}

void MainWindow::on_lineEditAi_a_returnPressed()
{
    a_a = ql.toDouble(ui->lineEditAi_a->text(), &ok);
    qDebug() << ui->lineEditAi_a->text();
    qDebug() << "a_a:" << QString("%1").arg(a_a, 0, 'g', 16);
}

void MainWindow::on_lineEditAi_b_returnPressed()
{
    a_b = ql.toDouble(ui->lineEditAi_b->text(), &ok);
    qDebug() << ui->lineEditAi_b->text();
    qDebug() << "a_b:" << QString("%1").arg(a_b, 0, 'g', 16);
}

void MainWindow::on_pushButtonAiAdd_clicked()
{
    int field;

    if (a_a <= a_b) {
        ui->tableWidgetVector->insertRow(ui->tableWidgetVector->rowCount());
        field = ui->tableWidgetVector->rowCount() - 1;
        ui->tableWidgetVector->setItem(field, 0, new QTableWidgetItem(QString::number(a_a, 'g', 16)));
        ui->tableWidgetVector->setItem(field, 1, new QTableWidgetItem(QString::number(a_b, 'g', 16)));

        a.push_back(a_a);
        ai.push_back(ia::Interval<long double> (a_a, a_b));
    }
    else QMessageBox::information(this,"ERROR!","a_prawy musi być większe równe od a_lewy!");
}

void MainWindow::on_pushButtonAiRemove_clicked()
{
    if (ui->tableWidgetVector->rowCount() > 0){
        ui->tableWidgetVector->removeRow(ui->tableWidgetVector->rowCount()-1);
        a.pop_back();
        ai.pop_back();
    }
}

void MainWindow::on_pushButtonRemoveAll_clicked()
{
    ui->tableWidgetVector->clearSelection();
    ui->tableWidgetVector->disconnect();
    ui->tableWidgetVector->clearContents();
    ui->tableWidgetVector->setRowCount(0);

    a.clear();
    ai.clear();
}

void MainWindow::on_pushButtonCount_clicked()
{
    if (ui->tableWidgetVector->rowCount() == n+1) {
        if (normalOrInterval) {
            if (x_a <= x_b) {
                clearResults();

                xi = ia::Interval<long double> (x_a, x_b);
                resulti = NewtonRootsInterval(n,ai,xi,mit,eps,wi,it,st);
                ui->tableWidgetResults->setItem(3,0,new QTableWidgetItem(QString::number(st, 'g', 1)));

                if (st == 0 || st == 3) {
                    ui->tableWidgetResults->setItem(0,0,new QTableWidgetItem(QString::number(resulti.a,'e',15)));
                    ui->tableWidgetResults->setItem(0,1,new QTableWidgetItem(QString::number(resulti.b,'e',15)));
                    ui->tableWidgetResults->setItem(1,0,new QTableWidgetItem(QString::number(wi.a,'e',15)));
                    ui->tableWidgetResults->setItem(1,1,new QTableWidgetItem(QString::number(wi.b,'e',15)));
                    ui->tableWidgetResults->setItem(2,0,new QTableWidgetItem(QString::number(it, 'g', 10)));
                    ui->tableWidgetResults->setItem(4,0,new QTableWidgetItem(QString::number(resulti.GetWidth(), 'e', 15)));
                    ui->tableWidgetResults->setItem(5,0,new QTableWidgetItem(QString::number(wi.GetWidth(), 'e', 15)));
                }
            } else QMessageBox::information(this,"ERROR!",tr("x.b musi być większe równe x.a!"));
        } else {
            clearResults();

            result = NewtonRootsNormal(n,a,x_a,mit,eps,w,it,st);
            ui->tableWidgetResults->setItem(3,0,new QTableWidgetItem(QString::number(st, 'g', 1)));

            if (st == 0 || st == 3) {
                ui->tableWidgetResults->setItem(0,0,new QTableWidgetItem(QString::number(result,'e',15)));
                ui->tableWidgetResults->setItem(1,0,new QTableWidgetItem(QString::number(w,'e',15)));
                ui->tableWidgetResults->setItem(2,0,new QTableWidgetItem(QString::number(it, 'g', 10)));
            }
        }
    } else QMessageBox::information(this,"ERROR!","Liczba wierszy w wektorze danych nie odpowiada liczbie n!");
}

void MainWindow::clearResults() {
    ui->tableWidgetResults->clearSelection();
    ui->tableWidgetResults->disconnect();
    ui->tableWidgetResults->clearContents();
}

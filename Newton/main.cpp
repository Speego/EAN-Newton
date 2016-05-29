#include "Interval.h"
#include "mainwindow.h"
#include "newtonrootsnormal.h"
#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    vector<long double> a, b, c, d, e;
    a.push_back(3);a.push_back(-1);a.push_back(-3);a.push_back(1);
    b.push_back(0);b.push_back(0);b.push_back(0);b.push_back(0);b.push_back(0);b.push_back(1);b.push_back(0);b.push_back(-4);b.push_back(0);b.push_back(1);
    c.push_back(2);
    d.push_back(-2);d.push_back(0);d.push_back(1);
    e.push_back(0);e.push_back(0);e.push_back(0);e.push_back(0);e.push_back(0);e.push_back(1);e.push_back(0);e.push_back(-4);e.push_back(0);e.push_back(1);
    int it, st;
    long double w;
    cout.precision(15);
//    cout << NewtonRootsNormal(3,a,2,10,1e-16,w,it,st) << endl;
//    cout << w << endl << it << endl << st << endl << endl;
//    cout << NewtonRootsNormal(9,b,3,20,1e-16,w,it,st) << endl;
//    cout << w << endl << it << endl << st << endl << endl;
//    cout << NewtonRootsNormal(0,c,-1,10,1e-16,w,it,st) << endl;
//    cout << w << endl << it << endl << st << endl << endl;
//    cout << NewtonRootsNormal(2,d,0,10,1e-16,w,it,st) << endl;
//    cout << w << endl << it << endl << st << endl << endl;
//    cout << NewtonRootsNormal(9,e,3,8,1e-16,w,it,st) << endl;
//    cout << w << endl << it << endl << st << endl << endl;

    ia::Interval<long double> *inter = new ia::Interval<long double>(3.0, 3.8);
    cout << inter->GetWidth() << "; " << inter->a << "; " << inter->b << endl;
    *inter = inter->Opposite();
    cout << inter->GetWidth() << "; " << inter->a << "; " << inter->b << endl;
    QApplication aPP(argc, argv);
    MainWindow window;
    window.show();
    return aPP.exec();
}

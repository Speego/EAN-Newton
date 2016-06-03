#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication aPP(argc, argv);
    MainWindow window;
    window.show();
    return aPP.exec();
}



//    a.push_back(3);a.push_back(-1);a.push_back(-3);a.push_back(1);
//    b.push_back(0);b.push_back(0);b.push_back(0);b.push_back(0);b.push_back(0);b.push_back(1);b.push_back(0);b.push_back(-4);b.push_back(0);b.push_back(1);
//    c.push_back(2);
//    d.push_back(-2);d.push_back(0);d.push_back(1);
//    e.push_back(0);e.push_back(0);e.push_back(0);e.push_back(0);e.push_back(0);e.push_back(1);e.push_back(0);e.push_back(-4);e.push_back(0);e.push_back(1);

//    vector<ia::Interval<long double> > ai, bi, ci, di, ei;
//    ai.push_back(ia::Interval<long double>(3,3));ai.push_back(ia::Interval<long double>(-1,-1));ai.push_back(ia::Interval<long double>(-3,-3));ai.push_back(ia::Interval<long double>(1,1));
//    bi.push_back(ia::Interval<long double>(0,0));bi.push_back(ia::Interval<long double>(0,0));bi.push_back(ia::Interval<long double>(0,0));bi.push_back(ia::Interval<long double>(0,0));bi.push_back(ia::Interval<long double>(0,0));
//    bi.push_back(ia::Interval<long double>(1,1));bi.push_back(ia::Interval<long double>(0,0));bi.push_back(ia::Interval<long double>(-4,-4));bi.push_back(ia::Interval<long double>(0,0));bi.push_back(ia::Interval<long double>(1,1));
//    ci.push_back(ia::Interval<long double>(2,2));
//    di.push_back(ia::Interval<long double>(-2,-2));di.push_back(ia::Interval<long double>(0,0));di.push_back(ia::Interval<long double>(1,1));
//    ei.push_back(ia::Interval<long double>(0,0));ei.push_back(ia::Interval<long double>(0,0));ei.push_back(ia::Interval<long double>(0,0));ei.push_back(ia::Interval<long double>(0,0));ei.push_back(ia::Interval<long double>(0,0));
//    ei.push_back(ia::Interval<long double>(1,1));ei.push_back(ia::Interval<long double>(0,0));ei.push_back(ia::Interval<long double>(-4,-4));ei.push_back(ia::Interval<long double>(0,0));ei.push_back(ia::Interval<long double>(1,1));
//    ia::Interval<long double> wi, result;

//    //pierwszy
//    cout << "Normal\n" << NewtonRootsNormal(3,a,2,10,eps,w,it,st) << endl;
//    cout << w << endl << it << endl << st << endl << "Interval\n";
//    result = NewtonRootsInterval(3,ai,ia::Interval<long double>(2,2),10,eps,wi,it,st);
//    cout << result.a << "; " << result.b << endl;
//    cout << wi.a << "; " << wi.b << endl << it << endl << st << endl << endl;

//    //drugi
//    cout << "Normal\n" << NewtonRootsNormal(9,b,3,20,eps,w,it,st) << endl;
//    cout << w << endl << it << endl << st << endl << "Interval\n";
//    result = NewtonRootsInterval(9,bi,ia::Interval<long double>(3,3),20,eps,wi,it,st);
//    cout << result.a << "; " << result.b << endl;
//    cout << wi.a << "; " << wi.b << endl << it << endl << st << endl << endl;

//    //trzeci
//    cout << "Normal\n" << NewtonRootsNormal(0,c,-1,10,eps,w,it,st) << endl;
//    cout << w << endl << it << endl << st << endl << "Interval\n";
//    result = NewtonRootsInterval(0,ci,ia::Interval<long double>(-1,-1),10,eps,wi,it,st);
//    cout << result.a << "; " << result.b << endl;
//    cout << wi.a << "; " << wi.b << endl << it << endl << st << endl << endl;

//    //czwarty
//    cout << "Normal\n" << NewtonRootsNormal(2,d,0,10,eps,w,it,st) << endl;
//    cout << w << endl << it << endl << st << endl << "Interval\n";
//    result = NewtonRootsInterval(2,di,ia::Interval<long double>(0,0),10,eps,wi,it,st);
//    cout << result.a << "; " << result.b << endl;
//    cout << wi.a << "; " << wi.b << endl << it << endl << st << endl << endl;

//    //piaty
//    cout << "Normal\n" << NewtonRootsNormal(9,e,3,8,eps,w,it,st) << endl;
//    cout << w << endl << it << endl << st << endl << "Interval\n";
//    result = NewtonRootsInterval(9,ei,ia::Interval<long double>(3,3),8,eps,wi,it,st);
//    cout << result.a << "; " << result.b << endl;
//    cout << wi.a << "; " << wi.b << endl << it << endl << st << endl << endl;

#include "newtonrootsinterval.h"

using namespace ia;

Interval<long double> NewtonRootsInterval(int n, std::vector<Interval<long double> > a, Interval<long double> x, int mit, long double eps, Interval<long double>& w, int& it, int& st){
    Interval<long double> dw, u, v, xh;
    if (n < 1 || mit < 1)
        st = 1;
    else {
        w = a[n];
        for (int i=n-1; i>=0; i--)
            w = w*x + a[i];
        it = 0;
        if (w.b >= 0 && w.a <= 0)
            st = 0;
        else {
            st = 3;
            do {
                it++;
                w = a[n];
                dw = w;
                for (int i=n-1; i>0; i--) {
                    w = w*x + a[i];
                    dw = dw*x + w;
                }
                w = w*x + a[0];
                if (dw.b >= 0 && dw.a <= 0)
                    st = 2;
                else {
                    xh = x;
                    u = xh.Absolute();
                    x = x - w/dw;
                    v = x.Absolute();
                    if (v.a < u.a && v.b < u.b)
                        v = u;
                    if (v.b >= 0 && v.a <= 0)
                        st = 0;
                    else if (((x-xh).Absolute()/v).b <= eps)
                        st = 0;
                }
            } while (it != mit && st == 3);
        }
    }
    if (st == 0 || st == 3) {
        w = a[n];
        for (int i=n-1; i>=0; i--)
            w = w*x + a[i];
        return x;
    }
    return Interval<long double>(0,0);
}

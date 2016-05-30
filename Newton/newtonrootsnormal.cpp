#include "newtonrootsnormal.h"
#include <iostream>

long double NewtonRootsNormal(int n, std::vector<long double> a, long double x, int mit, long double eps, long double& w, int& it, int& st){
    long double dw, u, v, xh;
    if (n < 1 || mit < 1)
        st = 1;
    else {
        w = a[n];
        for (int i=n-1; i>=0; i--)
            w = w*x + a[i];
        it = 0;
        if (w == 0)
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
                if (dw == 0)
                    st = 2;
                else {
                    xh = x;
                    u = abs(xh);
                    x = x - w/dw;
                    v = abs(x);
                    if (v < u)
                        v = u;
                    if (v == 0)
                        st = 0;
                    else if (abs(x-xh)/v <= eps)
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
    return 0;
}


#ifndef NEWTONROOTSNORMAL_H
#define NEWTONROOTSNORMAL_H

#include <vector>

#define abs(a) (((a)>=0) ? (a) : (-1*(a)))

long double NewtonRootsNormal(int n, std::vector<long double> a, long double x, int mit, long double eps, long double& w, int& it, int& st);

#endif // NEWTONROOTSNORMAL_H

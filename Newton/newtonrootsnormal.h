#ifndef NEWTONROOTSNORMAL_H
#define NEWTONROOTSNORMAL_H

#include <vector>

#define abs(a) (((a)>=0) ? (a) : (-1*(a)))

long double NewtonRootsNormal(int, std::vector<long double>, long double, int, long double, long double&, int&, int&);

#endif // NEWTONROOTSNORMAL_H

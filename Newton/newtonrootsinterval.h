#ifndef NEWTONROOTSINTERVAL_H
#define NEWTONROOTSINTERVAL_H

#include "Interval.h"
#include <vector>

ia::Interval<long double> NewtonRootsInterval(int n, std::vector<ia::Interval<long double> > a, ia::Interval<long double> x, int mit, long double eps, ia::Interval<long double>& w, int& it, int& st);

#endif // NEWTONROOTSINTERVAL_H

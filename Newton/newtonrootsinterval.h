#ifndef NEWTONROOTSINTERVAL_H
#define NEWTONROOTSINTERVAL_H

#include "Interval.h"
#include <vector>

ia::Interval<long double> NewtonRootsInterval(int, std::vector<ia::Interval<long double> >, ia::Interval<long double>, int, ia::Interval<long double>, ia::Interval<long double>&, int&, int&);

#endif // NEWTONROOTSINTERVAL_H

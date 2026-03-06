#include "Triangle.hpp"
#include <cmath>
Triangle::Triangle(double a1, double a2, double a3) {
    l1 = a1;
    l2 = a2;
    l3 = a3;
}

double Triangle::getsquare() {
    double s = (l1 + l2 + l3) / 2;
    return sqrt(s * (s - l1) * (s - l2) * (s - l3));
}
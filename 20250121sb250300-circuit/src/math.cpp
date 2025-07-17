#include <cmath>
#include "math.h"

double pi() {
    return atan(1.0) * 4.0;
}

double circumference(double radius) {
    return 2 * pi() * radius;
}
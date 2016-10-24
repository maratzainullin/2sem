#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "data.h"

void Point::rand(int multiplier) {
    x = std::rand() % multiplier;
    y = std::rand() % multiplier;
}

std::ostream &operator<<(std::ostream &out_stream, const Point &data) {
    out_stream << std::fixed << std::setprecision(1) << "("
               << std::setw(4) << data.x << "; "
               << std::setw(4) << data.y << ")"
               << std::setw(4) << std::fixed << std::setprecision(1) << data.r;
    return out_stream;
}

std::istream &operator>>(std::istream &in_stream, Point &data) {
    std::cout << "Enter data:\n";
    in_stream >> data.x >> data.y;
    return in_stream;
}




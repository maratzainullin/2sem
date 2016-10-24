#ifndef INC_2SEM_DATA_H
#define INC_2SEM_DATA_H

#include <ostream>
#include <stdlib.h>

#define P_MULTIPLIER 100


struct Point {
    int len_of_line = 5;
    double x, y, r;

    Point() : x(0), y(0), r(0) {}

    void rand(int multiplier);

    friend std::ostream &operator<<(std::ostream &out_stream, const Point &data);

    friend std::istream &operator>>(std::istream &in_stream, Point &data);
};


#endif //INC_2SEM_DATA_H

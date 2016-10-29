#ifndef INC_2SEM_DATA_H
#define INC_2SEM_DATA_H

#include <ostream>
#include <string>
#include <stdlib.h>


//Двумерная точка.
struct Point_2D {
    int len_of_line = 5;
    double x, y, r;

    Point_2D() : x(0), y(0), r(0) {}

    static Point_2D frand(int multiplier);

    bool operator!=(Point_2D p);

    friend std::ostream &operator<<(std::ostream &out_stream, const Point_2D &data);

    friend std::istream &operator>>(std::istream &in_stream, Point_2D &data);

};

//Трехмерная точка.
struct Point_3D {
    int len_of_line = 4;
    double x, y, z, r;

    Point_3D() : x(0), y(0), z(0), r(0) {}

    static Point_3D frand(int multiplier);

    bool operator!=(Point_3D p);

    friend std::ostream &operator<<(std::ostream &out_stream, const Point_3D &data);

    friend std::istream &operator>>(std::istream &in_stream, Point_3D &data);

};

//Человек с телефоном.
struct Person {
    int len_of_line = 4;
    long long int telephone_number;
    std::string name;

    Person() : telephone_number(0), name("-") {}

    static Person frand(int multiplier);

    bool operator!=(Person p);

    friend std::ostream &operator<<(std::ostream &out_stream, const Person &data);

    friend std::istream &operator>>(std::istream &in_stream, Person &data);

};



#endif //INC_2SEM_DATA_H
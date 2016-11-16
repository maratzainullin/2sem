#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "data.h"


//Двумерная точка.

Point_2D Point_2D::frand(int multiplier) {
    Point_2D temp;
    temp.x = std::rand() % multiplier;
    temp.y = std::rand() % multiplier;
    return temp;
}

bool Point_2D::operator!=(Point_2D p) {
    return !((x == p.x) and (y == p.y));
}

bool Point_2D::operator==(Point_2D p) {
    return ((x == p.x) and (y == p.y));
}

std::ostream &operator<<(std::ostream &out_stream, const Point_2D &data) {
    out_stream << std::fixed << std::setprecision(1) << "("
               << std::setw(4) << data.x << "; "
               << std::setw(4) << data.y << ")"
               << std::setw(4) << std::fixed << std::setprecision(1);
    return out_stream;
}

std::istream &operator>>(std::istream &in_stream, Point_2D &data) {
    std::cout << "Enter data:\n";
    in_stream >> data.x >> data.y;
    return in_stream;
}


//Трехмерная точка.

Point_3D Point_3D::frand(int multiplier) {
    Point_3D temp;
    temp.x = std::rand() % multiplier;
    temp.y = std::rand() % multiplier;
    temp.z = std::rand() % multiplier;
    return temp;
}

bool Point_3D::operator!=(Point_3D p) {
    return (x != p.x) and (y != p.y) and (z != p.z);
}

bool Point_3D::operator==(Point_3D p) {
    return (x == p.x) and (y == p.y) and (z == p.z);
}

std::ostream &operator<<(std::ostream &out_stream, const Point_3D &data) {
    out_stream << std::fixed << std::setprecision(1) << "("
               << std::setw(4) << data.x << "; "
               << std::setw(4) << data.y << "; "
               << std::setw(4) << data.z << ")"
               << std::setw(4) << std::fixed << std::setprecision(1) << data.r;
    return out_stream;
}

std::istream &operator>>(std::istream &in_stream, Point_3D &data) {
    std::cout << "Enter data:\n";
    in_stream >> data.x >> data.y;
    return in_stream;
}


//Человек с телефоном.

Person Person::frand(int multiplier) {
    Person temp;
    std::string get_randomStr(int len);
    temp.telephone_number = std::rand() % 100000 + 99999;
    temp.name = get_randomStr(7);
    return temp;
}

bool Person::operator!=(Person p) {
    return (telephone_number != p.telephone_number) and (name != p.name);
}

bool Person::operator==(Person p) {
    return (telephone_number == p.telephone_number) and (name == p.name);
}

std::ostream &operator<<(std::ostream &out_stream, const Person &data) {
    out_stream << "("
               << std::setw(7) << data.name << "; "
               << std::setw(8) << data.telephone_number << ")"
               << std::setw(3);
    return out_stream;
}

std::istream &operator>>(std::istream &in_stream, Person &data) {
    std::cout << "Enter data(name, telephone_number):\n";
    in_stream >> data.name >> data.telephone_number;
    return in_stream;
}

std::string get_randomStr(int len) {
    static std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string result;
    result.resize(len);

    for (int i = 0; i < len; i++)
        result[i] = charset[rand() % charset.length()];

    return result;
}

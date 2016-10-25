#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "data.h"


//Двумерная точка.

void Point_2D::rand(int multiplier) {
    x = std::rand() % multiplier;
    y = std::rand() % multiplier;
}

bool Point_2D::operator!=(Point_2D p) {
    //return (x = p.x) and (y = p.y) ? false : true;
    if ((x == p.x) and (y == p.y))
        return false;
    else
        return true;
}

std::ostream &operator<<(std::ostream &out_stream, const Point_2D &data) {
    out_stream << std::fixed << std::setprecision(1) << "("
               << std::setw(4) << data.x << "; "
               << std::setw(4) << data.y << ")"
               << std::setw(4) << std::fixed << std::setprecision(1) << data.r;
    return out_stream;
}

std::istream &operator>>(std::istream &in_stream, Point_2D &data) {
    std::cout << "Enter data:\n";
    in_stream >> data.x >> data.y;
    return in_stream;
}


//Трехмерная точка.

void Point_3D::rand(int multiplier) {
    x = std::rand() % multiplier;
    y = std::rand() % multiplier;
    z = std::rand() % multiplier;
}

bool Point_3D::operator!=(Point_3D p) {
    //return (x = p.x) and (y = p.y) ? false : true;
    if ((x == p.x) and (y == p.y) and (z == p.z))
        return false;
    else
        return true;
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

void Person::rand(int multiplier) {
    std::string get_randomStr(int len);

    telephone_number = std::rand() % 100000 + 99999;

    name = get_randomStr(7);
}

bool Person::operator!=(Person p) {
    //return (x = p.x) and (y = p.y) ? false : true;
    if ((telephone_number == p.telephone_number) and (name == p.name))
        return false;
    else
        return true;
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
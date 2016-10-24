#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "data.h"

void Point_2D::rand(int multiplier) {
    x = std::rand() % multiplier;
    y = std::rand() % multiplier;
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


void Point_3D::rand(int multiplier) {
    x = std::rand() % multiplier;
    y = std::rand() % multiplier;
    z = std::rand() % multiplier;
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


void Person::rand(int multiplier) {
    std::string get_randomStr(int len);

    telephone_number = std::rand() % 1000000 + 9999999;

    name = get_randomStr(7);
}

std::ostream &operator<<(std::ostream &out_stream, const Person &data) {
    out_stream << "("
               << std::setw(8) << data.name << "; "
               << std::setw(11) << data.telephone_number << ")"
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
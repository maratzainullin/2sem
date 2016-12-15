#include "vector3d.hpp"

#include <cmath>

const vector3d vector3d::X = {1, 0, 0};
const vector3d vector3d::Y = {0, 1, 0};
const vector3d vector3d::Z = {0, 0, 1};
const vector3d vector3d::ZERO = {0, 0, 0};

vector3d::vector3d() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

vector3d::vector3d(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}

vector3d::vector3d(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

double vector3d::length() {
    return sqrt(x*x + y*y + z*z);
}

void vector3d::normalize()
{
    double inv_length = 1.0f / sqrt(x*x + y*y + z*z);
    x*=inv_length;
    y*=inv_length;
    z*=inv_length;
}

vector3d vector3d::operator+(const vector3d &a) {
    double new_x = x + a.x;
    double new_y = y + a.y;
    double new_z = z + a.z;
    return vector3d(new_x, new_y, new_z);
}

vector3d vector3d::operator+(const vector3d &a) const {
    double new_x = x + a.x;
    double new_y = y + a.y;
    double new_z = z + a.z;
    return vector3d(new_x, new_y, new_z);
}

vector3d vector3d::operator-(const vector3d &a) {
    double new_x = x - a.x;
    double new_y = y - a.y;
    double new_z = z - a.z;
    return vector3d(new_x, new_y, new_z);
}

vector3d vector3d::operator-() {
    return vector3d(-x, -y, -z);
}

vector3d vector3d::operator-() const{
    return vector3d(-x, -y, -z);
}

double vector3d::operator*(const vector3d &a) {
    return x*a.x + y*a.y + z*a.z;
}

vector3d operator*(const vector3d &b, const int a) {
    double new_x = b.x * a;
    double new_y = b.y * a;
    double new_z = b.z * a;
    return vector3d(new_x, new_y, new_z);
}

vector3d operator*(const int a, const vector3d &b) {
    double new_x = b.x * a;
    double new_y = b.y * a;
    double new_z = b.z * a;
    return vector3d(new_x, new_y, new_z);
}

vector3d vector3d::operator^(const vector3d &a) {
    double new_x = y * a.z - z * a.y;
    double new_y = a.x * z - x * a.z;
    double new_z = x * a.y - y * a.x;
    return vector3d(new_x, new_y, new_z);
}

vector3d vector3d::operator^(const vector3d &a) const {
    double new_x = y * a.z - z * a.y;
    double new_y = a.x * z - x * a.z;
    double new_z = x * a.y - y * a.x;
    return vector3d(new_x, new_y, new_z);
}

bool operator==(const vector3d &a, const vector3d &b) {
    return b.x == a.x && b.y == a.y && b.z == a.z;
}

bool operator!=(const vector3d &a, const vector3d &b) {
    return b.x != a.x || b.y != a.y || b.z != a.z;
}

std::ostream &operator<<(std::ostream &stream, const vector3d &a) {
    return stream << "{" << a.x << ", " << a.y << ", " << a.z << "}";
}

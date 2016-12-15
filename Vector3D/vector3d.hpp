#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <ostream>

class vector3d {
    friend vector3d operator*(const vector3d &b, const int a);
    friend vector3d operator*(const int a, const vector3d &b);
    friend bool operator==(const vector3d &a, const vector3d &b);
    friend bool operator!=(const vector3d &a, const vector3d &b);
    friend std::ostream &operator<<(std::ostream &stream, const vector3d &a);

public:
    const static vector3d X;
    const static vector3d Y;
    const static vector3d Z;
    const static vector3d ZERO;

    double x;
    double y;
    double z;
    vector3d();
    vector3d(int x, int y, int z);
    vector3d(double x, double y, double z);

    double length();
    void normalize();

    vector3d operator+(const vector3d &a);
    vector3d operator+(const vector3d &a) const;
    vector3d operator-(const vector3d &a);
    vector3d operator-();
    vector3d operator-() const;
    vector3d operator^(const vector3d &a);
    vector3d operator^(const vector3d &a) const;
    double operator*(const vector3d &a);

};

#endif


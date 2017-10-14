// Copyright 2017 Nazarov Aleksandr

#include "include/volume_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>

double Volume::Cube(double a) {
    if (a <= 0)
        throw std::string("error of class \"Volume\": incorrect arguments");
    return pow(a, 3);
}

double Volume::Dodecahedron(double a) {
    if (a <= 0)
        throw std::string("error of class \"Volume\": incorrect arguments");
    return ((pow(a, 3)*(15.0 + 7.0 * sqrt(5.0))) / 4);
}

double Volume::Cylinder(double h, double r) {
    if (h <= 0 || r <= 0)
        throw std::string("error of class \"Volume\": incorrect arguments");
    return M_PI * pow(r, 2) * h;
}

double Volume::Parallelepiped(double S, double h) {
    if (S <= 0 || h <= 0)
        throw std::string("error of class \"Volume\": incorrect arguments");
    return S * h;
}

double Volume::Parallelepiped(double a, double b, double h) {
    if (a <= 0 || b <= 0 || h <= 0)
        throw std::string("error of class \"Volume\": incorrect arguments");
    return a * b * h;
}

double Volume::Parallelepiped(double a, double b, double c, double x) {
    if (a <= 0 || b <= 0 || c <= 0 || sin(x) <= 0)
        throw std::string("error of class \"Volume\": incorrect arguments");
    double res = a * b * c * sin(x);
    return res;
}

double Volume::Pyramid(double S, double h) {
    if (S <= 0 || h <= 0)
        throw std::string("error of class \"Volume\": incorrect arguments");
    return S * h / 3;
}

double Volume::Pyramid(double a, double base_h, double pyramid_h) {
    if (a <= 0 || base_h <= 0 || pyramid_h <= 0)
        throw std::string("error of class \"Volume\": incorrect arguments");
    return a * base_h / 2 * pyramid_h / 3;
}

double Volume::Cone(double h, double r) {
    if (h <= 0 || r <= 0)
        throw std::string("error of class \"Volume\": incorrect arguments");
    return M_PI * pow(r, 2) * h/3;
}

double Volume::Sphere(double r) {
    if (r <= 0)
        throw std::string("error of class \"Volume\": incorrect arguments");
    return 4 / 3 * M_PI * pow(r, 3);
}

double Volume::Ellipsoid(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0)
        throw std::string("error of class \"Volume\": incorrect arguments");
    return 4 / 3 * M_PI * a * b * c;
}

double Volume::Paraboloid(double h, double r) {
    if (h <= 0 || r <= 0)
        throw std::string("error of class \"Volume\": incorrect arguments");
    return M_PI * pow(r, 2) * h / 2;
}

double Volume::RectangularParallelepiped(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0)
        throw std::string("error of class \"Volume\": incorrect arguments");
    return a * b * c;
}

double Volume::Frustum(double r_base_1, double r_base_2, double h) {
    if (r_base_1 <= 0 || r_base_2 <= 0 || h <= 0)
        throw std::string("error of class \"Volume\": incorrect arguments");
    return M_PI * h * (pow(r_base_1, 2) +
        r_base_1 * r_base_2 + pow(r_base_2, 2)) / 3;
}

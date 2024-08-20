#include "shapes.h"

double Shape::getSurfaceArea() {
    return this->surfaceArea;
}

double Shape::getVolume() {
    return this->volume;
}

Cube::Cube(double side) {
    this->side = side;
    this->volume = side * side * side;
    this->surfaceArea = 6 * side * side;
}

Sphere::Sphere(double radius) {
    this->radius = radius;
    this->volume = 4.0 / 3.0 * 3.14 * radius * radius * radius;
    this->surfaceArea = 4 * 3.14 * radius * radius;
}

Piramid::Piramid(double base, double height) {
    this->base = base;
    this->height = height;
    this->volume = 1.0 / 3.0 * base * base * height;
    this->surfaceArea = base * base + 4 * (base * height / 2);
}

Parallelepiped::Parallelepiped(double side1, double side2, double side3) {
    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
    this->volume = side1 * side2 * side3;
    this->surfaceArea = 2 * (side1 * side2 + side1 * side3 + side2 * side3);
}

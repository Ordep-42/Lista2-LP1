#ifndef SHAPES_H
#define SHAPES_H

class Shape {
    public:
        double getVolume();
        double getSurfaceArea();
    protected:
        double volume;
        double surfaceArea;
};

class Sphere : public Shape {
    public:
        Sphere(double radius);
    private:
        double radius;
};

class Cube : public Shape {
    public:
        Cube(double side);
    private:
        double side;
};

class Piramid : public Shape {
    public:
        Piramid(double base, double height);
    private:
        double base;
        double height;
};

class Parallelepiped : public Shape {
    public:
        Parallelepiped(double side1, double side2, double side3);
    private:
        double side1;
        double side2;
        double side3;
};

#endif
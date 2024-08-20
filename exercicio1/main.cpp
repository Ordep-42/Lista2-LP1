#include "shapes.h"
#include <iostream>

void usage() {
    std::cout << "Utilização: calculadora <forma> <parametros>" << std::endl;
    std::cout << "Formas: cubo, esfera, piramide, paralelepipedo" << std::endl;
    std::cout << "Parametros: cubo <aresta>, esfera <raio>, "
        "piramide <base> <altura>, "
        "paralelepipedo <aresta1> <aresta2> <aresta3>" << std::endl;
}

int main(int argc, char const *argv[]) {
    if (argc < 3 or argc > 5) {
        usage();
        return 1;
    }

    std::string shape = argv[1];
    if (shape == "cubo") {
        if (argc != 3) {
            usage();
            return 1;
        }
        double side = std::stod(argv[2]);
        Cube cube(side);
        std::cout << "Volume: " << cube.getVolume() << std::endl;
        std::cout << "Área: " << cube.getSurfaceArea() << std::endl;
    } else if (shape == "esfera") {
        if (argc != 3) {
            usage();
            return 1;
        }
        double radius = std::stod(argv[2]);
        Sphere sphere(radius);
        std::cout << "Volume: " << sphere.getVolume() << std::endl;
        std::cout << "Área: " << sphere.getSurfaceArea() << std::endl;
    } else if (shape == "piramide") {
        if (argc != 4) {
            usage();
            return 1;
        }
        double base = std::stod(argv[2]);
        double height = std::stod(argv[3]);
        Piramid piramid(base, height);
        std::cout << "Volume: " << piramid.getVolume() << std::endl;
        std::cout << "Área: " << piramid.getSurfaceArea() << std::endl;
    } else if (shape == "paralelepipedo") {
        if (argc != 5) {
            usage();
            return 1;
        }
        double side1 = std::stod(argv[2]);
        double side2 = std::stod(argv[3]);
        double side3 = std::stod(argv[4]);
        Parallelepiped paralelepiped(side1, side2, side3);
        std::cout << "Volume: " << paralelepiped.getVolume() << std::endl;
        std::cout << "Área: " << paralelepiped.getSurfaceArea() << std::endl;
    } else {
        usage();
        return 1;
    }
    return 0;
}
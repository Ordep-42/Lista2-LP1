#include "frog.h"
#include "run.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

int main(int argc, char *argv[]) {
    Run run = Run();

    int choice = -1;

    while (choice != 4) {
        system("clear");
        std::cout << "CORRIDA DE SAPOS" << std::endl;
        std::cout << "----------------" << std::endl;
        std::cout << "[ 1 ] - Adicionar Sapos" << std::endl;
        std::cout << "[ 2 ] - Iniciar corrida" << std::endl;
        std::cout << "[ 3 ] - Mostrar informações" << std::endl;
        std::cout << "[ 4 ] - Sair" << std::endl;
        std::cout << "Escolha uma opção:" << std::endl;
        std::cin >> choice;

        std::string nome;
        switch (choice) {
        case 1:
            system("clear");
            std::cout << "Digite o nome do sapinho: " << std::endl;
            std::cin >> nome;
            run.addFrog(nome);
            break;
        case 2:
            system("clear");
            if (run.notEnoughRunners()) {
                std::cout << "Não há corredores suficientes." << std::endl;
                std::cout << "\nPressione Enter para continuar..." << std::endl;
                std::cin.ignore();
                std::cin.get();
                break;
            }

            run.run();
            std::cout << "\nPressione Enter para continuar..." << std::endl;
            std::cin.ignore();
            std::cin.get();

            break;

        case 3:
            system("clear");
            run.showInfo();
            std::cout << "Pressione Enter para continuar..." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        }
    }

    return 0;
}

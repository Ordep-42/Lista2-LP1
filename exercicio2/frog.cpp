#include "frog.h"
#include "run.h"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

Frog::Frog(std::string nome, int id) {
    this->nome = nome;
    this->id = id;

    this->wins = 0;
    this->ties = 0;
    this->loss = 0;

    this->distance = 0;
    this->amountOfJumps = 0;
    this->totalAmountOfJumps = 0;
}

std::string Frog::getName() { return this->nome; }
int Frog::getDistance() { return this->distance; }
int Frog::getJumps() { return this->amountOfJumps; }

void Frog::showInfo() {
    std::cout << "Nome    : " << this->nome << std::endl;
    std::cout << "Vitórias: " << this->wins << std::endl;
    std::cout << "Empates : " << this->ties << std::endl;
    std::cout << "Derrotas: " << this->loss << std::endl;
    std::cout << "Total de pulos: " << this->totalAmountOfJumps << std::endl;
}

void Frog::jump() {
    int jumpLimit = Run::getRunLength() - this->distance;
    this->amountOfJumps += 1;
    this->totalAmountOfJumps += 1;
    this->distance += rand() % jumpLimit + 1;
}

bool Frog::isWinner() {
    if (Run::getRunLength() <= this->distance) {
        return true;
    } else {
        return false;
    }
}

void Frog::addWin() { this->wins++; }
void Frog::addTie() { this->ties++; }
void Frog::addLoss() { this->loss++; }

void Frog::resetRun() {
    this->distance = 0;
    this->amountOfJumps = 0;
}

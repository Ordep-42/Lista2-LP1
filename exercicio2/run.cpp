#include "run.h"
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

int Run::runLength = 100;

Run::Run() {
    this->runners = {};
    this->runLength = 100;
}

void Run::run() {
    this->endRun();

    this->printState();
    std::cout << "Pressione Enter para continuar..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    while (!this->hasWinner()) {
        this->step();
        this->printState();
        std::cout << "Pressione Enter para continuar..." << std::endl;
        std::cin.ignore();
        std::cin.get();
    }

    int winners = this->amountOfWinners();

    switch (winners) {
    case 0:
        std::cout << "Algum erro aconteceu, não houveram vencedores."
                  << std::endl;
        break;
    case 1:
        std::cout << "Temos um vencedor!" << std::endl;
        this->updateWinners();
        break;
    default:
        std::cout << "Ocorreu um empate!" << std::endl;
        this->updateWinners();
        break;
    }

    this->endRun();
}

void Run::showInfo() {
    std::cout << "Tamanho da corrida: " << this->runLength << std::endl;
    std::cout << "Corredores: " << std::endl;
    for (Frog &frog : this->runners) {
        frog.showInfo();
        std::cout << "-------" << std::endl;
    }
}

void Run::printState() {
    system("clear");
    for (Frog &frog : this->runners) {
        std::cout << frog.getName() << " está na posição " << frog.getDistance()
                  << " com " << frog.getJumps() << " pulos." << std::endl;
    }
}

int Run::getRunLength() { return Run::runLength; }

void Run::addFrog(std::string nome) {
    int id = this->runners.size();
    Frog newFrog = Frog(nome, id);
    runners.push_back(newFrog);
}

void Run::step() {
    for (Frog &frog : this->runners) {
        frog.jump();
    }
}

bool Run::notEnoughRunners() {
    if (this->runners.size() < 2) {
        return true;
    }

    return false;
}

bool Run::hasWinner() {
    for (Frog &frog : this->runners) {
        if (frog.isWinner()) {
            return true;
        }
    }
    return false;
}

int Run::amountOfWinners() {
    if (!this->hasWinner()) {
        return 0;
    }

    int winners = 0;

    for (Frog &frog : this->runners) {
        if (frog.isWinner()) {
            winners += 1;
        }
    }

    return winners;
}

void Run::updateWinners() {
    int totalAmountOfWinners = this->amountOfWinners();

    if (totalAmountOfWinners == 0) {
        return;
    }

    for (Frog &frog : this->runners) {
        if (frog.isWinner() && totalAmountOfWinners == 1) {
            frog.addWin();
        } else if (frog.isWinner() && totalAmountOfWinners > 1) {
            frog.addTie();
        } else if (!frog.isWinner()) {
            frog.addLoss();
        }
    }
}

void Run::endRun() {
    for (Frog &frog : this->runners) {
        frog.resetRun();
    }
}

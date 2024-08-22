#ifndef FROG
#define FROG

#include <string>

class Frog {
  public:
    Frog(std::string nome, int id);
    void showInfo();
    void jump();
    bool isWinner();
    void addWin();
    void addTie();
    void addLoss();
    void resetRun();

    std::string getName();
    int getDistance();
    int getJumps();

  private:
    std::string nome;
    int id;
    int distance;
    int amountOfJumps;
    int wins;
    int ties;
    int loss;
    int totalAmountOfJumps;
};

#endif // !FROG

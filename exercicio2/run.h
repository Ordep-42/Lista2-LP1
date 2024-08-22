#ifndef RUN
#define RUN

#include "frog.h"
#include <string>
#include <vector>

class Run {
  private:
    std::vector<Frog> runners;
    static int runLength;

  public:
    Run();

    static int getRunLength();

    void showInfo();
    void printState();

    void run();

    void step();
    void addFrog(std::string);

    bool hasWinner();
    bool notEnoughRunners();
    int amountOfWinners();
    void updateWinners();

    void endRun();
};

#endif // !RUN

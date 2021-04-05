#include "Game.h"

int main() {
    srand (time(0));
    Game UNO(2, 20);
    UNO.play();
    return 0;
}
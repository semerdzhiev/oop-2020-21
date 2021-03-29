#include "Game.h"

int main() {
    srand (time(NULL));
    Game UNO(2, 7);
    UNO.play();
    return 0;
}
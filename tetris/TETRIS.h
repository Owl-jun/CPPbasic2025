#pragma once
#include "GAME.h"
#include <iostream>

struct Block {
    int block[4][4];
    int posX, posY;
    Block();
    ~Block();
};

class TETRIS : public GAME {
private:
    int (*field)[10];
    Block* curBlock;
    void Render();

public:
    void run();

    TETRIS();
    ~TETRIS();
};

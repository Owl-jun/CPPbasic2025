#include "TETRIS.h"

Block::Block() 
    : posX(0)
    , posY(0)
{
    memset(block, 0, sizeof(int) * 4 * 4);
}

Block::~Block() {}

// ========================================

void TETRIS::Render() {
    for (int y = 0; y < 22; y++) {
        for (int x = 0; x < 12; x++) {
            if (x == 0 || x == 11 || y == 0 || y == 21)
                std::cout << "бс";
            else if (field[y - 1][x - 1])
                std::cout << "бр";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void TETRIS::run() { Render(); }

TETRIS::TETRIS()
    : field(new int[20][10])
    , curBlock(new Block)
{
    memset(field, 0, sizeof(int) * 20 * 10);
}

TETRIS::~TETRIS()
{
    delete[] field;
    delete curBlock;
}
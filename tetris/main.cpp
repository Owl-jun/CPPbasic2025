#include "TETRIS.h"

int main()
{
    GAME* CURGAME = new TETRIS;
    GAMESTART(CURGAME);
    
    delete CURGAME;
	return 0;
}
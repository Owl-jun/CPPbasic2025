#pragma once
class GAME {
public:
    virtual void run() = 0;
};

void GAMESTART(GAME* _game)
{
    _game->run();
}
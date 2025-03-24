#include <iostream>

class TETRIS {
private:
    int (*field)[10];
    int (*currentBlock)[4];  // 4x4 형태로 정의된 블록
    int posX, posY;  // 블록의 현재 위치

    void Render()
    {
        for (int y = 0; y < 22; y++) {
            for (int x = 0; x < 12; x++) {
                if (x == 0 || x == 11 || y == 0 || y == 21)
                    std::cout << "■"; // 외벽
                else if (field[y - 1][x - 1])  // 실제 필드는 20x10 (1씩 오프셋 조정)
                    std::cout << "□"; // 고정된 블록
                else
                    std::cout << "  "; // 빈 칸
            }
            std::cout << std::endl;
        }
    }
public:
    TETRIS() 
        : field(new int[20][10])
        , currentBlock(new int[4][4])
        , posX(0)
        , posY(0)
    {
        memset(field, 0, sizeof(int) * 20 * 10);
        Render();
    }
    ~TETRIS()
    {
        delete[] field;
        delete[] currentBlock;
    }
};



int main()
{
    TETRIS tetris;

    
	return 0;
}
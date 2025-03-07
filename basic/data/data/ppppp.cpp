#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> memo;
    int count = total;
    int tempAcc = 0;
    while (true) {
        for (int i = 0; i < num; ++i)
        {
            tempAcc += count - i;
            memo.insert(memo.begin(), count - i);
        }
        if (total == tempAcc) {
            break;
        }
        else { memo.clear(); }
        tempAcc = 0;
        --count;
    }

    return memo;
}

int main() {

    solution(5, 0);
    
    return 0;
}
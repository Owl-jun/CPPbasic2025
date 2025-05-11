#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int namuji = n % w;  // 마지막 줄 남은 박스 수
    int floor = namuji == 0 ? n / w : (n / w) + 1;  // 총 층수

    vector<vector<int>> boxes;
    vector<int> box;

    // 박스 채우기
    for (int i = 0; i < floor; ++i) {
        int limit = (i == floor - 1) ? (namuji == 0 ? w : namuji) : w;

        for (int j = 0; j < limit; ++j) {
            if (i % 2 == 0) {
                box.push_back((w * i) + j + 1);
            }
            else {
                box.push_back((w * i) + limit - j);
            }
        }

        boxes.push_back(box);
        box.clear();
    }

    // num 위치 찾기
    int target_row = -1;
    int target_col = -1;
    for (int i = 0; i < boxes.size(); ++i) {
        auto it = find(boxes[i].begin(), boxes[i].end(), num);
        if (it != boxes[i].end()) {
            target_row = i;
            target_col = distance(boxes[i].begin(), it);
            break;
        }
    }

    // 위에 있는 같은 열에 박스 있는지 체크
    for (int i = target_row; i < boxes.size(); ++i) {
        if (target_col < boxes[i].size()) {
            answer++;
        }
    }

    return answer;
}

int main() {
    cout << solution(22, 6, 8) << endl;   // 3
    cout << solution(13, 3, 6) << endl;   // 4
    cout << solution(10, 5, 10) << endl;  // 1
    cout << solution(12, 5, 11) << endl;  // 1
    cout << solution(3, 3, 2) << endl;    // 1
    cout << solution(7, 3, 7) << endl;    // 1
    return 0;
}

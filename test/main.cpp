#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<tuple<int, int, int>> q; // x, y, depth
    q.push({ 0, 0, 1 });
    visited[0][0] = true;

    int dx[4] = { 0, 0, 1, -1 }; // RIGHT, LEFT, DOWN, UP
    int dy[4] = { 1, -1, 0, 0 };

    while (!q.empty()) {
        auto [x, y, depth] = q.front(); q.pop();

        if (x == n - 1 && y == m - 1) {
            return depth;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && maps[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny, depth + 1 });
                }
            }
        }
    }

    return -1; // 목적지 도달 못함
}


int main() {

    std::cout << solution({ {1,0,1,1,1}
              ,{1,0,1,0,1}
              ,{1,0,1,1,1}
              ,{1,1,1,0,1}
              ,{0,0,0,0,1}
        }) << std::endl;

    return 0;
}
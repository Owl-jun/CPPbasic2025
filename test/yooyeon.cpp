#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    for (int i = 0; i < schedules.size(); ++i) {
        int hour = schedules[i] / 100;
        int min = schedules[i] % 100;
        if ((min + 10) >= 60) { 
            hour = hour + 1 > 23 ? 0 : hour + 1;
            min = (min + 10) - 60;
        }
        else { min += 10; }
        int limit = hour * 100 + min;
        bool niceGuy = true;
        for (int j = 0; j < timelogs[0].size(); ++j) {
            int curDay = ((startday-1 + j) % 7)+1 ;
            if (curDay < 6) {
                niceGuy = timelogs[i][j] <= limit ? true : false;
                if (!niceGuy) { break; }
            }
        }
        if (niceGuy) { answer++; }
    }

    return answer;
}

int main() {


    cout << solution({ 730, 855, 700, 720 }, { {710, 700, 650, 735, 700, 931, 912}, {908, 901, 805, 815, 800, 831, 835}, {705, 701, 702, 705, 710, 710, 711},{707, 731, 859, 913, 934, 931, 905} }, 1) << flush;
    cout << solution({ 730, 855, 700, 720 }, { {710, 700, 650, 735, 700, 931, 912}, {908, 901, 805, 815, 800, 831, 835}, {705, 701, 702, 705, 710, 710, 711},{707, 731, 859, 913, 934, 931, 905} }, 2) << flush;
    cout << solution({ 730, 855, 700, 720 }, { {710, 700, 650, 735, 700, 931, 912}, {908, 901, 805, 815, 800, 831, 835}, {705, 701, 702, 705, 710, 710, 711},{707, 731, 859, 913, 934, 931, 905} }, 3) << flush;

    return 0;
}
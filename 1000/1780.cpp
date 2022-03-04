#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, cann;
int minusCnt, zeroCnt, plusCnt;
vector<vector<int>> paper;
void divide(int startX, int startY, int cann);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        vector<int> temp;
        for(int j = 0; j < n; j++) {
            int input;
            cin >> input;
            temp.push_back(input); 
        }
        paper.push_back(temp);
    }

    divide(0, 0, n);

    cout << minusCnt << endl << zeroCnt << endl << plusCnt << endl;

    return 0;
}

void divide(int startX, int startY, int cann){
    // cout << startX << " " << startY << " " << cann << endl;

    // 종이의 가로 칸수가 1일 때, 즉, 1x1일 때
    if(cann == 1) {
        if(paper[startX][startY] == -1) {
            minusCnt++;
        }
        else if(paper[startX][startY] == 0) {
            zeroCnt++;
        }
        else {
            plusCnt++;
        }

        return ;
    }

    int num = paper[startX][startY];
    bool end = true;
    for(int i = startX; i < startX + cann; i++) {
        for(int j = startY; j < startY + cann; j++) {
            if(paper[i][j] != num) {
                end = false;
                break;
            }
        }
        if(!end) {
            break;
        }
    }


    if(end) {
        if(num == -1) {
            minusCnt++;
        }
        else if(num == 0) {
            zeroCnt++;
        }
        else {
            plusCnt++;
        }
    }
    else {
        int temp = cann / 3;
        divide(startX, startY, temp);
        divide(startX + temp, startY, temp);
        divide(startX + (2 * temp), startY, temp);
        divide(startX, startY + temp, temp);
        divide(startX + temp, startY + temp, temp);
        divide(startX + (2 * temp), startY + temp, temp);
        divide(startX, startY + (2 * temp), temp);
        divide(startX + temp, startY + (2* temp), temp);
        divide(startX + (2 * temp), startY + (2 * temp), temp);
    }

    return ;
}
#include <bits/stdc++.h>

using namespace std;

int check_rank(int data) {
    switch(data) {
        case 6:
            return 1;
        case 5:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
        case 2:
            return 5;
        default:
            return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    // 정렬
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    int zero_cnt = 0;
    int result = 0;
    for(auto lotto: lottos) {
        if(lotto == 0) {
            zero_cnt++;
            continue;
        }
        for(auto num: win_nums) {
            if(num == lotto) {
                cout << num << "\n";
                result++;
                continue;
            }
        }
    }
    
    answer.push_back(check_rank(result + zero_cnt));
    answer.push_back(check_rank(result));
    
    return answer;
}
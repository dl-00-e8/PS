#include <bits/stdc++.h>

using namespace std;

void back_tracking(string input, int depth, int& cnt, char arr[], unordered_map<string, int>& m) {
    if(depth == 5) {
        return;
    }
    
    for(int i = 0; i < 5; i++) {
        input += arr[i];
        cnt++;
        m[input] = cnt;
        back_tracking(input, depth + 1, cnt, arr, m);
        input.pop_back();
    }
}


int solution(string word) {
    char arr[] = {'A', 'E', 'I', 'O', 'U'};
    unordered_map<string, int> m;
    int answer = 0;
    int cnt = 0;
    
    back_tracking("", 0, cnt, arr, m);
    
    if(m.find(word) != m.end()) {
        answer= m[word];
    }
    
    return answer;
}
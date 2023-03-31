#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector<string> v;
    map<string, int> m;
    
    // map container insert
    for(int i = 0; i < clothes.size(); i++) {
        if(m.find(clothes[i][1]) != m.end()) {
           auto iter = m.find(clothes[i][1]);
            iter->second++;
        }
        else {
            m.insert({clothes[i][1], 1});
            v.push_back({clothes[i][1]});
        }
    }
    
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        answer *= iter->second + 1;
    }
    
    return answer - 1;
}

// 각 의상 종류 내에서 옷을 선택을 할 수도, 안할 수도 있다. 따라서 각 의상 종류별로 의상을 고르는 경우의 수는 의상 개수 + 1.
// 모든 의상 종류 내에서 의상을 고르지 않은 경우, 즉 의상을 하나도 고르지 않은 경우는 제거해줘야 한다.
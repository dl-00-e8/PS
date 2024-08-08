#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int arr[51][51];
    int gift_rate[51];
    unordered_map<string, int> um;
    
    memset(arr, 0, sizeof(arr));
    memset(gift_rate, 0, sizeof(gift_rate));
    
   for(int i = 0; i < friends.size(); i++) {
       um[friends[i]] = i + 1;
   }
    
    for(auto gift: gifts) {
        int find_space = gift.find(' ');
        string from_friend = gift.substr(0, find_space);
        string to_friend = gift.substr(find_space+1);
        
        auto from_it = um.find(from_friend);
        auto to_it = um.find(to_friend);
        if (from_it != um.end() && to_it != um.end()) {
            int from_idx = from_it->second;
            int to_idx = to_it->second;
            arr[from_idx][to_idx]++;
            gift_rate[from_idx]++;
            gift_rate[to_idx]--;
        } 
    }
    
    // i가 받는 카운트
    for(int i = 1; i < friends.size() + 1; i++) {
        int result = 0;
        for(int j = 1; j < friends.size() + 1; j++) {
            if(i == j) {
                continue;
            }
            
            if(arr[i][j] == arr[j][i]) {
                if(gift_rate[i] > gift_rate[j]) {
                    result++;
                } 
            } else if(arr[i][j] > arr[j][i]) {
                result++;
            } else {
                continue;
            }
        
        }
        answer = max(answer, result);
    }
    
    return answer;
}
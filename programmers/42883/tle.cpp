#include <bits/stdc++.h>

using namespace std;


int dfs(string number, bool visited[], int now_depth, int idx, int cnt) {
    if(now_depth == cnt) {
        string result = "";
        for(int i = 0; i < number.size(); i++) {
            if(visited[i]) {
                result += number[i];
            }
        }
        return stoi(result);
    }
    int result = 0;
    for(int i = idx; i < number.size(); i++) {
        if(visited[i]) {
            continue;
        }
        
        visited[i] = 1;
        result = max(result, dfs(number, visited, now_depth + 1, i, cnt));
        visited[i] = 0;
    }
    
    return result;
}

string solution(string number, int k) {   
    bool visited[number.size()];
    memset(visited, 0, sizeof(visited));
    
    int answer = dfs(number, visited, 0, 0, number.size() - k);
    
    return to_string(answer);
}
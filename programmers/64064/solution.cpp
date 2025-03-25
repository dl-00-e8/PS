#include <bits/stdc++.h>

using namespace std;

set<string> answer;

void backtracking(int now, int depth, int size, set<int> b_set[], bool visited[]) {
    if(now == depth) {
        string result = "";
        for(int i = 0; i < size; i++) {
            if(visited[i]) {
                result += "1";
            } else {
                result += "0";
            }
        }
        answer.insert(result);
        return;
    }
    
    for(auto idx: b_set[now]) {
        if(visited[idx]) {
            continue;
        }
        
        visited[idx] = true;
        backtracking(now + 1, depth, size, b_set, visited);
        visited[idx] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    set<int> b_set[banned_id.size()];
    bool visited[user_id.size()];
    
    memset(visited, 0, sizeof(visited));
    
    for(int i = 0; i < banned_id.size(); i++) {
        string ban = banned_id[i];
        for(int j = 0; j < user_id.size(); j++) {
            string user = user_id[j];
            
            // 단어 길이가 다른 경우
            if(ban.size() != user.size()) {
                continue;
            } else {
                bool equal = true;
                for(int s = 0; s < ban.size(); s++) {
                    if(ban[s] == '*') {
                        continue;
                    }
                    
                    if(ban[s] != user[s]) {
                        equal = false;
                        break;
                    }
                }
                
                if(equal) {
                    b_set[i].insert(j);
                }
            }
        }
    }
    
    backtracking(0, banned_id.size(), user_id.size(), b_set, visited);
    
    return answer.size();
}
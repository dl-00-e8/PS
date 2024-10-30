#include <bits/stdc++.h>

using namespace std;

int check_diff(string a, string b) {
    int result = 0;
    
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) {
            result++;
        }
    }
    
    return result;
}

int solution(string begin, string target, vector<string> words) {       
    // 찾을 수 없는 경우 확인
    bool can = false;
    for(int i = 0; i < words.size(); i++) {
        if(words[i] == target) {
            can = true;
            break;
        }
    }
    
    if(!can) {
        return 0;
    }
    
    // BFS 진행
    int word_size = words.size();
    unordered_map<string, int> visited;
    queue<string> q;
    
    q.push(begin);    
    visited[begin] = 1;
    while(!q.empty()) {
        string now = q.front();
        q.pop();
        
        for(auto word: words) {
            // 한 개의 알파벳만 차이나는지 확인
            if(check_diff(now, word) <= 1) {
                if(visited[word] == 0) {
                    visited[word] = visited[now] + 1;
                    q.push(word);
                } else {
                    if(visited[word] > visited[now] + 1) {
                        visited[word] = visited[now] + 1;
                        q.push(word);
                    }
                }
                
                // 타겟에 일치하는지 확인
                if(word == target) {
                    return visited[target] - 1;
                }
            }
        }
    }
        
    
    return visited[target] - 1;
}
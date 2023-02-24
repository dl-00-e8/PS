#include <bits/stdc++.h>

using namespace std;

int visited[201];
void dfs(int x);

void dfs(int x, vector<vector<int>> computers) {
    for(int i = 0; i < computers[x].size(); i++) {
        if(computers[x][i] && !visited[i]) {
            visited[i] = visited[x];
            dfs(i, computers);
        }
    }   
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 1;
    
    memset(visited, 0, sizeof(visited));
    
    //i번 노드와 i번 노드 간의 연결 관계는 0으로 변경
    for(int i = 0; i < n; i++) {
        computers[i][i] = 0;
    }
    
    // DFS 진행
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i] = answer;
            dfs(i, computers);
            answer++;
        }
    }
    
    return answer - 1;
}
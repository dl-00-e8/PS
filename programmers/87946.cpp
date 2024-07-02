#include <bits/stdc++.h>

using namespace std;

int backTracking(int idx, int depth, bool visited[], int k, vector<vector<int>> dungeons) {
   int temp = 0;
    
    // 더 이상 접근할 수 있는 던전이 없을 경우 0 반환
    if(depth == dungeons.size()) {
        return 0;
    }
    
    // 필요 피로도 확인 후 접근 불가 시 0 반환
    if(k < dungeons[idx][0]) {
        return 0;
    }

    k -= dungeons[idx][1];
    visited[idx] = true;
    for(int i = 0; i < dungeons.size(); i++) {
        if(!visited[i]) {
            temp = max(temp, backTracking(i, depth + 1, visited, k, dungeons));
        }
    }
    visited[idx] = false;
    
    
    return temp + 1;
}

int solution(int k, vector<vector<int>> dungeons) {
    bool visited[8];
    int answer = -1;
    
    // 방문 여부 배열 0으로 초기화
    memset(visited, 0, sizeof(visited));
 
    // 던전 배열만큼 백트래킹 진행
    for(int i = 0; i < dungeons.size(); i++) {
        answer = max(answer, backTracking(i, 0, visited, k, dungeons));
    }
    
    return answer;
}
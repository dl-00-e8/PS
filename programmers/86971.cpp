#include <bits/stdc++.h>

using namespace std;

int parent[101];

int findParent(int parent[], int x) {
    if(parent[x] != x) {
        return parent[x] = findParent(parent, parent[x]);
    }
    
    return x;
}

void unionParent(int parent[], int a, int b) {
    int pa = findParent(parent, a);
    int pb = findParent(parent, b);
    
    if(pa < pb) {
        parent[pa] = pb;
    }
    else {
        parent[pb] = pa;
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    
    for(int i = 0; i < wires.size(); i++) {        
        // parent 배열 초기화
        for(int k = 1; k < n + 1; k++) {
            parent[k] = k;
        }
        
        // Disjoint set 진행
        for(int j = 0; j < wires.size(); j++) {
            if(i == j) {
                continue;
            }
            
            unionParent(parent, wires[j][0], wires[j][1]);
        }
        
        int fCnt = 1, sCnt = 1;
        int fParent = findParent(parent, wires[i][0]);
        int sParent = findParent(parent, wires[i][1]);
        for(int k = 1; k < n + 1; k++) {
            if(k == wires[i][0] || k == wires[i][1]) {
                continue;
            }
            
            int now = findParent(parent, k);
            if(now == fParent) {
                fCnt++;
            }
            else if(now == sParent) {
                sCnt++;
            }
        }
        
        answer = min(answer, abs(fCnt - sCnt));
    }
    
    return answer;
}
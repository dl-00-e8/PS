#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int distance[n + 1];
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    vector<int> graph[n + 1];
    
    fill(&distance[0], &distance[0] + sizeof(distance) / sizeof(int), INF);
    
    for(int i = 0; i < edge.size(); i++) {
        int first = edge[i][0];
        int second = edge[i][1];
        
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    
    pq.push({0, 1});
    distance[1] = 0;
    while(!pq.empty()) {
        int now = pq.top().second;
        int cost = pq.top().first;
        
        pq.pop();
        
        if(distance[now] < cost) {
            continue;
        }
        
        for(int i = 0; i < graph[now].size(); i++) {
            int next= graph[now][i];
            
            if(distance[next] > distance[now] + 1) {
                distance[next] = distance[now] + 1;
                pq.push({distance[next], next});
            }
        }
    }
    
    int maxCnt = 0;
    for(int i = 1; i < n + 1; i++) {
        if(maxCnt == distance[i]) {
            answer++;   
        }
        else if(maxCnt < distance[i]) {
            maxCnt = distance[i];
            answer = 1;
        }
    }
    
    return answer;
}
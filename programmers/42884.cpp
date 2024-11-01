#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if(a[1] == b[1]) {
        return a[0] > b[0];
    }
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), compare);
    
    int answer = 1;
    int last_camera = routes[0][1];
    for(int idx = 0; idx < routes.size(); idx++) {
        vector<int> route = routes[idx];
        if(route[0] <= last_camera) {
            continue;
        } else {
            answer++;
            last_camera = route[1];
        }
    }
    return answer;
}
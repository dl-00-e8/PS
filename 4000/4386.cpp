#include <bits/stdc++.h>

using namespace std;

#define enld "\n"

int n;
vector<pair<double, double>> graph;
double line[101][101];
int parent[101];
int findParent(int parent[], int x);
void unionParent(int parent[], int a, int b);
double dist(double x1, double x2, double y1, double y2);
double solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        pair<double, double> input;
        cin >> input.first >> input.second;
        graph.push_back(input);
    }

    cout << fixed;
    cout.precision(2);
    cout << solve() << endl;
    cout.unsetf(ios::fixed);

    return 0;
}

int findParent(int parent[], int x) {
    if(parent[x] != x) {
        return parent[x] = findParent(parent, parent[x]);
    }

    return parent[x];
}

void unionParent(int parent[], int a, int b) {
    int pa = findParent(parent, a);
    int pb = findParent(parent, b);

    if(pa < pb) {
        parent[pb] = pa;
    }
    else {
        parent[pa] = pb;
    }
}

double dist(double x1, double x2, double y1, double y2) {
    double result = sqrt(pow(fabs(x2 - x1), 2) + pow(fabs(y2 -y1), 2));

    return result;
}

double solve() {
    pair<double, pair<double, double>> now;
    double result = 0.0;

    priority_queue<pair<double, pair<double, double>>, vector<pair<double, pair<double, double>>>, greater<pair<double, pair<double, double>>>> pq; 

    // 간선 오름차순 정렬
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            line[i + 1][j + 1] = dist(graph[i].first, graph[j].first, graph[i].second, graph[j].second);
            if(line[i + 1][j + 1] == 0) {
                continue;
            }
            pq.push({line[i + 1][j + 1], {i + 1, j + 1}});
        }
    }

    // 부모노드 초기화
    for(int i = 1; i < n + 1; i++) {
        parent[i] = i;
    }

    // 크루스칼 알고리즘
    while(!pq.empty()) {
        now = pq.top();
        pq.pop();

        if(findParent(parent, now.second.first) != findParent(parent, now.second.second)) {
            unionParent(parent, now.second.first, now.second.second);
            result += now.first;
        }   
    }

    return result;
}
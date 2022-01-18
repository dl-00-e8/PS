#include <bits/stdc++.h>

using namespace std;

int n;
int prefixSum[100000];
vector<pair<int, int>> graph;
int distance(int x1, int y1, int x2, int y2);
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x, y;
		
		cin >> x >> y;
		graph.push_back({x, y});
	}
	
	solve();
	
	return 0;
}

int distance(int x1, int y1, int x2, int y2) {
	int dist = 0;
	
	if(x1 >= x2 && y1 >= y2) {
		dist = (x1 - x2) + (y1 - y2);
	}
	else if(x1 < x2 && y1 >= y2) {
		dist = (x2 - x1) + (y1 - y2);
	}
	else if(x1 >= x2 && y1 < y2) {
		dist = (x1 - x2) + (y2 - y1);
	}
	else {
		dist = (x2 - x1) + (y2 - y1);
	}
	
	return dist;
}

void solve() {
	int result, exception;
	
	prefixSum[0] = 0;
	for(int i = 1; i < n; i++) {
		prefixSum[i] = prefixSum[i - 1] + distance(graph[i - 1].first, graph[i - 1].second, graph[i].first, graph[i].second);
	}
	
	result = prefixSum[n - 1];
	for(int i = 1; i < n - 1; i++) {
		exception = prefixSum[i - 1] + distance(graph[i - 1].first, graph[i - 1].second, graph[i + 1].first, graph[i + 1].second) + (prefixSum[n -1] - prefixSum[i + 1]);
		result = min(result, exception);
	}
	
	cout << result << endl;
}
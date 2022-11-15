#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m, k;
int node[10001];
int money[10001];
int parent[10001];
vector<pair<int, int>> graph;
void unionParent(int parent[], int a, int b);
int findParent(int parent[], int x);
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(money, 0, sizeof(money));
	memset(node, 0, sizeof(node));
	memset(parent, 0, sizeof(parent));	
	
	cin >> n >> m >> k;
	for(int i = 1; i < n + 1; i++) {
		cin >> money[i];
		parent[i] = i;
	}
	for(int i = 0; i < m; i++) {
		int v, w;
		cin >> v >> w;
		graph.push_back({v, w});
	}
	
	solve();

	return 0;
}

void unionParent(int parent[], int a, int b) {
	int pa = findParent(parent, a);
	int pb = findParent(parent, b);
	
	if(money[pa] < money[pb]) {
		parent[pb] = pa;
	}
	else {
		parent[pa] = pb;
	}
}

int findParent(int parent[], int x) {
	if(parent[x] != x) {
		return parent[x] = findParent(parent, parent[x]);
	}	
	
	return parent[x];
}

void solve() {
	int result = 0;
	
	for(int i = 0; i < m; i++) {
		int v, w;
		v = graph[i].first;
		w = graph[i].second;
		
		if(findParent(parent, v) != findParent(parent, w)) {
			unionParent(parent, v, w);
		}
	}
	
	for(int i = 1; i < n + 1; i++) {
		int now = findParent(parent, i);
		
		if(!node[now]) {
			result += money[now];
			
			node[now] = true;
		}
	}
	
	if(result > k) {
		cout << "Oh no" << endl;
	}
	else {
		cout << result << endl;
	}
}

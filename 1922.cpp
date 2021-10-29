#include <bits/stdc++.h>

using namespace std;

int n, m;
int parent[1001];
vector<pair<int, pair<int, int>>> graph;
int findParent(int x);
void unionParent(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		graph.push_back(make_pair(cost, make_pair(a, b)));
	}
	
	for(int i = 1; i < n + 1; i++) {
		parent[i] = i;
	}
	
	sort(graph.begin(), graph.end());
	
	int result = 0;
	for(int i = 0; i < m; i++) {
		if(findParent(graph[i].second.first) != findParent(graph[i].second.second)) {
			unionParent(graph[i].second.first, graph[i].second.second);
			result += graph[i].first;	
		}
	}
	
	cout << result << endl;
	
	return 0;
}

int findParent(int x) {
	if(parent[x] != x) {
		parent[x] = findParent(parent[x]);
	}
	
	return parent[x];
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	
	if(a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

/*
vector<pair<int, pair<int, int>>> Edge;
--> Edge.push_back(make_pair(c, make_pair(a, b)));

bool compare(node a, node b) {
	return a.cost > b.cost;
} --> 내림 차순 정렬이였음. 내림 차순 정렬이라서 발생한 문제
*/

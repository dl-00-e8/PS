#include <bits/stdc++.h>

using namespace std;

int n, m, result;
vector<int> graph[501];
bool visited[501] = { false };
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	q.push(1);
	visited[1] = true;
	for(int i = 0; i <= graph[1].size(); i++) {
		int now = q.front();
		q.pop();
		for(int j= 0; j < graph[now].size(); j++) {
			int next = graph[now][j];
			if(visited[next] == false) {
				visited[next] = true;
				q.push(next);
				result++;
			}
		}
	}
	
	cout << result << endl;
	
	return 0;
}
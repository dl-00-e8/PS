#include <bits/stdc++.h>

using namespace std;

int n;
int visited[100001];
vector<int> graph[100001];
queue<int> order;
void bfs();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	for(int i = 0; i < n; i++) {
		int input;
		cin >> input;
		order.push(input);
	}
	
	if(graph[1].size() == 0) {
		cout << 0 << endl;
	}
	else if(order.front() != 1) {
		cout << 0 << endl;
	}
	else {
		bfs();
	}
	
	return 0;
}

void bfs() {
	int now;
	queue<int> q;
	
	q.push(order.front());
	visited[order.front()] = true;
	order.pop();
	while(!q.empty()) {
		now = q.front();
		q.pop();
		
		set<int> s;
		
		for(int i = 0; i < graph[now].size(); i++) {
			if(visited[graph[now][i]]) {
				continue;
			}
			visited[graph[now][i]] = true;
			s.insert(graph[now][i]);
		}
		
		for(int i = 0; i < (int)s.size(); i++) {		
			if(s.find(order.front()) == s.end()) {
				cout << 0 << endl;
				return;
			}
			else {
				q.push(order.front());
				order.pop();
			}
		}
	}
	
	cout << 1 << endl;
}
#include <bits/stdc++.h>

using namespace std;

int n;
struct node {
	int x;
	int y;
	int p;
};
vector<node> graph;
bool enable[201][201]; // 해당 각 IDX의 도달 여부 확인
int distance(int x1, int y1, int x2, int y2);
int bfs(int start);
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		node temp;
		cin >> temp.x >> temp.y >> temp.p;;
		graph.push_back(temp);
	}
	
	solve();
	
	return 0;
}

int distance(int x1, int y1, int x2, int y2) {
	int x, y;
	
	x = abs(x1 - x2);
	x = pow(x, 2);
	y = abs(y1 - y2);
	y = pow(y, 2);
	
	return x + y;
}

int bfs(int start) {
	int cnt, now;
	bool use[n];
	queue<int> q;
	
	memset(use, 0, sizeof(use));
	
	q.push(start);
	use[start] = true;
	cnt = 1;
	while(!q.empty()) {	
		now = q.front();
		q.pop();
		
		for(int j = 0; j < n; j++) {
			if(enable[now][j] == true && use[j] == false) {
				use[j] = true;
				q.push(j);
				cnt++;
			}
		}
	}

	return cnt;
}

void solve() {
	int result;
	
	// 각 도달 가능 여부 초기화
	memset(enable, 0, sizeof(enable));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) {
				enable[i][j] = true;
				continue;
			}
			if((graph[i].p * graph[i].p) >= distance(graph[i].x, graph[i].y, graph[j].x, graph[j].y)) {
				enable[i][j] = true;
			}
		}
	}

	result = -1;
	for(int i = 0 ; i < n; i++) {
		result = max(result, bfs(i));
	}
	
	cout << result << endl;
}
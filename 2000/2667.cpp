#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> graph;
int visited[26][26];
vector<int> cntNum(626);
void bfs(int x, int y, int index);
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		vector<int> temp;
		for(int j = 0; j < n; j++) {
			char input;
			cin >> input;
			temp.push_back(input - '0');
		}
		graph.push_back(temp);
	}
	
	solve();
	
	return 0;
}

void bfs(int x, int y, int index) {
	pair<int, int> now;
	queue<pair<int, int>> q;
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	
	q.push({x, y});
	visited[x][y] = index;
	cntNum[index] += 1;
	while(!q.empty()) {
		now = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			
			if(n <= nx || nx < 0 || n <= ny || ny < 0) {
				continue;
			}
			
			if(graph[nx][ny] == 1 && visited[nx][ny] == 0) {
				visited[nx][ny] = index;
				cntNum[index] += 1;
				q.push({nx, ny});
			}
		}
	}
}

void solve() {
	int cnt = 1;
		
	fill(cntNum.begin(), cntNum.end(), 0);
	memset(visited, 0, sizeof(visited));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(graph[i][j] == 1 && visited[i][j] == 0) {
				bfs(i, j, cnt);
				cnt++;
			}
		}
	}
	
	cntNum.resize(cnt);
	sort(cntNum.begin(), cntNum.end());
	cout << cnt - 1 << endl;
	for(int i = 1; i < cnt; i++) {
		cout << cntNum[i] << endl;
	}
}
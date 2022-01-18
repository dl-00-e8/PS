#include <bits/stdc++.h>

using namespace std;

int n, m, dist, result;
pair<int, int> graph[51][51];
bool visited[51][51];
vector<pair<int, int>> v;
pair<int, int> bfs(int x, int y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 1; i < n + 1; i++) {
		for(int j = 1; j < m + 1; j++) {
			int input;
			cin >> input;
			graph[i][j] = {input, 0};
			if(input > 0) {
				v.push_back({i, j});
			}
		}
	}
	
	dist = 0;
	result = 0;
	if(v.empty()) {
		cout << '0' << endl;
		return 0;
	}
	
	for(int i = 0; i < v.size(); i++) {
		pair<int, int> now = bfs(v[i].first, v[i].second);
		
		if(dist < now.second) {
			dist = now.second;
			result = now.first;
		}
		else if(dist == now.second) {
			result = max(result, now.first);
		}
		else if(dist > now.second) {
			continue;
		}
	}

	cout << result << endl;
	
	return 0;
}

pair<int, int> bfs(int x, int y) {
	int nx, ny;
	pair<int, int> now;
	queue<pair<int, int>> q;
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	pair<int, int> temp[51][51];
	
	copy(&graph[0][0], &graph[0][0] + (51 * 51), &temp[0][0]);
	memset(visited, 0, 51 * 51);
	
	int result = 0;
	int dist = 0;
	
	q.push({x, y});
	int start = graph[x][y].first;
	while(!q.empty()) {
		now = q.front();
		visited[now.first][now.second] = true;
		q.pop();
		
		for(int i = 0; i < 4; i++) {
			nx = now.first + dx[i];
			ny = now.second + dy[i];
			
			if(0 < nx && nx <= n && 0 < ny && ny <= m) {
				if(temp[nx][ny].first == 0) {
					continue;
				}
				if(!visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({nx, ny});
					temp[nx][ny].second = temp[now.first][now.second].second + 1;
					temp[nx][ny].first += start;	
					if(temp[nx][ny].second > dist) {
						dist = temp[nx][ny].second;
						result = temp[nx][ny].first;
					}
					else if(temp[nx][ny].second == dist) {
						result = max(result, temp[nx][ny].first);
					}
				}
			}
		}
	}
	
	return {result, dist};
}
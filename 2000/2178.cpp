#include <bits/stdc++.h>

using namespace std;

int n, m;
int graph[101][101];
bool visited[101][101];
queue<pair<int, int>> q;
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 1; i < n + 1; i++) {
		string input;
		cin >> input;
		for(int j = 0; j < m; j++) {
			graph[i][j + 1] = int(input[j] - 48);
		}
	}
	
	solve();
	
	return 0;
}

void solve() {
	int x, y, nx, ny, result;
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	
	q.push({1, 1});
	visited[1][1] = true;
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			
			if(0 < nx && nx <= n && 0 < ny && ny <= m) {
				if(0 < graph[nx][ny] && visited[nx][ny] == false) {
					q.push({nx, ny});
					visited[nx][ny] = true;
					graph[nx][ny] = graph[x][y] + 1;
				}
				
			}
		}
	}
	
    cout << graph[n][m] << endl;
}
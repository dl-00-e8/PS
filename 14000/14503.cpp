#include <bits/stdc++.h>

using namespace std;

int n, m, r, c, d, result;
int graph[51][51];
bool visited[51][51] = { false };
int leftDirection(int d);
void simulation(int x, int y, int d);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	cin >> r >> c >> d;
	for(int i = 1; i < n + 1; i++) {
		for(int j = 1; j < m + 1; j++) {
			cin >> graph[i][j];
		}
	}
	
	simulation(r + 1, c + 1, d);
	
	return 0; 
}

// 왼쪽 방향 전환 함수
int leftDirection(int d) {
	if(d == 0) return 3;
	else if(d == 1) return 0;
	else if(d == 2) return 1;
	else if(d == 3) return 2;
	
	return 0;
}

// 로봇청소기 동작 함수
void simulation(int x, int y, int d) {
	int nx, ny, nd;
	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};

	visited[x][y] = true;
	result++;
	
	while(true) {
		int allClean = 0;
		for(int i = 0; i < 4; i++) {
			nd = leftDirection(d);
			nx = x + dx[nd];
			ny = y + dy[nd];
			d = nd;
			
			if(0 < nx && nx <= n && 0 < ny && ny <= m && graph[nx][ny] == 0 && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				result++;
				x = nx;
				y = ny;
				break;
			}
			else {
				allClean++;
			}
		}
		
		if (allClean == 4) {
			for(int i = 0; i < 2; i++) {
				nd = leftDirection(nd);
			}
			nx = x + dx[nd];
			ny = y + dy[nd];
			
			if (graph[nx][ny] == 1) {
				break;
			}
			else {
				x = nx;
				y = ny;
			}
		}
	}
	
	cout << result << endl;
}
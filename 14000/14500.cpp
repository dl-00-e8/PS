#include <bits/stdc++.h>

using namespace std;

int n, m;
int graph[501][501];
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 1; i < n + 1; i++) {
		for(int j = 1; j < m + 1; j++) {
			cin >> graph[i][j];
		}
	}

	solve();
	
	return 0;
}

void solve() {
	int result = 0;
	int dx[][3] = {
		{0, 0, 0},
		{1, 2, 3},
		{0, 1, 1},
		{0, -1, -2},
		{1, 1, 1},
		{0, 1, 2},
		{-1, -1, -1},
		{0, -1, -2},
		{-1, -1, -1},
		{0, 1, 2},
		{1, 1, 1},
		{1, 1, 2},
		{0, -1, -1},
		{1, 1, 2},
		{0, 1, 1},
		{-1, -1, -1},
		{1, 0, -1},
		{1, 1, 1},
		{1, 0, -1}
	};
	int dy[][3] = {
		{1, 2, 3},
		{0, 0, 0},
		{1, 0, 1},
		{-1, -1, -1},
		{0, -1, -2},
		{1, 1, 1},
		{0, 1, 2},
		{1, 1, 1},
		{0, -1, -2},
		{-1, -1, -1},
		{0, 1, 2},
		{0, 1, 1},
		{1, 1, 2},
		{0, -1, -1},
		{1, 1, 2},
		{-1, 0 , 1},
		{-1, -1, -1},
		{-1, 0, 1},
		{1, 1, 1}
	};
	
	for(int i = 1; i < n + 1; i++) {
		for(int j = 1; j < m + 1; j++) {
			for(int k = 0; k < 19; k++) {
				int temp = graph[i][j];
				bool compare = true;
				
				for(int d = 0; d < 3; d++) {
					int nx = i + dx[k][d];
					int ny = j + dy[k][d];
					
					if(0 < nx && nx <= n && 0 < ny && ny <= m) {
						temp += graph[nx][ny];
					}
					else {
						compare = false;
						break;
					}
				}
				
				if(compare) {
					result = max(result, temp);
				}
			}
		}
	}
	
	cout << result << endl;
}
#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int l, r, c;
int sx, sy, sz, ex, ey, ez;
int graph[31][31][31];
int visited[31][31][31];
int bfs(int x, int y, int z);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while(true) {
		memset(graph, 0, sizeof(graph));
		memset(visited, 0, sizeof(visited));
		
		cin >> l >> r >> c;
		
		if(l == 0 && r == 0 && c == 0) {
			break;	
		}
		
		for(int k = 1; k < l + 1; k++) {
			for(int i = 1; i < r + 1; i++) {
				for(int j = 1; j < c + 1; j++) {
					char input;
					cin >> input;
					if(input == 'S') {
						graph[i][j][k] = 2;
						sx = i;
						sy = j;
						sz = k;
					}
					else if(input == 'E') {
						graph[i][j][k] = 3;	
						ex = i;
						ey = j;
						ez = k;
					}
					else if(input == '.') {
						graph[i][j][k] = 0;	
					}
					else if(input == '#') {
						graph[i][j][k] = 1;	
					}
					
				}
			}	
		}
		
		int result = bfs(sx, sy, sz);
		if(result == 987654321) {
			cout << "Trapped!" << endl;	
		}
		else {
			cout << "Escaped in " << result << " minute(s)." << endl;
		}
	}
	
	return 0;
}

int bfs(int x, int y, int z) {
	int dx[] = {-1, 1, 0, 0, 0, 0};
	int dy[] = {0, 0, -1, 1, 0, 0};
	int dz[] = {0, 0, 0, 0, -1, 1};
	queue<pair<int, pair<int, int>>> q;
	
	q.push({z, {x, y}});
	visited[ex][ey][ez] = 987654321;
		
	while(!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int z = q.front().first;
		q.pop();
		
		for(int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			
			if(1 > nx || nx > r || 1 > ny || ny > c || 1 > nz || nz > l) {
				continue;
			}
			
			if(graph[nx][ny][nz] == 3) {
				visited[nx][ny][nz] = min(visited[nx][ny][nz], visited[x][y][z] + 1);
				
			}
			
			if(visited[nx][ny][nz] == 0) {
				if(graph[nx][ny][nz] == 0) {
					visited[nx][ny][nz] = visited[x][y][z] + 1;
					q.push({nz, {nx, ny}});
				}
			}
		}
	}
	
	/*
	for(int k = 1; k < l + 1; k++) {
		for(int i = 1; i < r + 1; i++) {
			for(int j = 1; j < c + 1; j++) {
				cout << visited[i][j][k] << " ";	
			}
			cout << endl;
		}
		cout << endl;
	}
	*/
	
	return visited[ex][ey][ez];
}
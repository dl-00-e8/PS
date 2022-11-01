#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int r, c, k, result;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int graph[6][6];
bool visited[6][6];
void backTracking(int x, int y, int cnt);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(graph, 0, sizeof(graph));
	memset(visited, 0, sizeof(visited));

	cin >> r >> c >> k;
	for(int i = 0; i < r; i++) {
		string input;
		cin >> input;
		for(int j = 0; j < c; j++) {
			if(input[j] == '.') {
				graph[i + 1][j + 1] = 0;
			}
			else {
				graph[i + 1][j + 1] = 1;
			}			
		}
	}

	result = 0;
	backTracking(r, 1, 1);

	cout << result << endl;

	return 0;
}

void backTracking(int x, int y, int cnt) {
	if(cnt > k) {
		return ;
	}

	if(x == 1 && y == c && cnt == k) {
		result++;
		return ;
	}

	if(x== 1 && y == c && cnt != k) {
		return ;
	}

	visited[x][y] = 1;

	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 1 || nx > r || ny < 1 || ny > c) {
			continue;
		}

		if(!visited[nx][ny] && graph[nx][ny] == 0) {
			backTracking(nx, ny, cnt + 1);
		}
	}
	visited[x][y] = 0;
}
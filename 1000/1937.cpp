#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int graph[501][501];
int dp[501][501];
bool visited[501][501];
int dfs(int x, int y);
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(graph, 0, sizeof(graph));
	memset(dp, 0, sizeof(dp));
	
	cin >> n;
	for(int i = 1; i < n + 1; i++) {
		for(int j = 1; j < n + 1; j++) {
			cin >> graph[i][j];		
		}
	}
	
	solve();
	
	return 0;	
}

int dfs(int x, int y) {
	if(visited[x][y]) {
		return dp[x][y];	
	}
	
	visited[x][y] = true;
	
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];	
		
		if(nx < 1 || nx > n || ny < 1 || ny > n) {
			continue;	
		}
		
		if(graph[x][y] < graph[nx][ny]) {
			dp[x][y] = max(dp[x][y], dfs(nx, ny));
		}
		
	}
	
	return ++dp[x][y];
}

void solve() {
	int result = 0;
	
	for(int i = 1; i < n + 1; i++) {
		for(int j = 1; j < n + 1; j++) {
			if(!visited[i][j]) {
				result = max(result, dfs(i, j));	
			}		
		}
	}
	
	/*
	for(int i = 1; i < n + 1; i++) {
		for(int j = 1; j < n + 1; j++) {
			cout << dp[i][j] << " ";	
		}
		cout << endl;
	}
	*/
	
	cout << result << endl;	
}
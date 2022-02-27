#include <bits/stdc++.h>

using namespace std;

int r, c, k;
long long dp[101][101];
vector<vector<int>> graph;
void move(int nx, int ny);
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> r >> c >> k;
	for(int i = 0; i < r; i++) {
		vector<int> temp(c);
		for(int j = 0; j < c; j++) {
			cin >> temp[j];
		}
		graph.push_back(temp);
	}
	
	memset(dp, 0, sizeof(dp));
	solve();
	
	return 0;
}

void move(int nx, int ny) {
	for(int i = nx + 1; i < r; i++) {
		for(int j = ny + 1; j < c; j++) {
			if(graph[nx][ny] != graph[i][j]) {
				dp[i][j] += dp[nx][ny];
				dp[i][j] %= 1000000007;
			}
		}
	}
}

void solve() {
	dp[0][0] = 1;	

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(dp[i][j] > 0) {
				move(i, j);
			}
		}
	}
	
	
	
	cout << dp[r - 1][c - 1] << endl;
}
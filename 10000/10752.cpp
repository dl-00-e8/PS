#include <bits/stdc++.h>

using namespace std;

int r, c, cnt;
vector<vector<char>> graph;
void dfs(int x, int y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> r >> c;
	for(int i= 0; i < r; i++) {
		vector<char> temp;
		for(int j = 0; j < c; j++) {
			char input;
			cin >> input;
			temp.push_back(input);
		}
		graph.push_back(temp);
	}
	
	cnt = 0;
	dfs(0, 0);
	
	cout << cnt << endl;

	return 0;
}

void dfs(int x, int y) {
	char result;
	
	if(x == r - 1 && y == c - 1) {
		++cnt;
		return;
	}
	
	if(graph[x][y] == 'R') {
		result = 'B';
	}
	else if(graph[x][y] == 'B') {
		result = 'R';
	}
	
	for(int i = x + 1; i < r; i++) {
		for(int j = y + 1; j < c; j++) {
			if(graph[i][j] == result) {
				dfs(i, j);
			}
		}
	}
}
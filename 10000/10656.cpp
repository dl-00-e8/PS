#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<char>> v;
vector<pair<int, int>> result;
bool check(int x, int y);
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		vector<char> temp;
		for(int j = 0; j < m; j++) {
			char input;
			cin >> input;
			temp.push_back(input);
		}
		v.push_back(temp);
	}
	
	solve();
	
	return 0;
}

bool check(int x, int y) {
	int nx, ny;
	int dir[] = {-1, 1, 2};
	bool result = true;
	
	if(v[x][y] == '.') {
		for(int i = 0; i < 3; i++) {
			nx = x + dir[i];
			ny = y;
			if(i == 0) {
				if(0 <= nx && nx < n && 0 <= ny && ny < m) {
					if(v[nx][ny] == '.') {
						result = false;
					}	
				}
			}
			else {
				if(0 <= nx && nx < n && 0 <= ny && ny < m) {
					if(v[nx][ny] != '.') {
						result = false;
					}
				}
				else {
					result = false;
				}
			}
		}
		
		if(result == false) {
			result = true;
			
			for(int i = 0; i < 3; i++) {
				nx = x;
				ny = y + dir[i];
				if(i == 0) {
					if(0 <= nx && nx < n && 0 <= ny && ny < m) {
						if(v[nx][ny] == '.') {
							result = false;
						}	
					}
				}
				else {
					if(0 <= nx && nx < n && 0 <= ny && ny < m) {
						if(v[nx][ny] != '.') {
							result = false;
						}
					}
					else {
						result = false;
					}
				}
			}	
		}
	}
	else if(v[x][y] == '#') {
		result = false;
	}
	
	return result;
}

void solve() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(check(i, j)) {
				result.push_back({i + 1, j + 1});	
			}
		}
	}
	
	cout << result.size() << endl;
	for(int i = 0; i < result.size(); i++) {
		cout << result[i].first << " " << result[i].second << endl;
	}
}
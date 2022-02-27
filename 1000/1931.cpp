#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back({start, end});
	}
	
	sort(v.begin(), v.end(), greater<pair<int, int>>());

	solve();
	
	return 0;
}

void solve() {	
	int index = 0;
	vector<pair<int, int>> result;
	
	result.push_back(v[0]);
	if(1 < n) {
		for(int i = 1; i < n; i++) {
			if(result[index].first >= v[i].second) {
				result.push_back(v[i]);
				index++;
			}
		}
	}

	cout << result.size() << endl;
}
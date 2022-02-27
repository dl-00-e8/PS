#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> v;
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	
	sort(v.begin(), v.end());
	
	solve();
	
	return 0;
}


void solve() {
	int result = 0;
	vector<int> dist(n - 1);
	
	for(int i = 0; i < n - 1; i++) {
		dist[i] = v[i + 1] - v[i];
	}
	
	sort(dist.begin(), dist.end());
	
	for(int i = 0; i < n - k; i++) {
		result += dist[i];
	}
	
	cout << result << endl;
}
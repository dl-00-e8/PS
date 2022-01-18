#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> v(101);
int dp[10001];
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	for(int i = 1; i < n + 1; i++) {
		cin >> v[i];
	}
	
	solve();
	
	return 0;
}

void solve() {	
	dp[0] = 1;
	if(v[0] > k) {
		cout << 0 << endl;
	}
	else {
		for(int i = 1; i < n + 1; i++) {
			for(int j = v[i]; j < k + 1; j++) {
				dp[j] = dp[j] + dp[j - v[i]];
			}
		}
	}
	
	cout << dp[k] << endl;
}
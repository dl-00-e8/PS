#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int dp[100001];
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	while(n--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	
	if(v.size() == 1) {
		cout << v[0] << endl;
	}
	else {
		solve();	
	}
	
	return 0;
}

void solve() {
	int result = v[0];
	
	dp[0] = v[0];
	for(int i = 1; i < v.size(); i++) {
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		
		result = max(result, dp[i]);
	}
	
	cout << result << endl;
}
#include <bits/stdc++.h>

using namespace std;

int t;
long long n, m;
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while(t--) {
		cin >> n >> m;
		solve();
	}
	
	
	return 0;
}

void solve() {
	long long result = 0;
	
	while(n > 0) {
		n /= 2;
		result++;
	}
	
	if(m > 0) {
		result += m;
	}

	cout << result << '\n';
}
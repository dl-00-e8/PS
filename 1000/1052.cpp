#include <bits/stdc++.h>

using namespace std;

int n, k;
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	
	if(n <= k) {
		cout << 0 << endl;
	}
	else {
		solve();	
	}
	
	return 0;
}

void solve() {
	int result;
	
	for(result = 0; ; result++) {
		int cnt = 0;
		int temp = n;
		
		while(temp > 0) {
			if(temp % 2) {
				cnt++;
			}
			
			temp /= 2;
		}
		
		if(cnt <= k) {
			break;
		}
		
		n++;
	}
	
	cout << result << endl;
}
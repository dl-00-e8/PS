#include <bits/stdc++.h>

using namespace std;

string a, b;
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> a >> b;
	
	solve();
	
	return 0;
}

void solve() {
	int minNum = 987654321;
	for(int i = 0; i < b.length() - a.length() + 1; i++) {
		int cnt = 0;
		
		for(int j = 0; j < a.length(); j++) {
			if(a[j] != b[j + i]) {
				cnt++;
			}
		}
		
		minNum = min(minNum, cnt);
	}
	
	cout << minNum << endl;
}
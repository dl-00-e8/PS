#include <bits/stdc++.h>

using namespace std;

string s, t, result;
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> s >> t;
	
	solve();
	
	return 0;
}

void solve() {
	for(int i = 0; i < s.size(); i++) {
		result += s[i];
		
		if(result.size() >= t.size() && result.substr(result.size() - t.size()) == t) {
			result.resize(result.size() - t.size());
		}
	}
	
	cout << result << endl;
}
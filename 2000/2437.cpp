#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
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
	
	solve();
	
	return 0;
}

void solve() {
	sort(v.begin(), v.end(), less<int>());
	
	int result = 1;
	for(int i = 0; i < v.size(); i++) {
		if(result < v[i]) {
			break;
		}
		
		result += v[i];
	}
	
	cout << result << endl;
}
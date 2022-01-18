#include <bits/stdc++.h>

using namespace std;

int n, s;
vector<int> v;
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	cin >> s;
	
	solve();
	
	return 0;
}

void solve() {
	int maxNum, maxIdx;
	
	for(int i = 0; i < n; i++) {
		maxNum = v[i];
		maxIdx = i;
		for(int j = i + 1; j < n; j++) {
			if(s - (j - i) >= 0) {
				if(maxNum < v[j]) {
					maxNum = v[j];
					maxIdx = j;
				}
			}
		}
		for(int j = maxIdx; j > i; j--) {
			swap(v[j], v[j - 1]);
		}
		s -= (maxIdx - i);
		if(s <= 0) {
			break;
		}
	}
	
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}
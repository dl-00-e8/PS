#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> v;
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	for(int i = 1; i < n + 1; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	
	solve();
	
	return 0;
}

void solve() {
	int choco = 0;
	int day = 0;
	
	int minNum = *min_element(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++) {
		if(v[i] > minNum) {
			choco += (v[i] - minNum);
			day++;
		}
	}
	
	cout << choco << " " << day << endl;
}
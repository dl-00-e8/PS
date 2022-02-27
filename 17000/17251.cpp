#include <bits/stdc++.h>

using namespace std;

int n, maxNum;
int strength[1000001];
vector<int> locate;
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 1; i < n + 1; i++) {
		int input;
		cin >> input;
		strength[i] = input;
		if(input == maxNum) {
			locate.push_back(i);
		}
		else if(input > maxNum) {
			maxNum = input;
			locate.clear();
			locate.push_back(i);
		}
	}
	
	solve();
	
	return 0;
}


void solve() {
	int rCnt, bCnt;
	
	bCnt = locate[0] - 1;
	rCnt = n - locate[locate.size() - 1];

	if(rCnt > bCnt) {
		cout << 'R' << endl;
	}
	else if(rCnt == bCnt) {
		cout << 'X' << endl;
	}
	else if(rCnt < bCnt) {
		cout << 'B' << endl;
	}
}
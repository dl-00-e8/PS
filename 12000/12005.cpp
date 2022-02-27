#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> v;
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	
	solve();
	
	return 0;
}

void solve() {
	int temp;
	int result = 0;
	
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {			
			if(v[j] - v[i] <= k) {
				if(j == n - 1) {
					temp = j - i + 1;
					result = max(temp, result);
				}
				else {
					continue;	
				}
			}
			else {
				temp = j - i;
				result = max(temp, result);
				break;
			}
		}
	}
	
	cout << result << endl;
}
#include <bits/stdc++.h>

using namespace std;

int n, k, a, b;
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k >> a >> b;
	
	solve();
	
	return 0;
}

void solve() {
	bool escape = false;
	int index = 0;
	int result = 0;
	vector<int> v(n, k);

	while(!escape) {
		index = min_element(v.begin(), v.end()) - v.begin();
		
		for(int i = 0; i < a; i++) {
			if(n <= index) {
				index -= n;
			}
			v[index] += b;
			
			index++;
		}
		
		for(int i = 0; i < v.size(); i++) {
			v[i] -= 1;
			if(v[i] == 0) {
				escape = true;
			}
		}
		
		result++;
	}
	
	cout << result << endl;
}
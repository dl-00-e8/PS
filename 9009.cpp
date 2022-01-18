#include <bits/stdc++.h>

using namespace std;

int t, idx, input;
vector<int> v;
void solve(int input);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	
	v.push_back(0);
	v.push_back(1);
	idx = 2;
	while(true) {
		int fibonacci = v[idx - 1] + v[idx - 2];
		
		if(fibonacci > 1000000000) {
			break;
		}
		
		v.push_back(fibonacci);
		idx++;
	}
	// v.size() == 45
	
	while(t--) {
		cin >> input;
		
		solve(input);
	}
	
	return 0;
}

void solve(int input) {
	int loca;
	vector<int> result;
	
	loca = v.size() - 1;
	while(input) {
		for(int i = loca; 0 < i; i--) {
			if(v[i] <= input) {
				result.push_back(v[i]);
				input -= v[i];
				loca = i - 1;
				break;
			}
		}
	}

	// Output
	for(int i = result.size() - 1; 0 <= i; i--) {
		if(i == 0) {
			cout << result[i] << endl;
			break;
		}
		cout << result[i] << " ";
	}
}
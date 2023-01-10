#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <stack>

using namespace std;

#define endl "\n"

int n;
vector<int> v;
stack<int> s;
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);	
	}
	
	solve();
	
	return 0;
}

void solve() {
	int idx = 0;
	bool suc = true;
	vector<char> result;
	
	
	for(int i = 1; i < n + 1; i++) {
		if(i < v[idx]) {
			s.push(i);
			result.push_back('+');	
		}
		else if(i == v[idx]) {
			s.push(i);
			result.push_back('+');
			
			if(s.empty()) {
				suc = false;
				break;	
			}
			
			while(!s.empty()) {
				if(s.top() == v[idx]) {
					s.pop();
					result.push_back('-');
					
					idx++;	
				}
				else if(s.top() > v[idx]) {
					suc = false;
					break;
				}	
				else {
					break;	
				}
			}
		}
		else {
			suc = false;
			break;
		}
	}
	
	if(suc) {
		for(int i = 0; i < result.size(); i++) {
			cout << result[i] << endl;	
		}	
	}
	else {
		cout << "NO" << endl;
	}	
}

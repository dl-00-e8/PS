#include <bits/stdc++.h>

using namespace std;

int n, answer, input;
vector<int> p;
vector<int> m;
int calc(vector<int> &v, int type);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> input;
		if(input > 0) {
			p.push_back(input);
		}
		else {
			m.push_back(input);
		}
	}
	
	answer = calc(p, 1);
	answer += calc(m, -1);
	
	cout << answer << endl;
	
	return 0;
}

int calc(vector<int> &v, int type) {
	int result = 0;
	int temp = 0;
	
	if(type == 1) {
		sort(v.begin(), v.end(), greater<int>());
		if(v.size() % 2 == 0 && v.size() != 0) {
			for(int i = 0; i < v.size(); i += 2) {
				result += max(v[i] + v[i + 1], v[i] * v[i + 1]);
			}
		}
		else if(v.size() % 2 == 1) {
			for(int i = 0; i < v.size(); i += 2) {
				if(i == v.size() - 1) {
					result += v[i];
					continue;
				}
				result += max(v[i] + v[i + 1], v[i] * v[i + 1]);
			}
		}
	}
	else if(type == -1) {
		sort(v.begin(), v.end(), less<int>());
		
		if(v.size() % 2 == 0 && v.size() != 0) {
			for(int i = 0; i < v.size(); i += 2) {
				result += max(v[i] + v[i + 1], v[i] * v[i + 1]);
			}
		}
		else if(v.size() % 2 == 1) {
			for(int i = 0; i < v.size(); i += 2) {
				if(i == v.size() - 1) {
					result += v[i];
					continue;
				}
				result += max(v[i] + v[i + 1], v[i] * v[i + 1]);
			}
		}
	}

	return result;
}


/*
음수 개수를 카운팅해야함
*/
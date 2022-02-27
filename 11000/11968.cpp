#include <bits/stdc++.h>

using namespace std;

int n;
struct inform {
	int num = 987654321;
	bool use = false;
};
vector<inform> elsie;
vector<inform> bessie;
bool compare(const inform& i1, const inform& i2); //정렬 함수
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		inform input;
		cin >> input.num;
		elsie.push_back(input);
	}
	
	solve();
	
	return 0;
}

bool compare(const inform& i1, const inform& i2) {
	if(i1.num < i2.num) return true;

	return false;
}


void solve() {
	int idx = 0;
	int result = 0;
	
	sort(elsie.begin(), elsie.end(), compare);
	
	for(int i = 1; i < (2 * n) + 1; i++) {
		if(elsie[idx].num != i) {
			inform input;
			input.num = i;
			bessie.push_back(input);
		}
		else {
			idx++;
		}
	}
	
	idx = 0;
	for(int i = 0; i < elsie.size(); i++) {
		for(int j = idx; j < bessie.size(); j++) {
			if(elsie[i].num < bessie[j].num && bessie[j].use == false) {
				result++;
				idx++;
				bessie[j].use = true;
				break;
			}
		}
	}
	
	cout << result << endl;
}
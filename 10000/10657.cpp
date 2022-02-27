#include <bits/stdc++.h>

using namespace std;

int n;
stack<pair<int, int>> input;
stack<pair<int, int>> temp;
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	while(n--) {
		int pos, speed;
		cin >> pos >> speed;
		input.push({pos, speed});
	}
	
	solve();
	
	return 0;
}

void solve() {
	bool end = true;
	pair<int, int> now;
	
	/*
	while(end) {	
		// input --> temp 이동하면서 확인
		temp.push(input.top());
		input.pop();
		for(int i = 0; input.size(); i++) {
			// 1. 앞 주자와 속도가 같거나 작을 경우
			
			// 2. 앞 주자보다 속도가 빠를 경우, 
		}
		
		
		// temp --> input 이동하면서 확인
		input.push(temp.top());
		temp.pop();
		
	}
	*/
	
	temp.push(input.top());
	input.pop();
	while(!input.empty()) {
		now = input.top();
		input.pop();
		
		if(temp.top().second >= now.second) {
			temp.push(now);
		}
		else {
			continue;
		}
	}
	
	cout << temp.size() << endl;
	
}
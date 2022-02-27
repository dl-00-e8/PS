#include <bits/stdc++.h>

using namespace std;

string photo[5];
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i = 0; i < 5; i++) {
		cin >> photo[i];
	}
	
	solve();
	
	return 0;
}


void solve() {
	for(int i = 0; i < photo[0].size(); i++) {
		if(photo[0][i] == '.' && photo[1][i] == 'o') {
			photo[0][i] = 'o';
			photo[1][i] = 'w';
			photo[2][i] = 'l';
			photo[3][i] = 'n';
			photo[4][i] = '.';
		}
		else if(photo[0][i] == '.' && photo[1][i] == '.') {
			continue;
		}
		else if(photo[0][i] == 'o' && photo[1][i] == 'w') {
			photo[0][i] = '.';
			photo[1][i] = 'o';
			photo[2][i] = 'm';
			photo[3][i] = 'l';
			photo[4][i] = 'n';
		}
	}
	
	for(int i = 0; i < 5; i++) {
		cout << photo[i] << endl;
	}
}
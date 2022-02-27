#include <bits/stdc++.h>

using namespace std;

int n, x, y;
int a[101];
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; i++) {
		int input;
		cin >> input;
		a[i] = input;
	}
	cin >> x >> y;

	solve();

	return 0;
}

void solve() {
	int relative, absolute;

	relative  = n * x / 100;

	absolute = 0;	
	for(int i = 0; i < n; i++) {
		if(a[i] >= y) {
			absolute++;
		}
	}
	
	cout << relative << " " << absolute << endl;
}
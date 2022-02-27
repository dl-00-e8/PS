#include <bits/stdc++.h>

using namespace std;

int n, m;
int gcd(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	cout << m - gcd(n, m) << endl;
	
	return 0;
}

int gcd(int a, int b) {
	if(a % b == 0) {
		return b;
	}
	
	return gcd(b, a%b);
}
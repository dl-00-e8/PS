#include <bits/stdc++.h>

using namespace std;

int t, n;
pair<int, int> goldbach[5001];
bool sosu[10001];
void primeArr();
void find();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	
	primeArr();
	find();
	
	for(int i = 0; i < t; i++) {
		cin >> n;
		cout << goldbach[n / 2].first << " " << goldbach[n / 2].second << endl;
	}
	
	return 0;
}

void primeArr() {
	int m = sqrt(10000);
	
	fill_n(sosu, 10001, true);
	
	for(int i = 2; i < m + 1; i++) {
		if(sosu[i] == true) {
			for(int j = (i * 2); j < 10001; j += i) {
				sosu[j] = false;
			}
		}
	}
}

void find() {
	int first, second;
	
	goldbach[2] = {2, 2};
	goldbach[3] = {3, 3};
	
	for(int i = 8; i < 10001; i += 2) {
		if((i / 2) % 2 != 0) {
			first = (i / 2);
			second = (i / 2);
		}
		else {
			first = (i / 2) - 1;
			second = (i / 2) + 1;
		}
		
		for(; first != 1;) {
			if(sosu[first] == true && sosu[second] == true) {
				goldbach[i / 2] = {first, second};
				break;
			}
			
			first -= 2;
			second += 2;
		}
	}
}
#include <bits/stdc++.h>

using namespace std;

int n, result;
int num = 9;
int alphabet[26];
string input;

bool compare(int &a, int &b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> input;
		int var = 1;
		for(int j = input.length() - 1; j >= 0; j--) {
			alphabet[input[j] - 'A'] += var;
			var *= 10;
		}
	}
	
	sort(alphabet, alphabet + 26, compare);
	
	for(int i = 0; i < 26; i++) {
		if(alphabet[i] == 0) {
			break;
		}
		
		result += alphabet[i] * num;
		num--;
	}
	
	cout << result << endl;
	
	return 0;
}
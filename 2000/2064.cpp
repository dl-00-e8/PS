#include <bits/stdc++.h>

using namespace std;

int n;
int data[1001];
string networkIp;
string networkMask;
int change(string input);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		string input;
		cin >> input;
		data[i] = change(input);
	}
	
	for(int i = 0; i < n; i++) {
		cout << data[i] << endl;
	}
	
	return 0;
}

int change(string input) {
	int index = 0;
	string temp, result;
	
	for(int i = 0; i < input.length(); i++) { 
		if(input[i] == '.') {
			result.append(temp);
			temp = "";
			index++;
			continue;
		}
		
		temp.append(input[i].c_str());
	}
	
	
	
	return stoi(result);
}
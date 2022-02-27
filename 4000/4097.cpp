#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(true) {
		int n;
		
		cin >> n;
		
		if(n == 0) {
			break;
		}
		else{
			int temp;
			int result[n + 1] = { 0 };
			int answer = -987654321;
			
			for(int i = 0; i < n; i++) {
				cin >> temp;
				result[i] = temp;
			}
			
			for(int i = 1; i < n; i++) {
				result[i] = max(result[i], result[i] + result[i - 1]);
			}
			
			/*
			for(int i = 1; i < n; i++) {
				answer = max(answer, result[i]);
			}
			*/
			cout << *max_element(result, result + n) << endl;
			
			// cout << answer << endl;
		}
		
		
	}
	return 0;
}

/*
max_element를 사용할 때, 범위에 조심할 것
*/
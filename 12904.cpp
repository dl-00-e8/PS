#include <bits/stdc++.h>

using namespace std;

string a, b, temp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> a;
	cin >> b;
	
	int i = 0;
	while(i < 3) {
		if(b[b.length() - 1] == 'B'){
			temp = b.substr(0, b.length() - 1);
			reverse(temp.begin(), temp.end());
		}
		else if(b[b.length() - 1] == 'A') {
			temp = b.substr(0, b.length() - 1);
		}
		b = temp;
		
		if(a.length() >= b.length()) {
			break;
		}
	}
	
	if(a == b) {
		cout << "1" << "\n";
	}
	else {
		cout << "0" << "\n";
	}
	
	return 0;
}

/*
algorithm헤더에 reverse함수 존재 --> 이를 적용한다.
사용 방법 : reverse(start, end)

파이썬 list slicing과 비슷한 방식으로 쓸만한 것
: copy(시작지점, 끝지점, 복사될 배열의 시작지점)

문자열의 일부를 추출하는 경우 : substr
사용법 : substr(시작지점, 길이)
*/
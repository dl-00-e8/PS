#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N, r, c;
int recursive(int seung, int x, int y, int value); // seung : 몇 승, x : 시작 x 좌표, y : 시작 y 좌표, value : 시작 좌표가 가지는 값

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r >> c;

    cout << recursive(N, 0, 0, 0) << endl;

    return 0;
}

int recursive(int seung, int x, int y, int value) {
    // 해당 박스의 범위 안에 있을 경우
    if(x <= r && r < x + 2 && y <= c && c < y + 2) {
        if(x == r) {
            if(y == c) {
                return value;
            }
            else if(y + 1 == c) {
                return value + 1;
            }
        }
        else if(x + 1== r) {
            if(y == c) {
                return value + 2;
            }
            else if(y + 1 == c) {
                return value + 3;
            }
        }
    }

    //divide & conquer 부분 작성
    int move = pow(2, seung - 1);
    if(x <= r && r < x + move && y <= c && c < y + move){
        return recursive(seung - 1, x, y, value);
    }
    else if(x + move <= r && r < x + (move * 2) && y <= c && c < y + move) {
        return recursive(seung - 1, x + move, y, value + (pow(4, seung - 1) * 2));
    }
    else if(x <= r && r < x + move && y + move <= c && c < y + (move * 2)) {
        return recursive(seung - 1, x, y + move, value + pow(4, seung - 1));
    }
    else if(x + move <= r && r < x + (move * 2) && y + move <= c && c < y + (move * 2)) {
        return recursive(seung - 1, x + move, y + move, value + (pow(4, seung - 1) * 3));
    }


    return 0;
}

/*
4의 15승에 관한 2차원 배열을 선언하는 것은 불가능
이유 : 4^15 > 10억
memoization으로 풀 수 있는가?

r, c 좌표를 배수로 나눈다는 마인드
4의 배수로 나누었을 때, 몫과 나머지를 이용해서 구한다.
*/
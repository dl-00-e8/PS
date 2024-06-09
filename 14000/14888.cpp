#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define MAX 1000000001
#define MIN -1000000001

int N, max_result, min_result;
int input[12];
int calc[4];
void back_tracking(int x, int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    max_result = MIN;
    min_result = MAX;
    memset(calc, 0, sizeof(calc));

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> input[i];
    }
    for(int i = 0; i < 4; i++) {
        cin >> calc[i];
    }

    back_tracking(input[0], 0);

    cout << max_result << endl << min_result << endl;

    return 0;
}

void back_tracking(int x, int depth) {
    // 마지막 도착 시   
    if(depth == N - 1) {
        max_result = max(max_result, x);
        min_result = min(min_result, x);
    }

    // 연산자별 대입
    depth++;
    for(int i = 0; i < 4; i++) {
        // 사용할 수 있는 연산자가 남았을 때만 진행
        if(calc[i] > 0) {
            calc[i]--;
            
            int temp;
            switch (i) {
                case 0:
                    temp = x + input[depth];
                    break;
                case 1:
                    temp = x - input[depth];
                    break;
                case 2:
                    temp = x * input[depth];
                    break;
                case 3:
                    if(x < 0) {
                        temp = -(abs(x) / input[depth]);
                    }
                    else if(x == 0) {
                        temp = 0;
                    }
                    else {
                        temp = x / input[depth];
                    }
                    break;
            }
            
            // cout << x << " " << temp << " " << depth << endl;
            back_tracking(temp, depth);

            calc[i]++;
        }
    }
}
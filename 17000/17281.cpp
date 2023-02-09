#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, answer;
int ining[51][10];
int line[10];
bool visited[10];
void setting(int cnt);
int play();
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < 10; j++) {
            cin >> ining[i][j];
        }
    }

    solve();

    return 0;
}

void setting(int cnt) {
    if(cnt == 9) {
        play();
    }
}

int play() {
    int now, out, result; // now = 라인업 idx
    bool base[4];
    
    // 이닝
    now = 1;
    result = 0;
    for(int i = 1; i < n + 1; i++) {
        // 주자 초기화
        memset(base, 0, sizeof(base));

        // 3 아웃카운트 체크
        out = 0;
        while(out < 3) {
            // 현재 선수 번호
            int hitter = line[now];

            if(ining[i][hitter] == 0) {
                out++;
            }
            else if(ining[i][hitter] == 1) {
                if(base[3]) {
                    base[3] = false;
                    result++;
                }
                
                if(base[2]) {
                    base[2] = false;
                    base[3] = true;
                }

                if(base[1]) {
                    base[1] = false;
                    base[2] = true;
                }

                base[1] = true;
            }
            else if(ining[i][hitter] == 2) {
                if(base[3]) {
                    base[3] = false;
                    result++;
                }
                
                if(base[2]) {
                    base[2] = false;
                    result++;
                }

                if(base[1]) {
                    base[1] = false;
                    base[3] = true;
                }

                base[2] = true;
            }
            else if(ining[i][hitter] == 3) {
                int cnt = 0;

                // 주자 수 확인
                for(int j = 3; j  > 0; j--) {
                    if(base[j]) {
                        cnt++;
                    }
                }

                // 점수 증가
                result += cnt;

                // 3루 주자만 존재
                memset(base, 0, sizeof(base));
                base[3] = true;
            }
            else if(ining[i][hitter] == 4) {
                int cnt = 1;

                // 주자 수 확인
                for(int j = 3; j  > 0; j--) {
                    if(base[j]) {
                        cnt++;
                    }
                }

                // 점수 증가
                result += cnt;

                // 주자 초기화
                memset(base, 0, sizeof(base));
            }

            // 다음 타자
            now++;
            if(now > 9) {
                now = 1;
            }
        }
    }

    return result;
}

void solve() {
    answer = 0;

    // for(int i = 1; i < 10; i++) {
    //     if(i == 4) {
    //         continue;
    //     }

    //     memset(line, 0, sizeof(line));
        
    //     line[1] = 4;
    //     setting(2);
    // }

    cout << answer << endl;
}
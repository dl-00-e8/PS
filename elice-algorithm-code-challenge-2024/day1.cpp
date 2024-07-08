#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define MAX 1000000

int N;
int result = MAX;
int visited[10];
void backTracking(int now, int depth, int size);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 숫자배열 초기화
    memset(visited, 0, sizeof(visited));

    cin >> N;
    
    // 숫자의 자릿수 확인을 위한 문자열 변환
    string change = to_string(N);
    int size = change.size();

    // 자릿수별 숫자 방문배열 저장
    int now = N;
    while(now) {
        int remainder = now % 10;
        now /= 10;
        
        visited[remainder]++;
    }

    for(int i = 1; i < 10; i++) {
        if(visited[i]) {
            visited[i]--;
            backTracking(i, 1, size);
            visited[i]++;
        }
    }

    cout << result << endl;

    return 0;
}

void backTracking(int now, int depth, int size) {
    // 탈출
    if(depth == size) {
        if(now > N && now < result) {
            result = now;
        }
        return;
    }

    for(int i = 0; i < 10; i++) {
        if(visited[i]) {
            visited[i]--;
            backTracking(now * 10 + i, depth + 1, size);
            visited[i]++;
        }
    }
}
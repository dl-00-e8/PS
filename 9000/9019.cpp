#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int t, a, b;
vector<string> answer;
int calc(char c, int num); // DSLR 연산 함수
void solve(int a, int b); // TC별 진행할 함수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        cin >> a >> b;
        solve(a, b);
    }

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}

int calc(char c, int num) {
    if(c == 'D') {
        num *= 2;

        if(num > 9999) {
            num %= 10000;
        }
    }
    else if(c == 'S') {
        if(num == 0) {
            num = 9999;
        }
        else {
            num -= 1;
        }
    }
    else if(c == 'L') {
        int temp = num;

        num = (temp / 1000) + ((temp % 1000) * 10);
    }
    else if(c == 'R') {
        int temp = num;

        num = (temp / 10) + ((temp % 10) * 1000);
    }

    return num;
}

void solve(int a, int b) {
    int tempNum;
    string result = "";
    queue<pair<int, string>> q;
    char dir[] = {'D', 'S', 'L', 'R'};
    bool visited[10001];
    
    memset(visited, 0, sizeof(visited));

    q.push({a, ""});
    visited[a] = true;

    while(!q.empty()) {
        int nowNum = q.front().first;
        string nowString = q.front().second;
        q.pop();

        if(nowNum == b) {
            answer.push_back(nowString);
            break;
        }

        for(int i = 0; i < 4; i++) {
            tempNum = calc(dir[i], nowNum);

            if(!visited[tempNum]) {
                visited[tempNum] = true;
                q.push({tempNum, nowString + dir[i]});
            }
            
        }
    }

    // cout << result << endl;
}

/*
시간 초과가 발생하는 이유 : string 복사
string복사를 여러번 반복하지 않도록 
C++에서 string 의 += 연산은 O(K)이다.
C++에서 string 의 + 연산은 O(N+K)이다.

s = s + "A"; --> O(N^2)의 시간복잡도를 가짐

위의 문제에서 핵심은 string 복사가 시간복잡도를 많이 잡아먹는다는 것인데,
이를 다른 변수로 복사해서 다시 넘겨주는 과정이 아닌
바로 넘겨주는 과정을 통해서 시간복잡도를 최소화하여야 함
*/
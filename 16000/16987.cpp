#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N;
vector<pair<int, int> > egg;
bool check();
int backtracking(int idx);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int s, w;
        cin >> s >> w;
        egg.push_back(make_pair(s, w));
    }

    int answer = backtracking(0);
    cout << answer << endl;

    return 0;
}

bool check(int idx) {
    bool result = true; // true: 다 깨짐, false: 하나라도 안 깨진 게 존재함

    for(int i = 0; i < egg.size(); i++) {
        if(i == idx) {
            continue;
        }

        if(egg[i].first > 0) {
            result = false;
        }
    }

    return result;
}

int backtracking(int idx) {
    // cout << "idx: " << idx << endl;
    // 최근에 든 계란이 가장 오른쪽에 위치한 계란일 경우, 계란을 치는 과정을 종료한다.
    if(idx == egg.size()) {
        int result = 0;
        for(int i = 0; i < egg.size(); i++) {
            // cout << egg[i].first << " " << egg[i].second << endl;
            if(egg[i].first <= 0) {
                result++;
            }
        }
        return result;
    }

    // 손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없으면 넘어간다.
    if(egg[idx].first <= 0 || check(idx)) {
        return backtracking(idx + 1);
    }

    int cnt = 0;
    // 깨지지 않은 다른 계란 중 하나를 친다.
    for(int i = 0; i < egg.size(); i++) {
        // 자기자신은 제외한다.
        if(i == idx || egg[i].first <= 0) {
            continue;
        }

        // 계란을 친다.
        egg[idx].first -= egg[i].second;
        egg[i].first -= egg[idx].second;
        cnt = max(cnt, backtracking(idx + 1));
    
        // backtracking이므로 원상 복귀한다.
        egg[idx].first += egg[i].second;
        egg[i].first += egg[idx].second;
    }

    return cnt;
}
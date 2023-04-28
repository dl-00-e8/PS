#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m, answer;
deque<int> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        dq.push_back(i);
    }

    answer = 0;
    while(m--) {
        int input;

        cin >> input;

        if(dq.front() == input) {
            dq.pop_front();
        }
        else {
            int now = 0;
            int size = dq.size();
            // 해당 노드 IDX찾기
            for(auto i = dq.begin(); i != dq.end(); i++) {
                if(*i == input) {
                    break;
                }
                now++;
            }
            if(size / 2 < now) {
                while(dq.front() != input) {
                    dq.push_front(dq.back());
                    dq.pop_back();
                    answer++;
                }
                dq.pop_front();
            }
            else {
                while(dq.front() != input) {
                    dq.push_back(dq.front());
                    dq.pop_front();
                    answer++;
                }
                dq.pop_front();
            }
        }
    }

    cout << answer << endl;

    return 0;
}
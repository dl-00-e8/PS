#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define MAX 100001

int N, M;
int rm[MAX]; // 제거할 문제 번호 관리
struct compare1 {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};
struct compare2 {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if(a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, compare1> h_pq; // first가 난이도, second 문제번호 -> 어려운
priority_queue<pair<int, int>, vector<pair<int, int> >, compare2> e_pq; // first가 난이도, second 문제번호 -> 쉬운

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(rm, 0, sizeof(rm));

    cin >> N;
    for(int i = 0; i < N; i++) {
        int P, L;

        cin >> P >> L;
        rm[P] = L;
        h_pq.push(make_pair(L, P));
        e_pq.push(make_pair(L, P));
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        string command;

        cin >> command;

        if(command == "recommend") {
            int x;

            cin >> x;

            switch (x) {
                case -1:
                    while(!e_pq.empty()) {
                        pair<int, int> now = e_pq.top();
                        
                        if(rm[now.second] == now.first) {
                            cout << now.second << endl;
                            break;
                        }

                        e_pq.pop();
                    }
                    break;

                case 1:
                    while(!h_pq.empty()) {
                        pair<int, int> now = h_pq.top();
                        
                        if(rm[now.second] == now.first) {
                            cout << now.second << endl;
                            break;
                        }

                        h_pq.pop();
                    }
                    break;
            }

        } else if(command == "add") {
            int p, l;

            cin >> p >> l;

            rm[p] = l;

            h_pq.push(make_pair(l, p));
            e_pq.push(make_pair(l, p));
        } else if(command == "solved") {
            int p;

            cin >> p;

            rm[p] = 0;
        }
            
    }

    return 0;
}
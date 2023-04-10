#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, t;
int cand[101];
vector<int> recommend;
vector<pair<int, pair<int, int>>> v; // first == idx, second.first == 추천 받은 횟수, second.second = 게시된 idx
bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cand, 0, sizeof(cand));

    cin >> n >> t;
    for(int i = 0; i < t; i++) {
        int rec;
        cin >> rec;
        recommend.push_back(rec);
    }

    solve();

    return 0;
}

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if(a.second.first == b.second.first) {
        return a.second.second < b.second.second;
    }

    return a.second.first < b.second.first;
}

void solve() {
    int answer;

    for(int i = 0; i < recommend.size(); i++) {
        int now = recommend[i];

        // 추천 수 확인
        cand[now]++;
        
        // 사진틀 용량 확인
        if(v.size() < n) {
            bool check = false;

            // 추천인 존재 여부 확인
            for(int j = 0; j < v.size(); j++) {
                if(v[j].first == now) {
                    v[j].second.first++;
                    check = true;
                }
            }

            if(!check) {
                v.push_back({now, {1, i}});
            }
        }
        else {
            bool check = false;
            for(int j = 0; j < v.size(); j++) {
                if(v[j].first == now) {
                    v[j].second.first++;
                    check = true;
                }
            }
            if(check) {
                continue;
            }

            // 정렬 후 최솟값 교체
            sort(v.begin(), v.end(), compare);
            
            cand[v[0].first] = 0;

            v[0].first = now;
            v[0].second.first = cand[now];
            v[0].second.second = i;
        }
    }

    sort(v.begin(), v.end(), less<pair<int, pair<int, int>>>());
    for(int i = 0; i < v.size(); i++) {
        cout << v[i].first << " ";
    }
    cout << endl;
}
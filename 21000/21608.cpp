#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int graph[21][21];
set<int> student[401];
bool compare(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b);
void setting(int x);
int solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));

    cin >> n;
    for(int i = 1; i < n * n + 1; i++) {
        int s;

        cin >> s;
        for(int j = 0; j < 4; j++) {
            int temp;

            cin >> temp;
            student[s].insert(temp);
        }

        setting(s);
    }

    cout << solve() << endl;

    return 0;
}

bool compare(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
    if(a.second.first == b.second.first) {
        if(a.second.second == b.second.second) {
            if(a.first.second == b.first.second) {
                return a.first.first < b.first.first;
            }
            return a.first.second < b.first.second;
        }
        return a.second.second > b.second.second;
    }

    return a.second.first > b.second.first;
}

void setting(int x) {
    vector<pair<pair<int, int>, pair<int, int>>> favorite; // 좋아하는 학생이 가장 많은 칸

    // 1단계. 좋아하는 학생이 가장 많은 칸 찾기
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            int cnt = 0;
            int empty = 0;

            if(graph[i][j] != 0) {
                continue;
            }

            // 인접한 칸 탐색
            for(int dir = 0 ; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if(nx < 1 || nx > n || ny < 1 || ny > n) {
                    continue;
                }

                if(graph[nx][ny] != 0) {
                    if(student[x].find(graph[nx][ny]) != student[x].end()) {
                        cnt++;
                    }
                }
                else {
                    empty++;
                }
            }

            favorite.push_back({{i, j}, {cnt, empty}});
        }
    }


    // 2단계. 비어있는 칸이 가장 많은 칸으로 자리 정하기
    if(favorite.size() == 1) {
        int gx = favorite[0].first.first;
        int gy = favorite[0].first.second;

        graph[gx][gy] = x; 
    }
    else {
        // 3단계. 비어있는 칸 -> 행 -> 열 순으로 정렬
        sort(favorite.begin(), favorite.end(), compare);

        int gx = favorite[0].first.first;
        int gy = favorite[0].first.second;

        graph[gx][gy] = x;
    }
}

int solve() {
    int answer = 0;

    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            int now = graph[i][j];
            int happy = 0;

            for(int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if(nx < 1 || nx > n || ny < 1 || ny > n) {
                    continue;
                }

                if(student[now].find(graph[nx][ny]) != student[now].end()) {   
                    happy++;
                }
            }

            if(happy == 0) {
                answer += 0;
            }
            else if(happy == 1) {
                answer += 1;
            }
            else if(happy == 2) {
                answer += 10;
            }
            else if(happy == 3) {
                answer += 100;
            }
            else {
                answer += 1000;
            }
        }
    }    

    return answer; 
}
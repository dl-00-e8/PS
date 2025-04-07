#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
set<set<pair<int, int> > > selection; // 가능한 모든 조합 확인
int graph[11][11];
bool visited[11][11];
void backtracking(int now, int depth, set<pair<int, int> > s);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int input;
            cin >> input;
            graph[i][j] = input;
        }
    }

    set<pair<int, int> > s;
    backtracking(0, 3, s);

    int answer = 987654321;
    for(auto c: selection) {
        int result = 0;

        memset(visited, 0, sizeof(visited));

        for(auto data: c) {
            if(visited[data.first][data.second]) {
                result = -1;
                break;
            }
            visited[data.first][data.second] = true;
            result += graph[data.first][data.second];

            for(int d = 0; d < 4; d++) {
                int nx = data.first + dx[d];
                int ny = data.second + dy[d];

                if(nx < 0 || nx >= N || ny < 0 || ny >= N) {
                    result = -1;
                    break;
                }

                if(visited[nx][ny]) {
                    result = -1;
                    break;
                }

                visited[nx][ny] = true;
                result += graph[nx][ny];
            }

            if(result == -1) {
                break;
            }
        }

        if(result == -1) {
            continue;
        } else {
            answer = min(answer, result);
        }
    }

    cout << answer << endl;

    return 0;
}

void backtracking(int now, int depth, set<pair<int, int> >  s) {
    if(now == depth) {
        selection.insert(s);
        return ;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j]) {
                continue;
            }

            visited[i][j] = true;
            s.insert(make_pair(i, j));
            backtracking(now + 1, depth, s);
            visited[i][j] = false;
            s.erase(make_pair(i, j));
        }
    }
}
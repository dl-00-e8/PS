#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int t, w, h;
queue<pair<int, int>> q;
queue<pair<int, int>> fire;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char graph[1001][1001];
int personVisited[1001][1001];
int fireVisited[1001][1001];
void fireBfs();
void personBfs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        fill(&personVisited[0][0], &personVisited[0][0] + sizeof(personVisited) / sizeof(int), INF);
        fill(&fireVisited[0][0], &fireVisited[0][0] + sizeof(fireVisited) / sizeof(int), INF);

        cin >> w >> h;
        for(int i = 1; i < h + 1; i++) {
            for(int j = 1; j < w + 1; j++) {
                cin >> graph[i][j];

                if(graph[i][j] == '*') {
                    fire.push({i, j});
                    fireVisited[i][j] = 0;
                }
                else if(graph[i][j] == '@') {
                    q.push({i, j});
                    personVisited[i][j] = 0;
                }
            }
        }

        fireBfs();

        personBfs();
    }

    return 0;
}

void fireBfs() {
    while(!fire.empty()) {
        int x = fire.front().first;
        int y = fire.front().second;

        fire.pop();

        for(int i = 0 ; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > h || ny < 1 || ny > w) {
                continue;
            }

            if(graph[nx][ny] != '#' && fireVisited[nx][ny] > fireVisited[x][y] + 1) {
                fireVisited[nx][ny] = fireVisited[x][y] + 1;
                fire.push({nx, ny});
            }
        }
    }
}

void personBfs() {
    bool end = false;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > h || ny < 1 || ny > w) {
                cout << personVisited[x][y] + 1 << endl;
                end = true;
                break;
            }

            if(graph[nx][ny] == '.' && personVisited[nx][ny] == INF && personVisited[x][y] + 1 < fireVisited[nx][ny]) {
                personVisited[nx][ny] = personVisited[x][y] + 1;
                q.push({nx, ny});
            }
        }

        if(end) {
            break;
        }
    }

    if(!end) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        while(!q.empty()) {
            q.pop();
        }
    }
}
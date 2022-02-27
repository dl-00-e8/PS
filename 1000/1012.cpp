#include <bits/stdc++.h>

using namespace std;

int t, m, n, k;
int graph[51][51];
vector<pair<int, int>> v;
bool visited[51][51];
void bfs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for(int test = 0; test < t; test++) {
        memset(graph, 0, sizeof(graph)); 
        memset(visited, 0, sizeof(visited));
        v.clear();

        cin >> m >> n >> k;
        for(int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
            graph[x][y] = 1;
        }

        bfs();
    }

    return 0;
}

void bfs() {
    int x, y, cnt;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for(int i = 0; i < v.size(); i++) {
        if(visited[v[i].first][v[i].second] == true) {
            continue;
        }

        queue<pair<int, int>> q;
        
        q.push({v[i].first, v[i].second});
        while(!q.empty()) { 
            x = q.front().first;
            y = q.front().second;
            visited[x][y] = true;
            q.pop();

            for(int d = 0; d < 4; d++) {
                if(0 <= x + dx[d] && x + dx[d] < 50 && 0 <= y + dy[d] && y + dy[d] < 50) {
                    if(visited[x + dx[d]][y + dy[d]] == false && graph[x + dx[d]][y + dy[d]] == 1) {
                        visited[x + dx[d]][y + dy[d]] = true;
                        q.push({x + dx[d], y + dy[d]});
                    }
                }
                
            }
        }

        cnt++;
    }

    cout << cnt << endl;
}


//fill(&arr[0][0], &arr[MAX - 1][MAX], 7); 도 가능 / 0으로 초기화할 경우, memset이 더 편하며 memset이 fill보다 처리속도가 빠르다.
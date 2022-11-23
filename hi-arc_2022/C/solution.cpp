#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, k;
pair<int, int> king;
bool visited[3][3];
vector<pair<int, int>> queen;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(visited, 0, sizeof(visited));

    cin >> n >> k;
    cin >> king.first >> king.second;
    for(int i = 0; i < k; i++) { 
        int r, c;
        cin >> r >> c;
        queen.push_back({r, c});
    }

    solve();

    return 0;
}

void solve() {
    int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

    for(int i = 0; i < queen.size(); i++) {
        // cout << "Q : " << queen[i].first << " " << queen[i].second << endl;
        for(int j = 0; j < 9; j++) {
            int nx = king.first + dx[j];
            int ny = king.second + dy[j];

            if(nx < 1 || nx > n || ny < 1 || ny > n) {
                visited[1 + dx[j]][1 + dy[j]] = true;
                continue;
            }

            //cout << nx << " " << ny << endl;

            if(visited[1 + dx[j]][1 + dy[j]]) {
                continue;
            }

            if(queen[i].first == nx) {
                //cout << "first" << nx << ny << endl;
                visited[1 + dx[j]][1 + dy[j]] = true;
            }
            else if(queen[i].second == ny) {
                //cout << "second" << nx << ny << endl;
                visited[1 + dx[j]][1 + dy[j]] = true;
            }
            else if((queen[i].first + queen[i].second) ==(nx + ny)) {
                //cout << "add" << nx << ny << endl;
                visited[1 + dx[j]][1 + dy[j]] = true;
            }
            else if(queen[i].first - nx == queen[i].second - ny) {
                visited[1 + dx[j]][1 + dy[j]] = true;
            }
        }
    }

    /*
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    */
    

    if(visited[1][1]) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i == 1 && j == 1) {
                    continue;
                }

                if(!visited[i][j]) {
                    cout << "CHECK" << endl;
                    return ;
                }
            }   
        }

        cout << "CHECKMATE" << endl;
        return ;
    }
    else {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i == 1 && j == 1) {
                    continue;
                }

                if(!visited[i][j]) {
                    cout << "NONE" << endl;
                    return ;
                }
            }   
        }

        cout << "STALEMATE" << endl;
        return ;
    }
}
#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m, k;
vector<int> tree[11][11];
queue<pair<int, pair<int, int>>> q;
int a[11][11];
int year[11][11];
void spring();
void summer();
void fall();
void winter();
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            cin >> a[i][j];
            year[i][j] = 5;
        }
    }
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a][b].push_back(c);
    }

    solve();

    return 0;
}

void spring() {
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            if(tree[i][j].size() == 0) {
                continue;
            }

            vector<int> temp;

            sort(tree[i][j].begin(), tree[i][j].end(), less<int>());

            for(int s = 0; s < tree[i][j].size(); s++) {
                int age = tree[i][j][s];
         
                if(year[i][j] >= age) {
                   year[i][j] -= age;

                    temp.push_back(age + 1);
                }
                else {
                    q.push({age, {i, j}});
                }
            }

            tree[i][j].swap(temp);
        }        
    }

}

void summer() {
    while(!q.empty()) {
        int age = q.front().first;
        pair<int, int> now = q.front().second;

        q.pop();

        year[now.first][now.second] += age / 2;
    }
}

void fall() {
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            if(tree[i][j].size() == 0) {
                continue;
            }

            for(int s = 0; s < tree[i][j].size(); s++) {
                int age = tree[i][j][s];

                if(age % 5 == 0) {
                    for(int x = i - 1; x < i + 2; x++) {
                        for(int y = j - 1; y < j + 2; y++) {
                            if(x < 1 || x > n || y < 1 || y > n) {
                                continue;
                            }
                            if(x == i && y == j) {
                                continue;
                            }

                            tree[x][y].push_back(1);
                        }
                    }
                }
            }
        }
    }
}

void winter() {
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            year[i][j] += a[i][j];
        }
    }
}

void solve() {
    int result = 0;
    
    for(int i = 0; i < k; i++) {
        spring();
        summer();
        fall();
        winter();
    }

    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            if(tree[i][j].size() != 0) {
                result += tree[i][j].size();
            }
        }
    }

    cout << result << endl;
}
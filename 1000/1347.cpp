#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N, dir = 2; // dir은 동서남북 순
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<char> input;
set<pair<int, int> > can_move;
void change_dir(char c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        char temp;
        cin >> temp;
        input.push_back(temp);
    }

    int x = 0, y = 0, lower_x = 0, lower_y = 0, upper_x = 0, upper_y = 0;
    can_move.insert(make_pair(x, y));
    for(auto c: input) {
        if(c == 'R') {
            change_dir(c);
        } else if(c == 'L') {
            change_dir(c);
        } else if(c == 'F') {
            x = x + dx[dir];
            y = y + dy[dir];

            can_move.insert(make_pair(x, y));
            lower_x = min(x, lower_x);
            lower_y = min(y, lower_y);
            upper_x = max(x, upper_x);
            upper_y = max(y, upper_y);
        }
    }

    for(int i = lower_x; i <= upper_x; i++) {
        for(int j = lower_y; j <= upper_y; j++) {
            if(can_move.find(make_pair(i, j)) != can_move.end()) {
                cout << '.';
            } else {
                cout << '#';
            }
        }
        cout << endl;
    }

    return 0;
}

void change_dir(char c) {
    if(c == 'R') {
        if(dir == 0) {
            dir = 2;
        } else if(dir == 1) {
            dir = 3;
        } else if(dir == 2) {
            dir = 1;
        } else if(dir == 3) {
            dir = 0;
        }
    } else if(c == 'L') {
        if(dir == 0) {
            dir = 3;
        } else if(dir == 1) {
            dir = 2;
        } else if(dir == 2) {
            dir = 0;
        } else if(dir == 3) {
            dir = 1;
        }
    }
}
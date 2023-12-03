#include <bits/stdc++.h>

using namespace std;

#define endl \n
#define ll long long

int A, B, C;
bool visited[201][201][201];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    memset(visited, 0, sizeof(visited));

    cin >> A >> B >> C;
    
    solve();

    return 0;
}

void solve() {
    vector<int> answer;
    queue<pair<int, pair<int, int> > > q;

    q.push(make_pair(0, make_pair(0, C)));
    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second.first;
        int c = q.front().second.second;

        q.pop();

        // 해당 물의 양으로 기존에 계산한 적이 있는지 여부 확인
        if(visited[a][b][c]) {
            continue;
        }
        visited[a][b][c]= true;

        // A 물통의 물의 양이 0인 경우 answer에 저장
        if(a == 0) {
            answer.push_back(c);
        }

        // A에서 B로
        if(a + b > B) {
            q.push(make_pair(a + b - B, make_pair(B, c)));
        } else {
            q.push(make_pair(0, make_pair(a + b, c)));
        }

        // A에서 C로
        if(a + c > C) {
            q.push(make_pair(a + c - C, make_pair(b, C)));
        } else {
            q.push(make_pair(0, make_pair(b, a + c)));
        }

        // B에서 A로
        if(b + a > A) {
            q.push(make_pair(A, make_pair(b + a - A, c)));
        } else {
            q.push(make_pair(b + a, make_pair(0, c)));
        }

        // B에서 C로
        if(b + c > C) {
            q.push(make_pair(a, make_pair(b + c - C, C)));
        } else {
            q.push(make_pair(a, make_pair(0, b + c)));
        }

        // C에서 A로
        if(c + a > A) {
            q.push(make_pair(A, make_pair(b, c + a - A)));
        } else {
            q.push(make_pair(c + a, make_pair(b, 0)));
        }

        // C에서 B로
        if(c + b > B) {
            q.push(make_pair(a, make_pair(B, c + b - B)));
        } else {
            q.push(make_pair(a, make_pair(c + b, 0)));
        }
    }

    // answer 오름차순 정렬 필요
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    sort(answer.begin(), answer.end());
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}
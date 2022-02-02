#include <bits/stdc++.h>

using namespace std;

int before, after;
int result[3];
int participants[4][2];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    before = 0;
    after = 0;
    for(int i = 0; i < 4; i++) {
        cin >> participants[i][0] >> participants[i][1];
        before += participants[i][0];
        after += participants[i][1];
    }

    solve();

    return 0;
}

void solve() {
    int newParticipants = after - before;

    // 새로운 참가자가 있을 경우
    if(newParticipants) {
        participants[0][0] += newParticipants;
    }

    // promote count
    for(int i = 0; i < 4; i++) {
        result[i] = participants[i][0] - participants[i][1];
        participants[i + 1][0] += result[i];
    }

    // 결과 출력
    for(int i = 0; i < 3; i++) {
        cout << result[i] << endl;
    }
}
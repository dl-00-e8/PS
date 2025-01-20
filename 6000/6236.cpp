#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N, M, answer = 100001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int input;
        cin >> input;
    }

    int start = 0;
    int end = N - 1;

    while(start <= end) {

        answer = min(answer, k);
    }

    cout << answer << endl;

    return 0;
}
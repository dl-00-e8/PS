#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int solution(int N, int T, vector<vector<int> > chapter);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, T;
    vector<vector<int> > chapter;
    cin >> N >> T;
    for(int i = 0; i < N; i++) {
        int K, S;
        cin >> K >> S;
        vector<int> temp;
        temp.push_back(K);
        temp.push_back(S);
        chapter.push_back(temp);
    }

    cout << solution(N, T, chapter);

    return 0;
}

int solution(int N, int T, vector<vector<int> > chapter) {
    int answer = 0;
    int dp[101][10001];

    memset(dp, 0, sizeof(dp));

    for(int i = 1; i < N + 1; i++) {
        for(int j = 0; j < T + 1; j++) {
            vector<int> node = chapter[i - 1];
            if(node[0] <= j) {
                if(node[1] + dp[i - 1][j - node[0]] > dp[i - 1][j]) {
                    dp[i][j] = node[1] + dp[i - 1][j - node[0]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for(int i = 0; i < T + 1; i++) {
        answer = max(answer, dp[N][i]);
    }

    return answer;
}
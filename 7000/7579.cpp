#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int solution(int  N, int M, vector<int> active, vector<int> cost);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    vector<int> active;
    vector<int> cost;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int input;
        cin >> input;
        active.push_back(input);
    }
    for(int i = 0; i < N; i++) {
        int input;
        cin >> input;
        cost.push_back(input);
    }

    cout << solution(N, M, active, cost);

    return 0;
}

int solution(int  N, int M, vector<int> active, vector<int> cost) {
    int answer = 0;
    ll dp[101][10001];

    memset(dp, 0, sizeof(dp));

    int sum_cost = 0;
    for(int i = 0; i < N; i++) {
        sum_cost += cost[i];
    }

    for(int i = 1; i < N + 1; i++) {
        for(int j = 0; j < sum_cost + 1; j++) {
            if(j - cost[i - 1] >= 0) {
                if(dp[i - 1][j] < dp[i - 1][j - cost[i - 1]] + active[i - 1]) {
                    dp[i][j] = dp[i - 1][j - cost[i - 1]] + active[i - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    } 

    for(int i = 0; i < sum_cost + 1; i++) {
        if(dp[N][i] >= M) {
            answer = i;
            break;
        }
    }

    return answer;
}

/**
 * 메모리를 배낭 유형의 DP 배열로 보이기에는 MLE이 발생할 수 있다.
 * 비용을 배낭의 DP 배열로 활용한 뒤, 원하는 메모리 제한을 가장 적은 비용으로 달성한 경우를 찾는 방식으로 접근한다.
 */
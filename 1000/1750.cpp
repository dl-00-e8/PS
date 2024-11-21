#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define mod 10000003

int gcd(int a, int b);
int solution(int N, vector<int> elements);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    vector<int> elements;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int input;
        cin >> input;
        elements.push_back(input);
    }

    cout << solution(N, elements);

    return 0;
}

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int solution(int N, vector<int> elements) {
    int dp[N + 1][100001];

    memset(dp, 0, sizeof(dp));

    for(int i = 1; i < N + 1; i++) {
        dp[i][elements[i - 1]] = 1;
    }

    for(int i = 1; i < N + 1; i++) {
        int element = elements[i - 1];
        for(int j = 1; j < 100001; j++) { // dp[i][j] i번째 index기준으로 j라는 최대공약수를 만들 수 있는 경우의 수
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;

            int gcd_result = gcd(element, j);
            dp[i][gcd_result] += dp[i - 1][j];
            dp[i][gcd_result] %= mod;
        }
    }

    return dp[N][1];
}

/**
 * 
DP[i][j] += DP[i - 1][j] + DP[i - 1][k] -> i - 1번째 수까지 써서 최대공약수가 j가 되는 경우를 그대로 가져오고 j와 k의 최대공약수가 j가 되도록 하는 k를 찾아 DP[i - 1][k]를 더해주는 방식이다.
j를 만족시키는 gcd(j, k)를 찾는 과정이 복잡할 수 있다. 그렇기에, 아래와 같이 풀어낸다.
DP[i][j] += DP[i - 1][j]
DP[i][gcd(seq[i], j)] += DP[i - 1][j]
 */
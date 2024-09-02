#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

ll K, N, answer = 1, max_value = 1;
vector<ll> lan;
ll calc(ll mid);
void binary_search(ll left, ll right);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> K >> N;
    for(int i = 0; i < K; i++) {
        ll input;
        cin >> input;
        lan.push_back(input);

        // 최대값 찾기
        max_value = max(max_value, input);
    }

    binary_search(1, max_value);
    cout << answer << endl;

    return 0;
}

ll calc(ll mid) {
    ll result = 0;
    for(ll i = 0; i < K; i++) {
        result += lan[i] / mid;
    }
    return result;
}

void binary_search(ll left, ll right) {
    // 더 이상 탐색 불가
    if(left > right) {
        return;
    }

    ll mid = (left + right) / 2;
    // 랜선 잘랐을 때, 만들 수 있는 개수 = result
    ll result = calc(mid);
    // 달성한 경우
    if(result >= N) {
        answer = max(answer, mid);
        binary_search(mid + 1, right);

    // 달성하지 못한 경우
    } else {
        binary_search(left, mid - 1);
    }
} 

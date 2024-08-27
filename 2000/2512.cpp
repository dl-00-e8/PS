#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 1000000000

int N, budget, min_budget = INF, max_budget = 0;
int answer, sum; // 정답과 해당 정답으로 만들 수 있는 예산 총합
int limit[10001];
bool binary_search(int left, int right);
int calc(int mid);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(limit, 0, sizeof(limit));

    cin >> N;
    for(int i = 0; i < N; i++) {
        int input;
        cin >> input;
        limit[i] = input;

        max_budget = max(max_budget, input);
    }
    cin >> budget;

    min_budget = 0;
    binary_search(min_budget, max_budget);

    cout << answer << endl;

    return 0;
}

bool binary_search(int left, int right) {
    // 좌측이 우측보다 더 커진 값을 가지게 되면, 못 찾았으므로 false 반환    
    if(left > right) {
        return false;
    }

    int mid = (left + right) / 2;

    // 해당 예산으로 만들 수 있는 총합을 구함
    int result = calc(mid);
    // 맥시멈을 채울 수 있다면?
    if(result == budget) {
        answer = mid;
        sum = result;
        return true;
    // 맥시멈을 넘겨버렸다면?
    } else if(result > budget) {
        return binary_search(left, mid - 1);
    // 맥시멈을 못 채웠다면?
    } else {
        if(sum < result) {
            answer = mid;
            sum = result;
        }
        return binary_search(mid + 1, right);
    }
}

int calc(int mid) {
    int result = 0;

    for(int i = 0; i < N; i++) {
        if(limit[i] > mid) {
            result += mid;
        } else {
            result += limit[i];
        }
    }

    return result;
}
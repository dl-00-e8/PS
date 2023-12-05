#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int solve(int num);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cout << solve(n) << endl;

    return 0;
}

int solve(int num) {
    int answer = 0;

    while(num % 5 != 0 && num > 1) {
        num -= 2;
        answer++;
    }
    if(num == 1) {
        return -1;
    }
    answer += num / 5;

    return answer;
}
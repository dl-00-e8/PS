#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define MAX 100000000

int N;
vector<int> result;
bool is_prime(int x);
void backtracking(int x, int digitx);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    backtracking(2, 1);
    backtracking(3, 1);
    backtracking(5, 1);
    backtracking(7, 1);

    // Output
    for(int value : result) {
        cout << value << endl;
    }

    return 0;
}

bool is_prime(int x) {
    for(int i = 2; i < sqrt(x) + 1; i++) {
        if(x % i == 0) {
            return false;
        }
    }

    return true;
}

void backtracking(int x, int digit) {
    // 자릿수 만들어질 경우, result 값에 추가
    if(digit == N) {
        result.push_back(x);
        return;
    }

    for(int i = 1; i < 10; i++) {
        int temp = x * 10 + i;
    
        if(is_prime(temp)) {
            backtracking(temp, digit + 1);
        }
    }
}
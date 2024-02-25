#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int K, answer = 0;
stack<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    for(int i = 0; i < K; i++) {
        int input;

        cin >> input;
        if(input == 0 && s.size() != 0) {
            s.pop();
        }
        else {
            s.push(input);
        }
    }

    int stack_size = s.size();
    for(int i = 0; i < stack_size; i++) {
        answer += s.top();
        s.pop();
    }

    cout << answer << endl;

    return 0;
}
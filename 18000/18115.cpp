#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
vector<int> input;
queue<int> q;
deque<int> dq;
void solve(int input);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1; i < n + 1; i++) {
        q.push(i);    
    }
    for(int i = 1; i < n + 1; i++) {
        int temp;
        cin >> temp;
        input.push_back(temp);
    }

    for(int i = n - 1; i >= 0; i--) {
        solve(input[i]);
    }

    int dqSize = dq.size();
    for(int i = 0; i < dqSize; i++) {
        cout << dq.back() << " ";
        dq.pop_back();
    }
    cout << endl;

    return 0;
}

void solve(int input) {
    int now = q.front();

    if(input == 1) {
        dq.push_back(now);
    }
    else if(input == 2) {
        int temp = dq.back();
        dq.pop_back();
        dq.push_back(now);
        dq.push_back(temp);
    
    }
    else { 
        dq.push_front(now);
    }

    q.pop();
}
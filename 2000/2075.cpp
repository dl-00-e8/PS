#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
priority_queue<int, vector<int>, greater<int>> pq; //내림차순 정렬

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n * n; i++) {
        int input;
        cin >> input;
        if(i < n) {
            pq.push(input);
        }
        else {
            if(pq.top() < input) {
                pq.pop();
                pq.push(input);
            }
            else {
                continue;
            }
        }
    }

    cout << pq.top() << endl;

    return 0;
}
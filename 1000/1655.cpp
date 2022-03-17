#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    priority_queue<int, vector<int>, less<int>> small;
    priority_queue<int, vector<int>, greater<int>> big;
    for(int i = 0; i < n; i++) {
        int input;

        cin >> input;
        
        if(i == 0) {
            small.push(input);
            cout << small.top() << endl;
        }
        else if(i == 1) {
            if(input < small.top()) {
                cout << input << endl;
                small.push(input);
                big.push(small.top());
                small.pop();
            }
            else {
                cout << small.top() << endl;
                big.push(input);
            }
        }
        else {
            // 홀수 idx
            if(i % 2 == 0) {
                if(input > big.top()) {
                    big.push(input);
                    small.push(big.top());
                    big.pop();
                }
                else if(input < small.top()) {
                    small.push(input);
                }
                else if(small.top() <= input && input <= big.top()) {
                    small.push(input);
                }

                cout << small.top() << endl;
            }
            // 짝수 idx
            else {
                if(input > big.top()) {
                    big.push(input);
                }
                else if(input < small.top()) {
                    small.push(input);
                    big.push(small.top());
                    small.pop();
                }
                else if(small.top() <= input && input <= big.top()) {
                    big.push(input);
                }


                cout << small.top() << endl;
            }
        }
    }

    return 0;
}

/*
sort compare에서는
greater : 내림차순
less : 오름차순

pq에서는
greater : 작은 것부터 출력
less : 큰 거부터 출력
*/
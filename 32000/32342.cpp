#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Q;
    vector<string> S;
    vector<int> answer;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        string input;
        cin >> input;
        S.push_back(input);
    }

    for(int i = 0; i < Q; i++) {
        int result = 0;
        
        if(S[i].size() >= 3) {
            for(int j = 0; j < S[i].size() - 2; j++) {
                if(S[i][j] == 'W' && S[i][j + 1] == 'O' && S[i][j + 2] == 'W') {
                    result++;
                }
            }
        }
        
        answer.push_back(result);
    }

    for(auto value: answer) {
        cout << value << endl;
    }

    return 0;
}
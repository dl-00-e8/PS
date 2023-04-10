#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
set<string> s;
vector<string> answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string input;
        cin >> input;
        s.insert(input);
    }
    for(int i = 0; i < m; i++) {
        string input;
        cin >> input;

        auto result = s.find(input);
        if(result != s.end()) {
            answer.push_back(*result);
        }
    }

    sort(answer.begin(), answer.end(), less<string>());

    cout << answer.size() << endl;
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}
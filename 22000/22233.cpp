#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N, M;
set<string> keyword;
vector<string> split(string str, char delimiter);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string input;

        cin >> input;
        keyword.insert(input);
    }
    for(int i = 0; i < M; i++) {
        string input;
        cin >> input;
        vector<string> memo = split(input, ',');

        for(int j = 0; j < memo.size(); j++) {
            if (keyword.find(memo[j]) != keyword.end()) {
                keyword.erase(memo[j]);
            }
        }

        cout << keyword.size() << endl;
    }

    return 0;
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

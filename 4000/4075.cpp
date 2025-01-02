#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int T, N, D;
unordered_map<string, vector<string> > um;
vector<pair<string, int> > answer;
bool compare(pair<string, int> a, pair<string, int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}
int dfs(string idx, int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int i = 1; i <= T; i++) {
        um.clear();
        answer.clear();

        cin >> N >> D;

        for(int j = 0; j < N; j++) {
            string parent;
            int cnt;
            cin >> parent >> cnt;

            vector<string> child_list;
            while(cnt--) {
                string child;
                cin >> child;
                child_list.push_back(child);
            }
            um[parent] = child_list;
        }

        // Solution
        for(auto parent: um) {
            int result = dfs(parent.first, D);
            if(result > 0) {
                answer.push_back(make_pair(parent.first, result));
            }
        }
        sort(answer.begin(), answer.end(), compare);

        // OUTPUT
        int last = -1;
        cout << "Tree " << i << ":" << endl;
        for(int j = 0; j < answer.size(); j++) {
            if(j < 3 || answer[j].second == last) {
                cout << answer[j].first << " " << answer[j].second << endl;
                last = answer[j].second;
            }
        }
        if(i < T) {
            cout << endl;
        }
    }

    return 0;
}

int dfs(string idx, int depth) {
    // 목표 차수에 도달했으면 반환
    if(depth == 1) {
        return (um[idx].size() == 0) ? 0 : um[idx].size();
    }

    int result = 0;
    vector<string> child_list = um[idx];
    for(auto child: child_list) {
        if(!um.count(child)) {
            continue;
        }
        result += dfs(child, depth - 1);
    }

    return result;
}
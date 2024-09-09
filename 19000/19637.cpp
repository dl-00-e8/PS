#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N, M;
string result = "";
bool compare(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}
vector<pair<string, int> > names;
set<int> scores;
void search(int target, int left, int right);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string name;
        int score;
        cin >> name >> score;

        // 기존에 들어가지 않은 점수일 경우에만 추가
        if(scores.find(score) == scores.end()) {
            scores.insert(score);
            names.push_back(make_pair(name, score));
        }
    }

    // 오름 차순 정렬
    sort(names.begin(), names.end(), compare);

    for(int i = 0; i < M; i++) {
        int score;
        cin >> score;
        search(score, 0, names.size() - 1);
        cout << result << endl;
    }

    return 0;
}

void search(int target, int left, int right) {
    // 탈출 조건
    if(left > right) {
        return;
    }

    int mid = (left + right) / 2;
    if(names[mid].second == target) {
        result = names[mid].first;
        return;
    } else if(names[mid].second > target) {
        result = names[mid].first;
        search(target, left, mid - 1);
    } else {
        search(target, mid + 1, right);
    }
}
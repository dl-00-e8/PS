#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a,  pair<int, int>  b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }

    return a.second > b.second;
}

vector<int> solution(vector<int> answers) {
    int fIdx, sIdx, tIdx;
    vector<pair<int, int>> cnt;
    int first[] = {1, 2, 3, 4 ,5};
    int second[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int third[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> answer;

    cnt.push_back({1, 0});
    cnt.push_back({2, 0});
    cnt.push_back({3, 0});

    fIdx = 0;
    sIdx = 0;
    tIdx = 0;
    for(int i = 0; i < answers.size(); i++) {
        if(first[fIdx] == answers[i]) {
            cnt[0].second += 1;
        }
        if(second[sIdx] == answers[i]) {
            cnt[1].second += 1;
        }
        if(third[tIdx] == answers[i]) {
            cnt[2].second += 1;
        }
    
        fIdx++;
        sIdx++;
        tIdx++;

        if(fIdx >= (sizeof(first)/sizeof(int))) {
            fIdx = 0;
        }
        if(sIdx >= (sizeof(second)/sizeof(int))) {
            sIdx = 0;
        }
        if(tIdx >= (sizeof(third)/sizeof(int))) {
            tIdx = 0;
        }
    }

    sort(cnt.begin(), cnt.end(), compare);
    
    for(int i = 0; i < 3; i++) {
        if(cnt[i].second == cnt[0].second) {
            answer.push_back(cnt[i].first);
        }
    }

    return answer;
}
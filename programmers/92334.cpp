#include <bits/stdc++.h> 

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    bool reported[1001][1001];
    vector<int> record[1001];
    unordered_map<string, int> idx;
    vector<int> answer(id_list.size());

    memset(reported, 0, sizeof(reported));
    
    // idx 부여
    for(int i = 0; i < id_list.size(); i++) {
        idx[id_list[i]] =i;
    }
    
    for(auto r: report) {
        int loc = 0;
        for(int i = 0; i < r.size(); i++) {
            if(r[i] == ' ') {
                loc = i;
                break;
            }
        }
        string a = r.substr(0, loc);
        string b = r.substr(loc + 1, r.size() - loc);
        
        int a_idx = idx[a];
        int b_idx = idx[b];
        
        // 이미 신고한 적이 있다면
        if(reported[a_idx][b_idx]) {
            continue;
        }
        
        reported[a_idx][b_idx] = true;
        record[b_idx].push_back(a_idx);        
    }
    
    for(int i = 0; i < id_list.size(); i++) {
        if(record[i].size() >= k) {
            for(auto value: record[i]) {
                answer[value]++;
            }
        }
    }
    
    return answer;
}
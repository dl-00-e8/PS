#include <bits/stdc++.h>

using namespace std;

vector<string> split(string str, char keyword) {
    int idx = 0;
    vector<string> result;
    
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == keyword) {
            string divide = str.substr(idx, i - idx);
            result.push_back(divide);
            idx = i + 1;
        }
        
        if(i == str.size() - 1) {
            string divide = str.substr(idx);
            result.push_back(divide);
        }
    }

    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> user;
    queue<vector<string>> q;
    
    for(auto data: record) {
        vector<string> data_list = split(data, ' ');
        string order = data_list[0];
        string uid = data_list[1];
        
        if(order == "Enter") {
            string nickname = data_list[2];
            user[uid] = nickname;
            
            vector<string> temp;
            temp.push_back("Enter");
            temp.push_back(uid);
            q.push(temp);
        } else if(order == "Leave") {
            vector<string> temp;
            temp.push_back("Leave");
            temp.push_back(uid);
            q.push(temp);
        } else if(order == "Change") {
            string nickname = data_list[2];
            user[uid] = nickname;
            
            vector<string> temp;
            temp.push_back("Change");
            temp.push_back(uid);
            q.push(temp);
        }
    }
    
    while(!q.empty()) {
        vector<string> now = q.front();
        q.pop();
        
        if(now[0] == "Enter") {
            string result = user[now[1]] + "님이 들어왔습니다.";
            answer.push_back(result);
        } else if(now[0] == "Leave") {
            string result = user[now[1]] + "님이 나갔습니다.";
            answer.push_back(result);
        }
    }
    
    return answer;
}
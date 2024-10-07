#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    unordered_map<string, int> duration;
    vector<int> answer;
    
    for(auto term: terms) {
        string type = term.substr(0, 1);
        string dur_str = term.substr(2, term.size() - 1);
        int dur_int = stoi(dur_str);
        duration[type] = dur_int;
    }
    
    int t_year = stoi(today.substr(0, 4));
    int t_month = stoi(today.substr(5, 2));
    int t_day = stoi(today.substr(8, 2));
    
    for(int i = 0; i < privacies.size(); i++) {
        string privacy = privacies[i];
        int year = stoi(privacy.substr(0, 4));
        int month = stoi(privacy.substr(5, 2));
        int day = stoi(privacy.substr(8, 2));
        string type = privacy.substr(11, 1);
        
        int add = duration[type];
        if(day == 1) {
            month += (add - 1);
            day = 28;
        } else {
            month += add;
            day -= 1;
        }
        
        while(month > 12) {
            year++;
            month -= 12;
        }
        
        if(t_year > year) {
            answer.push_back(i + 1);
        } else if(t_year == year) {
            if(t_month > month) {
                answer.push_back(i + 1);
            } else if(t_month == month) {
                if(t_day > day) {
                    answer.push_back(i + 1);
                }
            }
        }
    }
    
    return answer;
}
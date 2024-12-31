#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> change_and_remove(string str) {
    vector<string> result_temp;
    unordered_map<string, int> result;
    
    // 2글자씩 끊어서 집합 생성 및 반환
    for(int i = 0; i < str.size() - 1; i++) {
        string temp = str.substr(i, 2);
        result_temp.push_back(temp);
    }
    
    for(auto data: result_temp) {
        if(!isalpha(data[0]) || !isalpha(data[1])) {
            continue;
        }
        string set;
        char ch = tolower(data[0]);
        set += ch;
        ch = tolower(data[1]);
        set += ch;
        
        if(result[set] == 0) {
            result[set] = 1;
        } else {
            result[set]++;
        }
    }
    
    return result;
}

int solution(string str1, string str2) {
    unordered_map<string, int> str1_list = change_and_remove(str1);
    unordered_map<string, int> str2_list = change_and_remove(str2);
    
    int find_set_size = 0;
    int union_set_size = 0;
    
    for(auto value: str1_list) {
        // 교집합인 경우
        if(str2_list[value.first]) {
            find_set_size += min(value.second, str2_list[value.first]);
            union_set_size += max(value.second, str2_list[value.first]);
        } else {
            union_set_size += value.second;
        }
    }
    
    for(auto value: str2_list) {
        if(!str1_list[value.first]) {
            union_set_size += value.second;
        }
    }
    
    if(union_set_size == 0 && find_set_size == 0) {
        return 65536;
    }
    
    float result = float(find_set_size) / union_set_size;
    return int(result * 65536);
}
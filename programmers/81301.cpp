#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    string result = "";
    string num_arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int idx = 0;
    while(idx < s.size()) {
        if('0' <= s[idx] && s[idx] <= '9') {
            result += s[idx];
            idx++;
        } else {
            for(int i = 0; i < 10; i++) {
                string num = num_arr[i];
                if(s.substr(idx, num.size()) == num) {
                    result += to_string(i);
                    idx = idx + num.size();
                    break;
                }
            }
        }
    }
    
    return stoi(result);
}
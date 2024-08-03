#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> nums) {
    set<int> s;
    
    int div = nums.size() / 2;    
    for(auto num: nums) {
        if(s.size() < div) {
            if(s.find(num) == s.end()) {
                s.insert(num);
            }         
        }   
    }
    
    return s.size();
}
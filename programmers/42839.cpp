#include <bits/stdc++.h>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    
    // 에라토스테네스의 체
    int prime[10000001];
    
    fill(&prime[0], &prime[0] + (sizeof(prime) / sizeof(int)), 1);
    
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2; i < sqrt(10000001); i++) {
        if(prime[i]) {
            for(int j = i + i; j < 10000001; j += i) {
                prime[j] = 0;
            }
        }
    }
    
    // 소수 찾기
    unordered_set<int> case_set;
    sort(numbers.begin(), numbers.end());
    do {
        for (int i = 1; i <= numbers.size(); i++) {
            string sub_str = numbers.substr(0, i);
            int num = stoi(sub_str);
            case_set.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    for(auto num: case_set) {
        if(prime[num]) {
            answer++;
        }
    }
    
    return answer;
}
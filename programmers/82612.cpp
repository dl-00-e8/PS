#include <bits/stdc++.h>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;

    long long temp = 0;
    for(long long i = 1; i < count + 1; i++) {
        temp += i;   
    }
    answer = temp * price - money;
    
    if(answer < 0) {
        answer = 0;
    }
    
    return answer;
}s
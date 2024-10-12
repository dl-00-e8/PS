#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    sort(wallet.begin(), wallet.end());
    
    while(true) {
        // 탈출 조건 명시
        if(bill[0] <= wallet[0] && bill[1] <= wallet[1]) {
            break;
        }
        
        if(bill[0] < bill[1]) {
            bill[1] /= 2;
        } else {
            bill[0] /= 2;
        }
        
        sort(bill.begin(), bill.end());
        
        answer++;
    }
    
    return answer;
}
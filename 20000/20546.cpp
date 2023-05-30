#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int money;
int stock[15];
int junhyeon();
int seongmin();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> money;
    for(int i = 1; i < 15; i++) {
        cin >> stock[i];
    }

    int j = junhyeon();
    int s = seongmin();

    if(j > s) {
        cout << "BNP" << endl;
    }
    else if(j == s) {
        cout << "SAMESAME" << endl;
    }
    else {
        cout << "TIMING" << endl;
    }

    return 0;
}

int junhyeon() {
    int nowm = money;  // 보유 현금
    int nows = 0; // 보유 주식

    for(int i = 1; i < 15; i++) {
        int temp = (nowm / stock[i]);
        nowm -=  (temp * stock[i]);
        nows += temp;
    }

    return nowm + (nows * stock[14]);
}

int seongmin() {
    int nowm = money;  // 보유 현금
    int nows = 0; // 보유 주식
    int incCnt = 0;
    int decCnt = 0;

    for(int i = 2; i < 15; i++) {
        if(stock[i] > stock[i - 1]) {
            incCnt++;
            decCnt = 0;
        }
        else if(stock[i] < stock[i - 1]) {
            incCnt = 0;
            decCnt++;
        }
        else {
            incCnt = 0;
            decCnt = 0;
        }

        if(decCnt == 3) {
            int temp = (nowm / stock[i]);
            nowm -=  (temp * stock[i]);
            nows += temp;
            incCnt = 0;
        }
        
        if(incCnt == 3) {
            int temp = (stock[i] * nows);
            nowm +=  temp;
            nows = 0;   
            decCnt = 0; 
        }
    }

    return nowm + (nows * stock[14]);
}
#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int num;
bool primeNum[4000001];
vector<int> prime;
int cnt[4000001];
int solprimee(int num);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 에라토스테네스의 체 Default
    memset(primeNum, 1, sizeof(primeNum));
    primeNum[0] == false;
    primeNum[1] == false;
    for(int i = 2; i < sqrt(4000000) + 1; i++) {
        if(primeNum[i]) {
            for(int j = i + i; j < 4000001; j += i) {
                primeNum[j] = false;
            }
        }
    }

    for(int i = 2; i < 4000001; i++) {
        if(primeNum[i]) {
            prime.push_back(i);
        }
    }

    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < prime.size(); i++) {
        int sum = 0;
        for(int j = i; j < prime.size(); j++) {  
            sum = sum + prime[j];

            if(sum > 4000000) {
                break;
            }
            else {
                cnt[sum]++;
            }
        }
    }

    cin >> num;

    cout << cnt[num] << endl;

    return 0;
}


/*
최대 소수의 범위가 400,000이므로 시작 당시
에라토스테네스의 체로 모든 소수들 구해놓고
각 수를 만들 수 있는 경우의 수를 찾기
*/
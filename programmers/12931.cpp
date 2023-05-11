#include <bits/stdc++.h>

using namespace std;
int solution(int n)
{
    int answer = 0;

      for(int i = 10; i < 1000000001; i *= 10) {
        int temp = n % i;
        cout << temp << endl;
        n -= temp;
        
        answer += temp / (i / 10);
        
        if(i > n) {
            break;
        }
    }

    return answer;
}
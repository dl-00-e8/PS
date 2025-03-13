#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    stack<char> st;
    
    for (char digit : number) {
        // 스택에 있는 값과 현재 숫자를 비교하여 삭제
        while (!st.empty() && k > 0 && st.top() < digit) {
            st.pop();
            k--;
        }
        st.push(digit);
    }

    // k가 남아있다면 스택의 뒤에서부터 k개의 숫자를 제거
    while (k--) {
        st.pop();
    }

    // 스택에 남은 값들을 결과 문자열로 변환
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;  // 역순으로 쌓이므로 앞에 추가
        st.pop();
    }

    return result;
}
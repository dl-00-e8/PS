#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
// #define ll long long

string S;
stack<char> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;
    for(auto c: S) {
        if(c == ')') {
            // ll num = 0;
            // ll mul = 1;
            string temp;

            // 괄호를 만나거나, 스택이 비지 않을때까지 반복
            while(!s.empty() && s.top() != '(') {
                char now = s.top();
                s.pop();
                temp += now;
                // num += mul * (now - '0');
                // mul *= 10;
            }
            // 괄호 스택에서 제거
            if(!s.empty() && s.top() == '(') {
                s.pop();
            }
            
            int K;
            if(!s.empty() && s.top() != '(' && s.top() != ')') {
                char now = s.top();
                s.pop();

                K = now - '0';
            } else {
                continue;
            }

            // string num_to_str = to_string(num);
            reverse(temp.begin(), temp.end());
            string repeat = "";
            while(K--) {
                // repeat += num_to_str;
                repeat += temp;
            }
            // cout << repeat << endl;

            for(auto r_c : repeat) {
                s.push(r_c);
            }
            // cout << "s size: " << s.size() << endl;
        } else {
            s.push(c);
        }
    }

    cout << s.size() << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define MAX 100000

string input;
vector<int> laser;
vector<pair<int, int> > stick;
int solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> input;

    cout << solve() << endl;

    return 0;
}

int solve() {
    int result = 0;
    stack<pair<char, int> > s;

    // 레이저와 막대기 위치 파싱
    for(int i = 0; i < input.length(); i++) {
        if(input[i] == '(') {
            s.push(make_pair(input[i], i + 1));
        }
        else if(input[i] == ')') {
            // 스택이 비어있지 않는 경우 판단 로직 진행
            if(!s.empty()) {
                pair<char, int> p = s.top();
                s.pop();

                if(p.first == '(' && p.second == i) {
                    laser.push_back(i);
                }
                else if(p.first == '(' && p.second != i) {
                    stick.push_back(make_pair(p.second, i + 1));
                }
                else {
                    s.push(make_pair(input[i], i + 1));
                }
            }   
        }
    }
    
    sort(laser.begin(), laser.end());

    for(pair<int, int> now : stick) {
        int temp_result = 0;
        
        for(int idx : laser) {
            if(now.first <= idx && idx < now.second) {
                temp_result++;
            }
        }

        result += temp_result + 1;
    }

    return result;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    bool uOper = false;
    string answer = "";
    string minNum, maxNum;
    vector<int> data;
    
    // vector<int>형 변환
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            continue;
        }
        else if(s[i] == '-') {
            uOper = true;
        }
        else if('0' <= s[i] && s[i] <= '9') {
            int now = s[i] - '0';

            // 몇 자리 숫자인지 확인
            int j = i + 1;
            while(j < s.size()) {
                if(s[j] == ' ') {
                    break;
                }
                
                if('0' <= s[j] && s[j] <= '9') {
                    int temp = s[j] - '0';
                    now = (now * 10) + temp;
                }
                
                j++;
            }
            i = j;

            if(uOper) {
                data.push_back((-1) * now);
                uOper = false;
            }
            else {
                data.push_back(now);
            }
        }
    }

    // data 오름차순 정렬
    sort(data.begin(), data.end(), less<int>());

    // int to string 변환
    minNum = to_string(data[0]);
    maxNum = to_string(data[data.size() - 1]);
    answer = minNum + ' ' + maxNum;
    
    return answer;
}
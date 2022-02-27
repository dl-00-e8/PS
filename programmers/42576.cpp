#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    bool end = true;
    string answer = "";
    
    sort(participant.begin(), participant.end(), greater<string>());
    sort(completion.begin(), completion.end(), greater<string>());
    
    for(int i = 0; i < completion.size(); i++) {
        if(participant[i] != completion[i]) {
            answer = participant[i];
            end = false;
            break;
        }
    }
    
    if(end) {
        answer = participant[participant.size() - 1];
    }
    
    return answer;
}
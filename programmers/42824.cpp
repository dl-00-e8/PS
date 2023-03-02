#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow;
    vector<int> answer;
    
    // row : 가로, col : 세로
    for(int col = 1; col <= total / 2; col++) {
        if(total % col != 0) {
            continue;
        }
        
        int row = total / col;
        
        if((row * 2) + (col * 2) - 4 == brown) {
            answer.push_back(row);
            answer.push_back(col);
            
            break;
        }
    }
    
    return answer;
}
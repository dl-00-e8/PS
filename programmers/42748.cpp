#include <algorithm>
#include <string>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int a = 0; a < commands.size(); a++) {
        int i, j, k;
        vector<int> temp;
        
        i = commands[a][0];
        j = commands[a][1];
        k = commands[a][2];
        
        for(int b = i - 1; b < j; b++) {
            temp.push_back(array[b]);
        }
        
        sort(temp.begin(), temp.end(), less<int>());
        
        answer.push_back(temp[k - 1]);
    }
    
    
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
        
    for(int i = 0; i < arr1.size(); i++) {
        vector<int> tempArr;
        for(int j = 0; j < arr2[0].size(); j++) {
            int temp = 0;
            for(int k = 0; k < arr1[i].size(); k++) {
                temp += arr1[i][k] * arr2[k][j];
            }
            tempArr.push_back(temp);
        } 
        answer.push_back(tempArr);
    }
    
    
    return answer;
}
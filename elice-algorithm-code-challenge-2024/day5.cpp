#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, sequence_size;
vector<int> v;
vector<int> result;
map<int, int> countMap;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    sequence_size = 1 << n;
    v.resize(sequence_size);
    for(int i = 0; i < sequence_size; i++) {
        cin >> v[i];
    }

    solve();
    
    return 0;
}

void solve() {
    sort(v.begin(), v.end());
    
    for(int i = 0; i < sequence_size; i++) {
        countMap[v[i]]++;
    }
    countMap[0] = 0;

    vector<int> tmp;

    while(result.size() < n) {
        int minValue = 0;
        for(int i = 0; i < sequence_size; i++) {
            if(countMap[v[i]] > 0) {
                minValue = v[i];
                countMap[minValue]--;
                break;
            }
        }

        for(int i = 0; i < tmp.size(); i++) {
            int sum = tmp[i] + minValue;
            if(countMap.find(sum) != countMap.end()) {
                countMap[sum]--;
                tmp.push_back(sum);
            }
        }
        tmp.push_back(minValue);
        result.push_back(minValue);
    }
    
    sort(result.begin(), result.end());

    for(int value: result) {
        cout << value << " ";
    }
    cout << endl;
}

/**
테스트 케이스 모음
3
1 4 7 3 0 6 5 2
-> 1 2 4

3
0 5 10 15 5 10 15 15
-> 5 5 5

4
0 1 2 3 3 4 5 6 100000 100001 100002 100003 100003 100004 100005 100006
-> 1 2 3 100000
 */

/**
 * 문제에서 어려웠던 점 
 * - 시간복잡도를 제대로 예상하지 못했다.
 * - 수열이 중복일 수 있다는 생각을 하지 못 했다.
 */
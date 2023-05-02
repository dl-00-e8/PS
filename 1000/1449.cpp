#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, l;
bool taped[1001];
vector<int> input;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(taped, 0, sizeof(taped));

    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        int temp;

        cin >> temp;
        input.push_back(temp);
    }   

    solve();

    return 0;
}

void solve() {
    int answer = 0;
    
    sort(input.begin(), input.end(), less<int>());

    for(int i = 0; i < n; i++) {
        bool check = false;
        for(int j = n - 1; j > i; j--) {
            if(input[j] - input[i] < l) {
                answer++;
                i = j;
                check = true;
                break;
            }
        }

        if(!check) {
            answer++;
        }
    }

    cout << answer << endl;
}
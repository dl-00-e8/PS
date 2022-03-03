#include <bits/stdc++.h>

using namespace std;

int n, result;
bool visited1[40];
bool visited2[40];
bool visited3[40];
void choose(int idx);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    result = 0;
    choose(0);

    cout << result << endl;

    return 0;
}

void choose(int idx) {
    if(idx == n) {
        result++;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(visited1[i] || visited2[i + idx] || visited3[idx - i + n - 1]) {
            continue;
        }
        visited1[i] = true;
        visited2[i + idx] = true;
        visited3[idx - i + n - 1] = true;
        choose(idx + 1);
        visited1[i] = false;
        visited2[i + idx] = false;
        visited3[idx - i + n - 1] = false;
    }
}
#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, m;
int result[9];
bool visited[9];
vector<int> num;
void backTracking(int idx, int count, int size, int selected);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int input;
        
        cin >> input;
        num.push_back(input);
    }

    sort(num.begin(), num.end(), less<int>());

    backTracking(0, 0, n, m);

    return 0;
}

void backTracking(int idx, int count, int size, int selected) {
    // Output
    if(count == selected) {
        for(int i = 0; i < selected; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    
    for(int i = 0; i < size; i++) {
        if(visited[i]) {
            continue;
        }

        visited[i] = true;
        result[count] = num[i];
        backTracking(i, count + 1, size, selected);
        visited[i] = false;
    }
}
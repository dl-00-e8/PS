#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> card;
vector<int> check;
bool binarySearch(int start, int end, int num);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        card.push_back(input);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int input;
        cin >> input;
        check.push_back(input);
    }
    
    solve();

    return 0;
}

bool binarySearch(int start, int end, int num) {
    int mid = (start + end) / 2;

    // start보다 end가 커지는 조건
    if(start > end) {
        return false;
    }
    
    // 찾는 번호가 현재 idx의 value보다 작을 때
    if(num < card[mid]) {
        return binarySearch(start, mid - 1, num);
    }
    // 찾는 번호와 동일할 때
    else if(num == card[mid]) {
        return true;
    }
    // 찾는 번호가 현재 idx의 value보다 클 때
    else {
        return binarySearch(mid + 1, end, num);
    }
}

void solve() {
    sort(card.begin(), card.end(), less<int>());

    for(int i = 0; i < m; i++) {
        if(binarySearch(0, n -1, check[i])) {
            cout << 1 << " ";
        }
        else {
            cout << 0 << " ";
        }
    }
}
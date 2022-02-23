#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define maxNum 100,000

int n, m;
vector<int> num;
vector<int> tree;
int init(int start, int end, int node);
int findMin(int start, int end, int node, int left, int right);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    tree.resize(4 * n);
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        num.push_back(input);
    }

    init(0, n -1, 1);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << findMin(0, n - 1, 1, a - 1, b - 1) << endl;
    }

    return 0;
}

// start : 시작 idx, end : 마지막 idx
int init(int start, int end, int node) {
    if(start == end) {
        return tree[node] = num[start];
    }
    int mid = (start + end) / 2;
    
    // 둘 중의 더 최솟값이 해당 노드의 값이 됨
    return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

// start : 시작 idx, end : 끝 idx, left, right : 최솟값을 구하는 범위
int findMin(int start, int end, int node, int left, int right) {
    // 범위 밖에 있는 경우
    if(left > end || right < start) return 1000000001;
    
    // 범위 안에 있는 경우
    if(left <= start && end <= right) return tree[node];
    
    // 범위를 더 쪼개야 하는 경우
    int mid = (start + end) / 2;
    return min(findMin(start, mid, node * 2, left, right), findMin(mid + 1, end, node * 2 + 1, left, right));
}
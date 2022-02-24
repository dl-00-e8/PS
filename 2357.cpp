#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define MAX 100000

int n, m;
vector<int> v(100001, 0);
int maxTree[4 * MAX];
int minTree[4 * MAX];
int minInit(int start, int end, int node);
int maxInit(int start, int end, int node);
int findMin(int start, int end, int node, int left, int right);
int findMax(int start, int end, int node, int left, int right);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    minInit(0, n - 1, 1);
    maxInit(0, n - 1, 1);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << findMin(0, n - 1, 1, a - 1, b -1) << " " << findMax(0, n - 1, 1, a - 1, b- 1) << endl;
    }

    return 0;
}

int minInit(int start, int end, int node) {
    if(start == end) {
        return minTree[node] = v[start];
    }

    int mid = (start + end) / 2;
    return minTree[node] = min(minInit(start, mid, node * 2), minInit(mid + 1, end, node * 2 + 1));
}

int maxInit(int start, int end, int node) {
    if(start == end) {
        return maxTree[node] = v[start];
    }

    int mid = (start + end) / 2;
    return maxTree[node] = max(maxInit(start, mid, node * 2), maxInit(mid + 1, end, node * 2 + 1));
}

int findMin(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 1000000001;

    if(left <= start && end <= right) return minTree[node];
    
    int mid = (start + end) / 2;
    return min(findMin(start, mid, node * 2, left, right), findMin(mid + 1, end, node * 2 + 1, left, right));
}

int findMax(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;

    if(left <= start && end <= right) return maxTree[node];
    
    int mid = (start + end) / 2;
    return max(findMax(start, mid, node * 2, left, right), findMax(mid + 1, end, node * 2 + 1, left, right));
}
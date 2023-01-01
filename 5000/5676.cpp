#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, k;
int x[100001];
int segTree[400001];
vector<int> result;
int invert(int x);
int init(int start, int end, int node);
int mul(int start, int end, int node, int left, int right);
int update(int start, int end, int node, int index, int value);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> n >> k) {
        memset(x, 0, sizeof(x));
        memset(segTree, 0, sizeof(segTree));

        for(int i = 0; i < n; i++) {
            cin >> x[i];
        }

        init(0, n - 1, 1);

        for(int i = 0; i < k; i++) {
            char input;

            cin >> input;
            if(input == 'C') {
                int i, v;
                cin >> i >> v;
                update(0, n - 1, 1, i - 1, v);
            }
            else if(input == 'P') {
                int i, j;
                cin >> i >> j;
                result.push_back(mul(0, n - 1, 1, i - 1, j - 1));
            }
        }


        for(int i = 0; i < result.size(); i++) {
            if(result[i] == 1) {
                cout << '+';
            }
            else if(result[i] == 0) {
                cout << 0;
            }
            else if(result[i] == -1) {
                cout << '-';
            }
        }
        cout << endl;

        vector<int>().swap(result);
    }

    return 0;
}

int invert(int x) {
    if(x == 0) {
        return 0;
    }
    else if(x > 0) {
        return 1;
    }
    
    return -1;
}

int init(int start, int end, int node) {
    if(start == end) {
        return segTree[node] = invert(x[start]);
    }

    int mid = (start + end) / 2;

    return segTree[node] = invert(init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1));
}

int mul(int start, int end, int node, int left, int right) {
    if(left > end || right < start) {
        return 1;
    }

    if(left <= start && end <= right) {
        return segTree[node];
    }

    int mid = (start + end) / 2;

    return invert(mul(start, mid, node * 2 , left, right) * mul(mid + 1, end, node * 2 + 1, left, right));
}

int update(int start, int end, int node, int index, int value) {
    if(index < start || index > end) {
        return segTree[node];
    }

    if(start == end) {
        return segTree[node] = invert(value);
    }

    int mid = (start + end) / 2;
    
    return segTree[node] = invert(update(start, mid, node * 2, index, value) * update(mid + 1, end, node* 2 + 1, index, value));
}

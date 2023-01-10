#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

ll n, m, k;
ll arr[1000001];
ll tree[1000000 * 4 + 1];
ll init(ll start, ll end, ll node);
void update(ll start, ll end, ll node, ll index, ll diff);
ll sum(ll start, ll  end, ll node, ll left, ll right);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(arr, 0, sizeof(arr));
    memset(tree, 0, sizeof(tree));

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        ll input;
        cin >> input;
        arr[i] = input;
    }

    init(0, n - 1, 1);

    for(ll i = 0; i < m + k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        if(a == 1) {
            update(0, n - 1, 1, b - 1, c - arr[b - 1]);
            arr[b - 1] = c;
        }
        else if(a == 2) {
            cout << sum(0, n - 1, 1, b - 1, c - 1) << endl;
        }
    }

    return 0;
}

ll init(ll start, ll end, ll node) {
    if(start == end) {
        return tree[node] = arr[start];
    }

    ll mid = (start + end) / 2;

    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(ll start, ll end, ll node, ll index, ll diff) {
    if(index < start || index > end) {
        return ;
    }

    tree[node] += diff;

    if(start == end) {
        return ;
    }

    ll mid = (start + end) / 2;

    update(start, mid, node * 2, index, diff);
    update(mid + 1, end, node * 2 + 1, index, diff);
}

ll sum(ll start, ll  end, ll node, ll left, ll right) {
    if(left > end || right < start) {
        return 0;
    }

    if(left <= start && end <= right) {
        return tree[node];
    }

    ll mid = (start + end) / 2;

    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
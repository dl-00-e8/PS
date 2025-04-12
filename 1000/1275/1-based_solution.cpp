#include <iostream>     // 입출력: cin, cout
#include <vector>       // 벡터
#include <queue>        // 큐, 우선순위 큐
#include <stack>        // 스택
#include <deque>        // 덱
#include <algorithm>    // sort, min, max, lower_bound 등
#include <cmath>        // 수학 함수: sqrt, pow, abs 등
#include <cstring>      // memset, strcpy 등 (C 스타일)
#include <string>       // string 클래스
#include <map>          // map, multimap
#include <set>          // set, multiset
#include <unordered_map> // unordered_map (필요시)
#include <unordered_set> // unordered_set (필요시)

using namespace std;

#define endl "\n"
#define ll long long

int N, Q;
vector<ll> v(100001, 0);
ll tree[4 * 100000 + 1]; // seg tree는 4배
ll init(int start, int end, int node); // start: 시작 인덱스, end: 끝 인덱스
ll sum(int start, int end, int node, int left, int right); // left, right: 구간 합을 구하고자 하는 범위
void update(int start, int end, int node, int index, ll diff); 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    for(int i = 1; i < N + 1; i++) {
        cin >> v[i];
    }

    init(1, N, 1); // node는 1번 부터 시작

    for(int i = 0; i < Q; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        if(x > y) {
            cout << sum(1, N, 1, y, x) << endl;
        } else {
            cout << sum(1, N, 1, x, y) << endl;
        }

        update(1, N, 1, a, b - v[a]);
        v[a] = b;
    }

    return 0;
}

ll init(int start, int end, int node) {
    if(start == end) {
        return tree[node] = v[start];
    }

    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int node, int left, int right) {
    if(left > end || right < start) {
        return 0;
    }

    if(left <= start && end <= right) {
        return tree[node];
    }
    
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, ll diff) {
    if(index < start || index >end) {
        return;
    }

    tree[node] += diff;
    if(start == end) {
        return ;
    }

    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, diff);
    update(mid + 1, end, node * 2 + 1, index, diff);
}
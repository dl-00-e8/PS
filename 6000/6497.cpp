#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int m, n, result;
int parent[20001];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int findParent(int parent[], int x);
void unionParent(int parent[], int a, int b);
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(true) {
        cin >> m >> n;

        // Break Condition
        if(m == 0 && n == 0) {
            break;
        }

        result = 0;
		memset(parent, 0, sizeof(parent));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>().swap(pq);

        // ÃÊ±âÈ­
        for(int i = 0; i < m; i++) {
            parent[i] = i;
        }

		for (int i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			pq.push({ z, {x, y} });

			result += z;
		}

        solve();
	}
	
	return 0;
}

int findParent(int parent[], int x) {
	if (parent[x] != x) {
		return parent[x] = findParent(parent, parent[x]);
	}

	return parent[x];
}

void unionParent(int parent[], int a, int b) {
	int pa = findParent(parent, a);
	int pb = findParent(parent, b);

	if (pa < pb) {
		parent[pa] = pb;
	}
	else {
		parent[pb] = pa;
	}
}

void solve() {
	while (!pq.empty()) {
		int nowC = pq.top().first;
		int nowX = pq.top().second.first;
		int nowY = pq.top().second.second;

		pq.pop();

		if (findParent(parent, nowX) != findParent(parent, nowY)) {
			unionParent(parent, nowX, nowY);
            result -= nowC;
		}
	}

    cout << result << endl;
}
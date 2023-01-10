#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <stack>

using namespace std;

#define endl "\n"
#define INF 987654321

int n, x, y, m;
int relation[101];
vector<int> parent[101];
vector<int> child[101];
void solve(int x, int y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	fill(&relation[0], &relation[0] + sizeof(relation) / sizeof(int), INF);
	
	cin >> n;
	cin >> x >> y;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		
		parent[b].push_back(a);
		child[a].push_back(b);
	}
	
	solve(x, y);
	
	return 0;
}

void solve(int x, int y) {
	queue<int> q;
	
	q.push(x);
	relation[x] = 0;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		
		for(int i = 0; i < parent[now].size(); i++) {
			int next = parent[now][i];
			
			if(relation[next] > relation[now] + 1) {
				relation[next] = relation[now] + 1;	
				q.push(next);
			}
		}
		
		for(int i = 0; i < child[now].size(); i++) {
			int next = child[now][i];
			
			if(relation[next] > relation[now] + 1) {
				relation[next] = relation[now] + 1;	
				q.push(next);
			}
		}	
	}
	
	
	
	if(relation[y] != INF) {
		cout << relation[y] << endl;	
	}
	else {
		cout << -1 << endl;	
	}
}

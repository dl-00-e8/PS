#include <bits/stdc++.h>

using namespace std;

int n, del, cnt;
struct node {
	int parent;
	bool remove;
	vector<int> child;
};
vector<node> tree(51);
void bfs(int start);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> tree[i].parent;
		tree[i].remove = false;
		if(tree[i].parent != -1) {
			tree[tree[i].parent].child.push_back(i);
		}
	}
	cin >> del;

	bfs(del);
	
	cnt = 0;
	for(int i = 0; i < n; i++) {
		if(tree[i].remove == false) {
			if(tree[i].child.size() == 0) {
				cnt++;
			}
			else if(tree[i].child.size() > 0) {
				bool check = true;
				
				for(int j = 0; j < tree[i].child.size(); j++) {
					if(tree[tree[i].child[j]].remove == false) {
						check = false;
					}
				}
				
				if(check) {
					cnt++;
				}
			}
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}

void bfs(int start) {	
	int now;
	queue<int> q;
	
	q.push(start);
	tree[start].remove = true;
	while(!q.empty()) {
		now = q.front();
		q.pop();
		
		for(int i = 0; i < tree[now].child.size(); i++) {
			if(tree[tree[now].child[i]].remove == false) {
				tree[tree[now].child[i]].remove = true;
				q.push(tree[now].child[i]);
			}
		}
	}

}
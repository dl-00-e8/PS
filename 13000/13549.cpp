#include <bits/stdc++.h>

using namespace std;

int n, k;
int visited[100001];
void bfs(int start);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	
	fill(visited, visited + sizeof(visited)/sizeof(int), 987654321);
	
	bfs(n);
	
	cout << visited[k] << endl;
	
	return 0;
}

void bfs(int start) {
	int now, move, temp;
	int dir[] = {-1, 1, 2};
	queue<int> q;
	
	q.push(start);
	visited[start] = 0;
	while(!q.empty()) {
		now = q.front();
		q.pop();
		
		for(int i = 0; i < 3; i++) {
			if(i == 2) {
				move = now * dir[i];
				temp = visited[now];
			}
			else {
				move = now + dir[i];
				temp = visited[now] + 1;
			}
			
			if(0 > move || move > 100000) {
				continue;
			}
			
			if(visited[move] > temp) {
				visited[move] = temp;
				q.push(move);
			}
		}
	}
}
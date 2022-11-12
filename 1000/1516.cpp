#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int indigree[501];
vector<int> graph[501];
int cost[501];
int result[501];
void topologySort();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(indigree, 0, sizeof(indigree));
	memset(cost, 0, sizeof(cost));
	memset(result, 0, sizeof(result));
	
	cin >>  n;
	for(int i = 1; i < n + 1; i++) {
		int time, input;
		cin >> time;
		cost[i] = time;
		
		while(true) {
			cin >> input;
			
			if(input == -1) {
				break;
			}
			else {
				indigree[i]++;
				graph[input].push_back(i);
			}	
		}	
	}
	
	topologySort();
	for(int i = 1; i < n + 1; i++) {
		cout << result[i] << endl;	
	}
	
	return 0;	
}

void topologySort() {
	queue<int> q;
	
	for(int i = 1; i < n + 1; i++) {
		if(!indigree[i]) {
			q.push(i);	
		}	
	}
	
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		
		result[now] += cost[now]; 
		
		for(int i = 0; i < graph[now].size(); i++) {
			indigree[graph[now][i]]--;
			
			// have to update the code
            result[graph[now][i]] = max(result[graph[now][i]], result[now]);
			
			if(indigree[graph[now][i]] == 0) {
				q.push(graph[now][i]);
			}	
		}
	}
}

/*
have to check adding twice about same value.
in topologySort, check about max time.
*/
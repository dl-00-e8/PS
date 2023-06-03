#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>

using namespace std;

#define endl "\n"
#define INF 10000000000
#define ll long long

int n, m;
vector<pair<ll, pair<ll, ll>>> graph;
ll dist[501];
void bellmanFord(int start);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	fill(&dist[0], &dist[0] + sizeof(dist) / sizeof(ll), INF);
	
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		ll a, b, c;
		
		cin >> a >> b >> c;
		graph.push_back({c, {a, b}});	
	}
	
	bellmanFord(1);
	
	return 0;
}

void bellmanFord(int start) {
	dist[start] = 0;
	
	for(int i = 1; i < n + 1; i++) {
		for(int j = 0; j < m; j++) {
			int now = graph[j].second.first;
			int next = graph[j].second.second;
			int cost = graph[j].first;
			
			if(dist[now] != INF && dist[next] > dist[now] + cost) {
				dist[next] = dist[now] + cost;
				
				// negative cycle
				if(i == n) {
					cout << -1 << endl;
					return ;	
				}
			}	
		}	
	}
	
	for(int i = 2; i < n + 1; i++) {
		if(dist[i] != INF) {
			cout << dist[i] << endl;
		}
		else {
			cout << -1 << endl;	
		}	
	}
}

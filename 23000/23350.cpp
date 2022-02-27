#include <bits/stdc++.h>

using namespace std;

int n, m, maxRank;
int rankCnt[101];
queue<pair<int, int>> q;
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	maxRank = 0;
	while(n--) {
		int p, w;
		cin >> p >> w;
		q.push({p, w});
		rankCnt[p]++;
		maxRank = max(maxRank, p);
	}
	
	solve();
	
	return 0;
}

void solve() {
	int move;
	int result = 0;
	pair<int, int> now;
	stack<pair<int, int>> space;
	stack<pair<int, int>> temp;

	while(!q.empty()) {
		now = q.front();
		q.pop();
		
		// cout << "now : " << now.first << ", " << now.second << endl;
		
		if(maxRank == now.first) {
			if(space.empty()) {
				space.push(now);
				result += now.second;
				// cout << "적재 공간 이동 : " << now.second << endl;
			}
			else {
				// 만약 적재했던 것을 나머지 공간에 옮겨놓고 다시 적재해야 하는 경우에 대한 구현
				move = 0;
				while(true) {
					if(space.empty()) {
						space.push(now);
						move += now.second;
						// cout << "빈공간 적재 진행 : " << now.second << endl;
						break;
					}
					else {
						if(space.top().first == now.first) {
							if(space.top().second < now.second) {
								// cout << "무게 차이로 나머지 공간 이동 : " << space.top().second << endl;
								temp.push(space.top());
								move += space.top().second;
								space.pop();								
							}
							else if(space.top().second >= now.second) {
								// cout << "적재 진행 : " << now.second << endl;
								space.push(now);
								move += now.second;
								break;
							}
						}
						else if(space.top().first > now.first) {
							// cout << "우선순위 차이로 바로 적재 진행 : " << now.second << endl;
							space.push(now);
							move += now.second;
							break;
						}
					}
				}	
				while(!temp.empty()) {
					// cout << "나머지 공간에서 적재 공간 원위치 : " << temp.top().second << endl;
					space.push(temp.top());
					move += temp.top().second;
					temp.pop();
				}
				
				result += move;
				// cout << "결과 : " << result << endl;
			}
			
			rankCnt[maxRank]--;
			if(rankCnt[maxRank] == 0) {
				maxRank--;
			}
		}
		else {
			q.push(now);
			result += now.second;
			// cout << "뒤로 미루기 : " << now.second << endl;
		}
	}
	
	cout << result << endl;
}
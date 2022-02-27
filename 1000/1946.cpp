#include <bits/stdc++.h>

using namespace std;

int n, t;
bool compare(pair<int, int> a, pair<int, int> b);
void recruit(vector<pair<int, int>> &v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	
	for(int test = 0; test < t; test++) {
		vector<pair<int, int>> v;
		
		cin >> n;
		for(int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back(pair<int, int>(a, b));
		}
		recruit(v);
	}
	
	return 0;
}

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

void recruit(vector<pair<int, int>> &v) {
	int result = 1;
	
	sort(v.begin(), v.end(), compare);
	
	int temp = v[0].second;
	for(int i = 1; i < v.size(); i++) {
		if(v[i].second < temp) {
			result++;
			temp = v[i].second;
		}
		
	}
	
	cout << result << "\n";
}

/*
처음 생각 : 내림차순으로 정렬하여 비교
내림차순 정렬 시
7 3
6 1
5 7
4 2
3 6
2 5
1 4

위와 같은 풀이 방식이면 3 6은 채용불가로 뜨는데,
실질적으로는 7 3보다 두번째것이 크므로 채용 가능이다.

정답 풀이 : 오름차순으로 정렬하여 비교
(문제 내에서 성적이 '순위'로 표현되었기 때문에, 오름차순으로 정렬하라는 의미임
--> 이런 건 파악할 수 있는 능력을 길러야 할 필요가 있을 듯)
*/
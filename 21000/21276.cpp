#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N, M;
string name[1001];
unordered_map<string, vector<string> > graph;
unordered_map<string, int> indegree; // 진입차수
unordered_map<string, vector<string> > child;
void topology_sort();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> name[i];
        vector<string> temp;
        vector<string> temp2;
        graph[name[i]] = temp;
        indegree[name[i]] = 0;
        child[name[i]] = temp2;
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        string X, Y;
        cin >> X >> Y;
        graph[Y].push_back(X);
        indegree[X]++;
    }

    topology_sort();
    
    return 0;
}

void topology_sort() {
    queue<string> q;
    vector<string> root;

    // root 찾기
    for(auto data: indegree) {
        if(data.second == 0) {
            q.push(data.first);
            root.push_back(data.first);
        }
    }

    while(!q.empty()) {
        string now = q.front();
        q.pop();

        // 진입차수를 하나씩 감소시킨다.
        for(auto p: graph[now]) {
            if(--indegree[p] == 0) {
                q.push(p);

                if(!child.count(now)) {
                    vector<string> child_list;
                    child_list.push_back(p);
                    child[now] = child_list;
                } else {
                    child[now].push_back(p);
                }
            }
        }
    }

    // Output
    sort(root.begin(), root.end());
    cout << root.size() << endl;
    for(auto r: root) {
        cout << r << " ";
    }
    cout << endl;
    // 정렬 후 출력
    vector<pair<string, vector<string> > > answer;
    for(auto c: child) {
        answer.push_back(make_pair(c.first, c.second));
    }
    sort(answer.begin(), answer.end());
    for(auto a: answer) {
        cout << a.first << " " << a.second.size() << " ";
        
        vector<string> temp;
        for(auto as: a.second) {
            temp.push_back(as);
        }
        sort(temp.begin(), temp.end());

        for(auto t: temp) {
            cout << t << " ";
        }
        cout << endl;
    }
}
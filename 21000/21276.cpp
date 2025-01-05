#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N, M;
string name[1001];
unordered_map<string, vector<string> > graph;
void topology_sort();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> name[i];
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;

    }
    
    return 0;
}

void topology_sort() {
    
}
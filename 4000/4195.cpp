#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define MAX 100000 * 2

int t, f, value;
map<string, int> m;
int parent[MAX + 1];
int cnt[MAX + 1];
int findParent(int parent[], int x);
void unionParent(int parent[], int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        memset(cnt, 0, sizeof(cnt));
        memset(parent, 0, sizeof(parent));
        m.clear();
        value = 1;

        cin >> f;

        for(int i = 0; i < f; i++) {
            int a, b;
            string A, B;
            cin >> A >> B;

            if(m.find(A) != m.end()) {
                a = m.find(A)->second;
            }
            else {
                a = value;
                parent[value] = value;
                m.insert({A, value});
                value++;
            }
            
            if(m.find(B) != m.end()) {
                b = m.find(B)->second;
            }
            else {
                b = value;
                parent[value] = value;
                m.insert({B, value});
                value++;
            }
            
            unionParent(parent, a, b);
        }
    }
    
    return 0;
}

int findParent(int parent[], int x) {
    if(parent[x] != x) {
        return parent[x] = findParent(parent, parent[x]);
    }

    return parent[x];
}

void unionParent(int parent[], int a, int b) {
    int pa = findParent(parent, a);
    int pb = findParent(parent, b);
    
    if(pa < pb) {
        parent[pb] = pa;
        cnt[pa] += cnt[pb] + 1;
        
        cout << cnt[pa] + 1 << endl;
    }
    else if(pa == pb) {
        cout << cnt[pa] + 1 << endl;    
    
        return ;
    }
    else {
        parent[pa] = pb;
        cnt[pb] += cnt[pa] + 1;

        cout << cnt[pb] + 1 << endl;
    }
}
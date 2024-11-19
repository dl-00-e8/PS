#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

vector<int> solution(int N, int R, int Q, vector<vector<int> > graph, vector<int> U);
void make_tree(int current_node, int parent_node, vector<int> connect[], vector<int> child[], int parent[]);
void count_subtree_nodes(int current_node, vector<int> child[], int subtree_size[]);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, R, Q;
    vector<vector<int> > graph;
    vector<int> U;

    cin >> N >> R >> Q;
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);
        graph.push_back(temp);
    }
    for(int i = 0; i < Q; i++) {
        int u;
        cin >> u;
        U.push_back(u);
    }

    vector<int> answer = solution(N, R, Q, graph, U);
    for(auto value: answer) {
        cout << value << endl;
    }

    return 0;
}

void make_tree(int current_node, int parent_node, vector<int> connect[], vector<int> child[], int parent[]) {
    for(auto node: connect[current_node]) {
        if(node != parent_node) {
            child[current_node].push_back(node);
            parent[node] = current_node;
            make_tree(node, current_node, connect, child, parent);
        }
    }
}

void count_subtree_nodes(int current_node, vector<int> child[], int subtree_size[]) {
    subtree_size[current_node] = 1;
    for(auto node: child[current_node]) {
        count_subtree_nodes(node, child, subtree_size);
        subtree_size[current_node] += subtree_size[node];
    }
}

vector<int> solution(int N, int R, int Q, vector<vector<int> > graph, vector<int> U) {
    vector<int> answer;
    vector<int> connect[N + 1];
    vector<int> child[N + 1];
    int subtree_size[N + 1];
    int parent[N + 1];
    
    memset(subtree_size, 0, sizeof(subtree_size)); // 서브트리 내에 자기자신은 꼭 포함되기에
    for(int i = 1; i < N + 1; i++) {
        parent[i] = i;
    }
    parent[R] = -1;

    for(auto data: graph) {
        int x = data[0];
        int y = data[1];
        connect[x].push_back(y);
        connect[y].push_back(x);
    }

    make_tree(R, -1, connect, child, parent);
    count_subtree_nodes(R, child, subtree_size);

    for(auto node: U) {
        answer.push_back(subtree_size[node]);
    }

    return answer;
}
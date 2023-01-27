#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int graph[55][55];
int change(char c);
char reverse(int i);
void floydWarshall();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));

    cin >> n;
    for(int i = 0; i < n; i++) {
        int first, second;

        for(int j = 0; j < 4; j++) {
            char input;
            cin >> input;
            
            if(j == 0) {
                first = change(input);
            }
            else if(j == 3) {
                second = change(input);
            }
        }

        graph[first][second] = 1;
    }
    
   floydWarshall();

    return 0;
}

int change(char c) {
    int num;

    if('A' <= c && c <= 'Z') {
        num = c - 'A';
    }
    else {
        num = c - 'a' + 26;
    }

    return num;
}

char reverse(int i) {
    char c;
    
    if(0 <= i && i <= 25) {
        c = i + 'A';    
    }
    else {
        c = i - 26 + 'a';
    }

    return c;
}

void floydWarshall() {
    vector<pair<char, char>> result;

    for(int k = 0; k < 55; k++) {
        for(int i = 0; i < 55; i++) {
            for(int j = 0; j < 55; j++) {
                if(graph[i][k] == 1 && graph[k][j] == 1) {
                    graph[i][j] = 1;
                }
            }
        }
    }

    for(int i = 0; i < 55; i++) {
        for(int j = 0; j < 55; j++) {
            if(i == j) {
                continue;
            }

            if(graph[i][j] == 1) {
                result.push_back({reverse(i), reverse(j)});
            }
        }
    }

    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i++) {
        cout << result[i].first << " => " << result[i].second << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N;
vector<int> input;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 1; i < N; i++) {
        int color;
        cin >> color;

        input.push_back(color);
    }

    solve();

    return 0;
}

void solve() {
    int red_edges = 0;
    vector<int> component_size(N, 1);
    int components = N;

    for(auto color: input) {
        // 빨간색 간선인 경우
        if(color == 0) {
            int min1 = INT_MAX, min2 = INT_MAX;
            for(int size : component_size) {
                if(size > 0) {
                    if(size <= min1) {
                        min2 = min1;
                        min1 = size;
                    } else if(size < min2) {
                        min2 = size;
                    }
                }
            }
            red_edges += min1 * min2;

            for(int& size : component_size) {
                if(size == min2) {
                    size = 0;
                    break;
                }
            }
            for(int& size : component_size) {
                if(size == min1) {
                    size += min2;
                    break;
                }
            }
        // 파란색 간선인 경우
        } else {
            int max1 = 0, max2 = 0;
            for(int size : component_size) {
                if(size > max1) {
                    max2 = max1;
                    max1 = size;
                } else if(size > max2) {
                    max2 = size;
                }
            }

            for(int& size : component_size) {
                if(size == max2) {
                    size = 0;
                    break;
                }
            }
            for(int& size : component_size) {
                if(size == max1) {
                    size += max2;
                    break;
                }
            }
        }
        components--;
    }

    cout << red_edges << endl;
}
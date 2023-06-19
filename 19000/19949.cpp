#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int result = 0;
int arr[11];
int answer[11];
void choose(int cnt); 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(arr, 0, sizeof(arr));
    memset(answer, 0, sizeof(answer));

    for(int i = 1; i < 11; i++) {
        cin >> arr[i];
    }

    choose(0);

    cout << result << endl;

    return 0;
}

void choose(int cnt) {
    if(cnt == 10) {
        int temp = 0;
        for(int i = 1; i < 11; i++) {
            if(arr[i] == answer[i]) {
                temp++;
            }
        }

        if(temp >= 5) {
            result++;
        }

        return ;
    }

    for(int i = 1; i < 6; i++) {
        if(cnt > 1 && answer[cnt - 1] == i && answer[cnt] == i) {
            continue;
        }
        answer[cnt + 1] = i;
        choose(cnt + 1);
    }
}
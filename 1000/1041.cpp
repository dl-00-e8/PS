#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

ll n;
vector<ll> dice(6, 0);
ll solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < 6; i++) {
        cin >> dice[i];
    }

    cout << solve() << endl;

    return 0;
}

ll solve() {
    ll result = 0;

    if(n == 1) {
        sort(dice.begin(), dice.end(), greater<ll>());
        for(int i = 1; i < 6; i++) {
            result += dice[i];
        }
    }
    else {
        ll firstV, firstC, secondV, secondC, thirdV, thirdC;

        // 한 칸만 보여도 되는 경우
        firstC = ((n - 2) * (n - 2) * 5) + ((n - 2) * 4);
        firstV = *min_element(dice.begin(), dice.end());
        result += (firstV * firstC);

        // 두 칸만 보이면 되는 경우
        secondC = ((n - 2) * 8) + 4;
        secondV = 987654321;
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                if(i != j && i + j != 5){
                    secondV = min(secondV, dice[i] + dice[j]);
                }
            }
        }
        result += (secondV * secondC);

        // 세 칸 보이면 되는 경우
        thirdC = 4;
        thirdV = 987654321;
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                if(i == j || i + j == 5) {
                    continue;
                }
                for(int k = 0; k < 6; k++) {
                    if(i == k || j == k) {
                        continue;
                    }

                    if(i + k != 5 && j + k != 5) {
                        thirdV = min(thirdV, dice[i] + dice[j] + dice[k]);
                    }
                }
            }
        }
        result += (thirdC * thirdV); 

        // cout << firstV << " " << secondV << " " << thirdV << endl;
        // cout << firstC << " " << secondC << " " << thirdC << endl;
    }

    return result;
}
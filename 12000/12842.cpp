#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define MAX 1000000

vector<int> v;
bool prime[MAX + 1];
void setting();
string solve(int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    setting();

    while(true) {
        int input;

        cin >> input;

        if(input == 0) {
            break;
        }

        if(input < 6) {
            continue;
        }
        
        cout << solve(input) << endl; 
    }

    return 0;
}

void setting() {
    memset(prime, 1, sizeof(prime));

    prime[0] = false;
    prime[1] = false;
    
    for(int i = 2; i < sqrt(MAX); i++) {
        if(prime[i]) {
            v.push_back(i);
            for(int j = i * i; j < MAX + 1; j += i) {
                prime[j] = false;
            }
        }
    }
}

string solve(int x) {
    for(auto value : v) {
        int diff = x - value;
        if(prime[diff]) {
            return to_string(x) + " = " + to_string(value) + " + " + to_string(diff);
        }
    }
    
    return "Goldbach's conjecture is wrong.";
}
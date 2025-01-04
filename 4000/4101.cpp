#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b;
    
    while(true) {
        cin >> a >> b;
        
        if(a == 0 && b == 0) {
            break;
        }
        
        if(a > b) {
            cout << "Yes" << endl;
        } else { 
            cout << "No" << endl;
        }
    }
    
    return 0;
}

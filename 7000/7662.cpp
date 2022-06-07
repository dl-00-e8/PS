#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int t, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        multiset<int> ms;
        
        cin >> k;

        while(k--) {
            char input;
            int data;
            
            cin >> input >> data;
            if(input == 'I') {
                ms.insert(data);
            }
            else {
                if(ms.empty()) {
                    continue;
                }

                if(data == -1) {
                    ms.erase(ms.begin());
                }
                else {
                    auto loca = ms.end();
                    loca--;
                    ms.erase(loca);
                }
            }
        }

        if(ms.empty()) {
            cout << "EMPTY" << endl;
        }
        else {
            auto loca = ms.end();
            loca--;
            cout << *loca << " " << *ms.begin() << endl;
        }
    }    

    return 0;
}
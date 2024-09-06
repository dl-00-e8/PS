#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int p, m;
vector<pair<int, vector<pair<int, string> > > > room; 
bool compare(pair<int, string> a, pair<int, string> b) {
    return a.second < b.second;
}
void output();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> p >> m;
    for(int i = 0; i < p; i++) {
        int l;
        string n;

        cin >> l >> n;

        // 방이 아예 없는 경우
        if(room.empty()) {
            vector<pair<int, string> > player;
            player.push_back(make_pair(l, n));
            room.push_back(make_pair(l, player));
        } else {
            // 방 순회
            bool canEnter = false;
            for(int j = 0; j < room.size(); j++) {
                // 방에 입장 가능한 경우
                if(room[j].second.size() < m && (room[j].first - 10 <= l && l <= room[j].first + 10)) {
                    room[j].second.push_back(make_pair(l, n));
                    canEnter = true;
                    break;
                }
            }

            // 입장할 수 있는 방이 없는 경우
            if(!canEnter) {
                vector<pair<int, string> > player;
                player.push_back(make_pair(l, n));
                room.push_back(make_pair(l, player));
            }
        }
    }

    output();

    return 0;
}

void output() {
    for(int i = 0; i < room.size(); i++) {
        sort(room[i].second.begin(), room[i].second.end(), compare);
        
        if(room[i].second.size() == m) {
            cout << "Started!" << endl;
        } else {
            cout << "Waiting!" << endl;
        }

        for(int j = 0; j < room[i].second.size(); j++) {
            cout << room[i].second[j].first << " " << room[i].second[j].second << endl;
        }
    }
}

/**
 * 1. 매칭이 가능한 방이 있는지/없는지 확인
 * 2. 없다면 개설
 * 3. 있다면 입장 후 방 정원 찰 때까지 대기
 * 4. 입장 가능한 방이 여러 개라면 먼저 생성된 방에 입장
 * 5. 방에 정원이 모두 차면 게임 시작
 * 
 * 방에서 관리해야 하는 데이터
 * - 처음 입장한 플레이어의 레벨
 * - 현재 방에 있는 플레이어의 수
 * - 현재 방에 있는 플레이어의 정보 (닉네임 사전순으로 관리해야함)
 * 
 * 1초의 시간 제한
 * 플레이어의 수 1<=p<=300 / 방의 정원 1<=m<=300
 * 방의 정원이 1일 때, 플레이어의 수가 300이라면 -> 300*300 = 90000
 */
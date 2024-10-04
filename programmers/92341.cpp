#include <bits/stdc++.h>

using namespace std;

int calc(vector<int> fees, string in_time, string out_time) {
    int total_min = 0;
    
    int in_hour = stoi(in_time.substr(0, 2));
    int in_min = stoi(in_time.substr(3, 2));
    int out_hour = stoi(out_time.substr(0, 2));
    int out_min = stoi(out_time.substr(3, 2));
    
    if(out_min >= in_min) {
        // 10:44 12:44
        total_min += (out_hour - in_hour) * 60;
        total_min += out_min - in_min;
    } else {
        // 10:44 12:42
        total_min += (out_hour - in_hour - 1) * 60;
        total_min += (60 - (in_min - out_min));
    }
    
    return total_min;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    set<string> in_s; // 들어온 차 정보 관리
    unordered_map<string, string> in_m; // 차 입차 시간 관리
    unordered_map<string, int> result; // 차별로 총 주차 시간 관리
    vector<pair<string, int>> temp; // 차량번호 순서대로 정렬하기 위한 임시 벡터 배열
    vector<int> answer; // 결과 배열
    
    for(auto record: records) {
        string time = record.substr(0, 5);
        string car_num = record.substr(6, 4);
        string status = (record.size() == 13) ? record.substr(11, 2) : record.substr(11, 3);
        
        if(status == "IN") {
            in_s.insert(car_num);
            in_m[car_num] = time;
        } else if(status == "OUT") {
            // 입차 기록이 존재한다면
            if(in_s.find(car_num) != in_s.end()) {
                in_s.erase(car_num);
                
                // 주차 요금 계산
                int park_min = calc(fees, in_m[car_num], time);
                result[car_num] += park_min;
            }
        }
    }
    
    // 출차 기록이 없는 경우 계산
    for(auto e: in_s) {
        int park_min = calc(fees, in_m[e], "23:59");
        result[e] += park_min;
    }
    
    for(auto& r: result) {
        // 주차 금액 계산
        int cost = fees[1]; // 기본 요금 부과

        if(r.second > fees[0]) {
            r.second -= fees[0];

            if(r.second % fees[2] > 0) {
                cost += ((r.second / fees[2]) + 1) * fees[3];
            } else if(r.second % fees[2] == 0) {
                cost += ((r.second / fees[2])) * fees[3];
            }
        }
    
        temp.push_back({r.first, cost});   
    }
    
    sort(temp.begin(), temp.end());
    
    for(auto t: temp) {
        answer.push_back(t.second);
    }
    
    return answer;
}
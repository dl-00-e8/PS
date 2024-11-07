#include <bits/stdc++.h>

using namespace std;

bool compare1(pair<int, string> a, pair<int, string> b) {
    return a.first > b.first;
}

bool compare2(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> genre_map;
    unordered_map<string, vector<pair<int, int>>> genre_song;
    
    for(int i = 0; i < genres.size(); i++) {
        string genre = genres[i];
        int play = plays[i];
        
        // 장르 정보가 존재한다면,
        if(genre_map.find(genre) != genre_map.end()) {
            genre_map[genre] += play;
            genre_song[genre].push_back({i, play});
        } else {
            genre_map[genre] = play;
            vector<pair<int, int>> temp;
            temp.push_back({i, play});
            genre_song[genre] = temp;
        }
    }
    
    // 장르 재생 내림차순 정리
    vector<pair<int, string>> genre_vector;
    for(auto &m: genre_map) {
        genre_vector.push_back({m.second, m.first});
    }
    sort(genre_vector.begin(), genre_vector.end(), compare1);
    
    for(auto genre: genre_vector) {
        vector<pair<int, int>> song_vector = genre_song[genre.second];
        sort(song_vector.begin(), song_vector.end(), compare2);
        int cnt = 2;
        int size = song_vector.size();
        int idx = 0;
        while(cnt && size) {
            answer.push_back(song_vector[idx].first);
            idx++;
            cnt--;
            size--;
        }
    }
    
    return answer;
}
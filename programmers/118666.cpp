#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    int kakao_mbti[4]; // 양수 = R/C/J/A, 음수 = T/F/M/N
    
    memset(kakao_mbti, 0, sizeof(kakao_mbti));
    
    for(int i = 0; i < survey.size(); i++) {
        string s = survey[i];
        int c = choices[i];
        if(c == 4) {
            continue;
        }
        
        switch(s[0]) {
            case 'R':
                if(c > 4) {
                    kakao_mbti[0] -= (c - 4);
                } else if(c < 4) {
                    kakao_mbti[0] += (4 - c);
                }
                break;
            case 'T':
                if(c > 4) {
                    kakao_mbti[0] += (c - 4);
                } else if(c < 4) {
                    kakao_mbti[0] -= (4 - c);
                }
                break;
            case 'C':
                if(c > 4) {
                    kakao_mbti[1] -= (c - 4);
                } else if(c < 4) {
                    kakao_mbti[1] += (4 - c);
                }
                break;
            case 'F':
                if(c > 4) {
                    kakao_mbti[1] += (c - 4);
                } else if(c < 4) {
                    kakao_mbti[1] -= (4 - c);
                }
                break;
            case 'J':
                if(c > 4) {
                    kakao_mbti[2] -= (c - 4);
                } else if(c < 4) {
                    kakao_mbti[2] += (4 - c);
                }
                break;
            case 'M':
                if(c > 4) {
                    kakao_mbti[2] += (c - 4);
                } else if(c < 4) {
                    kakao_mbti[2] -= (4 - c);
                }
                break;
            case 'A':
                if(c > 4) {
                    kakao_mbti[3] -= (c - 4);
                } else if(c < 4) {
                    kakao_mbti[3] += (4 - c);
                }
                break;
            case 'N':
                if(c > 4) {
                    kakao_mbti[3] += (c - 4);
                } else if(c < 4) {
                    kakao_mbti[3] -= (4 - c);
                }
                break;
        }
    }
    
    cout << kakao_mbti[0] << " " << kakao_mbti[1] << " " << kakao_mbti[2] << " " << kakao_mbti[3] << "\n";
    
    string answer = "";
    if(kakao_mbti[0] >= 0) {
        if(kakao_mbti[1] >= 0) {
            if(kakao_mbti[2] >= 0) {
                if(kakao_mbti[3] >= 0) {
                    answer = "RCJA";
                } else if(kakao_mbti[3] < 0) {
                    answer = "RCJN";
                }
            } else if(kakao_mbti[2] < 0) {
                if(kakao_mbti[3] >= 0) {
                    answer = "RCMA";
                } else if(kakao_mbti[3] < 0) {
                    answer = "RCMN";
                }
            }
        } else if(kakao_mbti[1] < 0) {
            if(kakao_mbti[2] >= 0) {
                if(kakao_mbti[3] >= 0) {
                    answer = "RFJA";
                } else if(kakao_mbti[3] < 0) {
                    answer = "RFJN";
                }
            } else if(kakao_mbti[2] < 0) {
                if(kakao_mbti[3] >= 0) {
                    answer = "RFMA";
                } else if(kakao_mbti[3] < 0) {
                    answer = "RFMN";
                }
            }
        }
    } else if(kakao_mbti[0] < 0) {
        if(kakao_mbti[1] >= 0) {
            if(kakao_mbti[2] >= 0) {
                if(kakao_mbti[3] >= 0) {
                    answer = "TCJA";
                } else if(kakao_mbti[3] < 0) {
                    answer = "TCJN";
                }
            } else if(kakao_mbti[2] < 0) {
                if(kakao_mbti[3] >= 0) {
                    answer = "TCMA";
                } else if(kakao_mbti[3] < 0) {
                    answer = "TCMN";
                }
            }
        } else if(kakao_mbti[1] < 0) {
            if(kakao_mbti[2] >= 0) {
                if(kakao_mbti[3] >= 0) {
                    answer = "TFJA";
                } else if(kakao_mbti[3] < 0) {
                    answer = "TFJN";
                }
            } else if(kakao_mbti[2] < 0) {
                if(kakao_mbti[3] >= 0) {
                    answer = "TFMA";
                } else if(kakao_mbti[3] < 0) {
                    answer = "TFMN";
                }
            }
        }
    }
    
    return answer;
}
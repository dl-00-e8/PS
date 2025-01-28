import java.util.*;

class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        HashMap<String, Integer> wantMap = new HashMap<String, Integer>();
        HashMap<String, Integer> resultMap = new HashMap<String, Integer>();
        
        // 정보 저장
        for(int i = 0; i < want.length; i++) {
            wantMap.put(want[i], number[i]);
        }
        
        // 10일 이상 남았을 때만 진행
        for(int i = 0; discount.length - i > 9; i++) {
            // 첫 번째는 10개 다 삽입
            if(i == 0) {
                for(int j = 0; j < 10; j++) {
                    if(resultMap.get(discount[j]) != null) {
                        resultMap.replace(discount[j], resultMap.get(discount[j]) + 1);
                    } else {
                        resultMap.put(discount[j], 1);
                    }
                }
                
            } else {
                int idx = i - 1;
                resultMap.replace(discount[idx], resultMap.get(discount[idx]) -1);
                int nextIdx = idx + 10;
                if(resultMap.get(discount[nextIdx]) != null) {
                    resultMap.replace(discount[nextIdx], resultMap.get(discount[nextIdx]) + 1);
                } else {
                    resultMap.put(discount[nextIdx], 1);
                }
            }
            
            boolean check = true;
            for(String wantKey: wantMap.keySet()) {
                if (!wantMap.get(wantKey).equals(resultMap.getOrDefault(wantKey, -1))) {
                    check = false;
                    break;
                }
            }
            
            if(check) {
                answer++;
            }
        }
        
        return answer;
    }
}
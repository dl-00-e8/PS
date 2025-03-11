import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        Queue<Integer> q = new LinkedList<>(); // 서버별 반납 시간을 FIFO 큐에 삽입
        
        for(int i = 0; i < players.length; i++) {
            // 서버 반납
            while(!q.isEmpty() && q.peek() <= i) {
                q.poll();
            }
            
            int n = players[i] / m; // 필요한 서버 수
            
            // 서버가 필요하다면 && 기존 서버 수로 커버가 가능한지 확인
            if(n > 0 && n > q.size()) {
                int cnt = n - q.size();
                answer += cnt;
                while(cnt > 0) {
                    q.add(i + k);

                    cnt--;
                }
            }       
        }
        
        return answer;
    }
}
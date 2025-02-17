import java.io.*;
import java.util.*;

class Pair {
    String first;
    Integer second;

    public Pair(String first, Integer second) {
        this.first = first;
        this.second = second;
    }
}

public class Main {
    public static void main(String[] args) throws Exception {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] cnt = new int[10];

        int T = Integer.parseInt(br.readLine());
        for(int i = 1; i < T + 1; i++) {
            // Input
            String str = br.readLine();
            StringBuilder answer = new StringBuilder();

            // Logic
            // 오름차순 정렬되어 있으며, 동일한 숫자가 반복되어 나올 수 있음
            // z는 0만 가지고 있다.
            for (char c: str.toCharArray()) {
                if(c == 'Z') {
                    cnt[0]++;
                }
            }

            // w는 2만 가지고 있다.
            for (char c: str.toCharArray()) {
                if(c == 'W') {
                    cnt[2]++;
                }
            }

            // u는 4만 가지고 있다.
            for (char c: str.toCharArray()) {
                if(c == 'U') {
                    cnt[4]++;
                }
            }
            // x는 6만 가지고 있다.
            for (char c: str.toCharArray()) {
                if(c == 'X') {
                    cnt[6]++;
                }
            }

            // g는 8만 가지고 있다.
            for (char c: str.toCharArray()) {
                if(c == 'G') {
                    cnt[8]++;
                }
            }

            // 1은 0, 2, 4를 빼고 남은 o이다.
            for (char c: str.toCharArray()) {
                if(c == 'O') {
                    cnt[1]++;
                }
            }
            cnt[1] -= (cnt[0] + cnt[2] + cnt[4]);

            // 3은 2와 8을 빼고 남은 t이다.
            for (char c: str.toCharArray()) {
                if(c == 'T') {
                    cnt[3]++;
                }
            }
            cnt[3] -= (cnt[2] + cnt[8]);

            // 5는 4를 제거하고 남은 f이다.
            for (char c: str.toCharArray()) {
                if(c == 'F') {
                    cnt[5]++;
                }
            }
            cnt[5] -= cnt[4];

            // 7은 6을 제거하고 남은 s이다.
            for (char c: str.toCharArray()) {
                if(c == 'S') {
                    cnt[7]++;
                }
            }
            cnt[7] -= cnt[6];

            // 9는 5,6,8을 제거하고 남은 i이다.
            for (char c: str.toCharArray()) {
                if(c == 'I') {
                    cnt[9]++;
                }
            }
            cnt[9] -= (cnt[5] + cnt[6] + cnt[8]);

            for(int j = 0; j < 10; j++) {
                while(cnt[j] > 0) {
                    answer.append(j);
                    cnt[j]--;
                }
            }

            // Output
            bw.write("Case #" + i + ": " + answer + "\n");
        }

        bw.flush();
    }
}
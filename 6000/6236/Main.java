import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int answer = 10000 * 100000;

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        int[] moneyArray = new int[N];
        for(int i = 0; i < N; i++) {
            moneyArray[i] = Integer.parseInt(br.readLine());
        }

        // Solve
        int start = 1;
        int end = 10000 * 100000;

        while(start <= end) {
            int m = 0; // 인출 횟수 카운팅
            int mid = (start + end) / 2; // 인출할 K원
            int result = 0; // 현재 수중에 가지고 있는 돈
            boolean isPossible = true;

            for(int i = 0; i < N; i++) {
                // 수중에 보유하고 있는 돈으로 하루를 보낼 수 없는 경우
                if(moneyArray[i] > result) {
                    if(moneyArray[i] > mid) {
                        isPossible = false;
                        break;
                    }
                    m++; // 인출 횟수 증가
                    result = mid;
                }
                // 잔액 사용
                result -= moneyArray[i];
            }

            // 이분탐색 조건 갱신
            if(isPossible && m <= M) {
                end = mid - 1;
                answer = Math.min(answer, mid);
            }
            else {
                start = mid + 1;
            }
        }

        bw.write(answer + "\n");
        bw.flush();
    }
}

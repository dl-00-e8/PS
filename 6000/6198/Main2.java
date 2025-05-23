import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 입력
        int N = Integer.parseInt(br.readLine());
        int[] heights = new int[N];
        
        for(int i = 0; i < N; i++) {
            heights[i] = Integer.parseInt(br.readLine());
        }

        // 각 빌딩에서 볼 수 있는 빌딩 수를 미리 계산 (O(N) 스택 활용)
        int[] canSee = new int[N];
        Stack<Integer> stack = new Stack<>();
        
        // 오른쪽에서 왼쪽으로 진행
        for(int i = N - 1; i >= 0; i--) {
            // 현재 빌딩보다 낮은 빌딩들을 스택에서 제거하면서 카운트
            while(!stack.isEmpty() && heights[stack.peek()] < heights[i]) {
                int idx = stack.pop();
                canSee[i]++;
                canSee[i] += canSee[idx]; // 제거된 빌딩이 볼 수 있던 빌딩들도 현재 빌딩에서 볼 수 있음
            }
            stack.push(i);
        }
        
        // 모든 관리인이 볼 수 있는 빌딩 수의 합
        long totalCount = 0;
        for(int i = 0; i < N; i++) {
            totalCount += canSee[i];
        }

        // 출력
        bw.write(totalCount + "\n");
        bw.flush();
        
        br.close();
        bw.close();
    }
}
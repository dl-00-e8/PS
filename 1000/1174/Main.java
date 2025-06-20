import java.io.*;
import java.util.*;

public class Main {

    // Initial Setting
    static int N;
    static List<Long> results; // 조합 결과
    static boolean[] visited = new boolean[10];

    public static void main(String[] args) throws Exception {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // Initial Setting
        Arrays.fill(visited, false);
        results = new ArrayList<>();

        // Input
        N = Integer.parseInt(br.readLine());

        // Solution
        for (int i = 0; i < 10; i++) {
            dfs(i, i);
        }

        Collections.sort(results);

        // Output
        if (N > results.size()) {
            System.out.println(-1);
        } else {
            System.out.println(results.get(N - 1));
        }

        bw.flush();
    }

    // DFS로 줄어드는 수 만들기
    static void dfs(long num, int lastDigit) {
        results.add(num);

        for (int next = 0; next < lastDigit; next++) {
            dfs(num * 10 + next, next);
        }
    }
}
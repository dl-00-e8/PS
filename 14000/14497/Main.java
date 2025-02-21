import java.io.*;
import java.util.*;

class Pair<T, U> {
    T first;
    U second;

    public Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }
}

public class Main {
    public static void main(String[] args) throws Exception {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // Input
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        input = br.readLine().split(" ");
        int x1 = Integer.parseInt(input[0]);
        int y1 = Integer.parseInt(input[1]);
        int x2 = Integer.parseInt(input[2]);
        int y2 = Integer.parseInt(input[3]);

        int[][] graph = new int[301][301];
        for(int[] array: graph) {
            Arrays.fill(array, 0);
        }
        for(int i = 1; i < N + 1; i++) {
            input = br.readLine().split("");
            for(int j = 0; j < M; j++) {
                if(i == x1 && j == y1 - 1) {
                    graph[i][j + 1] = 0;
                    continue;
                } else if(i == x2 && j == y2 - 1) {
                    graph[i][j + 1] = 1;
                    continue;
                }
                graph[i][j + 1] = Integer.parseInt(input[j]);
            }
        }

        // Logic
        int[][] visited = new int [301][301];
        for(int[] array: visited) {
            Arrays.fill(array, Integer.MAX_VALUE);
        }
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        Queue<Pair<Pair<Integer, Integer>, Integer>> q = new LinkedList<>();
        q.add(new Pair<>(new Pair<>(x1, y1), 0));
        visited[x1][y1] = 0;
        while(!q.isEmpty()) {
            Pair<Pair<Integer, Integer>, Integer> now = q.poll();

            // 이미 더 작은 값으로 갱신되었다면 무시
            if (visited[now.first.first][now.first.second] < now.second) {
                continue;
            }

            for(int i = 0; i < 4; i++) {
                // 해당 방향으로 1이 있을 때까지 진행
                int nx = now.first.first + dx[i];
                int ny = now.first.second + dy[i];

                if(nx < 1 || nx > N || ny < 1 || ny > M) {
                    continue;
                }

                if(visited[nx][ny] > visited[now.first.first][now.first.second] + graph[nx][ny]) {
                    visited[nx][ny] = visited[now.first.first][now.first.second] + graph[nx][ny];
                    q.add(new Pair<>(new Pair<>(nx, ny), visited[nx][ny]));
                }
            }
        }

        // Output
        bw.write(String.valueOf(visited[x2][y2]));
        bw.flush();
    }
}
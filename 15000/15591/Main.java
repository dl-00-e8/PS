import java.io.*;
import java.util.*;

class Pair {
    int first;
    int second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

public class Main {
    public static int MAX_INT = 987654321;

    public static void main(String[] args) throws Exception {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input_first = br.readLine().split(" ");
        int N = Integer.parseInt(input_first[0]);
        int Q = Integer.parseInt(input_first[1]);

        ArrayList<Pair>[] graph = new ArrayList[N + 1];
        for (int i = 0; i < N + 1 ; i++) {
            graph[i] = new ArrayList<>();
        }
        for(int i = 0; i < N - 1; i++) {
            String[] connect = br.readLine().split(" ");
            int p = Integer.parseInt(connect[0]);
            int q = Integer.parseInt(connect[1]);
            int r = Integer.parseInt(connect[2]);
            graph[p].add(new Pair(q, r));
            graph[q].add(new Pair(p, r));
        }

        for(int i = 0; i < Q; i++) {
            String[] q_list = br.readLine().split(" ");
            int k = Integer.parseInt(q_list[0]);
            int v = Integer.parseInt(q_list[1]);

            boolean[] visited = new boolean[N + 1];
            Arrays.fill(visited, false);
            Queue<Integer> q = new LinkedList<>();
            q.add(v);
            visited[v] = true;
            while(!q.isEmpty()) {
                int now = q.poll();

                for(Pair next: graph[now]) {
                    if(!visited[next.first] && next.second >= k) {
                        visited[next.first] = true;
                        q.add(next.first);
                    }
                }
            }

            int answer = 0;
            for(int j = 1; j < N + 1; j++) {
                if(j == v) {
                    continue;
                }
                boolean visit = visited[j];
                if(visit) {
                    answer++;
                }
            }
            bw.write(answer + "\n");
        }

        bw.flush();
    }
}
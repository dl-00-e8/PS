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
    public static Integer MAX_INT = 1000000000;

    public static void main(String[] args) throws Exception {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] inputFirst = br.readLine().split(" ");
        int N = Integer.parseInt(inputFirst[0]);
        int M = Integer.parseInt(inputFirst[1]);

        int[] vision = new int[N];
        String[] inputSecond = br.readLine().split(" ");
        for(int i = 0; i < N; i++) {
            vision[i] = Integer.parseInt(inputSecond[i]);
        }

        ArrayList<Pair>[] graph = new ArrayList[N];
        for(int i = 0; i < N; i++) {
            graph[i] = new ArrayList<>();
        }
        for(int i = 0; i < M; i++) {
            String[] inputThird = br.readLine().split(" ");

            int a = Integer.parseInt(inputThird[0]);
            int b = Integer.parseInt(inputThird[1]);
            int t = Integer.parseInt(inputThird[2]);

            graph[a].add(new Pair(b, t));
            graph[b].add(new Pair(a, t));
        }

        int[] distance = new int[N];
        Arrays.fill(distance, MAX_INT);

        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingInt(p -> p.first));

        pq.add(new Pair(0, 0));
        distance[0] = 0;
        while(!pq.isEmpty()) {
            Pair now = pq.poll();

            for(Pair next: graph[now.second]) {
                if((vision[next.first] == 0 || next.first == N - 1) && now.first + next.second < distance[next.first]) {
                    distance[next.first] = now.first + next.second;
                    pq.add(new Pair(distance[next.first], next.first));
                }
            }
        }

        if(distance[N - 1] != MAX_INT) {
            bw.write(distance[N - 1]);
        } else {
            bw.write(-1);
        }

        bw.flush();
    }
}
import java.io.*;
import java.util.*;

class Pair {
    long first;
    int second;

    public Pair(long first, int second) {
        this.first = first;
        this.second = second;
    }

}

public class Main {
    public static Long MAX_NUM = 10000000001L;

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

            graph[a].add(new Pair(t, b));
            graph[b].add(new Pair(t, a));
        }

        long[] distance = new long[N];
        Arrays.fill(distance, MAX_NUM);

        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingLong(p -> p.first));

        pq.add(new Pair(0, 0));
        distance[0] = 0;
        while(!pq.isEmpty()) {
            Pair now = pq.poll();

            if(now.first > distance[now.second]) {
                continue;
            }

            for(Pair next: graph[now.second]) {
                if((vision[next.second] == 0 || next.second == N - 1) && now.first + next.first < distance[next.second]) {
                    distance[next.second] = now.first + next.first;
                    pq.add(new Pair(distance[next.second], next.second));
                }
            }
        }

        if(distance[N - 1] != MAX_NUM) {
            bw.write(String.valueOf(distance[N - 1]));
        } else {
            bw.write(String.valueOf(-1));
        }

        bw.flush();
    }
}
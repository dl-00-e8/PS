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

class TrieNode {
    Map<Character, TrieNode> children;
    boolean isEndOfWord;

    TrieNode() {
        children = new HashMap<>();
        isEndOfWord = false;
    }
}

public class Main {

    // Initial Setting
    static int N, H, T;
    static PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

    public static void main(String[] args) throws Exception {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // Input
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        H = Integer.parseInt(input[1]);
        T = Integer.parseInt(input[2]);
        for(int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            int height = Integer.parseInt(input[0]);
            pq.add(height);
        }

        // Solution
        int cnt = 0;
        while(T > 0) {
            int now = pq.peek();

            if(now < H) {
                break;
            }
            pq.poll();
            pq.add((now == 1) ? 1 : now / 2);

            T--;
            cnt++;
        }

        // Output
        if(pq.peek() < H) {
            bw.write("YES" + "\n");
            bw.write(cnt + "\n");
        } else {
          bw.write("NO" + "\n");
          bw.write(pq.poll() + "\n");
        }
        bw.flush();
    }
}
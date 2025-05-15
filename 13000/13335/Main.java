import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

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

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int w = Integer.parseInt(input[1]);
        int L = Integer.parseInt(input[2]);
        Queue<Integer> q = Arrays.stream(br.readLine().split(" "))
                .map(Integer::parseInt).collect(Collectors.toCollection(LinkedList::new));
        Queue<Integer> bridge = new LinkedList<>();
        // 다리를 0으로 채워
        for(int i = 0; i < w; i++) {
            bridge.add(0);
        }

        int answer = 0;
        int w_sum = 0;
        while(!bridge.isEmpty()) {
            answer++;
            Integer now = bridge.poll();
            w_sum -= now;

            if(!q.isEmpty()) {
                Integer truck = q.peek();

                if(w_sum + truck <= L) {
                    w_sum += truck;
                    bridge.add(truck);
                    q.poll();
                } else {
                    bridge.add(0);
                }
            }
        }

        bw.write(answer+"");
        bw.flush();
    }
}
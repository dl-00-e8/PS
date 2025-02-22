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
        int answer = 0;
        int N = Integer.parseInt(br.readLine());
        Queue<String> inputQ= new LinkedList<>();
        Queue<String> outputQ = new LinkedList<>();
        for(int i = 0; i < N; i++) {
            inputQ.add(br.readLine());
        }
        for(int i = 0; i < N; i++) {
            outputQ.add(br.readLine());
        }

        while(!outputQ.isEmpty()) {
            String now = outputQ.poll();
            if(!inputQ.peek().equals(now)) {
                answer++;
                inputQ.remove(now);
            } else {
                inputQ.poll();
            }
        }

        // Output
        bw.write(String.valueOf(answer));
        bw.flush();
    }
}
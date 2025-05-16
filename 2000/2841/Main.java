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

        // Initial Setting
        List<Stack<Integer>> stackList = new ArrayList<>(7);
        for(int i = 0; i < 7; i++) {
            stackList.add(new Stack<>());
        }

        // Input
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int P = Integer.parseInt(input[1]);

        // Solution
        int answer = 0;
        for(int i = 0; i < N; i++) {
            input = br.readLine().split(" " );
            int line = Integer.parseInt(input[0]);
            int pret = Integer.parseInt(input[1]);

            if(!stackList.get(line).isEmpty()) {
                while(!stackList.get(line).isEmpty() && stackList.get(line).peek() > pret) {
                    stackList.get(line).pop();
                    answer++;
                }
            }

            if(!stackList.get(line).isEmpty() && stackList.get(line).peek() == pret) {
                continue;
            }

            stackList.get(line).add(pret);
            answer++;
        }

        // Output
        bw.write(answer+"");
        bw.flush();
    }
}
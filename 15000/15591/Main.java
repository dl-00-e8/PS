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


    public static void main(String[] args) throws Exception {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input_first = br.readLine().split(" ");
        int N = Integer.parseInt(input_first[0]);
        int Q = Integer.parseInt(input_first[1]);

        ArrayList<Pair> graph[] = new ArrayList[N];
        for(int i = 0; i < N - 1; i++) {

        }
        ArrayList<Pair> v = new ArrayList<>();
        for(int i = 0; i < Q; i++) {
            String[] q_list = br.readLine().split(" ");
            int k = Integer.parseInt(q_list[0]);
            int v = Integer.parseInt(q_list[1]);

        }


        bw.flush();
    }
}
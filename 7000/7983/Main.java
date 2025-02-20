import java.io.*;
import java.util.*;

class Pair {
    Integer first;
    Integer second;

    public Pair(Integer first, Integer second) {
        this.first = first;
        this.second = second;
    }
}

public class Main {
    public static void main(String[] args) throws Exception {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));

        ArrayList<Pair> assignment = new ArrayList<>();

        int n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            int d = Integer.parseInt(input[0]);
            int t = Integer.parseInt(input[1]);

            assignment.add(new Pair(t, d)); // t를 기준으로 내림차순이므로 순서를 바꾸어 저장
        }

        assignment.sort((a, b) -> b.first.compareTo(a.first));

        int needToStart = assignment.get(0).first - assignment.get(0).second; // 과제를 반드시 시작해야 하는 날짜
        for(int i = 1; i < n; i++) {
            int deadline = assignment.get(i).first;
            if(needToStart <= assignment.get(i).first) {
                deadline = needToStart;
            }
            needToStart = deadline - assignment.get(i).second;
        }

        bw.write(String.valueOf(needToStart));
        bw.flush();
    }
}
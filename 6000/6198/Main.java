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
    static int N;
    static Stack<Integer> building = new Stack<>();

    public static void main(String[] args) throws Exception {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // Input
        String input = br.readLine();
        N = Integer.parseInt(input);


        // Solution
        long answer = 0;
        for(int i = 0; i < N; i++) {
            int height = Integer.parseInt(br.readLine());

            while(!building.isEmpty() && building.peek() <= height) {
                building.pop();
            }
            answer += building.size();
            building.push(height);
        }

        // Output
        bw.write(answer+"\n");
        bw.flush();
    }
}
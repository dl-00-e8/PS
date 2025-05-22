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
    static int N, M, answer = 0;
    static TrieNode root;

    public static void main(String[] args) throws Exception {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // Input
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        // Solution
        root = new TrieNode();
        for(int i = 0; i < N; i++) {
            String line = br.readLine();
            insert(line);
        }

        for(int i = 0; i < M; i++) {
            String line = br.readLine();
            if(searchPrefix(line)) {
                answer++;
            }
        }

        // Output
        bw.write(answer+"\n");
        bw.flush();
    }

    public static void insert(String str) {
        TrieNode currentNode = root;
        for(char c : str.toCharArray()) {
            currentNode.children.putIfAbsent(c, new TrieNode());
            currentNode = currentNode.children.get(c);
        }
        currentNode.isEndOfWord = true;
    }

    public static boolean searchPrefix(String str) {
        TrieNode currentNode = root;
        for(char c : str.toCharArray()) {
            if(!currentNode.children.containsKey(c)) {
                return false;
            }
            currentNode = currentNode.children.get(c);
        }
        return true;
    }
}
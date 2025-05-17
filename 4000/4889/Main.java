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

        // Initial Setting
        int tc = 1;
        Stack<Character> stack = new Stack<>();

        // Input
        while(true) {
            int answer = 0;
            String input = br.readLine();
            if(input.contains("-")) {
                break;
            }

            // Solution
            for(char c: input.toCharArray()) {
                if(c == '{') {
                    stack.push(c);
                } else if(c == '}' && stack.isEmpty()){
                    answer++;
                    stack.push('{');
                } else if(c == '}') {
                    stack.pop();
                }
            }

            if(!stack.isEmpty()) {
                answer += (stack.size() / 2);
                while(!stack.isEmpty()) {
                    stack.pop();
                }
            }

            // Output
            bw.write(tc + ". " + answer + "\n");

            tc++;
        }

        bw.flush();
    }
}
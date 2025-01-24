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

        int N = Integer.parseInt(br.readLine());

        ArrayList<String> wordList = new ArrayList<>();
        for(int i = 0; i < N; i++) {
            String word = br.readLine();
            wordList.add(word);
        }
        wordList.sort(Comparator.comparingInt(String::length)); // 오름차순 정렬

        int answer = N;
        ArrayList<Integer> idxList = new ArrayList<>();
        for(int i = 0; i < N; i++) {
            String prefix = wordList.get(i);
            if(idxList.contains(i)) {
                continue;
            }
            for(int j = 0; j < N; j++) {
                String word = wordList.get(j);

                // Prefix 사용하고 있는 경우는 Continue
                if(i == j || idxList.contains(j)) {
                    continue;
                }

                // 단어의 시작이 동일하지 않은 경우만 부분집합에 포함
                if(word.startsWith(prefix)) {
                    idxList.add(i);
                    answer--;
                    break;
                }
            }
        }

        bw.write(answer + "\n");
        bw.flush();
    }
}
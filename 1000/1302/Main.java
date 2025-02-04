import java.io.*;
import java.util.*;

class Pair {
    String first;
    Integer second;

    public Pair(String first, Integer second) {
        this.first = first;
        this.second = second;
    }
}

public class Main {
    public static void main(String[] args) throws Exception {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        HashMap<String, Integer> sellMap = new HashMap<>();
        for(int i = 0; i < N; i++) {
            String bookName = br.readLine();
            if(sellMap.get(bookName) != null) {
                sellMap.replace(bookName, sellMap.get(bookName) + 1);
            } else {
                sellMap.put(bookName, 1);
            }
        }

        ArrayList<Pair> result = new ArrayList<>();
        for(String key : sellMap.keySet()) {
            result.add(new Pair(key, sellMap.get(key)));
        }
        
        result.sort(Comparator.comparingInt((Pair p) -> p.second).reversed().thenComparing(p -> p.first));

        bw.write(result.get(0).first);
        bw.flush();
    }
}
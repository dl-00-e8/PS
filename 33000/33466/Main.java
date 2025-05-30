import java.io.*;
import java.util.*;

public class Main {

    // Initial Setting
    static int T;

    public static void main(String[] args) throws Exception {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // Input
        T = Integer.parseInt(br.readLine());

        // Solution
        while(T-- > 0) {
            long N = Long.parseLong(br.readLine());

            // Output
            long answer = N + 2 * (N/2);
            bw.write(answer+"\n");
        }

        bw.flush();
    }
}
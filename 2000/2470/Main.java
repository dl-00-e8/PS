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
        int[] solution = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        // Result Data
        int gap = Integer.MAX_VALUE;
        int acid = 0;
        int alkali = 0;

        // 오름차순 정렬
        Arrays.sort(solution);

        // 투포인터 진행
        int left = 0;
        int right = N - 1;
        while(left < right) {
            int leftValue = solution[left];
            int rightValue = solution[right];

            if(leftValue + rightValue > 0) {
                if(Math.abs(leftValue + rightValue) < gap) {
                    acid = leftValue;
                    alkali = rightValue;
                    gap = Math.abs(leftValue + rightValue);
                }

                right--;
            } else if(leftValue + rightValue < 0) {
                if(Math.abs(leftValue + rightValue) < gap) {
                    acid = leftValue;
                    alkali = rightValue;
                    gap = Math.abs(leftValue + rightValue);
                }

                left++;
            } else {
                acid = leftValue;
                alkali = rightValue;
                break;
            }
        }

        bw.write(acid + " " + alkali);
        bw.flush();
    }
}
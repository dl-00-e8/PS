import java.util.*;
import java.io.*;

class Solution {
    int count(String str, char cnt) {
        int result = 0;
        for(char c: str.toCharArray()) {
            if(c == cnt) {
                result++;
            }
        }
        
        return result;
    }
    
    public int solution(int n) {
        String binary = Integer.toBinaryString(n);
        int n_cnt = count(binary, '1');
        
        for(int num = n + 1; num < 10000001; num++) {
            if(count(Integer.toBinaryString(num), '1') == n_cnt) {
                return num;
            }
        }
        
        return n;
    }
}
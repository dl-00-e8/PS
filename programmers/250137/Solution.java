import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int time = 0;
        int timeCnt = 0;
        int maxHealth = health;
        
        for(int i = 0; i < attacks.length; i++) {
            int attackTime = attacks[i][0];
            int attackDamage = attacks[i][1];
            
            health += ((attackTime - time - 1) / bandage[0]) * bandage[2] 
                + (attackTime - time - 1) * bandage[1];
            
            // 최대 체력 초과 시, 최대 체력으로 고정
            if(health > maxHealth) {
                health = maxHealth;
            }
            
            health -= attackDamage;            
            time = attackTime;
            
            if(health <= 0) {
                return -1;
            }
        }
        
        return health;
    }
}
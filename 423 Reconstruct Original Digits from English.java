
class Solution {
    public String originalDigits(String s) {
        int[] chars = new int[26];
        for (char c : s.toCharArray()) {
            chars[c - 'a']++;
        }
     
        //#0 z
        //#2 w
        //#4 u
        //#6 x
        //#8 g
        
        //#1 o - 0 -2 -4 
        //#3 h - 8
        //#5 v - 7
        //#7 s - 6
        //#9 i - 5 -6 -8
        
             
        int[] result = new int[10];
        result[0] = chars['z' - 'a'];
        result[2] = chars['w' - 'a'];
        result[4] = chars['u' - 'a'];        
        result[6] = chars['x' - 'a'];
        result[8] = chars['g' - 'a'];
        
        result[1] = chars['o' - 'a'];
        result[3] = chars['h' - 'a'];
        result[5] = chars['v' - 'a'];
        result[7] = chars['s' - 'a'];
        result[9] = chars['i' - 'a'];
        
        result[1] -= result[0] + result[2] + result[4];
        result[3] -= result[8];
        result[7] -= result[6];      
        result[5] -= result[7];
        result[9] -= result[8] + result[5] + result[6];
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < result[i]; j++) {
                sb.append(i);
            }
        }
        
        return sb.toString();
    }
}

// 03/29/2021 12:56	Accepted	3 ms	39.4 MB	java

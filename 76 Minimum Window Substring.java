class Solution {
    public String minWindow(String s, String t) {
        int[] map = new int[128];
        for(char ch:t.toCharArray()){
            map[ch]++;
        }
        
        int len = t.length();
        int begin=0;
        int end=0;
        int head=0;
        int d = Integer.MAX_VALUE;
        while(end<s.length()){
            if(map[s.charAt(end++)]-->0) len--;
            while(len==0){
                if(d>end-begin){
                    d = end-begin;
                    head = begin;
                }
                if(map[s.charAt(begin++)]++==0){
                    len++;
                }
            }
        }
        return d == Integer.MAX_VALUE?"":s.substring(head,head+d);
    }
}

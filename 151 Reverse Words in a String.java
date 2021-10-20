class Solution {
    public String reverseWords(String s) {
        String result = "";
        String current = "";
        int N = s.length();
        
        for(int i = N - 1; i >= 0; i--) {
            current = "";
            while(i >= 0 && s.charAt(i) != ' ') {
                current = s.charAt(i) + current;
                i--;
            }
            if(current.length() > 0) {
                result += (result.length() == 0 ? "": " ") + current;
            }
        }
        
        return result;
    }
}

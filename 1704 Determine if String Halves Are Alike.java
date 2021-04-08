
class Solution {
    public boolean halvesAreAlike(String s) {
        
        s = s.toLowerCase();//java 變小寫的函式
        int i = 0 ;
        int j = s.length()-1;
        int x = 0;
        int y = 0;      
        
        while(i < j) {
            if(s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'i' || s.charAt(i) == 'o' || s.charAt(i) == 'u')
                x++;
            if(s.charAt(j) == 'a' || s.charAt(j) == 'e' || s.charAt(j) == 'i' || s.charAt(j) == 'o' || s.charAt(j) == 'u')
                y++;
            
            i++;
            j--;
        }
        
        if(x == y) {
            return true;
        }
        return false;
    }
}

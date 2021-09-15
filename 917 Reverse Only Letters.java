class Solution {
    public String reverseOnlyLetters(String s) {
          int i = 0;
    int j = s.length() - 1;
    
    char ch[] = s.toCharArray();
    
    while(i < j){
        
        if(!isAlphabet(ch[i])){
            i++;
            continue;
        }
        else if(!isAlphabet(ch[j])){
            j--;
            continue;
        }
        
        char cht = ch[i];
        ch[i] = ch[j];
        ch[j] = cht;
        
        i++;
        j--;
    }
 
    return new String(ch);

    }

    public boolean isAlphabet(char ch){

        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
}

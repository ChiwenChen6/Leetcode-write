class Solution {
    public List<String> letterCombinations(String digits) {
        
        LinkedList<String> q=new LinkedList<>();
        
        String[] map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        if(digits.length()==0)
            return q;
        q.add("");
        for(int i=0;i<digits.length();i++){
            int idx=Character.getNumericValue(digits.charAt(i));
            
            while(q.peek().length()==i){
                String str=q.remove();
                for(char c: map[idx].toCharArray()){
                    q.add(str+c);
                }
            }
        }
        
        return q;
    }
}

// Status: Accepted
// Runtime: 4 ms
// Memory Usage: 38.9 MB

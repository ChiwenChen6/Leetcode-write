char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0) {
        return "";
    }
    
    for(int i=0; i<strlen(strs[0]); i++) {
        for(int j=1; j<strsSize; j++) {
            if(strs[0][i] != strs[j][i]) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
    return strs[0];
    
}


// Runtime: 0 ms, faster than 100.00% of C online submissions for Longest Common Prefix.
// Memory Usage: 6.1 MB, less than 13.46% of C online submissions for Longest Common Prefix.

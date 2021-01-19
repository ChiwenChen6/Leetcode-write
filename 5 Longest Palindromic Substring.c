

char * longestPalindrome(char * s){
    char *head, *end;
    char *p = s, *subStart = s;
    int maxLen = 1;
    while(*p){
        head = p; end = p;
        
        while(*(end+1) && *(end+1) == *end){
            end++; 
        }
        p = end + 1;
        
        while(*(end + 1) && (head > s) && *(end + 1) == *(head - 1)){
            head--;
            end++;
        }
        if(end - head + 1 > maxLen){
            maxLen = end - head + 1;
            subStart = head;
        }
    }
    
    char *rst = (char *) calloc(maxLen + 1, sizeof(char));
    strncpy(rst, subStart, maxLen);
    return rst;
}

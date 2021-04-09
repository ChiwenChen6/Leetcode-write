"""
Created on Fri Apr. 10 15:30 2021
@author: Chiwen Chen
"""

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    const char* str[8] = {"abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz" };
    char** ret = (char**)malloc(sizeof(char*));
    int size = 1;
    register int len;
    int len2;
    for (len = 0; digits[len]; len++) {
        if (digits[len] == '9' || digits[len] == '7')
            size *= 4;
        else
            size *= 3;
    }
    if (len == 0){
       size = 0;
    }
    *returnSize = size;
    ret = (char**)malloc(size * sizeof(char*));
    len2 = len + 1;
    for (register int i = 0; i < size; i++) {
        char* tmp = (char*)malloc(sizeof(char) * len2);
        tmp[len] = 0;
        ret[i] = tmp;
    }
    int temp = 1;
    int nSize;
    for (int i = 0; i < len; i++) {
        if (digits[i] == '9' || digits[i] == '7'){
            nSize = 4;
        } else{
            nSize = 3;            
        }
        temp *= nSize;
        const char* digit = str[digits[i] - '2'];
        register int count = 0;
        register int k = 0;
        int tt = size / temp;
        for (register int j = 0; j < size; j++) {
            ret[j][i] = digit[k];
            count++;
            if (count == tt) {
                k++;
                count = 0;
                if (k == nSize){
                    k = 0;                    
                }
            }       
        }
    }
    return ret;
}

Runtime: 0 ms
Memory Usage: 5.8 MB

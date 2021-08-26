int min(int a,int b)
{
	return a>b?b:a;
}
void reverse(char *str){
	int len=strlen(str);
	for(int i=0;i<len/2;i++)
	{
		char tmp=str[i];
		str[i]=str[len-1-i];
		str[len-1-i]=tmp;
	}
}
 
char * shortestCommonSupersequence(char * str1, char * str2){ 
    int m = strlen(str1); 
    int n = strlen(str2); 
  
    int dp[m + 1][n + 1]; 
  
    for (int i = 0; i <= m; i++)     { 
        for (int j = 0; j <= n; j++) 
        { 
            if(i == 0) 
                dp[i][j] = j; 
            else if(j == 0) 
                dp[i][j] = i; 
            else if(str1[i - 1] == str2[j - 1]) 
                dp[i][j] = 1 + dp[i - 1][j - 1]; 
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]); 
        } 
    } 

    char* str=calloc(4000,1); 
  	int idx=0;

    int i = m, j = n; 
    while (i > 0 && j > 0) 
    { 

        if (str1[i - 1] == str2[j - 1]) 
        { 
            // Put current character in result 
            str[idx++]=str1[i - 1]; 
  
            i--, j--; 
        } 
  
        else if (dp[i - 1][j] > dp[i][j - 1]) { 
            str[idx++]=str2[j - 1]; 
  
            j--; 
        } 
        else
        { 
            str[idx++]=str1[i - 1]; 
            i--; 
        } 
    } 
  
    while (i > 0) 
    { 
        str[idx++]=str1[i - 1]; 
        i--; 
    } 

    while (j > 0) 
    { 
        str[idx++]=str2[j - 1]; 
        j--; 
    } 

    reverse(str); 

    return str; 
} 
  
// Runtime: 27 ms, faster than 100.00% of C online submissions for Shortest Common Supersequence .
// Memory Usage: 10.3 MB, less than 100.00% of C online submissions for Shortest Common Supersequence .

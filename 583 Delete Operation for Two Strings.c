

int minDistance(char * word1, char * word2) {
    int n1 = strlen(word1);
    int n2 = strlen(word2);
    int c[n1+1][n2+1];  
    
    for(int i = 0; i <= n1; ++i) {
        c[i][0] = 0;
    }
  
    for(int j = 0; j <= n2; ++j){
        c[0][j] = 0;
    }

    for(int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            if (word1[i-1] == word2[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
            }
            else {
                int c1 = c[i][j-1];
                int c2 = c[i-1][j];
                c[i][j] = (c1 >= c2 ? c1 : c2);
            }
        }
    }
    return n1 + n2 - 2 * c[n1][n2];
}

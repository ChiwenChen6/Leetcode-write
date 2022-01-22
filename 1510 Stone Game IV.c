

bool winnerSquareGame(int n){
    int dp[100000] = {0};
    for(int i = 0; i <= n; i++) {
        if(dp[i]) continue;
        for(int j = 1; i + j * j <= n; j++){
            dp[i + j * j] = 1;

        }
    }
    return dp[n];
}

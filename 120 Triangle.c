


#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){

    int last_row_sz = triangleColSize[triangleSize - 1];
    
    int memo[last_row_sz];
    for (int idx = 0; idx < last_row_sz; ++idx)
        memo[idx] = triangle[triangleSize - 1][idx];
    
    for (int r = triangleSize -2; r >= 0; --r) {
        for (int c = 0 ; c < triangleColSize[r]; ++c) {
            memo[c] = triangle[r][c] + MIN(memo[c], memo[c + 1]);
        }
    }
    return memo[0];
}

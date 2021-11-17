class Solution {
    public int uniquePaths(int m, int n) {
        int[][] Arr = new int[m][n];
        for(int i=0;i<m;i++) {
            Arr[i][0]=1;
        }
        for(int i=0;i<n;i++) {
            Arr[0][i]=1;
        }
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                Arr[i][j]=Arr[i-1][j]+Arr[i][j-1];
            }
        }
        return Arr[m-1][n-1];    
    }
}

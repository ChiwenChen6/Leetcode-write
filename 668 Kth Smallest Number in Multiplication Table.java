class Solution {
    public int findKthNumber(int m, int n, int k) {
        int start = 1, end = m * n + 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (!check(m, n, mid, k)){
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
    
    private boolean check(int m, int n, int v, int k) {
        int num = 0;
        for (int i = 1, j = n; i <= m; ++i) {
            while (j >= 1 && j * i > v) {
                j--;
            }               
            if (j == 0) {
                break;
            }
            num += j;
            if (num >= k) {
                return true;
            }
        }
        return false;
    }
    
}

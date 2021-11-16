

int findKthNumber(int m, int n, int k){
        int start = 1;
        int end = m * n;
        while (start < end){
            int mid = round((start + end)/2);
            int curr = 0;
            int j = 1;
            for (int r=m; r>0 ;r--){
                while (j <= n&& r * j <= mid){
                    j += 1;
                }
                curr += j-1;
            }
            if (curr < k){
                start = mid + 1;
            } else{
                end = mid;
            }
        }   
        return start;
        
}

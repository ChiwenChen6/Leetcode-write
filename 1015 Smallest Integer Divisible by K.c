

int smallestRepunitDivByK(int k){
    if (k % 2 == 0 || k % 5 == 0) {
        return -1;
    }
    int N = 0;
    for (int i = 1; i <= k; i++) {
        N = (N*10 + 1) % k;
        if (N == 0) {
            return i;
        }
    }
    return -1;
}

bool isPowerOfTwo(int n){
    if (!n) {
        return false;
    } else {
        long k = n;
        return ((k & (2 * k - 1)) == k);
    }
}

class Solution {
    public int smallestRepunitDivByK(int k) {
    int e = K % 10;
    if (e == 2 || e == 4 || e == 5 || e == 6 || e == 8){ 
        return -1;
    }
    int l = 1;
    int r = 1 % K;
    while (l <= K) {
      if (r == 0){
          return l;
      }
      r = (r * 10 + 1) % K;
      l++;
    }
    return -1;
  }
}

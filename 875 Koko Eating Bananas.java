class Solution {
    public int minEatingSpeed(int[] piles, int h) {
  if (piles == null || piles.length == 0) return 0;
    int max = Integer.MIN_VALUE;
    for (int p: piles) max = Math.max(max, p);
    int st = 1, ed = max;
    while (st < ed) {
      int mid = (st + ed) / 2;
      if (isPossible(piles, h, mid)) {
          ed = mid;
      }
      else st = mid + 1;
    }
    return ed;
  }
  private boolean isPossible(int[] piles, int h, int K) {
    int time = 0;
    for (int p: piles) {
      time += p / K;
      if (p % K != 0) time++;
    }
    return time <= h;
  }
}

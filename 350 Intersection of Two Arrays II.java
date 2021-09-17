class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int m = nums1.length; 
        int n = nums2.length;
        if (m == 0 || n == 0) {
            return (new int[0]);
        }

         Arrays.sort(nums1);
         Arrays.sort(nums2);
         List<Integer> res = new ArrayList<Integer>();

         int p = 0, q = 0;
         while (true) {
             if (p == m || q == n) break;

             if (nums1[p] < nums2[q]) {
                 p++;
             }
             else if (nums1[p] > nums2[q]) {
                 q++;
             }
             else {
                res.add(nums1[p]);
                p++; q++;
             }
         }

         int[] resa = new int[res.size()];
         for (int i = 0; i < resa.length; i++) {
             resa[i] = res.get(i);
         }
         return resa;        

    }
}

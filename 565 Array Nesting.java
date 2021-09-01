class Solution {
    public int arrayNesting(int[] nums) {
        
        int cnt, max=0;
        
        for(int i=0;i<nums.length;i++) {
            cnt = 0;
            int index = i;
            
            while( nums[index] != -999) {     
                int temp = nums[index];
                nums[index] = -999;
                index = temp;
                cnt++;
            }
            
            max = Math.max(cnt,max);
        }
        
        return max;
    }
}

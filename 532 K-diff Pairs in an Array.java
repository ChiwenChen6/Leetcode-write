class Solution {
    public int findPairs(int[] nums, int k) {
        Arrays.sort(nums);
        int count = 0;
        int start = 0; 
        int end = nums.length -1;

        while(start < end) {
            int nums_st = nums[start];
            int nums_ed = nums[end];
            if(nums_ed - nums_st == k) {
                count++;
                while(nums[start] == nums_st){
                    start++;
                    if(start > nums.length -2)
                        break;
                }
                end = nums.length -1;
            } else if(nums_ed - nums_st >k) {
                end--;
            } else {
                start++;
                end = nums.length-1;
            }
        
            if(start == end) {
                if(start < nums.length -1) {
                    start++;
                    end = nums.length-1;
                }
            }
        }
        return count;
    }
}

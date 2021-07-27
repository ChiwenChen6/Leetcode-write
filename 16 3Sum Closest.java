class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int n = nums.length;        
        int ans = 0;
        int diff = Integer.MAX_VALUE;
        Arrays.sort(nums);        
        for(int i=0;i<n-2;i++){        
            int l = i+1;
            int r = n-1;
            while(l<r){        
                int sum = nums[i] + nums[l] + nums[r];                
                if(Math.abs(sum-target)<diff) {                    
                    ans = sum;
                    diff = Math.abs(sum - target);
                }                
                if(sum==target){                    
                    return sum;                    
                } else if(sum > target){                    
                    r--;
                }
                else l++;
            }
        }
        return ans;
    }
}

// Runtime: 3 ms, faster than 98.88% of Java online submissions for 3Sum Closest.
// Memory Usage: 38.5 MB, less than 73.14% of Java online submissions for 3Sum Closest.

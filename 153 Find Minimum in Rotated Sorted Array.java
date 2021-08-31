class Solution {
    public int findMin(int[] nums) {
        var low = 0;
        var high = nums.length - 1;
        if (nums[0] <= nums[high]) 
            return nums[0]; // not rotated

        while (low <= high) {
            var mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            if (nums[mid] < nums[mid - 1])
                return nums[mid];
            if (nums[mid] >= nums[high])
                low = mid + 1; // mid is too much on the left, bring it to the right
            else
                high = mid - 1; // mid is too much on the right, bring it to the left
        }
        return nums[0];
    }
}

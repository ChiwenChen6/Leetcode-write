class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        Stack<Integer> odd = new Stack<>();
        Stack<Integer> even = new Stack<>();
        int len = nums.length;
        for(int i = 0; i < len; i++){
            if(nums[i] % 2 == 0){
                odd.push(nums[i]);
            }else{
                even.push(nums[i]);
            }
        }
        for(int i = 0; i < len; i++){
            if(i % 2 == 0){
                nums[i] = odd.pop();
            }else{
                nums[i] = even.pop();
            }
        }
        return nums;
    }
}


// Runtime: 7 ms, faster than 15.48% of Java online submissions for Sort Array By Parity II.
// Memory Usage: 44.1 MB, less than 35.05% of Java online submissions for Sort Array By Parity II.

class Solution {
    fun jump(nums: IntArray): Int {
        val mArr = IntArray(nums.size){Integer.MAX_VALUE}
        val jArr = IntArray(nums.size){Integer.MAX_VALUE}
        if(nums.size > 1) {
            mArr[0] = 0
            jArr[0] = 0
            
            for(i in 1..nums.size-1){
                for(j in 0..i-1) {
                    if( j+nums[j] >= i){
                        mArr[i] = Math.min(mArr[j] + 1, mArr[i])
                        jArr[i] = j
                    }
                }
            }
            return mArr[nums.size-1]
        } else {
            return nums.size-1
        }
    }
}

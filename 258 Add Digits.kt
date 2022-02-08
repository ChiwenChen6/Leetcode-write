class Solution {
    fun addDigits(num: Int): Int {
        return if(num!=0 && num%9==0){ 9} else {num % 9}
    }
   
}

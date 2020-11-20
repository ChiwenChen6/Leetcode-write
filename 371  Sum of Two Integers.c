
"""
Created on Tues Nov. 17 18:17 2020

@author: Chiwen Chen
"""

int getSum(int a, int b){
  if(a==0) return b;
  if(b==0) return a;
  return getSum(a^b, ((a&b)&0xffffffff)<<1);
}

"""Success
Details 
Runtime: 0 ms, faster than 100.00% of C online submissions for Sum of Two Integers.
Memory Usage: 5.4 MB, less than 65.54% of C online submissions for Sum of Two Integers."""
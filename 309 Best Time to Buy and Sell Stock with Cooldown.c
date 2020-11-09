"""
Created on Mon Nov. 09 11:49 2020

@author: Chiwen Chen
"""


int maxProfit(int* prices, int pricesSize){
  if (pricesSize < 2) return 0;
  int* p=(int*) malloc(sizeof(int) * pricesSize);
  p[0] = 0;
  int sell = -1;
  for (int i = 1; i < pricesSize; i++) {
      if (prices[i] <= prices[i-1]) {
          p[i] = p[i-1];
          continue;
      }
      
      int diff=prices[i] - prices[i-1];
      if (sell==i-1) {
          p[i]=p[i-1] + diff;
      } else if (sell>0){
          p[i] = p[i-3] + diff;// 0:2
          
          
          
          if (prices[i] > prices[sell]) {
              p[i] = fmax(p[i-1] + prices[i] - prices[sell], p[i]);
          } else if (sell == i-2 && p[i] < p[i-1]){
              p[i] = p[i-1];
              continue;
          }
      } 
      
      
      
      else {
          p[i] = diff;
      }
      sell = i;
  }
    
    
  int ret = p[pricesSize-1];
  free(p);//release malloc
  return ret;
}
//Runtime: 4 ms, faster than 66.67% of C online submissions for Best Time to Buy and Sell Stock with Cooldown.
//Memory Usage: 6.2 MB, less than 77.78% of C online submissions for Best Time to Buy and Sell Stock with Cooldown.
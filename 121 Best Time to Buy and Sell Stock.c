

int maxProfit(int* prices, int pricesSize){
    int i =0;
    int min = prices[i];
    int profit =0;
    
    for(i=1;i<pricesSize;i++){
        if(prices[i]>min){
            
            profit = (prices[i]-min>=profit)?(prices[i]-min):profit;
        }
        else
            min = prices[i];
    
    }
    
    
    return profit;
}

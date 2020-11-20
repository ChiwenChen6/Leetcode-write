"""
Created on Tues Nov. 17 15:34 2020

@author: Chiwen Chen
"""



int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int gasstap =0;int start1=0;int count=0;
    for (int i=0;i<costSize;i++)
    {
        count= count+gas[i]-cost[i];
        gasstap=gasstap+gas[i]-cost[i];    
        if( gasstap<0){
            start1=i+1;
            gasstap=0 ;
        }
    }
    return  count<0?-1:start1;
}

"""Runtime: 4 ms, faster than 90.95% of C online submissions for Gas Station.
Memory Usage: 6.5 MB, less than 9.55% of C online submissions for Gas Station."""
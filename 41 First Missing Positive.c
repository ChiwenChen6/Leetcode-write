
"""
Created on Sun Nov. 22 20:01 2020

@author: Chiwen Chen
"""


int firstMissingPositive(int* nums, int n){
    int i=0,t;
    while(i < n){
        long c=(long)nums[i]-1;
        if(c > -1 && c < n && nums[c]!=nums[i]){
            t=nums[c];
            nums[c]=nums[i];
            nums[i]=t;
        }
        else 
            i++;
    }
    for(i=0;i<n && nums[i]==i+1;i++);
    return i+1;
}

"""Runtime: 4 ms, faster than 30.90% of C online submissions for First Missing Positive.
Memory Usage: 6.2 MB, less than 19.53% of C online submissions for First Missing Positive.
"""

"""紀錄別人達成的進階要求 O[N]"""
"""
int firstMissingPositive(int* nums, int n){
    int i=0,t;
    while(i < n){
        long c=(long)nums[i]-1;
        if(c > -1 && c < n && nums[c]!=nums[i]){
            t=nums[c];
            nums[c]=nums[i];
            nums[i]=t;
        }
        else 
            i++;
    }
    for(i=0;i<n && nums[i]==i+1;i++);
    return i+1;
}

"""
"""Runtime: 0 ms, faster than 100.00% of C online submissions for First Missing Positive.
Memory Usage: 6 MB, less than 42.57% of C online submissions for First Missing Positive."""
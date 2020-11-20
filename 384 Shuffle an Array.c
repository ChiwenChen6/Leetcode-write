
"""
Created on Tues Nov. 20 22:22 2020

@author: Chiwen Chen
"""



typedef struct {
    int *org;
    int solsize;
    
} Solution;


Solution* solutionCreate(int* nums, int solsize) {
    Solution* obj=(Solution *)malloc(sizeof(Solution));
    obj->org=nums;
    obj->solsize=solsize;
    return obj;
} 

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int* retSize) {
    *retSize=obj->solsize;
    return obj->org;
    
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int* retSize) {
    *retSize=obj->solsize;
    
    int *ret=(int*)calloc((*retSize),sizeof(int));//配置預設為型態的零值。這是準備回傳值
    int *array=(int*)calloc((*retSize),sizeof(int));//配置預設為型態的零值
    int temp=0;
    int count=-1;
    for(int i=0;i<*retSize;i++){    
        temp=random()%((*retSize)-i);//隨機大小的變動值位長度
        for(int j=0;j<*retSize;j++){
            if(array[j]==0){//確認目前還有哪個數值還沒有填入array
                count++;//計數記得
                if(count==temp){
                    array[j]=1;//隨機的部分進行確認已經放入準備回傳的array
                    ret[i]=obj->org[j];
                    count=-1;//跳出迴圈前回復計數
                    break;
                }
            }
        }
    }
    return ret;
}

void solutionFree(Solution* obj) {
    free(obj->org);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);
 
 * int* param_2 = solutionShuffle(obj, retSize);
 
 * solutionFree(obj);
*/
"""Runtime: 228 ms, faster than 25.93% of C online submissions for Shuffle an Array.
Memory Usage: 38.2 MB, less than 11.11% of C online submissions for Shuffle an Array."""


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int* result = (int *)malloc(nums1Size*sizeof(int));
    int p = 0;
    for(int i = 0;i<nums1Size;i++){
        int flag = 0;
        int last = -1;        
        for(int j = 0;j<nums2Size;j++){
            if(*(nums1+i)== *(nums2+j)){
                flag=1;
                last = nums1[i];
                if(j==nums2Size-1){
                    result[p]=-1;
                    break;
                }  
                continue;
            }
            if(flag==1){
                result[p]=-1;
                if(nums2[j]>last){
                    result[p]=nums2[j];
                    break;
                }
                
            }
        }
        p++;
    }
    *returnSize = p;
    return result;
    
}


// Runtime: 16 ms, faster than 26.92% of C online submissions for Next Greater Element I.
// Memory Usage: 6.5 MB, less than 58.97% of C online submissions for Next Greater Element I.

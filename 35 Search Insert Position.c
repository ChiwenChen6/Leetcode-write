
int searchInsert(int* nums, int numsSize, int target){
    int low = 0;
    int high = numsSize-1;
    int mid = (high+low)/2;
    
    while(low <= high){
        if(nums[mid] == target){
            return mid;
        }    
        else if(nums[mid] < target){
            low = mid+1;
            mid = (high+low)/2;
        }
        else{
            high = mid-1;
            mid = (high+low)/2;
        }    
    }
    return low;
}

Runtime: 4 ms, faster than 90.26% of C online submissions for Search Insert Position.
Memory Usage: 6.2 MB, less than 20.57% of C online submissions for Search Insert Position.

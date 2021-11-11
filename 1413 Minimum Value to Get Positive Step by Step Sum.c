
int minStartValue(int* nums, int numsSize){
    
    int i;
    int j;
    int sun = 0;
    int m;
    int sum;
    for(i=1; i<100000000; i++){    
        // re init
        m=0;
        sum=i;
            
        for(j=0;j<numsSize;j++) {
            sum = nums[j]+sum;
            if(sum<1){
                m=1;
                break;
            }
        }
        
        if(m==0){
            sun=i;
            break;
        }
    }
    return sun;
}

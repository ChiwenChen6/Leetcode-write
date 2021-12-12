

bool canPartition(int* nums, int numsSize) {
    int sum=0;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
    }
    if(sum%2==1){
        return false;
    }
    int* map=(int*)calloc(20001,sizeof(int));
    map[0]=1;
    int count=0;
    for(int i=0;i<numsSize;i++){
        for(int j=sum;j-nums[i]>=0;j--){
            map[j]=(map[j]+map[j-nums[i]])>0?1:0;
        }
    }
    return map[sum/2]!=0?true:false;
}

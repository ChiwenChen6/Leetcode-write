int isValid(int* piles, int pilesSize, int H,int k){
    int hour=0;
    for(int i=0;i<pilesSize;i++) {
        hour += piles[i]/k+(piles[i]%k!=0);
    }
    return hour>H?0:1;
}
int minEatingSpeed(int* piles, int pilesSize, int h) {
    int max=0;
    for(int i=0; i<pilesSize; i++) {
        if(max<piles[i]) {
            max = piles[i];
        }
    }
    int min = max/h+(max%h!=0);
    while(max>min) {
        int mid=(max+min)/2;
        if(isValid(piles, pilesSize,h,mid)) {
            max = mid;
        } else {
            min = mid+1;
        }
    }
    return min;
}

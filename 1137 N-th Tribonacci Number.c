

int tribonacci(int n){
    int i;
    int d[38]={};
    d[0]=0;
    d[1]=1;
    d[2]=1;
    if(n==0) {
        return 0;
    } else if(n==1 || n==2) {
        return 1;
    }
    for(i=3; i<=n; i++) {
        d[i] = d[i-1]+d[i-2]+d[i-3];
    }
    return d[n];

}

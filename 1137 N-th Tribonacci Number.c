int tribonacci(int n){
    int n0 = 0;
    int n1 = 1;
    int n2 = 1;
    int result = 0;

    if(n<1) return 0;
    if(n==1 || n==2) return 1;
    for(int i=3;i<=n;i++){
        result = n0 + n1 + n2;

        n0 = n1;
        n1 = n2;
        n2 = result;

    }
    return result;
}



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

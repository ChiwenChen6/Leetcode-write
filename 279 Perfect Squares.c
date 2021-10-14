

int numSquares(int n) {
    int temp = sqrt(n);
    if( temp*temp == n ) {
        return 1;
    }
    temp = n;
    while( temp%4==0 ) {
        temp /= 4;
    }
    if( temp%8 == 7 ) {
        return 4;
    }
    for(int i=1;i*i<n;i++) {
        temp = n-i*i;
        int a = sqrt(temp);
        if(a*a == temp) {
            return 2;
        }
    }
    return 3;
}



int trailingZeroes(int n){    
    int result = 0;
    if(n <5) {
        return 0;
    }
    for(int i =5; i<=n ; i+=5){
        if(i%5 == 0) {
            result++;
        }
        if(i%25 == 0) {
            result++;
        }
        if(i%125 == 0) {
            result++;  
        }       
        if(i%625 == 0) {
            result++;
        }
        if(i%3125 == 0) {
            result++;
        }
    }

    return result;
}

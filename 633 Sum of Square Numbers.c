
bool judgeSquareSum(int c) {
    long temp;
    for(long i = 0, j = 0; temp = i*i, temp<= c; i++) {
        j = sqrt(c - temp);
        if(temp+j*j == c){
            return true;
        }
    }
    return false;
}

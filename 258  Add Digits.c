

int addDigits(int num){
  int cnt=0;
    int sum=0;
    while(1) {
        sum += num%10;
        num = num/10;
        if(num<10) {
            sum += num;
            if(sum>=10) {
                num = sum;
                sum = 0;
            }else {
                break;
            }
        }
    }
    return sum;
}

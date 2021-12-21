

int reverse(int x){
    int digits[12];
    int cnt=0, neg_num=0;
    if (x>=INT_MAX || x<=INT_MIN) return 0;
    
    if(x<0){
        x=-x; neg_num=1;
    }
    while(1){
        if(x<10){            
            digits[cnt++]=x;
            break;
        }
        digits[cnt++]=x%10;
        x=x/10;
    }
    long sum=0;
    for(int i=0; i<cnt; i++){        
        sum=sum*10+digits[i];
        if (sum>=INT_MAX)
            return 0;

    }
    if(neg_num==1){
        sum=-sum;
    }
    return sum;
}

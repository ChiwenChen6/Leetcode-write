

int findComplement(int num){
    int i = 0;
    int res = 0;
    
    while (num > 0) {
        int nb = num % 2 ? 0 : 1;
        num >>= 1;
        res = res | (nb << i);
        i++;
    }
    return res;
}

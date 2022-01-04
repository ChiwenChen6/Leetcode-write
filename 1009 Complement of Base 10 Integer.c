

int bitwiseComplement(int n){
    if(!n) return 1;
    
    int bina = 1;
    int tmp = n;
    while(n){
        n /= 2;
        bina *=2;
    }
    return bina - tmp -1;
}

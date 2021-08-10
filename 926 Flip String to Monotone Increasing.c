

int minFlipsMonoIncr(char * s){
    if (*S == '\0'){ 
        return 0;
    }
    int size = strlen(S);
    int ArrayOnes[size];
    int ArrayZeros[size];
    int count1 = 0;
    int count0 = 0;
    int index0 = size - 1;
    
    char *Tracker1 = S;
    char *Tracker0 = S + size - 1;
    
    for (int i = 0; i < size; ++i) {
        if (*Tracker1 == '1') {
            ++count1;
            ArrayOnes[i] = count1;
        } else {
            ArrayOnes[i] = count1;
        }
        Tracker1 += 1;
        
        if (*Tracker0 == '0') {
            ++count0;
            ArrayZeros[index0] = count0;
        } else {
            ArrayZeros[index0] = count0;
        }
        Tracker0 -= 1;
        --index0;
    }
    
    int minFlips = count1; 
    for (int i = 0; i < size; ++i) {
        if ( (ArrayOnes[i]+ArrayZeros[i]-1) < minFlips) {
            minFlips = ArrayOnes[i]+ArrayZeros[i]-1; 
        }
    }
    
    return MinFlips;
}

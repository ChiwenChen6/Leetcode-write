

int minCostToMoveChips(int* chips, int chipsSize){
    int odd=0;
    int i;
    for (i=0; i<chipsSize; i++){
        if ((chips[i] % 2)==1) odd++;
    }
    if (odd > chipsSize-odd){
        return chipsSize-odd;
    } else {
        return odd;
    }
}

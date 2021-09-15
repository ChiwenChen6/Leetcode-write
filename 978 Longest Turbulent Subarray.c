int maxTurbulenceSize (int* arr, int arrSize) {
    int i = 1;
    int cnt = 1;
    int max = 1;
    // 0-init; 1-up; 2-down
    int state = 0; 
    
    for (i = 1; i < arrSize; i++) {
        if (arr[i] > arr[i-1]) {
            if (state != 2) cnt = 1;
            cnt++;
            state = 1;
        } else if (arr[i] < arr[i-1]) {
            if (state != 1) cnt = 1;
            cnt++;
            state = 2;
        } else {
            state = 0;
            cnt = 0;
        }
        max = cnt > max ? cnt : max;
    }
    
    return max;
}

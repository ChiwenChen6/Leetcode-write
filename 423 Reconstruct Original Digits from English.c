

char * originalDigits(char * s){
    int L[128];
    int i, j, d[10];
    int sum, ptr;
    char *resp, ch;
    int len = 0, n;
    
    for(i = 0; i < 128; i++){
        L[i] = 0;
    
    } 
    n=0;
    while(s[n]) { 
        L[s[n]]++;
        n++; 
        len++;
    }

    d[0] = L['z'];
    if(d[0]) { 
        L['e'] -= d[0]; L['r'] -= d[0]; L['o'] -= d[0]; 
    }

    d[2] = L['w'];
    if(d[2]) {
        L['t'] -= d[2]; L['o'] -= d[2]; 
    }

    d[6] = L['x'];
    if(d[6]) { 
        L['s'] -= d[6]; L['i'] -= d[6]; 
    }
    
    d[8] = L['g'];
    if(d[8]) { 
        L['e'] -= d[8]; 
        L['i'] -= d[8];  
        L['h'] -= d[8]; 
        L['t'] -= d[8]; 
    }
    
    d[4] = L['u'];
    if(d[4]) { 
        L['o'] -= d[4];
        L['f'] -= d[4];
        L['r'] -= d[4];
    }
    
    d[5] = L['f'];
    if(d[5]) { 
        L['i'] -= d[5]; 
        L['v'] -= d[5];
        L['e'] -= d[5];
    }
    
    d[3] = L['t'];
    if(d[3]) {
        L['e'] -= d[3];
        L['e'] -= d[3]; 
    }
    
    d[7] = L['s'];
    if(d[7]) {
        L['e'] -= d[7];
        L['v'] -= d[7];
        L['e'] -= d[7];
        L['n'] -= d[7]; 
    }
    
    d[1] = L['o'];
    if(d[1]) {
        L['n'] -= d[1];
        L['e'] -= d[1]; 
    }
    
    d[9] = L['i'];
    sum = ptr = 0;
    for(i = 0; i < 10; i++) {
        sum += d[i];
    }
    resp = calloc(sum+1, sizeof(char));
    for(i = 0; i < 10; i++) {
        ch = '0' + i;
        for(j = 0; j < d[i]; j++) {
            resp[ptr++] = ch; 
        }
    }
    resp[ptr] = '\0';
    return resp;
}

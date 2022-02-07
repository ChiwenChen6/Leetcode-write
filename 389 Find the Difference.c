char findTheDifference(char * s, char * t){
    char c = t[0];
    int i=0;
    while(s[i]) {
        c=c^s[i]^t[++i];
    }
    return c;
}

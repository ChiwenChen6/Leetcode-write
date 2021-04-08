bool halvesAreAlike(char * s){
    int count;
    char *p1 = s;
    count = 0;
    while(s && *s != '\0') {
        if((*s == 'a') ||(*s == 'e') ||(*s == 'i') ||(*s == 'o') ||(*s == 'u') ||
            (*s == 'A') ||(*s == 'E') ||(*s == 'I') ||(*s == 'O') ||(*s == 'U')) {
            if(*p1 != 0)
                count++;
            else
                count--;
        }      
        s++;
        if(*p1 != '\0') {
            p1++;
            p1++;
        }
    }
    if(count == 0) {
        return true;
    }
    return false;
}


// Status: Accepted
// Runtime: 0 ms
// Memory Usage: 5.9 MB


void reverseString(char *start, char *end) {
    while (start < end) {
        char c = *start;
        *start++ = *--end;
        *end = c;
    }
}

char * reverseWords(char * s){
    char *w = s;
    char *s_ptr = s;
    char *w_ptr = s;
    bool space = true;
    while ((*w_ptr = *s_ptr++) != 0) {
        if (*w_ptr != ' ') {
            space = false;
            w_ptr++;
        }
        else if (!space) {
            space = true;
            reverseString(w, w_ptr++);
            w = w_ptr;
        }
    }
    if (w_ptr == s) return s;
    if (space) *--w_ptr = 0;
    else reverseString(w, w_ptr);
    reverseString(s, w_ptr);
    return s;
}

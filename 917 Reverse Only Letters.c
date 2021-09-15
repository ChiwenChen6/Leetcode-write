bool is_not_letter(char s){
    return (s <'A'|| s>'Z') && (s<'a' || s>'z');
}

char * reverseOnlyLetters(char * s){
    int len = strlen(s);
    char * result = malloc(sizeof(char)*len);
    int count_not_letter = 0;
    for(int i =0; i<len;i++) {
        if((is_not_letter(s[i]))) {
            result[i] = s[i];
            count_not_letter ++;
        }else{
            result[i] =' ';
        }
    }   
    int count_letter = len -count_not_letter;

    char * temp = malloc(sizeof(char)*count_letter);
    int index =0;
    for(int i =0; i<len ;i++) {
        if(!(is_not_letter(s[i]))){
            temp[index] = s[i];
            index++;
        }
    }
    index --;
    for(int i= 0; i <len; i++){
        if(result[i] == ' ') {
            result[i] = temp[index--];
        }
    }
    for(int i=0; i<len; i++) {
        s[i] = result[i];
    }
    return s;    
}

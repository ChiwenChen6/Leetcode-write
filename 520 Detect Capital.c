

bool detectCapitalUse(char * word){
    int c=0;
    for(int i=0;i<strlen(word);i++){
            if(isupper(word[i])) {
                c++;
            }
        }
     return   !c || c == strlen(word) ||  c==1 && isupper(word[0]);
}

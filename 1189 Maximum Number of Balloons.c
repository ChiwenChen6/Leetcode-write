
int maxNumberOfBalloons(char* text){
    int len=strlen(text);
    if(len<7){
        return 0;
    }
    int countB=0;
    int countA=0;
    int countL=0;
    int countO=0;
    int countN=0;
    for(int i=0;i<len;i++){
        if(text[i]=='b'){
            countB++;
        }
        else if(text[i]=='a'){
            countA++;
        }
        else if(text[i]=='l'){
            countL++;
        }
        else if(text[i]=='o'){
            countO++;
        }
        else if(text[i]=='n'){
            countN++;
        }
    }
    int countBallon=0;
    while(countB>0 && countA>0 && countL>1 && countO>1 && countN>0){
        countBallon++;
        countB--;
        countA--;
        countL=countL-2;
        countO=countO-2;
        countN--;
    }
    return countBallon;    
}

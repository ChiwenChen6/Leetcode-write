char * minRemoveToMakeValid(char * s){
    if(s==NULL){
        return s;
    }

    int length=strlen(s);
    if(length==0){
        return s;
    }
    int open=0;
    int balance=0;
    int iter=0;
    int i;
    for(i=0;i<length;i++){
        if(s[i]!='(' && s[i]!=')' ){
            s[iter]=s[i];
            iter++; 
        } else if(s[i]=='('){
            balance++;
            open++;
            s[iter]=s[i];
            iter++;
        } else if(s[i]==')'){
            if(balance>0){
                balance--;
                s[iter]=s[i];
                iter++;
            } else{
              continue;      
            }
        }
    }

    int keep=open-balance;
    int j=0;
    for(i=0;i<iter;i++){
        if(s[i]!='('){
            s[j]=s[i];
            j++;
        }
        else{
            if(keep>0){
                s[j]=s[i];
                j++;
                keep--;
            }
            else{
                continue;
            }
        }
    }
    s[j]='\0';
    return s;
}

int evalRPN(char ** tokens, int tokensSize){
    int ret=0,idx=-1;
    int *stack=malloc(sizeof(int)*tokensSize);
    for(int i=0;i<tokensSize;i++)
    {
        if(!strcmp(tokens[i],"+"))
        {
            stack[idx-1]=stack[idx-1]+stack[idx];
            idx-=1;
        }
        else if(!strcmp(tokens[i],"-"))
        {
            stack[idx-1]=stack[idx-1]-stack[idx];
            idx-=1;
        }
        else if(!strcmp(tokens[i],"*"))
        {
            stack[idx-1]=stack[idx-1]*stack[idx];
            idx-=1;
        }
        else if(!strcmp(tokens[i],"/"))
         {
            stack[idx-1]=stack[idx-1]/stack[idx];
            idx-=1;
        }
        else 
            stack[++idx]=atoi(tokens[i]);
        
    }
    return stack[0];
}

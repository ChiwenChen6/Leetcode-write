 const char *ones[]={
"","enO ","owT ","eerhT ","ruoF ","eviF ","xiS ","neveS ","thgiE ","eniN ","neT ","nevelE ","evlewT ","neetrihT ","neetruoF ","neetfiF ","neetxiS ","neetneveS ","neethgiE ","neeteniN ",};

const char * tens[]={"","neT ","ytnewT ","ytrihT ","ytroF ","ytfiF ","ytxiS ","ytneveS ","ythgiE ","yteniN ",};
const char *thous[]={"","dnasuohT ","noilliM ","noilliB "};
const char *hundred = "derdnuH ";
char zero[] ="Zero";
void reverse_str(char * str,int len)
{
     char tmp,*ptr = str+len -1;
     while(str < ptr)
     {
        tmp = *str;
        *(str++) = *ptr;
        *(ptr--) = tmp;
    }
}
 int copy_str(const char * str,char * ret,int index)
{
    const char *ptr = str;
    while(*ptr)
        ret[index++] = *(ptr++);
    return index ;
}

char ret[512];/// result to return

char* numberToWords(int num) {
    if(!num) return zero;
    int index = 0,tmp;
    for(int i = 0; num; i++)
    {
        if(num%1000)
            index = copy_str(thous[i],ret,index); 
        tmp = num%100;num/=100;
        if(tmp < 20)
            index = copy_str(ones[tmp],ret,index); 
        else 
        {
            index = copy_str(ones[tmp%10],ret,index);
            index = copy_str(tens[tmp/10],ret,index);
        }
        tmp = num % 10;num /= 10;
        if(tmp)
        {
            index = copy_str(hundred,ret,index);
            index = copy_str(ones[tmp],ret,index);
        }
    }
    ret[--index] = '\0';
    reverse_str(ret,index);
    return ret;
}


int removePalindromeSub(char * s){
{
    int length = strlen(s);
    if (length == 0)
    {
        return 0;
    }
    int i;
    for (i = 0; i < length; i++)
    {
        if (s[i] != s[length - i - 1])
        {
            return 2;
        }
    }
    return 1;
}
}

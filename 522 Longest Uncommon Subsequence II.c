
int max(int a,int b)
{
    return a>b ? a:b;
}


bool LCS(char* a, char* b) {
        if (strlen(a)<strlen(b)) return false;
        int i = 0;
        for(int k=0;k<strlen(a);k++) {
            if(i < strlen(b) && b[i] == a[k]) {
                i++;
            }
        }
        return i == strlen(b);
}


int findLUSlength(char ** strs, int strsSize){
    int ret=-1,i,j;

    for(i=0;i<strsSize;i++) {
        for(j=0;j<strsSize;j++){
            if(i==j)
                continue;
            if(LCS(strs[j],strs[i])){
                break;
            }
        }
        if(j==strsSize){
            ret=max(ret,strlen(strs[i]));
        }
    }
    return ret;
}

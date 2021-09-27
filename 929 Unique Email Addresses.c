

int numUniqueEmails(char ** emails, int emailsSize){
    char uni[100][100] = {0};
    char email[100] = {0};
    int unisize = 0;
    int j;
    int k;
    int keepon;
    int found;

    for (int i = 0; i < emailsSize; i++){
        keepon = 1;
        j = 0;
        k = 0;
        found = 0;
        while (emails[i][j] != '@'){
            if (emails[i][j] == '+')
                keepon = 0;
            else if (keepon && emails[i][j] != '.')
                email[k++] = emails[i][j];
            j++;
        }
        while (emails[i][j])
            email[k++] = emails[i][j++];
        email[k] = 0;
        for (int u = 0; u < unisize && !found; u++)
            if (strcmp(uni[u], email) == 0)
                found = 1;
        if (!found)
            strcpy(uni[unisize++], email);
    }
    return unisize;
}

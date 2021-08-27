bool isValidSerialization(char* preorder) {
    int i = 0, j = 0;
    char l = ',';
    for (; *preorder; l = *preorder, ++preorder){
        if (*preorder == '#') ++j;
        else if (*preorder == ',') ;
        else if (l == ',' || l == '#') ++i;
        if (j - 1 == i) break;
    }   
    return j - 1 == i && *preorder && !*(preorder + 1) ? true : false;
}

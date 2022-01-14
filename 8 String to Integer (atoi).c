

int myAtoi(char * s){
    char *iter = s;
    char sign = 1;
    int integer = 0;
    while (*iter == ' '){
        iter++;
    }
    
    if (*iter == '-') {   
        sign *= -1;
        iter++;
    } else if (*iter == '+') {   
        iter++;
    }
        
    while (*iter >= 48 && *iter <= 57) {
        if ((integer == INT_MAX / 10 && *iter - 48 > INT_MAX % 10) || integer > INT_MAX / 10){
                return sign == 1 ? INT_MAX : INT_MIN;
        }
        integer *= 10;
        integer += *iter - 48;
        iter++;
    }
    
    return integer * sign;
}

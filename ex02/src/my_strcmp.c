int my_strcmp(char *str1, char *str2) {
while (*str1!='\0' || *str2!='\0') {
 if (*str1 > *str2) 
    return 1; 
 if (*str1 < *str2) 
    return -1; 
++str1; ++str2; 
}
return *str1? -1 : *str2? 1 : 0;
}

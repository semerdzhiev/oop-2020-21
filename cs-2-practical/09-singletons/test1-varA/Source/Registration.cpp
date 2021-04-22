#include "Registration.h"
#include<cstring>
#include<cctype>
#include<stdexcept>


bool Registration::isValid(const char *str) {
    size_t len = strlen(str);
    return len >= 7 &&
           len <= 8 &&
           isalpha(str[len - 1]) &&
           isalpha(str[len - 2]) &&
           isdigit(str[len - 3]) &&
           isdigit(str[len - 4]) &&
           isdigit(str[len - 5]) &&
           isdigit(str[len - 6]) &&
           isalpha(str[len - 7]) &&
           (len == 7 || isalpha(str[len - 8]));
}

Registration::Registration(const char *str) {
    if(!isValid(str))
        throw std::exception();
    strcpy(reg,str);
}

Registration & Registration::operator=(const char *str) {
    if(!isValid(str))
        throw std::exception();
    strcpy(reg,str);
}

bool Registration::operator==(const char *str) const {
    return strcmp(reg,str)==0;
}

const char * Registration::toString() const {
    return reg;
}
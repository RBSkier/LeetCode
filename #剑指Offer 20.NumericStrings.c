#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

bool scanUnsignedInteger(char** s){
    //扫描所有的整数
    if(isdigit(**s)){
        while(isdigit(**s)){
            ++(*s);
        }
        return true;
    }else{
        return false;
    }
}

bool scanInteger(char** s){
    //可选符号字符
    if(**s == '+' || **s == '-'){
        ++(*s);
    }
    return scanUnsignedInteger(s);
}

bool isNumber(char* s){
    if(s == NULL){
        return false;
    }
    //扫描所有的空格
    while(*s == ' '){
        ++s;
    }
    //扫描掉整数
    bool numeric = scanInteger(&s);
    //扫描掉小数
    if(*s == '.'){
        ++s;
        numeric |= scanUnsignedInteger(&s);
    }
    //扫描科学计数
    if(*s == 'e' || *s == 'E'){
        ++s;
        numeric &= scanInteger(&s);
    }

    while(*s == ' '){
        ++s;
    }

    return numeric && *s == '\0';
}
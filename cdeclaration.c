/**
 * @file cdeclaration.c
 * @brief c declaration annoitation program
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-10
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXTOKENLEN 100
#define MAXTOKENS   100

// 类型
enum type_tag{
    TYPE,
    QUALIFIER,
    INDENTIFIER,
};

// 标识结构体
struct token {
    char type;
    char string[MAXTOKENLEN];
};

// 保存第一个标识之前的所有标识
struct token stack[MAXTOKENS];

// 保存刚读入的标识
struct token this;





#ifndef CHAR_INFO_H
#define CHAR_INFO_H
#include <time.h>

typedef struct {
    char name[50];
    int age;
    float health;
    float sanity;
    float energy;
    int level;
    struct tm timestamp; 
    float metabolism;
} char_info;

#endif
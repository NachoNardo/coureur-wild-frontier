#ifndef CHAR_INFO_H
#define CHAR_INFO_H
#include <time.h>
#include "status.h"
#define MAX_STATUS 10

typedef struct {
    char name[50];
    int age;
    float health;
    float sanity;
    float energy;
    int level;
    struct tm timestamp; 
    float metabolism;
    status status_list[MAX_STATUS];
} char_info;

#endif
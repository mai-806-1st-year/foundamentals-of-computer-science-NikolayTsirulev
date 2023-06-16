#ifndef __person_h__
#define __person_h__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint;

typedef struct{
    char surname[50];
    char initials[2];
    char gender;
    uint school_number;
    char medal;
    uint math;
    uint physics;
    uint computer_science;
    char essay;
} person;
#endif

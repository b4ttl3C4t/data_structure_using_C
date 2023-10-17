#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define ARRAY_MAX_SIZE 100



typedef struct Array_Data_s
{
    double data;
} a_Data;

typedef struct Array_s
{
    uint64_t length;
    a_Data element[ARRAY_MAX_SIZE];
} a_Array;



//function prototype for operation of array:
void a_construction  (a_Array *);
void a_destruction   (a_Array *);
void a_traverse      (a_Array *);
void a_insertion     (a_Array *, uint64_t);
void a_deletion      (a_Array *, uint64_t);
void a_search        (a_Array *, uint64_t);
void a_update        (a_Array *, uint64_t);

void a_is_empty      (a_Array *);
void a_is_full       (a_Array *);

#endif
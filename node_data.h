#ifndef NODE_DATA_H
#define NODE_DATA_H

#include <stdio.h>

struct data
{
    char character;
    int integer;
    double real_number;
};

typedef struct data data_t;
typedef struct data *data_ptr_t;

data_t __data__(char character, int integer, double real_number)
{
    data_t temp;
    temp.character   = character;
    temp.integer     = integer;
    temp.real_number = real_number;
    return temp;
}

void __data_copy__(data_ptr_t destin, data_ptr_t source)
{
    *destin = *source;
}

int __data_compare__(data_ptr_t destin, data_ptr_t source)
{
    if(destin->character   == source->character && 
       destin->integer     == source->integer   && 
       destin->real_number == source->real_number )
    {
        return 0;
    }
    
    if( destin->character   >  source->character || 

       (destin->character   == source->character && 
        destin->integer     >  source->integer)  || 
        
       (destin->character   == source->character && 
        destin->integer     == source->integer   &&   
        destin->real_number >  source->real_number) )
    {
        return 1;
    }

    return -1;
}

void __data_display__(data_ptr_t node)
{
    printf("(%c, %d, %.2lf)", 
            node->character, 
            node->integer,
            node->real_number);
}

#endif
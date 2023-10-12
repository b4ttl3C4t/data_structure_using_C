#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "doubly_circular_xor_linked_list.h"

#define LIST_SIZE       50
#define LIST_TYPE_SIZE  2
#define OPCODE_SIZE     14
#define MALLOC_ERROR    "The memory allocation for linked list aborts."
#define MODE_ERROR      "The mode is not accessible."
#define OPCODE_ERROR    "The opcode is not accessible."
#define INDEX_ERROR     "The node does not exist."

//The definition of data for polynomials.
struct polynomial_data
{
    double coefficient;
    uint64_t power;
};

//The definition of data for the normal node.
struct node_data
{
    uint64_t integer;
};

//Constructing the data of compound linked list type.
struct Linked_List_Data_s
{
    union
    {
        struct polynomial_data polynomial;
        struct node_data data;
    };
};

int main(void)
{
    l_List *list = (l_List *)malloc(sizeof(l_List));
    uint64_t opcode;

    while(1)
    {
        printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",
                            "> control_table: ",
                            "  |code|    function    |",
                            "  |  0 | construction   |",
                            "  |  1 | insertion      |",
                            "  |  2 | insert_head    |",
                            "  |  3 | insert_tail    |",
                            "  |  4 | destruction    |",
                            "  |  5 | deletion       |",
                            "  |  6 | delete_head    |",
                            "  |  7 | delete_tail    |",
                            "  |  8 | search         |",
                            "  |  9 | display        |",
                            "  | 10 | sort           |",
                            "  | 11 | reverse        |",
                            "  | 12 | is_list_empty  |",
                            "  | 13 |      EXIT      |",
                            "> control_table: What do you want to do now? Please enter the opcode:");
        scanf("%llu", &opcode);
        getchar();

        if(opcode >= OPCODE_SIZE)
        {
            fprintf(stderr, "\n> control_table: %s", OPCODE_ERROR);
        }

        l_control_table(&list, opcode);
    }
}

void l_control_table(l_List **list, uint64_t opcode)
{
    uint64_t index;

    switch(opcode)
    {
    case 0:
        break;

    case 3:
        break;

    case 7:
        break;

    case 10:
        break;
    }

    return;
}

static void input_data  (l_Node *node);
static void swap        (l_Node *X, l_Node *Y);
static l_Node * node_xor(l_Node *X, l_Node *Y);

/*----------------------------------------function *l_initialization*  begin----------------------------------------*/
l_List * l_initialization(void)
{
    printf("\n%s", "> Initialization: Allocating the memory space for head node.");
    l_List *list = (l_List *)calloc(1, sizeof(l_List));

    //Probing whether the memory allocation successes.
    if(list == NULL)
    {
        fprintf(stderr, "\n%s%s", "> Initialization: ", MALLOC_ERROR);
        return NULL;
    }

    printf("\n%s", "> Initialization: The memory allocation completes!");
    printf("\n%s\n%s\n%s",  "> Initialization: Type mode table as following:",
                                    "  | 0 | normal linked list     |",
                                    "  | 1 | polynomial linked list |");
    
    //Interface for setting mode.
    printf("\n%s", "> Initialization: Please set the type mode for the head node:");
    scanf("%llu", list->type);
    getchar();
    
    //Probing whether the type mode is correct.
    if(list->type >= LIST_TYPE_SIZE)
    {
        fprintf(stderr, "\n%s%s", "> Initialization: ", MODE_ERROR);
        return NULL;
    }
    return list;
}
/*----------------------------------------function *l_initialization* end  ----------------------------------------*/
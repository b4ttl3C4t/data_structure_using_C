#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "linked_list.h"

#define LIST_SIZE       50
#define LIST_TYPE_SIZE  2
#define OPCODE_SIZE     13
#define MALLOC_ERROR    "The memory allocation for linked list aborts."
#define MODE_ERROR      "The mode is not accessible."
#define OPCODE_ERROR    "The opcode is not accessible."
#define INDEX_ERROR     "The node does not exist."

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

        if(opcode > OPCODE_SIZE)
        {
            fprintf(stderr, "\n> control_table: %s", OPCODE_ERROR);
        }

        l_control_table(&list, opcode);
    }
}

void l_control_table(l_List **node, uint64_t opcode)
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
l_Node * l_initialization(void)
{
    printf("\n%s", "> Initialization: Allocating the memory space for head node.");
    l_Node *head = (l_Node *)calloc(1, sizeof(l_Node));

    //Probing whether the memory allocation successes.
    if(head == NULL)
    {
        fprintf(stderr, "\n> Initialization: %s", MALLOC_ERROR);
        return NULL;
    }

    printf("\n%s", "> Initialization: The memory allocation completes!");
    printf("\n%s\n%s\n%s\n%s\n%s",  "> Initialization: Type mode table as following:",
                                    "  | 0 | singly linked list     |",
                                    "  | 1 | polynomial linked list |",
                                    "  | 2 | doubly linked list     |",
                                    "  | 3 | circular linked list   |");
    
    //Interface for setting mode.
    printf("\n%s", "> Initialization: Please set the type mode for the head node:");
    scanf("%llu", &head->type);
    getchar();
    
    //Probing whether the type mode is correct.
    if(head->type >= LIST_TYPE_SIZE)
    {
        fprintf(stderr, "\n> Initialization: %s", MODE_ERROR);
        return NULL;
    }
    return head;
}
/*----------------------------------------function *l_initialization* end  ----------------------------------------*/
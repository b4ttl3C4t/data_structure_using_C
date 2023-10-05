#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "linked_list.h"

#define LIST_SIZE 50
#define LIST_TYPE_SIZE 2
#define MALLOC_ERROR    "The memory allocation for linked list aborts."
#define MODE_ERROR      "The mode is not accessible."
#define OPCODE_ERROR    "The opcode is not accessible."
#define INDEX_ERROR     "The node does not exist."

int main(void)
{
    l_Node *head;
    uint64_t opcode;

    while(1)
    { 
        printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",
                            "> control_table: ",
                            "  |code|    function    |",
                            "  |  0 | initialization |",
                            "  |  1 | construction   |",
                            "  |  2 | insertion      |",
                            "  |  3 | insert_head    |",
                            "  |  4 | insert_tail    |",
                            "  |  5 | destruction    |",
                            "  |  6 | deletion       |",
                            "  |  7 | delete_head    |",
                            "  |  8 | delete_tail    |",
                            "  |  9 | search         |",
                            "  | 10 | display        |",
                            "  | 11 | sort           |",
                            "  | 12 | reverse        |",
                            "  | 13 | is_list_empty  |",
                            "  | 14 |      EXIT      |",
                            "> control_table: What do you want to do now? Please enter the opcode:");
        scanf("%llu", &opcode);
        getchar();

        if(opcode == 14)
        {
            printf("\n%s", "> control_table: Quitting the process for linked list");
            return 0;
        }

        if(opcode > 14)
        {
            fprintf(stderr, "\n> control_table: %s", OPCODE_ERROR);
        }

        l_control_table(&head, opcode);
    }
}

void l_control_table(l_Node **node, uint64_t opcode)
{
    uint64_t index;

    switch(opcode)
    {
    case 0:
        *node = l_initialization();
        break;

    case 3:
        *node = l_insert_head(*node);
        break;

    case 7:
        *node = l_delete_head(*node);
        break;

    case 10:
        l_display(*node);
        break;
    }

    return;
}

static void input_data  (l_Node *node);
static void swap        (l_Node *X, l_Node *Y);

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

    input_data(head);
    //Initializate linkage for head node.
    ;

    return head;
}
/*----------------------------------------function *l_initialization* end  ----------------------------------------*/
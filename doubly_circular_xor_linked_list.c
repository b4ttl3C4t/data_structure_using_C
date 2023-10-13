#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "doubly_circular_xor_linked_list.h"



#define LIST_TYPE_SIZE  2
#define OPCODE_SIZE     14
#define MALLOC_ERROR    "The memory allocation for linked list aborts."
#define MODE_ERROR      "The mode is not accessible."
#define OPCODE_ERROR    "The opcode is not accessible."
#define INDEX_ERROR     "The node does not exist."



enum LinkedListType
{
    normal      = 0,
    polynomial  = 1,
};
/*You should set the mode for the newer node (as following)
 *whenever you construst it.
 */

enum LinkedListReverse
{
    forward  = 0,
    backward = 1,
};
/*You should set the mode for the newer node (as following)
 *whenever you construst it.
 */

//The definition of data for polynomials.
struct polynomial_data
{
    double   coefficient;
    uint64_t power;
};

//The definition of data for the normal node.
struct node_data
{
    uint64_t integer;
};

//Constructing the data of compound linked list type.
typedef struct Linked_List_Data_s
{
    union
    {
        struct polynomial_data polynomial;
        struct node_data       default_data;
    };
} l_Data;

//The node type is for doubly circular xor linked list.
typedef struct Linked_List_Node_s
{
    struct Linked_List_Data_s *data;
    struct Linked_List_Node_s *link;
} l_Node;
/*The pointer to data is used to promote the code flexiblity, 
 *when you swap the data within two node, or change the data setting.
 */

//The linked list type.
typedef struct Linked_List_s
{
    enum    LinkedListType       type;
    enum    LinkedListReverse    status;
    struct  Linked_List_Node_s * head;
    struct  Linked_List_Node_s * dummy_sentinel_node;
} l_List;
//Constructing compound linked list type, then setting the mode by variable *type* .
//The *head node* means the beginning of the linked list.
//The *sentinel node* means the check point of the linked list.
/*The *dummy node* can avoid the special operation to the head node.
 *and let the code more clear and promote its readness.
 */
//The dummy_sentinel_node means it's the usage consisted of both dummy node and sentinel node.



//Internal function.
       static l_List *  initialization  (void);
       static void      special_handle  (enum LinkedListType type, l_Node *node);
inline static void      input_data      (enum LinkedListType type, l_Node *node);
inline static void      swap_data       (l_Node *X, l_Node *Y);
inline static l_Node *  node_xor        (l_Node *X, l_Node *Y);

int main(void)
{
    l_List *list = initialization();
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

/*----------------------------------------function *l_initialization*  begin----------------------------------------*/
l_List * initialization(void)
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

//Inputing the data of the node.
static void input_data(enum LinkedListType type, l_Node *node)
{
    if(node == NULL)
    {
        fprintf(stderr, "\n%s%s", "> input_data: ", INDEX_ERROR);
        return;
    }

    if(type == normal)
    {
        scanf("%d", node->data->default_data.integer);
        getchar();
        return;
    }
    if(type == polynomial)
    {
        scanf("%d%d",   node->data->polynomial.coefficient,
                        node->data->polynomial.power);
        getchar();
        return;
    }
}

//Swapping node by swapping the pointer *data* to the data of the node.
static void swap_data(l_Node *X, l_Node *Y)
{
    (X->data) = (struct Linked_List_Data_s *)((unsigned long)(X->data) ^ (unsigned long)(Y->data));
    (Y->data) = (struct Linked_List_Data_s *)((unsigned long)(X->data) ^ (unsigned long)(Y->data));
    (X->data) = (struct Linked_List_Data_s *)((unsigned long)(X->data) ^ (unsigned long)(Y->data));
}

//Returning the address of previous node or next node, depended on circumstances.
static l_Node * node_xor(l_Node *X, l_Node *Y)
{
    return (l_Node *)((unsigned long)(X) ^ (unsigned long)(Y));
}
#include "doubly_circular_xor_linked_list.h"

#define LIST_TYPE_SIZE  2
#define OPCODE_SIZE     14

#define MALLOC_ERROR        "The memory allocation for linked list aborts."
#define MODE_ERROR          "The mode is not accessible."
#define OPCODE_ERROR        "The opcode is not accessible."
#define INDEX_ERROR         "The node does not exist."
#define CONSTRUCT_MESSAGE   "The list has already constructed."



//The interface of the internal function.
       static l_List *  initialization  (void);
       static void      special_handle  (enum LinkedListType type, l_Node *node);
       static void      input_data      (enum LinkedListType type, l_Node *node);
       static void      output_data     (enum LinkedListType type, l_Node *node);
       static l_Node *  search_node     (l_List *list, uint64_t index);
inline static void      swap_data       (l_Node *X, l_Node *Y);
inline static l_Node *  node_xor        (l_Node *X, l_Node *Y);
inline static bool      is_empty        (l_List *list);



void main(void)
{
    l_List * list = initialization();

    while(l_control_table(list));
    //Not breaking the loop until l_control_table appear *opcode 13 (EXIT)*.
}

int8_t l_control_table(l_List *list)
{
    static uint64_t index, opcode;

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

    if(opcode == 13)
    {
        printf("\n%s", "> control_table: Exiting the program operation...");
        return false;
    }

    if(opcode >= OPCODE_SIZE)
    {
        fprintf(stderr, "\n%s%s", "> control_table: ", OPCODE_ERROR);
    }

    switch(opcode)
    {
    case 0:
        break;

    case 3:
        break;

    case 7:
        break;

    case 12:
        l_is_empty(list);
        break;
    }

    return true;
}

void l_construction(l_List *list)
{
    int is_first_flag = 1;
    l_Node * new;
    l_Data * new_data;

    if(!is_empty(list))
    {
        fprintf(stderr, "\n%s%s", "> Construction: ", CONSTRUCT_MESSAGE);
        return;
    }

    do
    {
        new      = (l_Node *)malloc(sizeof(l_Node));
        new_data = (l_Data *)malloc(sizeof(l_Data));
        if(new == NULL || new_data == NULL)
        {
            fprintf(stderr, "\n%s%s", "> Construction: ", MALLOC_ERROR);
            return;
        }

        new->data  = new_data;
        list->tail = new;
        input_data(list->type, new);

        if(is_first_flag)
        {
            is_first_flag = 0;
            list->head = new;
        }
    } while (1);
}

void l_is_empty(l_List *list)
{
    if(list->head == NULL)
    {
        printf("\n%s", "> is_empty: The list is empty.");
    }
    else
    {
        printf("\n%s", "> is_empty: The list is not empty.");
    }
}

l_List * initialization(void)
{
    printf("\n%s", "> initialization: Allocating the memory space for head node.");
    l_List *list = (l_List *)calloc(1, sizeof(l_List));

    //Probing whether the memory allocation successes.
    if(list == NULL)
    {
        fprintf(stderr, "\n%s%s", "> initialization: ", MALLOC_ERROR);
        return NULL;
    }

    printf("\n%s", "> initialization: The memory allocation completes!");
    printf("\n%s\n%s\n%s",  "> initialization: Type mode table as following:",
                            "  | 0 | normal linked list     |",
                            "  | 1 | polynomial linked list |");
    
    //Interface for setting mode.
    printf("\n%s", "> initialization: Please set the type mode for the head node:");
    scanf("%llu", list->type);
    getchar();
    
    //Probing whether the type mode is correct.
    if(list->type >= LIST_TYPE_SIZE)
    {
        fprintf(stderr, "\n%s%s", "> initialization: ", MODE_ERROR);
        return NULL;
    }

    return list;
}



//The implementation of the internal function.
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

static void output_data(enum LinkedListType type, l_Node *node)
{
    if(node == NULL)
    {
        fprintf(stderr, "\n%s%s", "> input_data: ", INDEX_ERROR);
        return;
    }

    if(type == normal)
    {
        printf("%d", node->data->default_data.integer);
        return;
    }
    if(type == polynomial)
    {
        printf("%d%d",  node->data->polynomial.coefficient,
                        node->data->polynomial.power);
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

//The function is not equal to *l_is_empty* , it returns boolean value instead.
static bool is_empty(l_List *list)
{
    if(list->head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Searching weather the node exists.
static l_Node * search_node(l_List *list, uint64_t index)
{
    if(is_empty(list))
    {
        return NULL;
    }

    list->previous   = list->head;
    list->current    = list->head->link;
    list->temporary  = NULL;

    while((list->current != list->tail) && (--index != 0))
    {
        list->temporary  = list->current;
        list->current    = node_xor(list->previous, list->current->link);
        list->previous   = list->temporary;
    }

    if((list->current == list->tail) && (index != 0))
    {
        return NULL;
    }

    return list->current;
}
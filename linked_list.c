#include "linked_list.h"

#define LIST_TYPE_SIZE  2
#define OPCODE_SIZE     14

#define MALLOC_ERROR        "The memory allocation for linked list aborts."
#define MODE_ERROR          "The mode is not accessible."
#define OPCODE_ERROR        "The opcode is not accessible."
#define INDEX_ERROR         "The node does not exist."
#define CONSTRUCT_MESSAGE   "The list has already constructed."
#define DESTRUCT_MESSAGE    "The list has already destructed."
#define WRONG_INPUT         "The input is invalid."



//The interface of the internal function.
       static l_List *  initialization  (void);
       static void      input_data      (enum LinkedListType type, l_Node *node);
       static void      output_data     (enum LinkedListType type, l_Node *node);
       static l_Node *  search_node     (l_List *list, uint64_t index);
inline static void      swap_data       (l_Node *X, l_Node *Y);
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
    int index, is_first_flag = 1;
    l_Node * new;
    l_Data * new_data;

    if(!is_empty(list))
    {
        fprintf(stderr, "\n%s%s", "> Construction: ", CONSTRUCT_MESSAGE);
        return;
    }

    //Initializing the value of *size*.
    printf("\n%s", "> Construction: Enter the size you to initialize the linked list.");
    do
    {
        if(scanf("%llu", &list->size) != 0 && list->size != 0)
        {
            getchar();
            break;
        }
        
        getchar();
        fprintf(stderr, "\n%s%s", "> Construction: ", WRONG_INPUT);

    } while(1);

    //Constructing the linked list based on the value of *size*.
    for(index = 0; index < list->size; ++index)
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

//Insert the new node to the previous one of the given index.
void l_insertion(l_List *list, uint64_t index)
{
    if(is_empty(list) || index == 0)
    {
        l_insert_head(list);
        return;
    }

    if(index == list->size)
    {
        l_insert_tail(list);
        return;
    }

    list->current = search_node(list, index);
    if(list->current == NULL)
    {
        fprintf(stderr, "\n%s%s", "> input_data: ", INDEX_ERROR);
        return;
    }

    //Constructing the node.
    list->current->prev->next = (l_Node *)malloc(sizeof(l_Node));
    input_data(list->type, list->current->prev->next);
    
    //Constructing the linkage of the *current* node between the prev and next one.
    list->current->prev->next->prev = list->current->prev->next;
    list->current->prev->next->next = list->current->next;
    list->current->next->prev = list->current->prev->next;
    ++(list->size);
}

void l_insert_head(l_List *list)
{
    if(is_empty(list))
    {
        fprintf(stderr, "\n%s%s", "> insert_head: ", DESTRUCT_MESSAGE);
        l_construction(list);
    }
}

void l_insert_tail(l_List *list);

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



//The implementation of the internal functions.
static void input_data(enum LinkedListType type, l_Node *node)
{
    if(node == NULL)
    {
        fprintf(stderr, "\n%s%s", "> input_data: ", INDEX_ERROR);
        return;
    }

    if(type == normal)
    {
        do
        {
            if(scanf("%d", node->data->default_data.integer) == 1)
            {
                getchar();
                return;
            }


        } while (1);
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

    if(index == 0)
    {
        return NULL;
    }

    list->current = list->head->next;
    while((list->current != list->head) && (--index != 0))
    {
        list->current = list->current->next;
    }

    if((list->current == list->tail) && (index != 0))
    {
        return NULL;
    }

    return list->current;
}
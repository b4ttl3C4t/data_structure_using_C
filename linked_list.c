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
       static void      input_data      (enum LinkedListType type, l_Node *node);
       static void      output_data     (enum LinkedListType type, l_Node *node);
       static l_Node *  search_node     (l_List *list, uint64_t index);
inline static bool      is_empty        (l_List *list);
inline static void      swap_data       (l_Node *X, l_Node *Y);



int main(void)
{
    l_List * list = l_initialization();

    while(l_control_table(list));
    //Not breaking the loop until l_control_table appear *opcode 13 (EXIT)*.
}

int8_t l_control_table(l_List *list)
{
    static uint64_t index, opcode;

    printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",
                        "> l_control_table: ",
                        "  |code|    function    |",
                        "  |  0 | l_construction   |",
                        "  |  1 | l_insertion      |",
                        "  |  2 | l_insert_head    |",
                        "  |  3 | l_insert_tail    |",
                        "  |  4 | l_destruction    |",
                        "  |  5 | l_deletion       |",
                        "  |  6 | l_delete_head    |",
                        "  |  7 | l_delete_tail    |",
                        "  |  8 | l_search         |",
                        "  |  9 | l_display        |",
                        "  | 10 | l_sort           |",
                        "  | 11 | l_reverse        |",
                        "  | 12 | l_is_empty       |",
                        "  | 13 |       EXIT       |",
                        "> l_control_table: What do you want to do now? Please enter the opcode:");
    scanf("%llu", &opcode);
    getchar();

    if(opcode == 13)
    {
        printf("\n%s", "> l_control_table: Exiting the program operation...");
        return false;
    }

    if(opcode >= OPCODE_SIZE)
    {
        fprintf(stderr, "\n%s%s", "> l_control_table: ", OPCODE_ERROR);
    }

    switch(opcode)
    {
    case 0:
        l_construction(list);
        break;

    case 1:
        scanf("%llu", &index);
        getchar();
        l_insertion(list, index);
        break;

    case 2:
        l_insert_head(list);
        break;
    
    case 3:
        l_insert_tail(list);
        break;

    case 4:
        l_destruction(list);
        break;
    
    case 5:
        scanf("%llu", &index);
        getchar();
        l_deletion(list, index);
        break;

    case 6:
        l_delete_head(list);
        break;
    
    case 7:
        l_delete_tail(list);
        break;

    case 8:
        scanf("%llu", &index);
        getchar();
        l_search(list, index);
        break;
    
    case 9:
        l_display(list);
        break;

    case 10:
        l_sort(list);
        break;
    
    case 11:
        l_reverse(list);
        break;

    case 12:
        l_is_empty(list);
        break;
    }

    return true;
}

l_List * l_initialization(void)
{
    printf("\n%s", "> l_initialization: Allocating the memory space for head node.");
    l_List *list = (l_List *)calloc(1, sizeof(l_List));

    //Probing whether the memory allocation successes.
    if(list == NULL)
    {
        fprintf(stderr, "\n%s%s", "> initialization: ", MALLOC_ERROR);
        return NULL;
    }

    printf("\n%s", "> l_initialization: The memory allocation completes!");
    printf("\n%s\n%s\n%s",  "> l_initialization: Type mode table as following:",
                            "  | 0 | normal linked list     |",
                            "  | 1 | polynomial linked list |");
    
    //Interface for setting mode.
    printf("\n%s", "> l_initialization: Please set the type mode for the head node:");
    scanf("%llu", list->type);
    getchar();
    
    //Probing whether the type mode is correct.
    if(list->type >= LIST_TYPE_SIZE)
    {
        fprintf(stderr, "\n%s%s", "> l_initialization: ", MODE_ERROR);
        return NULL;
    }

    return list;
}

void l_construction(l_List *list)
{
    uint32_t index, is_first_flag = 1;
    l_Node * new;
    l_Data * new_data;

    if(!is_empty(list))
    {
        fprintf(stderr, "\n%s%s", "> l_construction: ", CONSTRUCT_MESSAGE);
        return;
    }

    //Initializing the value of *size*.
    printf("\n%s", "> l_construction: Enter the size you to initialize the linked list.");
    while(1)
    {
        if(scanf("%llu", &list->size) != 0 && list->size != 0)
        {
            getchar();
            break;
        }
        
        getchar();
        fprintf(stderr, "\n%s%s", "> l_construction: ", WRONG_INPUT);
    }

    //Constructing the linked list based on the value of *size*.
    list->head = (l_Node *)malloc(sizeof(l_Node));  //The data for the head node is inaccessible.
    list->head->next = NULL;
    list->head->prev = NULL;
    list->current = list->head;

    for(index = 0; index < list->size; ++index)
    {
        list->current->next       = (l_Node *)malloc(sizeof(l_Node));
        if(list->current->next == NULL)
        {
            fprintf(stderr, "\n%s%s", "> l_construction: ", MALLOC_ERROR);
            return;
        }

        list->current->next->data = (l_Data *)malloc(sizeof(l_Data));
        if(list->current->next->data == NULL)
        {
            fprintf(stderr, "\n%s%s", "> l_construction: ", MALLOC_ERROR);
            return;
        }
        input_data(list->type, list->current->next);

        list->current->next->prev = list->current;
        list->current->next->next = list->head;
    }
}

//Insert the new node to the previous one of the given index.
void l_insertion(l_List *list, uint64_t index)
{
    if(is_empty(list))
    {
        l_construction(list);
        return;
    }

    if(index == 0)
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
        fprintf(stderr, "\n%s%s", "> l_insertion: ", INDEX_ERROR);
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
        fprintf(stderr, "\n%s%s", "> l_insert_head: ", DESTRUCT_MESSAGE);
        printf("\n%s", "> l_insert_head: Please initialize the linked list firstly.");
        return;
    }

    
}

void l_insert_tail(l_List *list)
{
    if(is_empty(list))
    {
        fprintf(stderr, "\n%s%s", "> l_insert_head: ", DESTRUCT_MESSAGE);
        printf("\n%s", "> l_insert_head: Please initialize the linked list firstly.");
        return;
    }

}

void l_destruction(l_List *list)
{
    uint32_t index;

    if(is_empty(list))
    {
        fprintf(stderr, "\n%s%s", "> l_insert_head: ", DESTRUCT_MESSAGE);
        return;
    }

    list->current = list->head->next;
    for(index = 0; index < list->size; ++index)
    {
        list->current = list->current->next;
        free(list->current->prev->data);
        free(list->current->prev);
    }
    free(list->current);
    free(list);
}

void l_search(l_List *list, uint64_t index)
{
    if(is_empty(list))
    {
        fprintf(stderr, "\n%s%s", "> l_search: ", DESTRUCT_MESSAGE);
        return;
    }

    if(index == 0)
    {
        fprintf(stderr, "\n%s%s", "> l_search: ", INDEX_ERROR);
        return;
    }

    list->current = list->head->next;
    while((list->current != list->head) && (--index != 0))
    {
        list->current = list->current->next;
    }

    if((list->current == list->head) && (index != 0))
    {
        fprintf(stderr, "\n%s%s", "> l_search: ", INDEX_ERROR);
        return;
    }

    output_data(list->type, list->current);
}

void l_display(l_List *list)
{
    if(is_empty(list))
    {
        fprintf(stderr, "\n%s%s", "> l_display: ", DESTRUCT_MESSAGE);
        return;
    }
    
    list->current = list->head->next;
    while(list->current != list->head)
    {
        output_data(list->type, list->current);
        list->current = list->current->next;
    }
}

void l_reverse(l_List *list)
{
    if(is_empty(list))
    {
        fprintf(stderr, "\n%s%s", "> l_reverse: ", DESTRUCT_MESSAGE);
        return;
    }

    if(list->size == 1)
    {
        printf("\n%s", "> l_reverse: The list has already resort.");
        return;
    }

    uint64_t i;
    list->current = list->head->next;
    for(i = 0; i < list->size; ++i)
    {
        list->current->prev->next = list->current->prev->prev;

    }
    list->head = list->current;

    printf("\n%s", "> l_reverse: The list has already resort.");
}

void l_is_empty(l_List *list)
{
    if(list->head == NULL)
    {
        printf("\n%s", "> l_is_empty: The list is empty.");
    }
    else
    {
        printf("\n%s", "> l_is_empty: The list is not empty.");
    }
}



//The implementation of the internal func
static void input_data(enum LinkedListType type, l_Node *node)
{
    if(node == NULL)
    {
        fprintf(stderr, "\n%s%s", "> input_data: ", INDEX_ERROR);
        return;
    }

    while(type == normal)
    {
        if(scanf("%d", node->data->default_data.integer) == 1)
        {
            getchar();
            return;
        }

        getchar();
        fprintf(stderr, "\n%s%s", "> input_data: ", WRONG_INPUT);
        printf("\n%s", "> input_data: Please enter again: ");
    }

    while(type == polynomial)
    {
        
        if(scanf("%lf%llu", node->data->polynomial.coefficient, node->data->polynomial.power) == 2)
        {
            getchar();
            return;
        }

        getchar();
        fprintf(stderr, "\n%s%s", "> input_data: ", WRONG_INPUT);
        printf("\n%s", "> input_data: Please enter again: ");
    }
}

static void output_data(enum LinkedListType type, l_Node *node)
{
    if(node == NULL)
    {
        fprintf(stderr, "\n%s%s", "> output_data: ", INDEX_ERROR);
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

    if((list->current == list->head) && (index != 0))
    {
        return NULL;
    }

    return list->current;
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

//Swapping node by swapping the pointer *data* to the data of the node.
static void swap_data(l_Node *X, l_Node *Y)
{
    (X->data) = (struct Linked_List_Data_s *)((unsigned long)(X->data) ^ (unsigned long)(Y->data));
    (Y->data) = (struct Linked_List_Data_s *)((unsigned long)(X->data) ^ (unsigned long)(Y->data));
    (X->data) = (struct Linked_List_Data_s *)((unsigned long)(X->data) ^ (unsigned long)(Y->data));
}
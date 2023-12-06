#include "linked_list.h"

#define LIST_TYPE_SIZE  2
#define OPCODE_SIZE     13

#define MALLOC_ERROR        "The memory allocation for linked list aborts."
#define MODE_ERROR          "The mode is not accessible."
#define OPCODE_ERROR        "The opcode is not accessible."
#define INDEX_ERROR         "The node does not exist."
#define CONSTRUCT_MESSAGE   "The list has already constructed."
#define DESTRUCT_MESSAGE    "The list has already destructed."
#define WRONG_INPUT         "The input is invalid."



void (*volatile const CONTROL_TABLE[OPCODE_SIZE - 1])(l_List *) = 
{
    l_construction,
    l_insertion,
    l_insert_head,
    l_insert_tail,
    l_destruction,
    l_deletion,
    l_delete_head,
    l_delete_tail,
    l_search,
    l_display,
    l_reverse,
    l_is_empty
};

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
    free(list);
    list = NULL;
}

int8_t l_control_table(l_List *list)
{
    static uint64_t opcode;

    printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",
                        "> l_control_table: ",
                        "  |code|     function     |",
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
                        "  | 10 | l_reverse        |",
                        "  | 11 | l_is_empty       |",
                        "  | 12 |       EXIT       |",
                        "> l_control_table: What do you want to do now? Please enter the opcode:");
    scanf("%llu", &opcode);
    getchar();

    if(opcode == 12)
    {
        printf("\n%s", "> l_control_table: Exiting the program operation...");
        return false;
    }

    if(opcode >= OPCODE_SIZE)
    {
        fprintf(stderr, "\n%s%s", "> l_control_table: ", OPCODE_ERROR);
    }

    CONTROL_TABLE[opcode](list);
    
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
    list->head = NULL;

    printf("\n%s", "> l_initialization: The memory allocation completes!");
    printf("\n%s\n%s\n%s",  "> l_initialization: Type mode table as following:",
                            "  | 0 | normal linked list     |",
                            "  | 1 | polynomial linked list |");
    
    //Probing whether the type mode is correct.
    //Interface for setting mode.
    printf("\n%s", "> l_initialization: Please set the type mode for the head node:");
    
    scanf("%llu", &list->type);
    getchar();

    while(list->type >= LIST_TYPE_SIZE)
    {
        fprintf(stderr, "\n%s%s", "> l_initialization: ", MODE_ERROR);
        printf("\n%s", "> l_initialization: Please set the type mode again:");

        scanf("%llu", &list->type);
        getchar();
    }

    list->size = 0;

    return list;
}

void l_construction(l_List *list)
{
    if(!is_empty(list))
    {
        fprintf(stderr, "\n%s%s", "> l_construction: ", CONSTRUCT_MESSAGE);
        return;
    }

    //Initializing the value of *size*.
    printf("\n%s", "> l_construction: Enter the size you to initialize the linked list:");
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

    list->head = (l_Node *)malloc(sizeof(l_Node));
    if(list->head == NULL)
    {
        fprintf(stderr, "\n%s%s", "> l_construction: ", MALLOC_ERROR);
        return;
    }
    //The data for the head node is inaccessible.
    list->head->next = list->head;
    list->head->prev = list->head;
    list->curr       = list->head;

    //Constructing the linked list based on the value of *size*.
    uint32_t index;
    for(index = 0; index < list->size; ++index)
    {
        (list->curr->next) = (l_Node *)malloc(sizeof(l_Node));
        if((list->curr->next) == NULL)
        {
            fprintf(stderr, "\n%s%s", "> l_construction: ", MALLOC_ERROR);
            return;
        }

        (list->curr->next)->data = (l_Data *)malloc(sizeof(l_Data));
        if((list->curr->next)->data == NULL)
        {
            fprintf(stderr, "\n%s%s", "> l_construction: ", MALLOC_ERROR);
            return;
        }
        input_data(list->type, (list->curr->next));

        (list->curr->next)->prev = list->curr;
        (list->curr->next)->next = list->head;
        list->curr = (list->curr->next);
    }
    list->head->prev = list->curr;
}

//Insert the new node to the previous one of the given index.
void l_insertion(l_List *list)
{
    if(is_empty(list))
    {
        fprintf(stderr, "\n%s%s", "> l_insertion: ", DESTRUCT_MESSAGE);
        l_construction(list);
        return;
    }

    uint64_t index;

    //Get input.
    printf("\n%s", "> l_insertion: Please enter the index:");
    while(scanf("%llu", &index) != 1)
    {
        getchar();
        fprintf(stderr, "\n%s%s", "> l_insertion: ", WRONG_INPUT);
        printf("\n%s", "> l_insertion: Please enter again:");
    }
    getchar();

    if(index == 0)
    {
        l_insert_head(list);
        return;
    }

    if(index == list->size - 1)
    {
        l_insert_tail(list);
        return;
    }

    //Find the key.
    list->curr = search_node(list, index);
    if(list->curr == NULL)
    {
        fprintf(stderr, "\n%s%s", "> l_insertion: ", INDEX_ERROR);
        return;
    }

    //Constructing the linkage of the *temp* node between the prev and next one.
    (list->temp) = (l_Node *)malloc(sizeof(l_Node));
    if((list->temp) == NULL)
    {
        fprintf(stderr, "\n%s%s", "> l_insertion: ", MALLOC_ERROR);
        return;
    }
    
    (list->temp)->data = (l_Data *)malloc(sizeof(l_Data));
    if((list->temp)->data == NULL)
    {
        fprintf(stderr, "\n%s%s", "> l_insertion: ", MALLOC_ERROR);
        return;
    }
    input_data(list->type, (list->temp));

    //Modify *list->curr->prev* firstly, then fine-tune the *list->curr* .
    (list->temp)->prev       = (list->curr->prev);
    (list->curr->prev)->next = (list->temp);

    (list->temp)->next       = (list->curr);
    (list->curr)->prev       = (list->temp);

    ++(list->size);
}

void l_insert_head(l_List *list)
{
    (list->temp) = (l_Node *)malloc(sizeof(l_Node));
    if((list->temp) == NULL)
    {
        fprintf(stderr, "\n%s%s", "> l_insert_head: ", MALLOC_ERROR);
        return;
    }

    (list->temp)->data = (l_Data *)malloc(sizeof(l_Data));
    if((list->temp)->data == NULL)
    {
        fprintf(stderr, "\n%s%s", "> l_insert_head: ", MALLOC_ERROR);
        return;
    }
    input_data(list->type, (list->temp));

    (list->temp)->prev = (list->head);
    (list->temp)->next = (list->head)->next;
    (list->head)->next->prev = (list->temp);
    (list->head)->next = (list->temp);

    ++list->size;
}

void l_insert_tail(l_List *list)
{
    (list->temp) = (l_Node *)malloc(sizeof(l_Node));
    if((list->temp) == NULL)
    {
        fprintf(stderr, "\n%s%s", "> l_insert_tail: ", MALLOC_ERROR);
        return;
    }

    (list->temp)->data = (l_Data *)malloc(sizeof(l_Data));
    if((list->temp)->data == NULL)
    {
        fprintf(stderr, "\n%s%s", "> l_insert_tail: ", MALLOC_ERROR);
        return;
    }
    input_data(list->type, (list->temp));

    (list->temp)->prev = (list->head)->prev;
    (list->temp)->next = (list->head);
    (list->head)->prev->next = (list->temp);
    (list->head)->prev = (list->temp);

    ++list->size;
}

void l_destruction(l_List *list)
{
    if(is_empty(list))
    {
        fprintf(stderr, "\n%s%s", "> l_destruction: ", DESTRUCT_MESSAGE);
        return;
    }
    
    for(list->curr  = list->head->next; 
        list->curr != list->head; 
        list->curr  = list->curr->next)
    {
        free(list->curr->data);
        list->curr->prev->next = list->curr->next;
        list->curr->next->prev = list->curr->prev;
        free(list->curr);
        --(list->size);
    }
    free(list->head);
    list->head = NULL;

    if(is_empty(list)) printf("ABC");
}

void l_deletion(l_List *list)
{
    if(is_empty(list))
    {
        fprintf(stderr, "\n%s%s", "> l_deletion: ", DESTRUCT_MESSAGE);
        return;
    };

    uint64_t index;

    printf("\n%s", "> l_deletion: Please enter the index:");
    while(scanf("%llu", &index) != 1)
    {
        getchar();
        fprintf(stderr, "\n%s%s", "> l_deletion: ", WRONG_INPUT);
        printf("\n%s", "> l_deletion: Please enter again:");
    }
    getchar();

    if(index == 0)
    {
        l_delete_head(list);
        return;
    }

    if(index == list->size - 1)
    {
        l_delete_tail(list);
        return;
    }
    
    list->curr = search_node(list, index + 1);
    
    if(list->curr == NULL)
    {
        fprintf(stderr, "\n%s%s", "> l_deletion: ", INDEX_ERROR);
        return;
    }

    free(list->curr->data);
    list->curr->prev->next = list->curr->next;
    list->curr->next->prev = list->curr->prev;
    free(list->curr);
    --(list->size);
}

void l_delete_head(l_List *list)
{
    if(is_empty(list))
    {
        fprintf(stderr, "\n%s%s", "> l_delete_head: ", DESTRUCT_MESSAGE);
        return;
    }

    (list->curr) = list->head->next;
    free((list->curr)->data);
    (list->curr)->next->prev = (list->head);
    (list->head)->next = (list->curr)->next;
    free((list->curr));

    --(list->size);
}

void l_delete_tail(l_List *list)
{
    if(is_empty(list))
    {
        fprintf(stderr, "\n%s%s", "> l_delete_head: ", DESTRUCT_MESSAGE);
        return;
    }

    (list->curr) = list->head->prev;
    free((list->curr)->data);
    (list->curr)->prev->next = (list->head);
    (list->head)->prev = (list->curr)->prev;
    free((list->curr));

    --(list->size);
}

void l_search(l_List *list)
{
    if(is_empty(list))
    {
        fprintf(stderr, "\n%s%s", "> l_search: ", DESTRUCT_MESSAGE);
        return;
    }

    uint64_t index;

    printf("\n%s", "> l_search: Please enter the index:");
    while(scanf("%llu", &index) != 1)
    {
        getchar();
        fprintf(stderr, "\n%s%s", "> l_search: ", WRONG_INPUT);
        printf("\n%s", "> l_search: Please enter again:");
    }
    getchar();

    if(index >= list->size)
    {
        fprintf(stderr, "\n%s%s", "> l_search: ", INDEX_ERROR);
        return;
    }

    list->curr = list->head->next;
    while((list->curr != list->head) && (index-- != 0))
    {
        list->curr = list->curr->next;
    }

    if((list->curr == list->head) && (index != 0))
    {
        fprintf(stderr, "\n%s%s", "> l_search: ", INDEX_ERROR);
        return;
    }

    output_data(list->type, list->curr);
}

void l_display(l_List *list)
{
    if(is_empty(list))
    {
        fprintf(stderr, "\n%s%s", "> l_display: ", DESTRUCT_MESSAGE);
        return;
    }

    list->curr = list->head->next;
    while(list->curr != list->head)
    {
        output_data(list->type, list->curr);
        list->curr = list->curr->next;
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
        printf("\n%s", "> l_reverse: The list has already reversed.");
        return;
    }

    uint64_t index;
    list->curr = list->head->next;
    for(index = 0; index <= list->size; ++index)
    {
        list->temp       = list->curr->next;
        list->curr->next = list->curr->prev;
        list->curr->prev = list->temp;

        list->curr = list->temp;
    }

    printf("\n%s", "> l_reverse: The list has already reversed.");
}

void l_is_empty(l_List *list)
{
    if(list->head == NULL || list->size == 0)
    {
        printf("\n%s", "> l_is_empty: The list is empty.");
    }
    else
    {
        printf("\n%s%llu", "> l_is_empty: The list is not empty, "
                                     "the size of the list is ", 
                                     list->size);
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
    
    if(type == normal)
    {
        printf("\n%s", "> input_data: Please enter the data:");

        while(1)
        {
            if(scanf("%d", &node->data->default_data.integer) == 1)
            {
                getchar();
                return;
            }

            getchar();
            fprintf(stderr, "\n%s%s", "> input_data: ", WRONG_INPUT);
            printf("\n%s", "> input_data: Please enter again:");
        }
    }

    if(type == polynomial)
    {
        printf("\n%s", "> input_data: Please enter the coefficient and the power:");
        
        while(1)
        {
            if(scanf("%lf", &node->data->polynomial.coefficient) == 1 && scanf("%llu", &node->data->polynomial.power) == 1)
            {
                getchar();
                return;
            }

            getchar();
            fprintf(stderr, "\n%s%s", "> input_data: ", WRONG_INPUT);
            printf("\n%s", "> input_data: Please enter again: ");
        }
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
        printf("%d ", node->data->default_data.integer);
        return;
    }

    if(type == polynomial)
    {
        printf("%lfx^%llu + ",  node->data->polynomial.coefficient,
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
    
    if(index >= list->size)
    {
        return NULL;
    }
    
    list->curr = list->head->next;
    while((list->curr != list->head) && (--index != 0))
    {
        list->curr = list->curr->next;
    }

    if((list->curr == list->head) && (index != 0))
    {
        return NULL;
    }

    return list->curr;
}

//The function is not equal to *l_is_empty* , it returns boolean value instead.
static bool is_empty(l_List *list)
{
    if(list == NULL || list->size == 0)
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
    if(X == Y) return;

    (X->data) = (struct Linked_List_Data_s *)((unsigned long)(X->data) ^ (unsigned long)(Y->data));
    (Y->data) = (struct Linked_List_Data_s *)((unsigned long)(X->data) ^ (unsigned long)(Y->data));
    (X->data) = (struct Linked_List_Data_s *)((unsigned long)(X->data) ^ (unsigned long)(Y->data));
}
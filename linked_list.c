#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(void)
{
    Node *head = initialization();

    
    return 0;
}

Node * initialization(void)
{
    printf("\n%s", "> Initialization: Allocating the memory space for head node.");
    Node *head = (Node *)calloc(1, sizeof(Node));

    //Probing whether the memory allocation success.
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
    scanf("%u", &head->type);
    getchar();
    
    //Probing whether the type mode is correct.
    if(head->type >= LIST_TYPE_SIZE)
    {
        fprintf(stderr, "\n> Initialization: %s", MODE_ERROR);
        return NULL;
    }

    input_data(head);

    return head;
}

void control_table(Node *node)
{
    unsigned int opcode, index;

    pritnf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",  
                        "> control_table: What do you want to do now?",
                        "  | 0 | insert_head |",
                        "  | 1 | insert_tail |",
                        "  | 2 | delete_head |",
                        "  | 3 | delete_tail |",
                        "  | 4 | display     |",
                        "  | 5 | insertion   |",
                        "  | 6 | deletion    |",
                        "  | 7 | search      |");
    scanf("%u", &opcode);
    getchar();

    /*switch(opcode)
    {
    case 0:
        insert_head(node);
        break;
    
    case 1:
        insert_tail(node);
        break;
    
    case 2:
        delete_head(node);
        break;
    
    case 3:
        delete_tail(node);
        break;
    
    case 4:
        display(node);
        break;
    
    case 5:
        printf("\n%s", "> control_table: The function needs a index to insert the node to designed location.");
        scanf("%u", &index);
        getchar();

        insertion(node, index);
        break;
    
    case 6:
        printf("\n%s", "> control_table: The function needs a index to delete the node of designed location.");
        scanf("%u", &index);
        getchar();

        deletion(node, index);
        break;
    
    case 7:
        printf("\n%s", "> control_table: The function needs a index to search the designed node.");
        scanf("%u", &index);
        getchar();

        search(node, index);
        break;
    
    default:
        fprintf(stderr, "\n> control_table: %s", OPCODE_ERROR);
        return ;
    }*/
}

/*----------------------------------------function *input_data* begin----------------------------------------*/
static inline void singly_input_data     (Node *node);
static inline void polynomial_input_data (Node *node);
static inline void doubly_input_data     (Node *node);
static inline void circular_input_data   (Node *node);

static void (*input_data_choose[LIST_TYPE_SIZE])(Node *node) = 
{ 
    singly_input_data, polynomial_input_data, singly_input_data, singly_input_data
};

inline void input_data(Node *node)
{
    printf("\n%s", "> input_data: Please set the data for the head node:");
    input_data_choose[node->type](node);
}

/*Even though you can do the identical task 
 *with singly, doubly and circular linked list
 *by function *singly_input_data*
 *you still have to set the *type* mode (like 0, 2, 3) of the node.
 */
static inline void singly_input_data(Node *node)
{
    scanf("%d", &node->singly.data);
    getchar();
}

static inline void polynomial_input_data(Node *node)
{
    scanf("%lf%u", &node->polynomial.coefficient, &node->polynomial.power);
    getchar();
}
/*----------------------------------------function *input_data* end  ----------------------------------------*/





/*----------------------------------------function *insert_head* begin----------------------------------------*/
static inline void singly_insert_head     (Node *node);
static inline void polynomial_insert_head (Node *node);
static inline void doubly_insert_head     (Node *node);
static inline void circular_insert_head   (Node *node);

static void (*insert_head_choose[LIST_TYPE_SIZE])(Node *node) = 
{ 
    singly_insert_head, polynomial_insert_head, doubly_insert_head, circular_insert_head
};

void insert_head(Node *node)
{
    insert_head_choose[node->type](node);
}

static inline void singly_insert_head(Node *node)
{
    static Node *head = NULL;
    head = (Node *)malloc(sizeof(Node));
    
    if(head == NULL)
    {
        fprintf(stderr, "%s\n", MALLOC_ERROR);
        return ;
    }

    //Setting the type and input data.
    head->type = node->type;
    singly_input_data(head);
    head->singly.next = node;

    node = head;
}

static inline void polynomial_insert_head(Node *node)
{
    ;
}

static inline void doubly_insert_head(Node *node)
{
    ;
}

static inline void circular_insert_head(Node *node)
{
    ;
}
/*----------------------------------------function *insert_head* end  ----------------------------------------*/





/*----------------------------------------function *insert_tail* begin----------------------------------------*/
static inline void singly_insert_tail     (Node *node);
static inline void polynomial_insert_tail (Node *node);
static inline void doubly_insert_tail     (Node *node);
static inline void circular_insert_tail   (Node *node);

static void (*insert_tail_choose[LIST_TYPE_SIZE])(Node *node) = 
{ 
    singly_insert_tail, polynomial_insert_tail, doubly_insert_tail, circular_insert_tail
};

void insert_tail(Node *node)
{
    ;
}

static inline void singly_insert_tail(Node *node)
{
    ;
}

static inline void polynomial_insert_tail(Node *node)
{
    ;
}

static inline void doubly_insert_tail(Node *node)
{
    ;
}

static inline void circular_insert_tail(Node *node)
{
    ;
}
/*----------------------------------------function *insert_tail* end  ----------------------------------------*/





/*----------------------------------------function *delete_head* begin----------------------------------------*/
static inline void singly_delete_head     (Node *node);
static inline void polynomial_delete_head (Node *node);
static inline void doubly_delete_head     (Node *node);
static inline void circular_delete_head   (Node *node);

static void (*delete_head_choose[LIST_TYPE_SIZE])(Node *node) = 
{ 
    singly_delete_head, polynomial_delete_head, doubly_delete_head, circular_delete_head
};

void delete_head(Node *node)
{
    ;
}

static inline void singly_delete_head(Node *node)
{
    ;
}

static inline void polynomial_delete_head(Node *node)
{
    ;
}

static inline void doubly_delete_head(Node *node)
{
    ;
}

static inline void circular_delete_head(Node *node)
{
    ;
}
/*----------------------------------------function *delete_head* end  ----------------------------------------*/





/*----------------------------------------function *delete_tail* begin----------------------------------------*/
static inline void singly_delete_tail     (Node *node);
static inline void polynomial_delete_tail (Node *node);
static inline void doubly_delete_tail     (Node *node);
static inline void circular_delete_tail   (Node *node);

static void (*delete_tail_choose[LIST_TYPE_SIZE])(Node *node) = 
{ 
    singly_delete_tail, polynomial_delete_tail, doubly_delete_tail, circular_delete_tail
};

void delete_tail(Node *node)
{
    ;
}

static inline void singly_delete_tail(Node *node)
{
    ;
}

static inline void polynomial_delete_tail(Node *node)
{
    ;
}

static inline void doubly_delete_tail(Node *node)
{
    ;
}

static inline void circular_delete_tail(Node *node)
{
    ;
}
/*----------------------------------------function *delete_tail* end  ----------------------------------------*/





/*----------------------------------------function *display* begin----------------------------------------*/
static inline void singly_display     (Node *node);
static inline void polynomial_display (Node *node);
static inline void circular_display   (Node *node);

static void (*display_choose[LIST_TYPE_SIZE])(Node *node) = 
{ 
    singly_display, polynomial_display, singly_display, circular_display
};

void display(Node *node)
{
    if(node->type >= LIST_TYPE_SIZE)
    {
        printf("%s", "It's not a booked type.");
        return ;
    }
    display_choose[node->type](node);
    //Resetting the sentinel node by NULL (or nil).
    sentinel_node = NULL;
    puts("");
}

static inline void singly_display(Node *node)
/*Both singly linked list and doubly linked list could be displayed step by step,
 *not having to care the minute difference between them in most of the time.
 */
{
    sentinel_node = NULL;
    do
    {
        printf("%lld ", node->singly.data);
        node = node->singly.next;
    } while (node != NULL);
}

static inline void polynomial_display(Node *node)
/*All the type of linked list except circular linked list could be displayed step by step,
 *not having to care the minute difference between them in most of the time.
 */
{
    sentinel_node = NULL;
    while(1)
    {
        printf("%lfx^%u", node->polynomial.coefficient, node->polynomial.power);
        node = node->polynomial.next;

        if(node != NULL)
            break;
        
        printf("%s", " + ");
    }
}

static inline void circular_display(Node *node)
{
    sentinel_node = node;
    /*The node means some node you want to begin with,
     *and the function could traverse all the node until
     *meeting with the beginning node again.
     *(Don't forget that it is a *circular* linked list.)
     */

    do
    {
        printf("%lld ", node->circular.data);
        node = node->circular.next;
    } while (node != sentinel_node);
}
/*----------------------------------------function *display* end  ----------------------------------------*/





/*----------------------------------------function *insert* begin----------------------------------------*/
static inline void singly_insert     (Node *node, unsigned int index);
static inline void polynomial_insert (Node *node, unsigned int index);
static inline void doubly_insert     (Node *node, unsigned int index);
static inline void circular_insert   (Node *node, unsigned int index);

static void (*insertion_choose[LIST_TYPE_SIZE])(Node *node, unsigned int index) = 
{ 
    singly_insert, polynomial_insert, doubly_insert, circular_insert
};

void insertion(Node *node, unsigned int index)
{
    ;
}

static inline void singly_insert(Node *node, unsigned int index)
{
    ;
}

static inline void polynomial_insert(Node *node, unsigned int index)
{
    ;
}

static inline void doubly_insert(Node *node, unsigned int index)
{
    ;
}

static inline void circular_insert(Node *node, unsigned int index)
{
    ;
}
/*----------------------------------------function *insert* end  ----------------------------------------*/





/*----------------------------------------function *delete* begin----------------------------------------*/
static inline void singly_delete     (Node *node, unsigned int index);
static inline void polynomial_delete (Node *node, unsigned int index);
static inline void doubly_delete     (Node *node, unsigned int index);
static inline void circular_delete   (Node *node, unsigned int index);

static void (*deletion_choose[LIST_TYPE_SIZE])(Node *node, unsigned int index) = 
{ 
    singly_delete, polynomial_delete, doubly_delete, circular_delete
};

void deletion(Node *node, unsigned int index)
{
    ;
}

static inline void singly_delete(Node *node, unsigned int index)
{
    ;
}

static inline void polynomial_delete(Node *node, unsigned int index)
{
    ;
}

static inline void doubly_delete(Node *node, unsigned int index)
{
    ;
}

static inline void circular_delete(Node *node, unsigned int index)
{
    ;
}
/*----------------------------------------function *delete* end  ----------------------------------------*/





/*----------------------------------------function *search* begin----------------------------------------*/
static inline int singly_search     (Node *node, unsigned int index);
static inline int polynomial_search (Node *node, unsigned int index);
static inline int doubly_search     (Node *node, unsigned int index);
static inline int circular_search   (Node *node, unsigned int index);

static int (*search_choose[LIST_TYPE_SIZE])(Node *node, unsigned int index) = 
{ 
    singly_search, polynomial_search, doubly_search, circular_search
};

int search(Node *node, unsigned int index)
{
    ;
}

static inline int singly_search(Node *node, unsigned int index)
{
    ;
}

static inline int polynomial_search(Node *node, unsigned int index)
{
    ;
}

static inline int doubly_search(Node *node, unsigned int index)
{
    ;
}

static inline int circular_search(Node *node, unsigned int index)
{
    ;
}
/*----------------------------------------function *search* end  ----------------------------------------*/
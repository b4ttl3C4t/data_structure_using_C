#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "linked_list.h"

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
static void l_swap      (l_Node *X, l_Node *Y);

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
    head->circular.next = NULL;
    head->circular.prev = NULL;

    return head;
}
/*----------------------------------------function *l_initialization* end  ----------------------------------------*/

/*----------------------------------------function *l_insert_head*    begin----------------------------------------*/
static inline l_Node * singly_insert_head     (l_Node *head, l_Node *node);
static inline l_Node * polynomial_insert_head (l_Node *head, l_Node *node);
static inline l_Node * doubly_insert_head     (l_Node *head, l_Node *node);
static inline l_Node * circular_insert_head   (l_Node *head, l_Node *node);

l_Node * l_insert_head(l_Node *node)
{
    static l_Node *head = NULL;
    head = (l_Node *)malloc(sizeof(l_Node));
    
    if(head == NULL)
    {
        fprintf(stderr, "\n> insert_head: %s", MALLOC_ERROR);
        return NULL;
    }

    switch(node->type)
    {
    case 0:
        return singly_insert_head(head, node);

    case 1:
        return polynomial_insert_head(head, node);

    case 2:
        return doubly_insert_head(head, node);

    case 3:
        return circular_insert_head(head, node);
    }
}

static inline l_Node * singly_insert_head(l_Node *head, l_Node *node)
{
    head->type = singly;
    input_data(head);

    head->singly.next = node;

    return head;
}

static inline l_Node * polynomial_insert_head(l_Node *head, l_Node *node)
{
    head->type = polynomial;
    input_data(head);

    head->polynomial.next = node;

    return head;
}

static inline l_Node * doubly_insert_head(l_Node *head, l_Node *node)
{
    head->type = doubly;
    input_data(head);

    head->doubly.next = node;
    head->doubly.prev = NULL;
    
    node->doubly.prev = head;

    return head;
}

static inline l_Node * circular_insert_head(l_Node *head, l_Node *node)
{
    head->type = circular;
    input_data(head);

    head->doubly.next = node;
    head->doubly.prev = node->doubly.prev;
    
    node->doubly.prev = head;

    return head;
}
/*----------------------------------------function *l_insert_head*    end  ----------------------------------------*/

/*----------------------------------------function *l_delete_head*    begin----------------------------------------*/
static inline l_Node * doubly_delete_head     (l_Node *node);
static inline l_Node * circular_delete_head   (l_Node *node);

l_Node * l_delete_head(l_Node *node)
{
    switch(node->type)
    {
    case 0:
        return doubly_delete_head(node);

    case 1:
        return doubly_delete_head(node);

    case 2:
        return doubly_delete_head(node);

    case 3:
        return circular_delete_head(node);
    }
}

static inline l_Node * doubly_delete_head(l_Node *node)
{
    sentinel_node = NULL;

    //Probing if the head node is the only one node.
    if(node->doubly.next == sentinel_node)
    {
        free(node);
        printf("\n%s", "> delete_head: The linked list is empty now.");
        return NULL;
    }

    static l_Node * next;
    node->doubly.next->doubly.prev = NULL;
    next = node->doubly.next;
    free(node);

    return next;
}

static inline l_Node * circular_delete_head(l_Node *node)
{
    sentinel_node = node;

    //Probing if the head node is the only one node.
    if(node->doubly.next == sentinel_node)
    {
        free(node);
        printf("\n%s", "> delete_head: The linked list is empty now.");
        return NULL;
    }

    static l_Node * next;
    node->circular.next->circular.prev = node->circular.prev;
    node->circular.prev->circular.next = node->circular.next;
    next = node->circular.next;
    free(node);

    return next;
}

/*----------------------------------------function *l_delete_head*    end  ----------------------------------------*/

/*----------------------------------------function *l_display*        begin----------------------------------------*/
static inline void singly_display     (l_Node *node);
static inline void polynomial_display (l_Node *node);
static inline void circular_display   (l_Node *node);

void l_display(l_Node *node)
{
    printf("\n%s", "> display: The data is as following:");

    switch(node->type)
    {
    case 0:
        singly_display(node);
        break;

    case 1:
        polynomial_display(node);
        break;

    case 2:
        /*There is no difference between singly and doubly linked list
         *when navigating through both the linked list type,
         *so you can use the same function on it.
         */
        singly_display(node);
        break;

    case 3:
        circular_display(node);
        break;
    }
}

static inline void singly_display(l_Node *node)
/*Both singly linked list and doubly linked list could be displayed step by step,
 *not having to care the minute difference between them in most of the time.
 */
{
    sentinel_node = NULL;

    while(1)
    {
        if(node == sentinel_node)
        {
            printf("%s", "NULL");
            break;
        }

        printf("%lld%s", node->singly.data, " -> ");
        node = node->singly.next;
    }
}

static inline void polynomial_display(l_Node *node)
/*All the type of linked list except circular linked list could be displayed step by step,
 *not having to care the minute difference between them in most of the time.
 */
{
    sentinel_node = NULL;

    while(1)
    {
        if(node->polynomial.power == 0)
        {
            printf("%lf", node->polynomial.coefficient);
            break;
        }

        printf("%lfx^%llu%s", node->polynomial.coefficient, node->polynomial.power, " -> ");
        node = node->polynomial.next;
    }
}

static inline void circular_display(l_Node *node)
{
    sentinel_node = node;
    /*The node means some node you want to begin with,
     *and the function could traverse all the node until
     *meeting with the beginning node again.
     *(Don't forget that it is a *circular* linked list.)
     */

    while(1)
    {
        if(node == sentinel_node)
        {
            printf("%s", "head");
            break;
        }

        printf("%lld%s", node->circular.data, " -> ");
        node = node->circular.next;
    }
}
/*----------------------------------------function *l_display*      end  ----------------------------------------*/

/*----------------------------------------function *input_data*     begin----------------------------------------*/
static inline void singly_input_data     (l_Node *node);
static inline void polynomial_input_data (l_Node *node);

static void input_data(l_Node *node)
{
    switch(node->type)
    {
    case 0:
        singly_input_data(node);
        break;

    case 1:
        polynomial_input_data(node);
        break;

    case 2:
        singly_input_data(node);
        break;

    case 3:
        singly_input_data(node);
        break;
    }
}

/*Even though you can do the identical task 
 *with singly, doubly and circular linked list
 *by function *singly_input_data*
 *you still have to set the *type* mode (like 0, 2, 3) of the node.
 */
static inline void singly_input_data(l_Node *node)
{
    printf("\n%s", "> input_data: Please set the data for the head node:");
    scanf("%lld", &node->singly.data);
    getchar();
}

static inline void polynomial_input_data(l_Node *node)
{
    printf("\n%s", "> input_data: Please set the coefficient for the head node (polynomial):");
    scanf("%lf", &node->polynomial.coefficient);
    getchar();

    printf("\n%s", "> input_data: warning: you have to only take positive integer, or the result may get wrong...");
    printf("\n%s", "> input_data: Please set the power for the head node (polynomial):");
    scanf("%llu", &node->polynomial.power);
    getchar();
}
/*----------------------------------------function *input_data*     end  ----------------------------------------*/
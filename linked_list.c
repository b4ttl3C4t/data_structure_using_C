#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "linked_list.h"

int main(void)
{
    Node *head;
    uint64_t opcode;

    while(1)
    { 
        printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",
                            "> control_table: ",
                            "  |code|    function    |",
                            "  |  0 | initialization |",
                            "  |  1 | termination    |",
                            "  |  2 | construction   |",
                            "  |  3 | insertion      |",
                            "  |  4 | insert_head    |",
                            "  |  5 | insert_tail    |",
                            "  |  6 | destruction    |",
                            "  |  7 | deletion       |",
                            "  |  8 | delete_head    |",
                            "  |  9 | delete_tail    |",
                            "  | 10 | search         |",
                            "  | 11 | display        |",
                            "  | 12 | sort           |",
                            "  | 13 | reverse        |",
                            "  | 14 | is_list_empty  |",
                            "  | 15 |      EXIT      |",
                            "> control_table: What do you want to do now? Please enter the opcode:");
        scanf("%llu", &opcode);
        getchar();

        if(opcode == 15)
        {
            printf("\n%s", "> control_table: Quitting the process of the linked list types");
            return 0;
        }

        if(opcode > 15)
        {
            fprintf(stderr, "\n> control_table: %s", OPCODE_ERROR);
        }
        
        l_control_table(&head, opcode);
    }
}

void l_control_table(Node **node, uint64_t opcode)
{
    uint64_t index;

    switch(opcode)
    {
    case 0:
        *node = l_initialization();

    case 1:
        l_termination(*node);
        break;

    case 11:
        l_display(*node);
        break;
    }

    return;
}

static void input_data(Node *node);

Node * l_initialization(void)
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

void l_termination(Node *head)
{

}

/*----------------------------------------function *insert_head*    begin----------------------------------------*/
static inline Node * singly_insert_head     (Node *node);
static inline Node * polynomial_insert_head (Node *node);
static inline Node * doubly_insert_head     (Node *node);
static inline Node * circular_insert_head   (Node *node);

Node * l_insert_head(Node *node)
{
    switch(node->type)
    {
    case 0:
        return singly_insert_head(node);

    case 1:
        return polynomial_insert_head(node);

    case 2:
        return doubly_insert_head(node);

    case 3:
        return circular_insert_head(node);
    }
}

static inline Node * singly_insert_head(Node *node)
{
    static Node *head = NULL;
    head = (Node *)malloc(sizeof(Node));
    
    if(head == NULL)
    {
        fprintf(stderr, "%s\n", MALLOC_ERROR);
        return NULL;
    }

    //Setting the type and input data.
    head->type = singly;
    input_data(head);
    head->singly.next = node;

    return head;
}

static inline Node * polynomial_insert_head(Node *node)
{
    ;
}

static inline Node * doubly_insert_head(Node *node)
{
    ;
}

static inline Node * circular_insert_head(Node *node)
{
    ;
}
/*----------------------------------------function *insert_head*    end  ----------------------------------------*/

/*----------------------------------------function *display*        begin----------------------------------------*/
static inline void singly_display     (Node *node);
static inline void polynomial_display (Node *node);
static inline void circular_display   (Node *node);

void l_display(Node *node)
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

    //Resetting the sentinel node by NULL (or nil).
    sentinel_node = NULL;
}

static inline void singly_display(Node *node)
/*Both singly linked list and doubly linked list could be displayed step by step,
 *not having to care the minute difference between them in most of the time.
 */
{
    sentinel_node = NULL;

    while(1)
    {
        printf("%lld ", node->singly.data);
        node = node->singly.next;

        if(node == NULL)
        {
            printf("%s", " -> NULL");
            break;
        }
        
        printf("%s", " -> ");
    }
}

static inline void polynomial_display(Node *node)
/*All the type of linked list except circular linked list could be displayed step by step,
 *not having to care the minute difference between them in most of the time.
 */
{
    sentinel_node = NULL;

    while(1)
    {
        printf("%lfx^%llu", node->polynomial.coefficient, node->polynomial.power);
        node = node->polynomial.next;

        if(node == NULL)
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

    while(1)
    {
        printf("%lld ", node->circular.data);
        node = node->circular.next;

        if(node == sentinel_node)
        {
            printf("%s", " -> head");
            break;
        }
        
        printf("%s", " -> ");
    }
}
/*----------------------------------------function *display*        end  ----------------------------------------*/

/*----------------------------------------function *input_data*     begin----------------------------------------*/
static inline void singly_input_data     (Node *node);
static inline void polynomial_input_data (Node *node);

static void input_data(Node *node)
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
static inline void singly_input_data(Node *node)
{
    printf("\n%s", "> input_data: Please set the data for the head node:");
    scanf("%lld", &node->singly.data);
    getchar();
}

static inline void polynomial_input_data(Node *node)
{
    printf("\n%s", "> input_data: Please set the coefficient for the head node (polynomial):");
    scanf("%lf", &node->polynomial.coefficient);
    getchar();

    printf("\n%s", "> input_data: Please set the power for the head node (polynomial):");
    scanf("%llu", &node->polynomial.power);
    getchar();
}
/*----------------------------------------function *input_data*     end  ----------------------------------------*/
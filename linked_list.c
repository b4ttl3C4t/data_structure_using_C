#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

int main(void)
{
    Node *head;

    unsigned int opcode;

    while(1)
    { 
        pritnf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",  
                            "> control_table: What do you want to do now?",
                            "  | 0 | initialization |",
                            "  | 1 | termination    |",
                            "  | 2 | insertion      |",
                            "  | 3 | insert_head    |",
                            "  | 4 | insert_tail    |",
                            "  | 5 | deletion       |",
                            "  | 6 | delete_head    |",
                            "  | 7 | delete_tail    |",
                            "  | 8 | search         |",
                            "  | 9 | display        |",
                            "  |  other  |   EXIT   |");
        scanf("%u", &opcode);
        getchar();

        if(opcode > 9)
        {
            fprintf(stderr, "\n> control_table: %s", OPCODE_ERROR);
            return 1;
        }
        
        control_table(&head, opcode);
    }
    
    return 0;
}





void l_control_table(Node **node, unsigned int opcode)
{
    unsigned int index;

    switch(opcode)
    {
    case 0:
        return l_initialization();

    case 1:
        l_termination(node);
        break;
   
    case 2:
        printf("\n%s", "> control_table: The function needs a index to insert the node to designed location.");
        scanf("%u", &index);
        getchar();
        l_insertion(node, index);
        break;

    case 3:
        l_insert_head(node);
        break;
    
    case 4:
        l_insert_tail(node);
        break;

    case 5:
        printf("\n%s", "> control_table: The function needs a index to delete the node of designed location.");
        scanf("%u", &index);
        getchar();
        l_deletion(node, index);
        break;
    
    case 6:
        l_delete_head(node);
        break;
    
    case 7:
        l_delete_tail(node);
        break;
    
    case 8:
        printf("\n%s", "> control_table: The function needs a index to search the designed node.");
        scanf("%u", &index);
        getchar();
        return l_search(node, index);
    
    case 9:
        l_display(node);
        break;
    }

    return;
}

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

void l_termination(Node *head)
{

}





/*----------------------------------------function *insertion*      begin----------------------------------------*/
static inline void singly_insert     (Node *node, unsigned int index);
static inline void polynomial_insert (Node *node, unsigned int index);
static inline void doubly_insert     (Node *node, unsigned int index);
static inline void circular_insert   (Node *node, unsigned int index);

Node * l_insertion(Node *node, unsigned int index)
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
/*----------------------------------------function *insertion*      end  ----------------------------------------*/

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
        singly_insert_head(node);
        break;

    case 1:
        polynomial_insert_head(node);
        break;

    case 2:
        doubly_insert_head(node);
        break;

    case 3:
        circular_insert_head(node);
        break;
    }
}

static inline Node * singly_insert_head(Node *node)
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

/*----------------------------------------function *insert_tail*    begin----------------------------------------*/
static inline void singly_insert_tail     (Node *node);
static inline void polynomial_insert_tail (Node *node);
static inline void doubly_insert_tail     (Node *node);
static inline void circular_insert_tail   (Node *node);

void l_insert_tail(Node *node)
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
/*----------------------------------------function *insert_tail*    end  ----------------------------------------*/





/*----------------------------------------function *deletion*       begin----------------------------------------*/
static inline void singly_delete     (Node *node, unsigned int index);
static inline void polynomial_delete (Node *node, unsigned int index);
static inline void doubly_delete     (Node *node, unsigned int index);
static inline void circular_delete   (Node *node, unsigned int index);

Node * l_deletion(Node *node, unsigned int index)
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
/*----------------------------------------function *deletion*       end  ----------------------------------------*/

/*----------------------------------------function *delete_head*    begin----------------------------------------*/
static inline void singly_delete_head     (Node *node);
static inline void polynomial_delete_head (Node *node);
static inline void doubly_delete_head     (Node *node);
static inline void circular_delete_head   (Node *node);

Node * l_delete_head(Node *node)
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
/*----------------------------------------function *delete_head*    end  ----------------------------------------*/

/*----------------------------------------function *delete_tail*    begin----------------------------------------*/
static inline void singly_delete_tail     (Node *node);
static inline void polynomial_delete_tail (Node *node);
static inline void doubly_delete_tail     (Node *node);
static inline void circular_delete_tail   (Node *node);

void l_delete_tail(Node *node)
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
/*----------------------------------------function *delete_tail*    end  ----------------------------------------*/





/*----------------------------------------function *search*         begin----------------------------------------*/
static inline int singly_search     (Node *node, unsigned int index);
static inline int polynomial_search (Node *node, unsigned int index);
static inline int doubly_search     (Node *node, unsigned int index);
static inline int circular_search   (Node *node, unsigned int index);

Node * l_search(Node *node, unsigned int index)
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
/*----------------------------------------function *search*         end  ----------------------------------------*/

/*----------------------------------------function *display*        begin----------------------------------------*/
static inline void singly_display     (Node *node);
static inline void polynomial_display (Node *node);
static inline void circular_display   (Node *node);

void l_display(Node *node)
{
    if(node->type >= LIST_TYPE_SIZE)
    {
        printf("%s", "It's not a booked type.");
        return ;
    }
    
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
    scanf("%d", &node->singly.data);
    getchar();
}

static inline void polynomial_input_data(Node *node)
{
    printf("\n%s", "> input_data: Please set the data for the head node (polynomial):");
    scanf("%lf%u", &node->polynomial.coefficient, &node->polynomial.power);
    getchar();
}
/*----------------------------------------function *input_data*     end  ----------------------------------------*/
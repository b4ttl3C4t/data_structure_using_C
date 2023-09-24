#include <stdio.h>
#include "linked_list.h"

//The *sentinel node* means the end of a linked list.
node *sentinel_node = NULL;

//function prototype for operation of linked list:
void    display(int, node *);
void    insertion(int, node *, int, int);
void    deletion(int, node *, int);
int     search(int, node *, int);
void    update(int, node *, int, int);

int main(void)
{
    return 0;
}

/*All the linked list type could be displayed step by step,
 *not having to care the minute difference between them.
 */
void display(int length, node *node)
{
    switch (node->type)
    {
    case 0:
        sentinel_node = NULL;
        do
        {
            printf("%d ", node->singly->data);
            node->singly = node->singly->next;
        } while (node->singly != NULL);
        break;

    case 1:
        sentinel_node = NULL;
        do
        {
            printf("%d ", node->doubly->data);
        } while (node->doubly != NULL);
        break;

    case 2:
        /*The node means some node you want to begin with,
         *and the function could traverse all the node until
         *meeting with the beginning node again.
         *(Don't forget that it is a *circular* linked list.)
         */
        sentinel_node = node;
        do
        {
            printf("%d ", node->circular->data);
        } while (node->circular != node->circular);
        break;
    
    default:
        printf("%s", "It's not a booked type.");
        break;
    }

    //Resetting the sentinel node by NULL (or nil).
    sentinel_node = NULL;
    puts("");
}
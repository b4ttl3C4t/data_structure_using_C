#include "doubly_linked_list.h"

int main(void)
{
    node_ptr_t head = NULL;

    insertion(&head, 'B'); print_list(head);
    insertion(&head, 'A'); print_list(head);
    insertion(&head, 'D'); print_list(head);
    deletion(&head, 'D'); print_list(head);
    deletion(&head, 'C'); print_list(head);
    deletion(&head, 'B'); print_list(head);
    deletion(&head, 'A'); print_list(head);
}

void insertion(node_ptr_t *head, char input)
{
    node_ptr_t new_node = (node_ptr_t)malloc(sizeof(node_t));
    if(new_node == NULL)
    {
        return;
    }

    new_node->data = input;
    node_ptr_t curr_node = *head;

    while(curr_node != NULL && curr_node->next != NULL && input > curr_node->data)
    {
        curr_node = curr_node->next;
    }

    if(curr_node == NULL && curr_node->next == NULL)
    {printf("1");
        new_node->prev = NULL;
        new_node->next = *head;
        *head = new_node;
    }
    else if(curr_node != NULL && curr_node->next == NULL)
    {printf("2");
        new_node->prev = curr_node;
        new_node->next = NULL;
        curr_node->next = new_node;
    }
    else
    {printf("3");
        new_node->prev = curr_node->prev;
        new_node->next = curr_node;
        curr_node->prev->next = new_node;
        curr_node->prev = new_node;
    }
}

void deletion(node_ptr_t *head, char value)
{
    if(is_empty(*head))
    {
        return;
    }

    node_ptr_t curr_node = *head;
    while(curr_node != NULL && value != curr_node->data)
    {
        curr_node = curr_node->next;
    }
    
    if(curr_node != NULL)
    {
        curr_node->prev->next = curr_node->next;
        curr_node->next->prev = curr_node->prev;
        free(curr_node);
    }
}

bool is_empty(node_ptr_t head)
{
    return head == NULL;
}

void print_list(node_ptr_t head)
{
    if(is_empty(head))
    {
        printf("NULL");
        return;
    }

    node_ptr_t curr_node = head;

    printf("NULL <-> ");
    while(curr_node != NULL)
    {
        printf("%c <-> ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("NULL\n");
}
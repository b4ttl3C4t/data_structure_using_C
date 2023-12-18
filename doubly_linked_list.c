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
    
    // Insert the head node when there is no node in the list.
    if(is_empty(*head))
    {
    	*head = new_node;
    	(*head)->prev = NULL;
    	(*head)->next = NULL;
    	return;
	}
    
    node_ptr_t curr_node = *head;

    while(curr_node->next != NULL && input > curr_node->data)
    {
        curr_node = curr_node->next;
    }
	
	// Insert from the head of the list, exclude the special case.
    if(curr_node == *head)
    {
        new_node->prev = NULL;
        new_node->next = *head;
        curr_node->prev = new_node;
        *head = new_node;
    }
	// Insert from the tail of the list, exclude the special case.
    else if(curr_node->next == NULL)
    {
        new_node->prev = curr_node;
        new_node->next = NULL;
        curr_node->next = new_node;
    }
	// Insert from the node within the list.
    else
    {
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
	
	// Delete the head node when it's the only-one node in the list.
	if((*head)->data == value && (*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		return;
	}
	// Delete the head of the list, and exclude the special case.
	else if((*head)->data == value)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free((*head)->prev);
		return;
	}

    node_ptr_t curr_node = *head;
    while(curr_node->next != NULL && value != curr_node->data)
    {
        curr_node = curr_node->next;
    }
    
    // Delete the tail of the list, and exclude the special case.
    if(curr_node->next == NULL && value == curr_node->data)
    {
        curr_node->prev->next = NULL;
        free(curr_node);
        return;
    }
	// Delete the node within the list.
    else if(curr_node->next != NULL)
    {
    	curr_node->prev->next = curr_node->next;
        curr_node->next->prev = curr_node->prev;
        free(curr_node);
        return;
	}
}

void reverse(node_ptr_t *head)
{
	if(is_empty(*head))
    {
        return;
    }
    
    node_ptr_t curr_node = *head;
    while(curr_node != NULL)
    {
    	
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
        printf("NULL\n");
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

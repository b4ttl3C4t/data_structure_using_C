#include "doubly_linked_list.h"

int main(void)
{
    node_ptr_t head = NULL;

    insertion(&head, __data__('B', 'B', 'B'));    print_list(head);
    insertion(&head, __data__('A', 'A', 'A'));    print_list(head);
    insertion(&head, __data__('D', 'D', 'D'));    print_list(head);
	reverse(&head); print_list(head);
    deletion(&head, __data__('D', 'D', 'D'));    print_list(head);
    deletion(&head, __data__('C', 'C', 'C'));    print_list(head);
    deletion(&head, __data__('B', 'B', 'B'));    print_list(head);
    deletion(&head, __data__('A', 'A', 'A'));    print_list(head);
}

void insertion(node_ptr_t *head, data_t input)
{
    node_ptr_t new_node = (node_ptr_t)malloc(sizeof(node_t));
    if (new_node == NULL)
    {
        return;
    }

    new_node->data = (data_ptr_t)malloc(sizeof(data_t));
    if (new_node->data == NULL)
    {
        free(new_node);
        return;
    }

    __data_copy__(new_node->data, &input);

    // Insert the head node when there is no node in the list.
    if (is_empty(*head))
    {
        *head = new_node;
        (*head)->prev = NULL;
        (*head)->next = NULL;
        return;
    }

    node_ptr_t curr_node = *head;
    
    while (curr_node->next != NULL)
    {
        curr_node = curr_node->next;
    }
	
	// Insert the node in the tail directly.
	new_node->prev = curr_node;
    new_node->next = NULL;
    curr_node->next = new_node;
}

void deletion(node_ptr_t *head, data_t value)
{
    if (is_empty(*head))
    {
        return;
    }

    if (__data_compare__((*head)->data, &value) == 0)
    {
		if((*head)->next == NULL)
		{// If the value is identical to data in head node.
			free(*head);
	        *head = NULL;
	        return;
		}
		else
		{// Delete the head of the list, and exclude the special case.
			*head = (*head)->next;
			free((*head)->prev);
			(*head)->prev = NULL;
	        return;
		}
    }

    node_ptr_t curr_node = *head;
    
    while (curr_node->next != NULL && 
           __data_compare__(curr_node->data, &value) != 0)
    {
        curr_node = curr_node->next;
    }

    // Delete the tail of the list, and exclude the special case.
    if (curr_node->next == NULL && 
        __data_compare__(curr_node->data, &value) == 0)
    {
        curr_node->prev->next = NULL;
        free(curr_node);
        return;
    }
    // Delete the node within the list.
    else if (curr_node->next != NULL)
    {
        curr_node->prev->next = curr_node->next;
        curr_node->next->prev = curr_node->prev;
        free(curr_node);
        return;
    }
}

void reverse(node_ptr_t *head)
{
    if (is_empty(*head))
    {
        return;
    }
    
    /* Don't have to reverse the list
	 * when there is one only node in the list. */
    if(is_empty((*head)->next))
    {
    	return;
	}
    
	node_ptr_t curr_node = (*head)->next;
    node_ptr_t temp_node;
    
	// Handle the head of the list.
    (*head)->prev = (*head)->next;
	(*head)->next = NULL;
    
    // Handle the node within the list.
    while (curr_node->next != NULL)
    {
        temp_node = curr_node->next;
        curr_node->next = curr_node->prev;
        curr_node->prev = temp_node;
        curr_node = temp_node;
    }
	*head = curr_node;
	
	// Handle the tail of the list.
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

bool is_empty(node_ptr_t head)
{
    return head == NULL;
}

void print_list(node_ptr_t head)
{
    if (is_empty(head))
    {
        printf("NULL\n");
        return;
    }

    node_ptr_t curr_node = head;

    printf("NULL <-> ");
    while (curr_node != NULL)
    {
        __data_display__(curr_node->data);
        printf(" <-> ");
        curr_node = curr_node->next;
    }
    printf("NULL\n");
}

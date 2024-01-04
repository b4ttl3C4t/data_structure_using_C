#include "circular_doubly_linked_list.h"

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
        (*head)->prev = *head;
        (*head)->next = *head;
        return;
    }

    node_ptr_t curr_node = *head;
    
    while (curr_node->next != *head)
    {
        curr_node = curr_node->next;
    }
	
	// Insert the node in the tail directly.
	new_node->prev = curr_node;
    new_node->next = *head;
    curr_node->next = new_node;
    (*head)->prev = new_node;
}

void deletion(node_ptr_t *head, data_t value)
{
    if (is_empty(*head))
    {
        return;
    }

    if (__data_compare__((*head)->data, &value) == 0)
    {
    	// if the head is the only element in list.
		if((*head)->next == *head)
		{
			free(*head);
	        *head = NULL;
	        return;
		}
		else
		{
		    node_ptr_t curr_node = (*head)->next;
			
		    // Find the location of the end.
		    while (curr_node->next != *head)
		    {
		        curr_node = curr_node->next;
		    }
		    
		    // Replace the head node and redirect the tail's next pointer to newer head.
			curr_node->next = (*head)->next;
			(*head)->next->prev = curr_node;
			free(*head);
			
			// Replace head node with newer head.
			*head = curr_node->next;
	        return;
		}
    }

    node_ptr_t curr_node = (*head)->next;	// The head node has already checked.
    
    while (curr_node->next != *head && 
           __data_compare__(curr_node->data, &value) != 0)
    {
        curr_node = curr_node->next;
    }

    // Delete the node within the list only if its value is found.
    if (__data_compare__(curr_node->data, &value) == 0)
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
    if((*head)->next == *head)
    {
    	return;
	}
    
	node_ptr_t curr_node = *head;
    node_ptr_t temp_node;
	
	// Handle the node within the list.
	// In this case, you could only suppose curr_node is not HEAD.
    do
    {
        temp_node = curr_node->next;
        curr_node->next = curr_node->prev;
        curr_node->prev = temp_node;
        
        curr_node = temp_node;
    } while (curr_node->next != *head);
	
	// Handle the tail of the list.
	curr_node->next = curr_node->prev;
	curr_node->prev = *head;
    *head = curr_node;
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

    printf("(HEAD)");
    do
    {
        __data_display__(curr_node->data);
        printf(" <-> ");
        curr_node = curr_node->next;
    } while (curr_node != head);
    printf("(HEAD)\n");
}

#include "singly_linked_list.h"

int main(void)
{
    node_ptr_t head = NULL;

    insertion(&head, __data__('B', 'B', 'B'));    print_list(head);
    insertion(&head, __data__('A', 'A', 'A'));    print_list(head);
    insertion(&head, __data__('D', 'D', 'D'));    print_list(head);
    reverse(&head);    print_list(head);
    deletion(&head, __data__('D', 'D', 'D'));    print_list(head);
    deletion(&head, __data__('C', 'C', 'C'));    print_list(head);
    deletion(&head, __data__('B', 'B', 'B'));    print_list(head);
    deletion(&head, __data__('A', 'A', 'A'));    print_list(head);
}

// According to input data, insert it alphabetically.
void insertion(node_ptr_t *head, data_t input)
{
    /* Allocate memory for the new node,
     * and probe whether it's successful. */
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
        (*head)->next = NULL;
        return;
    }
    
    node_ptr_t prev_node = NULL;
    node_ptr_t curr_node = *head;

    // Find the location of the end.
    while (curr_node != NULL)
    {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    new_node->next = curr_node;
    prev_node->next = new_node;
}

// According to value, remove the corresponding node.
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
			node_ptr_t temp_node = *head;
			*head = (*head)->next;
			free(temp_node);
	        return;
		}
    }

    node_ptr_t temp_node;
    node_ptr_t prev_node = *head;
    node_ptr_t curr_node = (*head)->next;	// The head node has already checked.

    // Find the location of the node which data is the value.
    while (curr_node->next != NULL && 
	       __data_compare__(curr_node->data, &value) != 0)
    {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    // Delete the node within the list only if its value is found.
    if (__data_compare__(curr_node->data, &value) == 0)
    {
        prev_node->next = curr_node->next;
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

    node_ptr_t prev_node = NULL;
    node_ptr_t next_node = NULL;
    node_ptr_t curr_node = *head;// Although the head node has already checked, you still reverse it.
    
	// In this case, you could only suppose curr_node is not NULL.
    while (curr_node != NULL)
    {
        // Operate the current node only when it's not NULL.
        next_node = curr_node->next;
        curr_node->next = prev_node;

        prev_node = curr_node;
        curr_node = next_node;
    }

    *head = prev_node;
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

    while (head != NULL)
    {
        __data_display__(head->data);
        printf(" --> ");
        head = head->next;
    }
    printf("NULL\n");
}

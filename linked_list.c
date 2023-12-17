#include "linked_list.h"

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

// According to input data, insert it alphabetically.
void insertion(node_ptr_t *head, char input)
{
    /* Allocate memory for the new node,
     * and probe whether it's successful. */
    node_ptr_t new_node = (node_ptr_t)malloc(sizeof(node_t));
    if (new_node == NULL)
    {
        return;
    }

    new_node->data = input;
    node_ptr_t prev_node = NULL;
    node_ptr_t curr_node = *head;

    // Find the location of what the input data should be.
    while (curr_node != NULL && input > curr_node->data)
    {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    /* If the location is the head node, then prev_node will be NULL,
     * and replace head node by the new one. */
    if (prev_node == NULL)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        prev_node->next = new_node;
        new_node->next = curr_node;
    }
}

// According to value, remove the corresponding node
void deletion(node_ptr_t *head, char value)
{
    if (is_empty(*head))
    {
        return;
    }

    // If the value is identical to data in head node.
    if ((*head)->data == value)
    {
        node_ptr_t temp_node = *head;
        *head = (*head)->next;
        free(temp_node);
        return;
    }

    node_ptr_t temp_node;
    node_ptr_t prev_node = NULL;
    node_ptr_t curr_node = *head;

    // Find the location of the node which data is the value.
    while (curr_node != NULL && value != curr_node->data)
    {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    /* If there is the searched node, 
     * then set the next_ptr of the prevent node, 
     * and delete the current node. */
    if (curr_node != NULL)
    {
        temp_node = curr_node;
        prev_node->next = curr_node->next;
        free(temp_node);
        return;
    }
}

bool is_empty(node_ptr_t head)
{
    return head == NULL;
}

void print_list(node_ptr_t head)
{
    if (is_empty(head))
    {
        return;
    }

    while (head != NULL)
    {
        printf("%c --> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
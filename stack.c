#include "stack.h"

#define STACK_EMPTY -1
#define STACK_MAX_SIZE 100

#define ACCESS_ERROR "The element is not accessible."

//The interface of the internal function.
static inline bool is_empty(int8_t);
static inline bool is_full(int8_t);
static inline void input_data(a_Data *);
static inline void output_data(a_Data *);

void a_s_peek(a_Stack *stack)
{
    if(is_empty(stack->top))
    {
        fprintf(stderr, "\n%s%s", "> a_s_peek: ", ACCESS_ERROR);
        return;
    }

    output_data(&(stack->container.element[stack->top]));
}

void a_s_pop(a_Stack *stack)
{
    if(is_empty(stack->top))
    {
        fprintf(stderr, "\n%s%s", "> a_s_pop: ", ACCESS_ERROR);
        return;
    }

    --(stack->top);
    output_data(&(stack->container.element[stack->top]));
}

void a_s_push(a_Stack *stack)
{
    if(is_full(stack->top))
    {
        fprintf(stderr, "\n%s%s", "> a_s_push: ", ACCESS_ERROR);
        return;
    }

    ++(stack->top);
    input_data(&(stack->container.element[stack->top]));
}

void a_s_is_empty(a_Stack *stack)
{
    if(is_empty(stack->top))
    {
        printf("\n%s", "> a_s_is_empty: The stack is empty now.");
        return;
    }
    printf("\n%s", "> a_s_is_empty: The stack is not empty now.");
}

void a_s_is_full(a_Stack *stack)
{
    if(is_full(stack->top))
    {
        printf("\n%s", "> a_s_is_full: The stack is full now.");
        return;
    }
    printf("\n%s", "> a_s_is_full: The stack is not full now.");
}

void l_s_peek(l_Stack *stack);
void l_s_pop(l_Stack *stack);
void l_s_push(l_Stack *stack);
void l_s_is_empt(l_Stack *stack);
void l_s_is_full(l_Stack *stack);



//The implementation of the internal function.
static inline void input_data(a_Data *element)
{
    scanf("%lf", &element->data);
    getchar();
}

static inline void output_data(a_Data *element)
{
    printf(" %lf", element->data);
}

static inline bool is_empty(int8_t top)
{
    if(top == STACK_EMPTY)
    {
        return 1;
    }
    return 0;
}

static inline bool is_full(int8_t top)
{
    if(top == STACK_MAX_SIZE)
    {
        return 1;
    }
    return 0;
}
#include "stack.h"

#define STACK_EMPTY 0
#define STACK_MAX_SIZE 100

#define STR(x)  #x
#define XSTR(x) STR(x)

#define ACCESS_ERROR "The element is not accessible."

//The interface of the internal function.
static inline void    input_data(a_Data *);
static inline void    output_data(a_Data);
static inline bool    is_empty(int8_t);
static inline bool    is_full(int8_t);



void a_s_construction(a_Stack *stack)
{
    if(!is_empty(stack->top))
    {
        printf("\n%s", "> a_s_construction: The stack has already existed.");
        return;
    }

    stack = (a_Stack *) malloc(sizeof(a_Stack));

    printf("\n%s", "> a_s_construction: Please set the size what you want.");
    printf("\n%s", "> a_s_construction: The size cannot be greater than "XSTR(STACK_MAX_SIZE)" or less than 1:");
    scanf("%d", &(stack->top));
    getchar();

    if(stack->top > STACK_MAX_SIZE || stack->top <= STACK_EMPTY)
    {
        printf("\n%s", "> a_s_construction: The stack cannot be constructed.");
        return;
    }
    
    for(unsigned int i = 0; i < stack->top; ++i)
    {
        printf("\n%s", "> a_s_construction: Please set the data:");
        input_data(&(stack->container.element[i]));
    }
}

void a_s_destruction(a_Stack *stack)
{
    free(stack);
}

void a_s_peek(a_Stack *stack)
{
    if(is_empty(stack->top))
    {
        fprintf(stderr, "\n%s%s", "> a_s_peek: ", ACCESS_ERROR);
        return;
    }

    output_data(stack->container.element[stack->top]);
}

void a_s_pop(a_Stack *stack)
{
    if(is_empty(stack->top))
    {
        fprintf(stderr, "\n%s%s", "> a_s_pop: ", ACCESS_ERROR);
        return;
    }

    --(stack->top);
    output_data(stack->container.element[stack->top]);
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
    }
    else
    {
        printf("\n%s", "> a_s_is_empty: The stack is not empty now.");
    }
}

void a_s_is_full(a_Stack *stack)
{
    if(is_full(stack->top))
    {
        printf("\n%s", "> a_s_is_full: The stack is full now.");
    }
    else
    {
        printf("\n%s", "> a_s_is_full: The stack is not full now.");
    }
}

void a_s_print(a_Stack *stack)
{
    printf("\n%s", "> a_s_print: The data in the stack as following:");
    
    for(unsigned int i = stack->top - 1; i >= 0; --i)
    {
        output_data(stack->container.element[i]);
    }
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

static inline void output_data(a_Data element)
{
    printf(" %lf", element.data);
}

static inline bool is_empty(int8_t top)
{
    if(top == STACK_EMPTY)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static inline bool is_full(int8_t top)
{
    if(top == STACK_MAX_SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
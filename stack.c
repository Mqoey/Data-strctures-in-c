#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
    struct Stack
{
   int top;
   unsigned capacity;
   int *array;
};

//creating stacks
struct Stack *createStack(unsigned capacity)
{
   struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
   stack->capacity = capacity;
   stack->top = -1;
   stack->array = (int *)malloc(stack->capacity * sizeof(int));
   return stack;
}
//checking if stack is full
int isFull(struct Stack *stack)
{
   return stack->top == stack->capacity - 1;
}
int isEmpty(struct Stack *stack)
{
   return stack->top == -1;
}

//inserting to stack
void push(struct Stack *stack, int item)
{
   if (isFull(stack))
      return;
   stack->array[++stack->top] = item;
   printf("%d pushed to stack \n", item);
}
//delete from stack
int pop(struct Stack *stack)
{
   if (isEmpty(stack))
      return INT_MIN;
   return stack->array[stack->top--];
}
int peek(struct Stack *stack)
{
   if (isEmpty(stack))
      return INT_MIN;
   return stack->array[stack->top];
}
int main()
{
   struct Stack *stack = createStack(100);
   push(stack, 11);
   push(stack, 12);
   push(stack, 33);
   printf("%d popped from stack \n", pop(stack));
   return 0;
}

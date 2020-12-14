#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//structure to represent a stack
struct Stack
{
	int StackLimit;
	char* array;
    bool flag;
    int top;
};

// function to create a stack of given capacity. It initializes size of stack as 0
struct Stack* createStack(int StackLimit)
{

	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->StackLimit = StackLimit;
	stack->top = -1;
	stack->array = (int*)malloc(stack->StackLimit * sizeof(int));
	return stack;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

int isFull(struct Stack* stack)
{
	return stack->top == stack->StackLimit - 1;
}

void push(struct Stack* stack, int element)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = element;
	printf("%d Element Pushed into the stack.\n", element);
}

int pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

int peek(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top];
}

//Driver function
int main()
{
	struct Stack* stack = createStack(100);

	push(stack, 10);
	push(stack, 10);
	push(stack, 10);
	pop (stack);
	push(stack, 20);
	peek (stack);
	push(stack, 30);
	pop (stack);
	pop (stack);

	printf("%d Element Popped from the stack.\n", pop(stack));

	return 0;
}

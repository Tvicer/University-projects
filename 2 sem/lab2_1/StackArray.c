#include <stdio.h>
#include "StackArray.h"



int isFull(PStack stack)
{
	return (stack->topIndex + 1) == stack->stackSize;
}



init(PStack stack)
{
	stack->stackSize = 1;
	stack->data = (PData)malloc(stack->stackSize * (sizeof(union Data)));
	stack->topIndex = -1;
}



int push(PStack stack, union Data toPush)
{
	if (isFull(stack))
	{
		stack->stackSize += 10;
		stack->data = (PData)realloc(stack->data, sizeof(union Data) * stack->stackSize);
	}
	stack->topIndex += 1;
	stack->data[stack->topIndex] = toPush;
}



int pop(PStack stack, PData destination)
{
	*destination = stack->data[stack->topIndex];
	stack->topIndex--;
	stack->stackSize--;

}



int top(const PStack stack, PData destination)
{
	*destination = stack->data[stack->topIndex];
}



int isEmpty(const PStack stack)
{
	if (stack->topIndex == -1)
	{
		return 0;
	}
	else
		return 1;
	if (stack == NULL)
		return -1;

}



int clear(PStack stack)
{
	while (stack->stackSize != 0)
	{
		stack->topIndex--;
		stack->stackSize--;
	}
	return 0;
}

int clear_top(PStack stack)
{
	stack->topIndex--;
	stack->stackSize--;
}
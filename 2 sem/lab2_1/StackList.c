#include <stdio.h>
#include "StackList.h"



int init(PStack stack)
{
	if (stack == NULL)
		return -1;
	else
		stack->top = NULL;
}



int push(PStack stack, union Data toPush)
{
	if (newNode == NULL)
		return -1;
	else if (stack != NULL)
	{
		PNode newNode = (PNode)malloc(sizeof(Node));
		newNode->data = toPush;
		newNode->next = stack->top;
		stack->top = newNode;
		return 0;
	}
	else
		return -1;
}



int pop(const PStack stack, PData destination)
{
	*destination = stack->top->data;
	PStack tmp = stack->top;
	stack->top = stack->top->next;
	free(tmp);
	return 0;
}



int top(const PStack stack, PData destination)
{
	if (stack != NULL)
	{
		*destination = stack->top->data;
		return 0;
	}
	else 
		return -1;
}



int isEmpty(const PStack stack)
{
	if ((stack->top == NULL) && (stack == NULL))
		return 0;
	else
		return 1;
}



int clear(PStack stack)
{
	while (!isEmpty)
	{
		PStack tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	return 0;
}


int clear_top(PStack stack)
{
	PStack tmp = stack->top;
	stack->top = stack->top->next;
	free(tmp);
	return 0;
}
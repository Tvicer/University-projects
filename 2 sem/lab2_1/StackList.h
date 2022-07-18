#pragma once

#include "DataTypes.h"

struct StackNode
{
	union Data data;
	struct StackNode* next;
};

typedef struct StackNode Node, *PNode;

struct StackBasedOnList
{
	enum DataType dataType;
	PNode top;
};

typedef struct StackBasedOnList Stack, *PStack;
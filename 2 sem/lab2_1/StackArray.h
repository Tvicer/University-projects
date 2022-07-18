#pragma once

#include "DataTypes.h"

struct StackBasedOnArray
{
	enum DataType dataType;
	union Data* data;
	size_t topIndex; // or pointer to the top element/next to the top element
	size_t stackSize;
};

typedef struct StackBasedOnArray Stack, *PStack;
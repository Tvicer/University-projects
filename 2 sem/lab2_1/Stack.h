#pragma once

#include "DataTypes.h"
//#include "StackList.h"
#include "StackArray.h"



int init(PStack stack); // 0 - success; others - own errors
int push(PStack stack, union Data toPush); // 0 - success; others - own errors
int pop(const PStack stack, PData destination); // 0 - success; others - own errors
int top(const PStack stack, PData destination); // 0 - success; others - own errors
int isEmpty(const PStack stack); // 0 - empty; 1 - empty; others - own errors;
int clear(PStack stack); // 0 - success; others - own errors

int clear_top(PStack stack); // 0 - success; others - own errors
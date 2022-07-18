#pragma once

enum DataType { NOTHING, NUMBER, OPERATOR };

union Data
{
	int number;
	char operator;
};

typedef union Data* PData;
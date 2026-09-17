#include "lib.h"
#include <iostream>
#include <algorithm>

Task::Task()
{
	num_1 = rand() % 100 + 1;
	num_2 = rand() % 100 + 1;
	char ops[] = { '+', '-','*', '/' };
	operation = ops[rand() % 4];
	calculate_answer();
}
Task::Task(int min_val, int max_val, char op)
{
	if (min_val > max_val) std::swap(min_val, max_val);
	num_1 = min_val + rand() % (max_val - min_val + 1);
	num_2 = min_val + rand() % (max_val - min_val + 1);

	if (op == '+' || op == '-' || op == '*' || op == '/')
	{
		operation = op;
	}
	else
	{
		char ops[] = { '+', '-','*', '/' };
		operation = ops[rand() % 4];
	}if (operation == '/' && num_2 == 0)
	{
		num_2 = 1;
	}
	calculate_answer();
}
void Task::calculate_answer()
{
	switch (operation) {
		case '+': answer = num_1 + num_2; break;
		case '-': answer = num_1 - num_2; break;
		case '*': answer = num_1 * num_2; break;
		case '/': answer = num_1 / num_2; break;
		default:answer = 0; break;
	}
}
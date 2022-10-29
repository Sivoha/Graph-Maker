#ifndef SRC_REVERSE_POLISH_NOTATION_H_
#define SRC_REVERSE_POLISH_NOTATION_H_

#include "stack.h"

char* ExpressionToRPN(char* expression);
double RPNToValue(char* RPN, double x);
void CatToOutput(node** operations, char** output);

#endif  // SRC_REVERSE_POLISH_NOTATION_H_

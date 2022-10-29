#ifndef SRC_OPERATIONS_PROCESSING_H_
#define SRC_OPERATIONS_PROCESSING_H_

int IsBinary(char operation);
int IsPrefix(char operation);
int CmpPriority(char first, char second);

double binary_operation_result(char operation, double first_operand,
                               double second_operand);
double prefix_operation_result(char operation, double operand);

#endif  // SRC_OPERATIONS_PROCESSING_H_

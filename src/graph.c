#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function_plot.h"
#include "parse.h"
#include "reverse_polish_notation.h"

int main() {
  while (1) {
    char *expression = malloc(sizeof(char));
    int i = 0, error = 1, input_error = 0;
    while ((scanf("%c", &expression[i]) == 1) && (expression[i] != '\n') &&
          (input_error != 1)) {
      char *temp = realloc(expression, (i + 1) * sizeof(char));
      if (temp != NULL) {
        expression = temp;
      } else {
        free(expression);
        input_error = 1;
      }
      i++;
    }
    if (!input_error) {
      expression[i] = '\0';
      char *parsed_expression = ParseExpression(expression, &error);
      if (error) {
        char plot[SIZE_Y][SIZE_X];
        char *RPN = ExpressionToRPN(parsed_expression);

        MakePlot(RPN, plot);
        PrintPlot(plot);

        free(RPN);
      } else {
        printf("ERROR");
      }

      free(parsed_expression);
      free(expression);
    } else {
      printf("ERROR");
    }
  }
  return 0;
}

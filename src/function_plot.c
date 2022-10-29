#include "function_plot.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "reverse_polish_notation.h"

void MakePlot(char *RPN, char plot_matrix[][SIZE_X]) {
  ResetPlot(plot_matrix);
  int column = 0;
  const double DELTA_X = 4 * M_PI / 200.;
  const double DELTA_Y = 4. / 58.;

  char *RPN_copy = malloc(strlen(RPN) * sizeof(char));
  strcpy(RPN_copy, RPN);

  for (double x = -2 * M_PI; x <= 2 * M_PI + 1e-6; x += DELTA_X) {
    double value = RPNToValue(RPN_copy, x);
    if (fabs(value) <= 2) {
      value += 2;
      int row = 0, counter = 0;
      double min_difference = 100;
      for (double y = 4; y >= 0; y -= DELTA_Y) {
        double difference = fabs(value - y);
        if (difference < min_difference) {
          min_difference = difference;
          row = counter;
        }
        counter++;
      }
      plot_matrix[row][column] = '*';
    }
    column++;
    strcpy(RPN_copy, RPN);
  }
  free(RPN_copy);
}

void ResetPlot(char plot_matrix[][SIZE_X]) {
  for (int i = 0; i < SIZE_Y; ++i) {
    for (int j = 0; j < SIZE_X; ++j) {
      plot_matrix[i][j] = '.';
    }
  }
}

void PrintPlot(char plot_matrix[][SIZE_X]) {
  for (int i = 0; i < SIZE_Y; ++i) {
    for (int j = 0; j < SIZE_X; ++j) {
      printf("%c", plot_matrix[i][j]);
    }
    printf("\n");
  }
}

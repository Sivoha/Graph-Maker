#ifndef SRC_FUNCTION_PLOT_H_
#define SRC_FUNCTION_PLOT_H_

#define SIZE_X 201
#define SIZE_Y 59

void MakePlot(char* RPN, char plot_matrix[][SIZE_X]);
void ResetPlot(char plot_matrix[][SIZE_X]);
void PrintPlot(char plot_matrix[][SIZE_X]);

#endif  // SRC_FUNCTION_PLOT_H_

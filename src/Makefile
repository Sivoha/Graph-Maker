CFLAGS = -Wall -Werror -Wextra 

all: build

build: graph.o reverse_polish_notation.o stack.o double_stack.o operations_processing.o function_plot.o parse.o 
	gcc $(CFLAGS) graph.o reverse_polish_notation.o stack.o double_stack.o operations_processing.o function_plot.o parse.o -o ../build/graph -lm

graph.o:
	gcc -c $(CFLAGS) graph.c -o graph.o -lm

parse.o:
	gcc -c $(CFLAGS) parse.c -o parse.o -lm

reverse_polish_notation.o:
	gcc -c $(CFLAGS) reverse_polish_notation.c -o reverse_polish_notation.o -lm

stack.o:
	gcc -c $(CFLAGS) stack.c -o stack.o -lm

double_stack.o:
	gcc -c $(CFLAGS) double_stack.c -o double_stack.o -lm

operations_processing.o:
	gcc -c $(CFLAGS) operations_processing.c -o operations_processing.o -lm

function_plot.o:
	gcc -c $(CFLAGS) function_plot.c -o function_plot.o -lm

rebuild: clean build

clean:
	rm -rf *.o *.out ../build/graph
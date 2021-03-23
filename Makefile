main: main.o graph.o parser.o
	gcc -o main main.o graph.o parser.o

graph.o: graph/graph.c
	gcc -c graph/graph.c

parser.o: parser/parser.c
	gcc -c parser/parser.c

clean:
	rm main
	rm *.o
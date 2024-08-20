PARAMS = -g -W -pedantic

all: main.cpp shapes
	g++ main.cpp shapes.o -o calculadora $(PARAMS)

shapes: shapes.cpp
	g++ -c shapes.cpp -o shapes.o $(PARAMS)

clean: 
	rm -f *.o calculadora
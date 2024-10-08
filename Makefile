sources:= IntegerIA.cpp FloatIA.cpp main.cpp
objects:= $(sources:.cpp=.o)

all: my_inf_arith

libmy_inf_arith: $(objects)
	ar rcs libmy_inf_arith.a $^
	
my_inf_arith: $(objects)
	g++ -o my_inf_arith $^

%.o: %.cpp
	g++ -c -o $@ $<

clean:
	rm -f $(objects) libmy_inf_arith.a my_inf_arith
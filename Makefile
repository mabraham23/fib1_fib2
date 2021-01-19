CXXFLAGS := -std=c++11

all: fib

fib1-graph.csv: collect_data.bash fib
	./collect_data.bash > fib1-graph.csv

fib2-graph.csv: collect_data.bash fib
	./collect_data.bash > fib2-graph.csv

test-run: fib
	./fib 40

fib: fib.cpp
	g++ $(CXXFLAGS) -o $@ $^

clean:
	-rm -f fib

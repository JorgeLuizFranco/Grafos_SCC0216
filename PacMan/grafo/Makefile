CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++11
EXEC=programa
OBJS=grafo.o main.o

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

grafo.o: grafo.cpp grafo.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp grafo.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

run:
	./programa

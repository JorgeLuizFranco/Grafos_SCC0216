CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++17
EXEC=programa
OBJS=main.o

SRC_FOLDER=src
BUILD_FOLDER=build

SRC_FILES=$(wildcard $(SRC_FOLDER)/*.cpp) $(wildcard $(SRC_FOLDER)/**/*.cpp)

OBJ_FOLDER=$(BUILD_FOLDER)/obj
OBJ_FILES=$(patsubst $(SRC_FOLDER)/%.cpp, $(OBJ_FOLDER)/%.o, $(SRC_FILES))

CXXFLAGS+= -I$(SRC_FOLDER)

all : $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(EXEC)

$(OBJ_FOLDER)/%.o : $(SRC_FOLDER)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_FOLDER)
	clear

run:
	./programa

zip:
	zip -r ICMComputadores.zip src/ Makefile 
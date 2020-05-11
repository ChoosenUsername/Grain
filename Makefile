CXX := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN     := Bin
SRC     := Sources
INCLUDE := Headers
LIB     := lib
EXECUTABLE  := grain

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	@echo "Executing..."
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	@echo "Building..."
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	@echo "Clearing..."
	-rm $(BIN)/*

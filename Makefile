CXX = g++
CXXFLAGS = -Iinclude

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
EXECUTABLE = $(BIN_DIR)/Scheduler

all: directories $(EXECUTABLE)

directories:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CXX) -c $< $(CXXFLAGS) -o $@

$(EXECUTABLE): $(OBJECTS)
	@$(CXX) $^ $(CXXFLAGS) -o $@

run:
	@cd $(BIN_DIR) && ./$(notdir $(EXECUTABLE))

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BIN_DIR)

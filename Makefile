BUILD_DIR := build
SRC_DIR := src
BIN_DIR := bin
INC_DIR := inc

TARGET_EXEC := $(BIN_DIR)/mpu9250
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
HEAD := $(wildcard $(INC_DIR)/*.h)

CXX = g++
CXXFLAGS = -Wall -O2
LDLIBS = -lpigpio -lpthread -lrt


.PHONY: all clean

all: $(TARGET_EXEC)

#to link objs into executable
$(TARGET_EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET_EXEC) $(LDLIBS)

#to build binaries
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEAD)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	@$(RM) -rv $(BIN_DIR)/mpu9250 $(BUILD_DIR)/*.o
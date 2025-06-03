CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TEST_DIR = tests
BUILD_DIR = build

# Main target
all: run_tests

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile tests
$(BUILD_DIR)/test_list: $(TEST_DIR)/test_list.cpp list.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_DIR)/test_list.cpp -o $(BUILD_DIR)/test_list

# Run tests
run_tests: $(BUILD_DIR)/test_list
	./$(BUILD_DIR)/test_list

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run_tests clean 
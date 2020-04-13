# -----------------------------------------------------------------------------
# Files and directories
# -----------------------------------------------------------------------------

SRC_DIR       = src
INC_DIR       = inc
OBJ_DIR       = obj
TST_DIR       = tests

BIN_SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
BIN_INC_FILES = $(wildcard $(INC_DIR)/*.h)
BIN_OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(BIN_SRC_FILES))

TST_SRC_FILES = $(wildcard $(TST_DIR)/*.cpp)
TST_OBJ_FILES = $(patsubst $(TST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TST_SRC_FILES))

# -----------------------------------------------------------------------------
# Flags
# -----------------------------------------------------------------------------

EXTRAS        = -Wno-unused-parameter -Wno-unused-variable
CFLAGS        = -Wall -Wextra -Werror -pedantic -std=c++11 $(EXTRAS)
IFLAGS        = -I $(INC_DIR)
TFLAGS        = -lcriterion

TARGETS       = quaternity tester

# -----------------------------------------------------------------------------
# Build rules
# -----------------------------------------------------------------------------

all: $(TARGETS)

quaternity: % : $(BIN_OBJ_FILES)
	$(CXX) $(CFLAGS) $(IFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(BIN_INC_FILES)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CFLAGS) $(IFLAGS) -c -o $@ $<

tester: % : $(TST_OBJ_FILES)
	$(CXX) $(CFLAGS) $(IFLAGS) $(TFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(TST_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CFLAGS) $(IFLAGS) -c -o $@ $<

# -----------------------------------------------------------------------------
# Phonies
# -----------------------------------------------------------------------------

test:
	@./tester

docs:
	@doxygen &> /dev/null
	@echo "docs generated"

clean:
	rm -rf $(OBJ_DIR) $(TARGETS)

re:
	@$(MAKE) clean
	@$(MAKE)

.PHONY: all test docs clean re

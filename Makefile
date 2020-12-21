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

EXTRAS        = -g -Wno-unused-parameter -Wno-unused-variable
CFLAGS        = -Wall -Wextra -Werror -pedantic -std=c++11 $(EXTRAS)
IFLAGS        = -I $(INC_DIR)
TFLAGS        = -lcriterion

TARGETS       = quaternity test

# -----------------------------------------------------------------------------
# Build rules
# -----------------------------------------------------------------------------

all: $(TARGETS)

quaternity: % : $(BIN_OBJ_FILES)
	@echo -e "LINK\t$@"
	@$(CXX) $(CFLAGS) $(IFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(BIN_INC_FILES)
	@echo -e "CXX\t$@"
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CFLAGS) $(IFLAGS) -c -o $@ $<

test: % : $(TST_OBJ_FILES)
	@echo -e "LINK\t$@"
	@$(CXX) $(CFLAGS) $(IFLAGS) $(TFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(TST_DIR)/%.cpp
	@echo -e "CXX\t$@"
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CFLAGS) $(IFLAGS) -c -o $@ $<

# -----------------------------------------------------------------------------
# Phonies
# -----------------------------------------------------------------------------

docs:
	@doxygen &> /dev/null
	@echo "docs generated"

clean:
	rm -rf $(OBJ_DIR) $(TARGETS)

re:
	@$(MAKE) -s clean
	@$(MAKE) -s

.PHONY: all docs clean re

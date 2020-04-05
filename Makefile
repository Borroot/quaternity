SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

SRC_FILES =	$(wildcard $(SRC_DIR)/*.cpp)
INC_FILES =	$(wildcard $(INC_DIR)/*.h)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

EXTRAS = -Wno-unused-parameter
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++11 $(EXTRAS)
IFLAGS = -I $(INC_DIR)

TARGET = quaternity

all: $(TARGET)

$(TARGET): % : $(OBJ_FILES)
	$(CXX) $(CFLAGS) $(IFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_FILES)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CFLAGS) $(IFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

re:
	@$(MAKE) clean
	@$(MAKE)

.PHONY: all clean re

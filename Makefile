CC = g++
CPPVERSION = c++14
SOURCE_DIR = ./src
HEADERS_DIR = ./headers
OBJ_DIR = ./obj
BIN_DIR = ./bin
FLAGS = -std=$(CPPVERSION) -I$(HEADERS_DIR) -Wall
LIBRARIES = -lSDL2 -lSDL2_image -lSDL2_mixer

OBJS = $(OBJ_DIR)/Animation.o $(OBJ_DIR)/Animator.o $(OBJ_DIR)/Audio.o \
	$(OBJ_DIR)/Game.o $(OBJ_DIR)/GameState.o $(OBJ_DIR)/Graphics.o $(OBJ_DIR)/Image.o \
	$(OBJ_DIR)/Input.o $(OBJ_DIR)/Map.o $(OBJ_DIR)/MapNode.o $(OBJ_DIR)/Rectangle.o \
	$(OBJ_DIR)/Scene.o $(OBJ_DIR)/SceneNode.o $(OBJ_DIR)/StateManager.o $(OBJ_DIR)/main.o \
	$(OBJ_DIR)/AnimatedDemo.o 

TARGET = $(BIN_DIR)/$(OUT_NAME)
OUT_NAME = engine

$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $(FLAGS) $(OBJS) $(LIBRARIES) -o $(TARGET)

$(OBJ_DIR)/%.o : $(SOURCE_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) -c -MD $(FLAGS) $< -o $@

-include $(OBJ_DIR)/*.d

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

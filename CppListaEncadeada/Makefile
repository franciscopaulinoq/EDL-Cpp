CXX      := g++
CXXFLAGS := -g3 -pedantic-errors -Wall -Wextra -Werror
LDFLAGS  := -L/usr/lib -lstdc++ -lm
OBJ_DIR  := ./objects
TARGET   := CppListaEncadeada.exe
INCLUDE  := -Iinclude/
SRC      := $(wildcard source/*.cpp)
OBJECTS  := $(SRC:source/%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES := $(OBJECTS:.o=.d)

MKDIR = mkdir
RMDIR = rmdir /S /Q

all: build $(TARGET)

build:
	@if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"

$(OBJ_DIR)/%.o: source/%.cpp
	@if not exist "$(@D)" mkdir "$(@D)"
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	@if exist "$(OBJ_DIR)" $(RMDIR) "$(OBJ_DIR)"
	@if exist "$(TARGET)" del "$(TARGET)"

info:
	@echo "[*] Object dir:      $(OBJ_DIR)"
	@echo "[*] Sources:         $(SRC)"
	@echo "[*] Objects:         $(OBJECTS)"
	@echo "[*] Dependencies:    $(DEPENDENCIES)"

run: all
	@echo "Executando..."
	@echo.
	@$(TARGET) $(ARGS)

-include $(DEPENDENCIES)

.PHONY: all build clean info run
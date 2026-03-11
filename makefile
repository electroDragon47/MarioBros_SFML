# Compiler
CXX = g++

# SFML paths
SFML_INCLUDE = C:\dev\SFML\SFML-3.0.2\include
SFML_LIB = C:\dev\SFML\SFML-3.0.2\lib

# Flags
CXXFLAGS = -std=c++20 -I$(SFML_INCLUDE) -Iinclude
LDFLAGS = -L$(SFML_LIB) -lsfml-graphics-d -lsfml-window-d -lsfml-system-d 

# Target
TARGET = build\main.exe
SRC = src/*.cpp 
all:
	$(CXX) $(SRC) -o $(TARGET) $(CXXFLAGS) $(LDFLAGS)

clean:
	del $(TARGET)
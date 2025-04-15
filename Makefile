CXX = g++
CXXFLAGS = -Wall -std=c++23 -Iinclude

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = banking_app

all: $(TARGET)

$(TARGET) : $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^ 

clean:
	rm -f $(TARGET) $(OBJ)
CXX = g++
CXXFLAGS = -Wall -std=c++23 -Iinclude

SRC = $(wildcard src/*.cpp)

TARGET = banking_app

all: $(TARGET)

$(TARGET) : $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^ 

clean:
	rm -f $(TARGET) $(OBJ)
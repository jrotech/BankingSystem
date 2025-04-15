CXX = g++
CXXFLAGS = -Wall -std=c++21 -Iinclude

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = banking_app

all: $(TARGET)

$(TARGET) : $(SRC)
	$(CXX) $(CSSFLAGS) -o $@ $^ 

clean:
	rm -f $(TARGET) $(OBJ)
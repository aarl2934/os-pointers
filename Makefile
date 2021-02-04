CC = g++

CFLAGS = -std=c++11

TARGET = pointers

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	rm $(TARGET)
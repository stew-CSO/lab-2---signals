CC = gcc
CFLAGS = -Wall

TARGET = signal_program

all: $(TARGET)

$(TARGET): signal.c
	$(CC) $(CFLAGS) -o $(TARGET) signal.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

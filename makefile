CC = g++
CFLAGS = -std=c++11
PROGRAM_NAME = Shah_Harshil_quicksort

all: $(PROGRAM_NAME) InputFileGenerator

$(PROGRAM_NAME): $(PROGRAM_NAME).cpp
	$(CC) $(CFLAGS) -o $(PROGRAM_NAME) $(PROGRAM_NAME).cpp

clean:
	rm -f $(PROGRAM_NAME) InputFileGenerator *.txt *.jpg

.PHONY: all clean

InputFileGenerator: InputFileGenerator.cpp
	$(CC) $(CFLAGS) -o InputFileGenerator InputFileGenerator.cpp

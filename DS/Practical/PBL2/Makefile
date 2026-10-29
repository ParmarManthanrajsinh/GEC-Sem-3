CC      := gcc
CFLAGS  := -O2 -std=c11 -Wall -Wextra
TARGET  := sorting_benchmark
SOURCE  := sorting_benchmark.c

.PHONY: all run report clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

report: results.csv
	python3 generate_report.py

clean:
	rm -f $(TARGET) results.csv results.xlsx

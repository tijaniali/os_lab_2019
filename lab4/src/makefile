CC = gcc
LAB3_SRC = /Users/tijaniali/Desktop/miet/oc/os_lab_2019/lab3/src
CFLAGS = -I. -I$(LAB3_SRC)

all: zombie process_memory parallel_sum parallel_min_max

BUILD_DIR = build

parallel_sum: parallel_sum.c $(BUILD_DIR)/utils_lab3.o
	$(CC) -pthread -o $@ $^ $(CFLAGS)

process_memory: process_memory.c
	$(CC) -o $@ $^ $(CFLAGS)

zombie: zombie.c
	$(CC) -o $@ $^ $(CFLAGS)

parallel_min_max: $(LAB3_SRC)/utils.o $(LAB3_SRC)/find_min_max.o $(LAB3_SRC)/parallel_min_max.c
	$(CC) -o $@ $(LAB3_SRC)/utils.o $(LAB3_SRC)/find_min_max.o $(LAB3_SRC)/parallel_min_max.c $(CFLAGS)


$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/find_min_max.o: | $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/find_min_max.o -c $(LAB3_SRC)/find_min_max.c $(CFLAGS)

$(BUILD_DIR)/utils_lab3.o: | $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/utils_lab3.o -c $(LAB3_SRC)/utils.c $(CFLAGS)

clean:
	rm -f *.o *.a zombie process_memory parallel_sum parallel_min_max
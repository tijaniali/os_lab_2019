CC = gcc
SRCDIR = src/revert_string
TESTDIR = src/tests
INCDIR = $(SRCDIR)
BUILD = build

CFLAGS = -I$(INCDIR)
PIC = -fPIC

# Common Homebrew / local prefixes where CUnit headers/libs may be installed on macOS
CUNIT_INC ?= -I/opt/homebrew/include -I/usr/local/include
CUNIT_LIB ?= -L/opt/homebrew/lib -L/usr/local/lib

REVERT_SRC = $(SRCDIR)/revert_string.c
REVERT_OBJ = $(BUILD)/revert_string.o
LIB_STATIC = $(BUILD)/librevert.a
LIB_DYNLIB = $(BUILD)/librevert.dylib

.PHONY: all clean test run_static run_dynamic

all: $(LIB_STATIC) $(LIB_DYNLIB) revert_static revert_dynamic

$(BUILD):
	mkdir -p $(BUILD)

$(REVERT_OBJ): $(REVERT_SRC) | $(BUILD)
	$(CC) $(CFLAGS) $(PIC) -c $< -o $@

$(LIB_STATIC): $(REVERT_OBJ)
	ar rcs $@ $^

$(LIB_DYNLIB): $(REVERT_OBJ)
	$(CC) -dynamiclib -o $@ $^

revert_static: $(SRCDIR)/main.c $(LIB_STATIC)
	$(CC) $(CFLAGS) -o $@ $(SRCDIR)/main.c $(LIB_STATIC)

revert_dynamic: $(SRCDIR)/main.c $(LIB_DYNLIB)
	$(CC) $(CFLAGS) -L$(BUILD) -lrevert -o $@ $(SRCDIR)/main.c

test: $(LIB_DYNLIB)
	@echo "Building CUnit tests..."
	$(CC) $(CFLAGS) $(CUNIT_INC) -o test_revert $(TESTDIR)/tests.c -L$(BUILD) -lrevert $(CUNIT_LIB) -lcunit
	@echo "Running tests with DYLD_LIBRARY_PATH=$(PWD)/$(BUILD)"
	DYLD_LIBRARY_PATH=$(PWD)/$(BUILD) ./test_revert

clean:
	rm -rf $(BUILD) revert_static revert_dynamic test_revert

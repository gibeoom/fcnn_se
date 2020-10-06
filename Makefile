# COMPILERS ###############################################
CC = emcc

# FLAGS ###################################################
CFLAGS := -O3 -s WASM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap", "ccall", "getValue", "setValue"]' -s ALLOW_MEMORY_GROWTH=1

# DIRECTORIES ###############################################
LIB_DIR0 := ./libdh
LIB_DIRS += -L$(LIB_DIR0)

INC_DIR0 := ./
INC_DIRS += -I$(INC_DIR0)

SRC_DIR := ./

# OBJECTS ###############################################
SOURCE1 := webdh.c

# LIBRARIES ###############################################
LIBRARY1 := deephearing
LIBRARIES += -l$(LIBRARY1) -lm 

# ROUTINES ################################################
OUT :
	$(CC) $(FUNCTIONS) $(SRC_DIR)$(SOURCE1) $(CFLAGS) $(LIB_DIRS) $(LIBRARIES) $(INC_DIRS)

clean :
	rm -rf *.gch

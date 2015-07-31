include ../common.mk
INC    = ../include
SRC    = ../src
OBJ    = ../obj
BIN    = ../bin
CC     = gcc $(UNIXCCOPS) -I$(INC) -I$(GHAASDIR)//include
LINK   = gcc
LIBS   = -L$(GHAASDIR)/lib -lCM10 $(UNIXLIBS)

TARGET = $(BIN)/cstSurveying.bin


OBJS = $(OBJ)/CSTsurveying.o

all: ${TARGET}

clean:
	rm $(TARGET) $(OBJS)

$(TARGET): $(OBJS) $(SRC)/Makefile
	$(LINK) $(OBJS) $(LIBS) -o $(TARGET)

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDES)
	$(CC) -o $(OBJ)/$*.o -c $(SRC)/$*.c

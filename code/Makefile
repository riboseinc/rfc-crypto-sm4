.PHONY: clean

CFLAGS = -g

DEPS = sm4.h
OBJ = sm4.o sm4_main.o print.o
CC = c99

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sm4_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f $(OBJ) sm4_test


CC = gcc
LDFLAGS += -static -lm
cjson_parse:main.o cJSON.o
	$(CC) main.o cJSON.o $(LDFLAGS) -o cjson_parse
*.o:*.c
clean:
	rm -rf *.o cjson_parse
.PHONY: clean


TARGET:=main
CC:=gcc
PWD:=$(shell pwd)
CSRCS:=$(wildcard *.c)
OBJS:=$(patsubst %.c,%.o,$(CSRCS))
$(TARGET):$(OBJS)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) -c $^ -o $@
#伪目标
clean:
	rm $(OBJS)			
	rm $(TARGET)	

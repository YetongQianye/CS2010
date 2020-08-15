#你的目标名字是main
TARGET:=mycp
#CC表示编译器名字
CC:=gcc
#CC:=arm-linux-gnueabi-gcc
TFTP:=/home/ 

#库和头文件的路径
#INC:=-I$(shell  pwd)/inc
#INC+=
LIBS:=-lpthread
#LIBS:=-L../lib
#LIBS+=-lxxxx
#找出工程中所有的.c文件赋值给CSRCS
PWD:=$(shell pwd)
CSRCS:=$(wildcard *.c)
#CSRCS+=$(wildcard $(PWD)/src/*.c)
#把CSRCS中的文件名,变为同名的.o文件
OBJS:=$(patsubst %.c,%.o,$(CSRCS))

$(TARGET):$(OBJS)
	$(CC) $^ -o $@ $(LIBS)
	cp $@ $(TFTP)

%.o:%.c
	$(CC) -c $< -o $@ $(LIBS)
#伪目标
clean:
	rm $(OBJS)
	rm $(TARGET)
	rm $(TFTP)/$(TARGET)





	



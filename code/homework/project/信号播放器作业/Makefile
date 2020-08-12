
#TARGET 表示最终生成的可执行文件的名字
TARGET := mp4_player


#CC 表示编译器
CC := arm-linux-gcc

#CSRCS 表示工程中所有用到的.c文件的名字
CSRCS := $(wildcard *.c)
#CSRCS += $(wildcard mp3/*.c)

#OBJS 表示工程中所有.o文件 的名字
OBJS := $(patsubst %.c, %.o, $(CSRCS))

#INC 表示头文件的搜索路径
INC := -I ./
INC += -I ../

#LIBS 表示库的搜索路径
#LIBS := -L ./ -ljpg
LIBS += 


$(TARGET): $(OBJS)
	$(CC)  $^ $(LIBS) -o $@
	cp -rf $(TARGET) /home/gec/tftp


%.o : %.c
	$(CC) -c $< $(INC) -o $@

clean:
	rm -rf $(OBJS) $(TARGET)

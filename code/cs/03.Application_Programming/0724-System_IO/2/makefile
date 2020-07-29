#1.
# main:main.o maxnum.o
# 	echo $?
# 	gcc main.o  maxnum.o -o main
	
# main.o:main.c 
# 	echo $?
# 	gcc -c main.c -o main.o	

# maxnum.o: maxnum.c
# 	gcc -c  maxnum.c -o  maxnum.o
# maxnum.c:
# 	touch maxnum.c
	
# #伪目标
# clean:
# 	rm *.o
# 	rm main


#2.
# TARGET:=main
# CC:=gcc
# $(TARGET):main.o maxnum.o
# 	$(CC) $^ -o $@
	
# main.o:main.c 
# 	$(CC) -c $^ -o $@

# maxnum.o:maxnum.c
# 	$(CC) -c $^ -o $@
# maxnum.c:
# 	touch a.c
		
#伪目标
# clean:
# 	rm *.O			
# 	rm main		



#3.
TARGET:=main
CC:=gcc
$(TARGET):main.o maxnum.o
	$(CC) $^ -o $@
%.o:%.c
	$(CC) -c $^ -o $@
#伪目标
clean:
	rm *.O			
	rm main		
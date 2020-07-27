
main:main.o a.o b.o
	echo $?
	gcc main.o -o main
	
main.o:main.c 
	echo $?
	gcc -c main.c -o main.o	

a.o:a.c
	gcc -c a.c -o a.o
a.c:
	touch a.c

b.o:b.c
	gcc -c b.c -o b.o
b.c:
	touch b.c
	
#伪目标
clean:
	rm *.o
	rm main

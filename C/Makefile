CC=gcc

# run: rubiks
# 	time ./rubiks

rubiks: rubiks.o fun.o dict.o
	$(CC) obj/rubiks.o obj/dict.o obj/fun.o -shared -o librubiks.so

rubiks.o: src/rubiks.c include/dict.h include/fun.h
	$(CC) -c -fPIC src/rubiks.c -o obj/rubiks.o

dict.o: include/dict.h
	$(CC) -c -fPIC src/dict.c -o obj/dict.o

fun.o: include/fun.h
	$(CC) -c -fPIC src/fun.c -o obj/fun.o

clean:
	rm -f rubiks obj/*
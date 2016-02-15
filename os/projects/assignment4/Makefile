librand.a:
	gcc -c -o rand.o rand.c; \
	ar rcs librand.a rand.o

librand.so:
	gcc -c -o rand.o rand.c; \
	ar rcs librand.so rand.o

random:
	gcc -o random main.c -L. -lrand

random_static:
	gcc -static -o random main.c -L. -lrand

clean:
	rm -f *.o *.a *.so random

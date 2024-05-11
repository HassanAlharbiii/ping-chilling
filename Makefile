build/box: main.c
	gcc main.c -o build/box -lraylib -lm

run: build/box
	./build/box
build:
	g++ main.cpp vector.cpp world.c -g -lGL -lGLU -lglut -lGLEW -o salut -Wall
run:
	./salut
clear:
	rm salut
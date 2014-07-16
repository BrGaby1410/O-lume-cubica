build:
	g++ main.cpp -g -lGL -lGLU -lglut -o salut -Wall
run:
	./salut
clear:
	rm salut
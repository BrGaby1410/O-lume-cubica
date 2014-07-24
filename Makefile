build:
	g++ main.cpp vector.cpp -g -lGL -lGLU -lglut -o salut -Wall
run:
	./salut
clear:
	rm salut
build:
	g++ -O2 main.cpp vector.cpp world.cpp -g -lGL -lGLU -lglut -lGLEW -L. -Wl,-rpath,. -o salut -Wall
run:
	./salut
clear:
	rm salut
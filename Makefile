build:
	clang++ -Wall -Wextra -std=c++17 ./src/*.cpp -I ./include -L ./lib -lraylib -lm -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -o demo
run:
	./demo
clean:
	rm -f ./demo

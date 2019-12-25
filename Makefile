.PHONY: build install uninstall clean

build:
	g++ -o ./build/matrix_cpp main.cpp

install: build
	cp ./build/matrix_cpp /usr/bin/matrix_cpp

uninstall: build
	rm -f  /usr/bin/matrix_cpp

clean:
	rm -Rf ./build/*
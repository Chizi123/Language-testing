EXECUTABLES="./c" "./cpp" "java main" "./main.sh" "python main.py" "./rust" "./fortran"

.PHONY: default all clean test java bash python
default: all

c: main.c
	gcc main.c -o c

cpp: main.cpp
	g++ main.cpp -o cpp

java: main.class
main.class: main.java
	javac main.java

rust: main.rs
	rustc main.rs -o rust

fortran: main.f
	gfortran main.f -o fortran
	rm llist.mod

bash:
python:

all: c cpp java bash python rust fortran

test: all
	./test.sh ${EXECUTABLES}

clean:
	rm main.class c cpp rust fortran

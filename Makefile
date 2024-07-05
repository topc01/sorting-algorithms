build:
	mkdir -p build
	cd build && cmake ..

code:
	cd build && make && cd ..

run:
	mkdir -p times
	./build/code

test: include/time.o include/sort.o include/utils.o
	g++ main.cpp include/time.o include/sort.o include/utils.o -o test

%.o: %.cpp
	g++ -o $@ -c $<

clean:
	rm include/*.o test
	

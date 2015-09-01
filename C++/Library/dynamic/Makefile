CC=g++
BIN=libdymath.so
OBJ=DynamicMath.o

StaticMath.o:DynamicMath.cpp DynamicMath.h
	$(CC) -c -fPIC DynamicMath.cpp

.PHONY:c-dynamic 
c-dynamic:
	$(CC) -shared -o $(BIN) $(OBJ)

.PHONY:test
test:
	$(CC) TestDynamicMath.cpp -L./ -ldymath

.PHONY:clean
clean:
	rm -f $(OBJ) $(BIN) *.out

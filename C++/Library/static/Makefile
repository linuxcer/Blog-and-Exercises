CC=g++
BIN=libstaticmath.a
OBJ=StaticMath.o

StaticMath.o:StaticMath.cpp StaticMath.h
	$(CC) -c StaticMath.cpp

.PHONY:c-static  
c-static:
	ar -crv $(BIN) $(OBJ)

.PHONY:test
test:
	$(CC) TestStaticMath.cpp -L./ -lstaticmath

.PHONY:clean
clean:
	rm -f $(OBJ) $(BIN) *.out
